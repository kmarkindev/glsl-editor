#include "App.h"
#include "MainForm/MainForm.h"

bool App::OnInit()
{
	auto mainForm = new MainForm(nullptr);
	mainForm->Centre();
	mainForm->Show();

	return true;
}
