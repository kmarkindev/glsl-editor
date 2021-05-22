#pragma once

#include "IUniformDTO.h"
#include "UniformDTO.h"

#include <wx/wx.h>

class UniformLine : public wxPanel
{
public:

    UniformLine(wxWindow* parent);

    IUniformDTO* GetUniformDTO();

private:
    wxTextCtrl* _nameCtrl;
    wxComboBox* _typeCtrl;

};
