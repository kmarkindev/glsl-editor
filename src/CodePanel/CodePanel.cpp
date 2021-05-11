#include "CodePanel.h"

CodePanel::CodePanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxPanel(parent, wxID_ANY, position, size)
{
	SetBackgroundColour(wxColor("purple"));
}