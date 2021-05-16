#include "CodePanel.h"

CodePanel::CodePanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxPanel(parent, wxID_ANY, position, size)
{
	SetupTextCtrl();

	auto sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(_textCtrl, 1, wxEXPAND);
	SetSizer(sizer);
}

std::string CodePanel::GetSrc()
{
	return std::string(_textCtrl->GetValue().c_str());
}

void CodePanel::SetSrc(const std::string& newSrc)
{
	_textCtrl->SetValue(newSrc);
}

int CodePanel::GetFontSize()
{
	return _textCtrl->GetFont().GetPointSize();
}

void CodePanel::SetFontSize(int newSize)
{
	auto font = _textCtrl->GetFont();
	font.SetPointSize(newSize);
	_textCtrl->SetFont(font);
}

void CodePanel::SetupTextCtrl()
{
	_textCtrl = new wxTextCtrl(this, wxID_ANY, wxT(""), 
		wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_PROCESS_TAB | wxHSCROLL);

	SetFontSize(20);
}
