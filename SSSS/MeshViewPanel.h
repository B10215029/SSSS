#pragma once
#include "resource.h"
#include "OpenGLPanel.h"
#include "MyMesh.h"
#include <GL\glew.h>
#include <glm\glm.hpp>

class MeshViewPanel : public OpenGLPanel
{
public:
	MeshViewPanel();
	~MeshViewPanel();
	int width;
	int height;
	MyMesh* mainMesh;
	MyMesh* selectMesh;
	glm::vec3 transform;
	glm::vec3 rotation;
	glm::vec4 faceColor;
	glm::vec4 lineColor;
	glm::vec4 pointColor;
	bool isLMBDown;
	bool isMMBDown;
	bool isLighting;
	bool drawFace;
	bool drawLine;
	bool drawPoint;
	float lineWidth;
	float pointSize;

	enum ViewDirection
	{
		FrontView,
		BackView,
		TopView,
		BottomView,
		RightView,
		LeftView,
		FTRView,
		BBLView,
		ResetView
	};

private:
	const int drawSolidVertexShaderResourceId = IDR_SHADER3;
	const int drawSolidFragmentShaderResourceId = IDR_SHADER4;
	const int drawWireframeVertexShaderResourceId = IDR_SHADER3;
	const int drawWireframeFragmentShaderResourceId = IDR_SHADER4;
	GLuint drawSolidProgram;
	GLuint drawWireframeProgram;
	GLuint vao, vbo, ebo;
	int vertexCount, faceCount;
	glm::ivec2 previousMousePosition;
	GLuint modelMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint projectionMatrixLocation;
	GLuint colorLocation;
	GLuint isLightingLocation;

public:
	void UpdateMainMesh(MyMesh *mesh);
	bool LoadMainMesh(const char* filename);
	void SetView(ViewDirection viewDirection);

	void initialize();
	void reshape(int width, int height);
	void display();
	void MouseDown(int x, int y, int button);
	void MouseUp(int x, int y, int button);
	void MouseMove(int x, int y);
	void MouseWheel(int x, int y, int delta);
};
