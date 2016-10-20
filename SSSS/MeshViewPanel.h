#pragma once
#include "resource.h"
#include "MyMesh.h"
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "OpenGLImplement.h"

class MeshView : public OpenGLImplement
{
public:
	MeshView();
	~MeshView();
	void UpdateMesh(MyMesh *mesh);
	int width;
	MyMesh* mainMesh;
	MyMesh* selectMesh;
	int height;
	bool isLMBDown;
	bool isMMBDown;
	glm::ivec2 previousMousePosition;
	glm::vec3 transform;
	glm::vec3 rotation;
	glm::vec4 faceColor;
	glm::vec4 lineColor;
	glm::vec4 pointColor;
	bool isLighting;
	bool drawFace;
	bool drawLine;
	bool drawPoint;
	float lineWidth;
	float pointSize;

	bool LoadMainMesh(const char* filename) {
		mainMesh = new MyMesh();
		mainMesh->request_vertex_normals();
		mainMesh->request_face_normals();
		if (!mainMesh->has_vertex_normals())
		{
			std::cerr << "ERROR: Standard vertex property 'Normals' not available!\n";
		}

		if (!OpenMesh::IO::read_mesh(*mainMesh, filename))
		{
			std::cerr << "read error\n";
			return false;
		}
		mainMesh->update_normals();
		isInvalid = true;

		return true;
	}

private:
	const int drawSolidVertexShaderResourceId = IDR_SHADER3;
	const int drawSolidFragmentShaderResourceId = IDR_SHADER4;
	const int drawWireframeVertexShaderResourceId = IDR_SHADER3;
	const int drawWireframeFragmentShaderResourceId = IDR_SHADER4;
	GLuint drawSolidProgram;
	GLuint drawWireframeProgram;
	GLuint vao, vbo, ebo;
	int vertexCount, faceCount;
	GLuint modelMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint projectionMatrixLocation;
	GLuint colorLocation;
	GLuint isLightingLocation;
	bool isInvalid;

public:
	void initialize();
	void reshape(int width, int height);
	void display();
	void MouseDown(int x, int y, int button);
	void MouseUp(int x, int y, int button);
	void MouseMove(int x, int y);
	void MouseWheel(int x, int y, int delta);
};
