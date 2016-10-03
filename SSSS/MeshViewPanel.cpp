#include "MeshViewPanel.h"
#include "ShaderUtility.h"
#include <iostream>

MeshViewPanel::MeshViewPanel(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer) : OpenGLPanel(panel, timer)
{

}

MeshViewPanel::~MeshViewPanel()
{

}

void MeshViewPanel::initialize()
{
	std::cout << "initialize" << std::endl;
	program = loadProgram(vertexShaderResourceId, fragmentShaderResourceId);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void MeshViewPanel::reshape(int width, int height)
{
	std::cout << "reshape" << width << ", " << height << std::endl;
	glViewport(0, 0, width, height);
}

void MeshViewPanel::display()
{
	std::cout << "display" <<std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(program);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
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
