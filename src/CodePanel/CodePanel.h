#pragma once

#include <wx/wx.h>
#include <string>

class CodePanel : public wxPanel
{
public:
	CodePanel(wxWindow* parent,
		wxPoint position = wxDefaultPosition, wxSize size = wxDefaultSize);
};