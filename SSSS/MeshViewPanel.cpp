#include "MeshViewPanel.h"
#include "ShaderUtility.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

MeshViewPanel::MeshViewPanel(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer) : OpenGLPanel(panel, timer)
{

}

MeshViewPanel::~MeshViewPanel()
{

}

void MeshViewPanel::initialize()
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
	if (!OpenMesh::IO::read_mesh(mesh, "Juassic_5471.obj"))
	{
		std::cerr << "read error\n";
	}
	mesh.update_normals();
	UpdateMesh(&mesh);
}

void MeshViewPanel::reshape(int width, int height)
{
	std::cout << "reshape" << width << ", " << height << std::endl;
	glViewport(0, 0, width, height);
}

void MeshViewPanel::display()
{
	//std::cout << "display" <<std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(program);
	glm::mat4 model(1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -1000));
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 1000.f);;
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void MeshViewPanel::MouseDown(int x, int y, int button)
{

}

void MeshViewPanel::MouseUp(int x, int y, int button)
{

}

void MeshViewPanel::MouseMove(int x, int y)
{

}

void MeshViewPanel::MouseWheel(int x, int y, int delta)
{

}

void MeshViewPanel::UpdateMesh(MyMesh *mesh)
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
