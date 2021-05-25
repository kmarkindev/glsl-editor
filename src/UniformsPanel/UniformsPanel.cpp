#include "UniformsPanel.h"

UniformsPanel::UniformsPanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxScrolled<wxPanel>(parent, wxID_ANY, position, size),
	_lines(std::vector<UniformLine>())
{
    SetSizer(new wxBoxSizer(wxVERTICAL));

    for(int i = 0; i < 20; ++i)
        AddUniform();

    SetScrollRate(1, 1);
}

std::vector<IUniformDTO> UniformsPanel::GetUniforms()
{
    return std::vector<IUniformDTO>();
}

UniformLine* UniformsPanel::AddUniform()
{
    auto newLine = new UniformLine(this);

    auto sizer = GetSizer();
    sizer->Add(newLine, 0, wxEXPAND | wxALL, 5);
    sizer->FitInside(this);

    return newLine;
}
