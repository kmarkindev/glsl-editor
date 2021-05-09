#pragma once

#include <wx/wx.h>

#include "MainFrame/MainFrame.h"

class App : public wxApp
{
protected:
	virtual bool OnInit();
};