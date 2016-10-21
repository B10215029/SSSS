#include "OpenGLEventTrigger.h"

OpenGLEventTrigger::OpenGLEventTrigger(System::Windows::Forms::Panel^ panel, System::Windows::Forms::Timer^ timer, OpenGLPanel* drawer) : panel(panel), timer(timer), drawer(drawer)
{
	drawer->SetPanel((HWND)(panel->Handle.ToInt32()));
	drawer->Resize(panel->Width, panel->Height);

	// set event
	this->panel->MouseDown += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLEventTrigger::panel_MouseDown));
	this->panel->MouseUp += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLEventTrigger::panel_MouseUp));
	this->panel->MouseMove += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLEventTrigger::panel_MouseMove));
	this->panel->MouseWheel += (gcnew System::Windows::Forms::MouseEventHandler(this, &OpenGLEventTrigger::panel_MouseWheel));
	this->panel->Resize += (gcnew System::EventHandler(this, &OpenGLEventTrigger::panel_Resize));
	this->timer->Tick += (gcnew System::EventHandler(this, &OpenGLEventTrigger::timer_Tick));
}

OpenGLEventTrigger::~OpenGLEventTrigger()
{
}

System::Void OpenGLEventTrigger::panel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	switch (e->Button) {
	case System::Windows::Forms::MouseButtons::Left:
		drawer->MouseDown(e->X, e->Y, 0);
		break;
	case System::Windows::Forms::MouseButtons::Right:
		drawer->MouseDown(e->X, e->Y, 1);
		break;
	case System::Windows::Forms::MouseButtons::Middle:
		drawer->MouseDown(e->X, e->Y, 2);
		break;
	case System::Windows::Forms::MouseButtons::XButton1:
		drawer->MouseDown(e->X, e->Y, 3);
		break;
	case System::Windows::Forms::MouseButtons::XButton2:
		drawer->MouseDown(e->X, e->Y, 4);
		break;
	case System::Windows::Forms::MouseButtons::None:
	default:
		drawer->MouseDown(e->X, e->Y, -1);
		break;
	}
}

System::Void OpenGLEventTrigger::panel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	switch (e->Button) {
	case System::Windows::Forms::MouseButtons::Left:
		drawer->MouseUp(e->X, e->Y, 0);
		break;
	case System::Windows::Forms::MouseButtons::Right:
		drawer->MouseUp(e->X, e->Y, 1);
		break;
	case System::Windows::Forms::MouseButtons::Middle:
		drawer->MouseUp(e->X, e->Y, 2);
		break;
	case System::Windows::Forms::MouseButtons::XButton1:
		drawer->MouseUp(e->X, e->Y, 3);
		break;
	case System::Windows::Forms::MouseButtons::XButton2:
		drawer->MouseUp(e->X, e->Y, 4);
		break;
	case System::Windows::Forms::MouseButtons::None:
	default:
		drawer->MouseUp(e->X, e->Y, -1);
		break;
	}
}

System::Void OpenGLEventTrigger::panel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	drawer->MouseMove(e->X, e->Y);
}

System::Void OpenGLEventTrigger::panel_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	drawer->MouseWheel(e->X, e->Y, e->Delta);
}

System::Void OpenGLEventTrigger::panel_Resize(System::Object^  sender, System::EventArgs^  e)
{
	drawer->Resize(panel->Width, panel->Height);
}

System::Void OpenGLEventTrigger::timer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	drawer->Update();
}