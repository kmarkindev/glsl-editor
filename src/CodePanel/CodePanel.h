#pragma once

#include <wx/wx.h>
#include <wx/textctrl.h>
#include <string>

class CodePanel : public wxPanel
{
public:
	CodePanel(wxWindow* parent,
		wxPoint position = wxDefaultPosition, wxSize size = wxDefaultSize);

	std::string GetSrc();
	void SetSrc(const std::string& newSrc);

private:
	wxTextCtrl* _textCtrl;

	void SetupTextCtrl();
};