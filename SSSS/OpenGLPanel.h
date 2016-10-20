#pragma once
#include <windows.h>
#include "OpenGLImplement.h"

public ref class OpenGLPanel
{
public:
	OpenGLPanel(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer, OpenGLImplement* implementation);
	~OpenGLPanel();

private:
	System::Windows::Forms::Panel^ panel;
	System::Windows::Forms::Timer^ timer;
	HDC hDC;
	HGLRC hGLRC;
	OpenGLImplement* implementation;

private: System::Void panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_Resize(System::Object^  sender, System::EventArgs^  e);
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e);

};
