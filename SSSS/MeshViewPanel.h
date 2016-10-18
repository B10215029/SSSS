#pragma once
#include "resource.h"
#include "MyMesh.h"
#include <GL\glew.h>
#include <glm\glm.hpp>

class MeshView
{
public:
	MeshView();
	~MeshView();
	void UpdateMesh(MyMesh *mesh);
	int width;
	int height;
	bool isLMBDown;
	bool isMMBDown;
	glm::ivec2 previousMousePosition;
	glm::vec3 transform;
	glm::vec3 rotation;

private:
	const int vertexShaderResourceId = IDR_SHADER3;
	const int fragmentShaderResourceId = IDR_SHADER4;
	GLuint program;
	GLuint vao, vbo, ebo;
	int vertexCount, faceCount;
	GLuint modelMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint projectionMatrixLocation;

public:
	void initialize();
	void reshape(int width, int height);
	void display();
	void MouseDown(int x, int y, int button);
	void MouseUp(int x, int y, int button);
	void MouseMove(int x, int y);
	void MouseWheel(int x, int y, int delta);

};
