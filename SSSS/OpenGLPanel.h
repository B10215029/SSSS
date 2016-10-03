#pragma once
#include <windows.h>

public ref class OpenGLPanel
{
public:
	OpenGLPanel(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer);
	~OpenGLPanel();

private:
	System::Windows::Forms::Panel^ panel;
	System::Windows::Forms::Timer^ timer;
	HDC hDC;
	HGLRC hGLRC;

private: System::Void panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void panel_Resize(System::Object^  sender, System::EventArgs^  e);
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e);

protected:
	virtual void initialize() = 0;
	virtual void reshape(int width, int height) = 0;
	virtual void display() = 0;
	virtual void MouseDown(int x, int y, int button) = 0;
	virtual void MouseUp(int x, int y, int button) = 0;
	virtual void MouseMove(int x, int y) = 0;
	virtual void MouseWheel(int x, int y, int delta) = 0;

};
