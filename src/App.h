#pragma once

#include "MainFrame/MainFrame.h"

#include <wx/wx.h>

class App : public wxApp
{
protected:
	virtual bool OnInit();
};