#include "OpenGLPanel.h"
#include <iostream>
#include <GL\glew.h>

OpenGLPanel::OpenGLPanel(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer, MeshView *implementation) : panel(panel), timer(timer), implementation(implementation)
{
	// set event
	this->panel->MouseDown += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLPanel::panel_MouseDown));
	this->panel->MouseUp += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLPanel::panel_MouseUp));
	this->panel->MouseMove += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLPanel::panel_MouseMove));
	this->panel->MouseWheel += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLPanel::panel_MouseWheel));
	this->panel->Resize += (gcnew System::EventHandler(this, &OpenGLPanel::panel_Resize));
	this->timer->Tick += (gcnew System::EventHandler(this, &OpenGLPanel::timer_Tick));

	// initial OpenGL
	hDC = GetDC((HWND)(panel->Handle.ToInt32()));
	hGLRC = NULL;

	// Set pixel format
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int cpf = ChoosePixelFormat(hDC, &pfd);
	if (!cpf) {
		std::cerr << "Choose Pixel Format Error\n";
		return;
	}

	SetPixelFormat(hDC, cpf, &pfd);

	hGLRC = wglCreateContext(hDC);
	if (!hGLRC) {
		std::cerr << "Create Render Context Error\n";
		return;
	}

	if (!wglMakeCurrent(hDC, hGLRC)) {
		hGLRC = NULL;
		std::cerr << "wglMakeCurrent Error\n";
		return;
	}
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
		return;
	}
	std::clog << (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(panel->Name)).ToPointer() << " create context ok" << std::endl;
	std::clog << "OpenGL Version: " << (char *)(glGetString(GL_VERSION)) << std::endl;

	implementation->initialize();
	implementation->reshape(panel->Width, panel->Height);
	wglMakeCurrent(NULL, NULL);
}

OpenGLPanel::~OpenGLPanel()
{
	if (hGLRC) {
		wglDeleteContext(hGLRC);
	}
}

System::Void OpenGLPanel::panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	switch (e->Button) {
	case System::Windows::Forms::MouseButtons::Left:
		implementation->MouseDown(e->X, e->Y, 0);
		break;
	case System::Windows::Forms::MouseButtons::Right:
		implementation->MouseDown(e->X, e->Y, 1);
		break;
	case System::Windows::Forms::MouseButtons::Middle:
		implementation->MouseDown(e->X, e->Y, 2);
		break;
	case System::Windows::Forms::MouseButtons::XButton1:
		implementation->MouseDown(e->X, e->Y, 3);
		break;
	case System::Windows::Forms::MouseButtons::XButton2:
		implementation->MouseDown(e->X, e->Y, 4);
		break;
	case System::Windows::Forms::MouseButtons::None:
	default:
		implementation->MouseDown(e->X, e->Y, -1);
		break;
	}
}

System::Void OpenGLPanel::panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	switch (e->Button) {
	case System::Windows::Forms::MouseButtons::Left:
		implementation->MouseUp(e->X, e->Y, 0);
		break;
	case System::Windows::Forms::MouseButtons::Right:
		implementation->MouseUp(e->X, e->Y, 1);
		break;
	case System::Windows::Forms::MouseButtons::Middle:
		implementation->MouseUp(e->X, e->Y, 2);
		break;
	case System::Windows::Forms::MouseButtons::XButton1:
		implementation->MouseUp(e->X, e->Y, 3);
		break;
	case System::Windows::Forms::MouseButtons::XButton2:
		implementation->MouseUp(e->X, e->Y, 4);
		break;
	case System::Windows::Forms::MouseButtons::None:
	default:
		implementation->MouseUp(e->X, e->Y, -1);
		break;
	}
}

System::Void OpenGLPanel::panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	implementation->MouseMove(e->X, e->Y);
}

System::Void OpenGLPanel::panel_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	implementation->MouseWheel(e->X, e->Y, e->Delta);
}

System::Void OpenGLPanel::panel_Resize(System::Object^  sender, System::EventArgs^  e)
{
	wglMakeCurrent(hDC, hGLRC);
	implementation->reshape(panel->Width, panel->Height);
	wglMakeCurrent(NULL, NULL);
}

System::Void OpenGLPanel::timer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	wglMakeCurrent(hDC, hGLRC);
	implementation->display();
	SwapBuffers(hDC);
	wglMakeCurrent(NULL, NULL);
}
