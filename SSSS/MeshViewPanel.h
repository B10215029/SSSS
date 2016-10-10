#pragma once
#include "OpenGLPanel.h"
#include "resource.h"
#include "MyMesh.h"
#include <GL\glew.h>
#include <glm\glm.hpp>

public ref class MeshViewPanel : public OpenGLPanel
{
public:
	MeshViewPanel(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer);
	~MeshViewPanel();
	void UpdateMesh(MyMesh *mesh);

private:
	const int vertexShaderResourceId = IDR_SHADER3;
	const int fragmentShaderResourceId = IDR_SHADER4;
	GLuint program;
	GLuint vao, vbo, ebo;
	int vertexCount, faceCount;
	GLuint modelMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint projectionMatrixLocation;

protected:
	void initialize() override;
	void reshape(int width, int height) override;
	void display() override;
	void MouseDown(int x, int y, int button) override;
	void MouseUp(int x, int y, int button) override;
	void MouseMove(int x, int y) override;
	void MouseWheel(int x, int y, int delta) override;

};
