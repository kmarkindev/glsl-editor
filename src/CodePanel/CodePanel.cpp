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
	return _textCtrl->GetZoom();
}

void CodePanel::SetFontSize(int newSize)
{
	_textCtrl->SetZoom(newSize);
}

void CodePanel::SetupTextCtrl()
{
	_textCtrl = new wxStyledTextCtrl(this, wxID_ANY);
	_textCtrl->SetMarginType(1, wxSTC_MARGIN_NUMBER);
	_textCtrl->SetMarginWidth(1, 25);
}
