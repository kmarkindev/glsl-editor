#pragma once

#include "MainFrame/MainFrame.h"
#include "Time/Time.h"

#include <wx/wx.h>

class App : public wxApp
{
protected:
	virtual bool OnInit();
};