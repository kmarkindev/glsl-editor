#include "UniformLine.h"

IUniformDTO* UniformLine::GetUniformDTO()
{
    return new UniformDTO<bool>(_nameCtrl->GetValue().ToStdString(), true);
}

UniformLine::UniformLine(wxWindow *parent)
    : wxPanel(parent, wxID_ANY)
{
    _nameCtrl = new wxTextCtrl(this, wxID_ANY);
    _typeCtrl = new wxComboBox(this, wxID_ANY);

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(_nameCtrl, 2, 0, 1);
    sizer->Add(_typeCtrl, 1, 0, 1);

    SetSizer(sizer);
}
