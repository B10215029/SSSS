#include "MeshViewPanel.h"
#include "ShaderUtility.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

MeshViewPanel::MeshViewPanel()
{
	mainMesh = NULL;
	selectMesh = NULL;
	isLMBDown = false;
	isRMBDown = false;
	isMMBDown = false;
	SetView(ResetView);
}

MeshViewPanel::~MeshViewPanel()
{

}

void MeshViewPanel::initialize()
{
	std::cout << "initialize" << std::endl;
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	drawSolidProgram = loadProgram(drawSolidVertexShaderResourceId, drawSolidFragmentShaderResourceId);
	modelMatrixLocation = glGetUniformLocation(drawSolidProgram, "model_matrix");
	viewMatrixLocation = glGetUniformLocation(drawSolidProgram, "view_matrix");
	projectionMatrixLocation = glGetUniformLocation(drawSolidProgram, "projection_matrix");
	colorLocation = glGetUniformLocation(drawSolidProgram, "color");
	isLightingLocation = glGetUniformLocation(drawSolidProgram, "isLighting");
	LoadMainMesh("../3D Mesh/Juassic_5471.obj");
}

void MeshViewPanel::reshape(int width, int height)
{
	//std::cout << "reshape" << width << ", " << height << std::endl;
	glViewport(0, 0, width, height);
	this->width = width;
	this->height = height;
}

void MeshViewPanel::display()
{
	//std::cout << "display" <<std::endl;
	if (!mainMesh) {
		return;
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(drawSolidProgram);
	glm::mat4 model = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1, 0, 0));
	model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 view = glm::translate(glm::mat4(1.0f), transform);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 10000.f);;
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(vao);
	if (drawFace) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glUniform4fv(colorLocation, 1, glm::value_ptr(faceColor));
		glUniform1i(isLightingLocation, isLighting);
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
		glUniform1i(isLightingLocation, 0);
	}
	if (drawLine) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glUniform4fv(colorLocation, 1, glm::value_ptr(lineColor));
		glEnable(GL_POLYGON_OFFSET_LINE);
		glPolygonOffset(-0.5, -0.5);
		glLineWidth(lineWidth);
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
	}
	if (drawPoint) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glUniform4fv(colorLocation, 1, glm::value_ptr(pointColor));
		glEnable(GL_POLYGON_OFFSET_POINT);
		glPolygonOffset(-0.6, -0.6);
		glPointSize(pointSize);
		glDrawElements(GL_TRIANGLES, faceCount * 3, GL_UNSIGNED_INT, 0);
	}
	glBindVertexArray(0);
}

void MeshViewPanel::UpdateMainMesh(MyMesh *mesh)
{
	Bind();
	if (mainMesh) {
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);
	}
	mainMesh = mesh;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	maxPointDist = 0;
	vertexCount = mesh->n_vertices();
	GLdouble *vertexData = new GLdouble[vertexCount * 6];
	for (MyMesh::VertexIter v_it = mesh->vertices_begin(); v_it != mesh->vertices_end(); ++v_it) {
		memcpy(vertexData + (v_it->idx() * 6), mesh->point(v_it.handle()).data(), sizeof(GLdouble) * 3);
		memcpy(vertexData + (v_it->idx() * 6 + 3), mesh->normal(v_it.handle()).data(), sizeof(GLdouble) * 3);
		for (int i = 0; i < 3; i++) {
			if (abs(mesh->point(v_it.handle())[i]) > maxPointDist) {
				maxPointDist = abs(mesh->point(v_it.handle())[i]);
			}
		}
	}
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(GLdouble) * 6, vertexData, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, sizeof(GLdouble) * 6, 0);
	glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, sizeof(GLdouble) * 6, (GLvoid*)(sizeof(GLdouble) * 3));
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

	glBindVertexArray(0);
	Release();
}

bool MeshViewPanel::LoadMainMesh(const char* filename) {
	MyMesh* mesh = new MyMesh();
	OpenMesh::IO::Options options;
	if (OpenMesh::IO::read_mesh(*mesh, filename, options)) {
		if (!options.check(OpenMesh::IO::Options::VertexNormal) && mesh->has_vertex_normals()) {
			mesh->update_normals();
		}
		//MyMesh* oldMesh = mainMesh;
		UpdateMainMesh(mesh);
		//if (oldMesh)
		//	delete[] oldMesh;
		SetView(ResetView);
		return true;
	}
	else {
		std::cerr << "read error\n";
		delete mesh;
		return false;
	}
}

void MeshViewPanel::SetView(ViewDirection viewDirection)
{
	switch(viewDirection) {
	case FrontView:
		rotation = glm::vec3(0, 0, 0);
		break;
	case BackView:
		rotation = glm::vec3(0, glm::pi<float>(), 0);
		break;
	case TopView:
		rotation = glm::vec3(glm::pi<float>() / 2, 0, 0);
		break;
	case BottomView:
		rotation = glm::vec3(-glm::pi<float>() / 2, 0, 0);
		break;
	case RightView:
		rotation = glm::vec3(0, -glm::pi<float>() / 2, 0);
		break;
	case LeftView:
		rotation = glm::vec3(0, glm::pi<float>() / 2, 0);
		break;
	case FTRView:
		rotation = glm::vec3(glm::pi<float>() / 4, -glm::pi<float>() / 4, 0);
		break;
	case BBLView:
		rotation = glm::vec3(-glm::pi<float>() / 4, glm::pi<float>() / 4, 0);
		break;
	case ResetView:
		transform = glm::vec3(0, 0, -maxPointDist * 3);
		rotation = glm::vec3(0, 0, 0);
		break;
	default:
		break;
	}
}

void MeshViewPanel::ExtractionMesh(float s)
{
	mainMesh->Extraction(s);
	UpdateMainMesh(mainMesh);
}

void MeshViewPanel::MouseDown(int x, int y, int button)
{
	if (button == 0)
		isLMBDown = true;
	if (button == 1)
		isRMBDown = true;
	if (button == 2)
		isMMBDown = true;
	previousMousePosition.x = x;
	previousMousePosition.y = y;
}

void MeshViewPanel::MouseUp(int x, int y, int button)
{
	if (button == 0)
		isLMBDown = false;
	if (button == 1)
		isRMBDown = false;
	if (button == 2)
		isMMBDown = false;
}

void MeshViewPanel::MouseMove(int x, int y)
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

void MeshViewPanel::MouseWheel(int x, int y, int delta)
{
	if (isRMBDown) {
		if (delta < 0) {
			transform.z -= 10;
		}
		else {
			transform.z += 10;
		}
	}
	else if (isLMBDown) {
		if (delta < 0) {
			transform.z -= 1000;
		}
		else {
			transform.z += 1000;
		}
	}
	else {
		if (delta < 0) {
			transform.z -= 100;
		}
		else {
			transform.z += 100;
		}
	}

}
