#pragma once

#include <wx/wx.h>
#include <wx/stc/stc.h>
#include <string>

class CodePanel : public wxPanel
{
public:
	CodePanel(wxWindow* parent,
		wxPoint position = wxDefaultPosition, wxSize size = wxDefaultSize);

	std::string GetSrc();
	void SetSrc(const std::string& newSrc);

	int GetFontSize();
	void SetFontSize(int newSize);

private:
	wxStyledTextCtrl* _textCtrl;

	void SetupTextCtrl();
};