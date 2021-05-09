#include "App.h"

bool App::OnInit()
{
	auto mainForm = new MainFrame(nullptr);
	mainForm->Centre();
	mainForm->Show();

	return true;
}
