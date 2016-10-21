#pragma once
#include <windows.h>

public class OpenGLPanel
{
public:
	OpenGLPanel();
	~OpenGLPanel();
	void SetPanel(HWND panelHandle);
	void Bind();
	void Release();

	virtual void initialize() = 0;
	virtual void reshape(int width, int height) = 0;
	virtual void display() = 0;
	virtual void MouseDown(int x, int y, int button) = 0;
	virtual void MouseUp(int x, int y, int button) = 0;
	virtual void MouseMove(int x, int y) = 0;
	virtual void MouseWheel(int x, int y, int delta) = 0;
	void Update();
	void Resize(int width, int height);

private:
	HDC hDC;
	HGLRC hGLRC;

};
