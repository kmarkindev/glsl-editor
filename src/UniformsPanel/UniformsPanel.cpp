#include "UniformsPanel.h"

UniformsPanel::UniformsPanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxScrolled<wxPanel>(parent, wxID_ANY, position, size),
	_lines(std::vector<UniformLine>())
{
    SetSizer(new wxBoxSizer(wxVERTICAL));

    for(int i = 0; i < 3; ++i)
        AddUniform();

    SetScrollRate(1, 1);
}

std::vector<IUniformDTO*> UniformsPanel::GetUniforms()
{
    auto uniforms = std::vector<IUniformDTO*>();

    auto sizer = GetSizer();

    for (auto* line : sizer->GetChildren())
    {
        auto dto = ((UniformLine*)line->GetWindow())->GetUniformDTO();
        uniforms.push_back(dto);
    }

    return uniforms;
}

UniformLine* UniformsPanel::AddUniform()
{
    auto newLine = new UniformLine(this);

    auto sizer = GetSizer();
    sizer->Add(newLine, 0, wxEXPAND | wxALL, 5);
    sizer->FitInside(this);

    return newLine;
}
