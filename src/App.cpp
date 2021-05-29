#include "App.h"

bool App::OnInit()
{
	Time::GetInstance();
	wxImage::AddHandler(new wxPNGHandler());

	auto mainForm = new MainFrame(nullptr);
	mainForm->Centre();
	mainForm->Show();

	return true;
}
