#include "MeshViewPanel.h"
#include "ShaderUtility.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

MeshView::MeshView()
{
	isLMBDown = false;
	isMMBDown = false;
}

MeshView::~MeshView()
{

}

void MeshView::initialize()
{
	std::cout << "initialize" << std::endl;
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	program = loadProgram(vertexShaderResourceId, fragmentShaderResourceId);
	modelMatrixLocation = glGetUniformLocation(program, "model_matrix");
	viewMatrixLocation = glGetUniformLocation(program, "view_matrix");
	projectionMatrixLocation = glGetUniformLocation(program, "projection_matrix");
	MyMesh mesh;
	mesh.request_vertex_normals();
	mesh.request_face_normals();
	if (!mesh.has_vertex_normals())
	{
		std::cerr << "ERROR: Standard vertex property 'Normals' not available!\n";
	}

	if (!OpenMesh::IO::read_mesh(mesh, "../3D Mesh/Juassic_5471.obj"))
	{
		std::cerr << "read error\n";
	}
	mesh.update_normals();

	UpdateMesh(&mesh);
}

void MeshView::reshape(int width, int height)
{
	//std::cout << "reshape" << width << ", " << height << std::endl;
	glViewport(0, 0, width, height);
	this->width = width;
	this->height = height;
}

void MeshView::display()
{
	//std::cout << "display" <<std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(program);
	glm::mat4 model = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1, 0, 0));
	model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 view = glm::translate(glm::mat4(1.0f), transform);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 10000.f);;
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void MeshView::UpdateMesh(MyMesh *mesh)
{
	GLuint vao, vbo, ebo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vertexCount = mesh->n_vertices();
	GLfloat *vertexData = new GLfloat[vertexCount * 6];
	for (MyMesh::VertexIter v_it = mesh->vertices_begin(); v_it != mesh->vertices_end(); ++v_it) {
		memcpy(vertexData + (v_it->idx() * 6), mesh->point(v_it.handle()).data(), sizeof(GLfloat) * 3);
		memcpy(vertexData + (v_it->idx() * 6 + 3), mesh->normal(v_it.handle()).data(), sizeof(GLfloat) * 3);
	}
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(GLfloat) * 6, vertexData, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (GLvoid*)(sizeof(GLfloat) * 3));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	delete[] vertexData;

	faceCount = mesh->n_faces();
	GLuint *vertexIndices = new GLuint[faceCount * 3];
	for (MyMesh::FaceIter f_it = mesh->faces_begin(); f_it != mesh->faces_end(); ++f_it) {
		int i = 0;
		for (MyMesh::FaceVertexIter fv_it = mesh->fv_iter(f_it.handle()); fv_it.is_valid(); ++fv_it, ++i) {
			vertexIndices[f_it->idx() * 3 + i] = fv_it->idx();
		}
	}
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, faceCount * sizeof(GLuint) * 3, vertexIndices, GL_STATIC_DRAW);
	delete[] vertexIndices;

	glBindVertexArray(vao);

	this->vao = vao;
	this->vbo = vbo;
	this->ebo = ebo;
}

void MeshView::MouseDown(int x, int y, int button)
{
	if (button == 0) {
		isLMBDown = true;
	}
	if (button == 2) {
		isMMBDown = true;
	}
	previousMousePosition.x = x;
	previousMousePosition.y = y;
}

void MeshView::MouseUp(int x, int y, int button)
{
	if (button == 0)
		isLMBDown = false;
	if (button == 2)
		isMMBDown = false;
}

void MeshView::MouseMove(int x, int y)
{
	if (isLMBDown) {
		rotation.x += glm::radians((float)(y - previousMousePosition.y));
		rotation.y += glm::radians((float)(x - previousMousePosition.x));
	}
	if (isMMBDown) {
		transform.x += (x - previousMousePosition.x) * glm::abs(transform.z) / 500;
		transform.y -= (y - previousMousePosition.y) * glm::abs(transform.z) / 500;
	}
	previousMousePosition.x = x;
	previousMousePosition.y = y;
}

void MeshView::MouseWheel(int x, int y, int delta)
{
	if (delta < 0) {
		transform.z -= 100;
	}
	else {
		transform.z += 100;
	}
}
