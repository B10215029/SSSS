#pragma once
#include "OpenGLPanel.h"
#include "resource.h"
#include <GL\glew.h>

public ref class MeshViewPanel : public OpenGLPanel
{
public:
	MeshViewPanel(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer);
	~MeshViewPanel();

private:
	const int vertexShaderResourceId = IDR_SHADER1;
	const int fragmentShaderResourceId = IDR_SHADER2;
	GLuint program;

protected:
	void initialize() override;
	void reshape(int width, int height) override;
	void display() override;
	void MouseDown(int x, int y, int button) override;
	void MouseUp(int x, int y, int button) override;
	void MouseMove(int x, int y) override;
	void MouseWheel(int x, int y, int delta) override;

};
