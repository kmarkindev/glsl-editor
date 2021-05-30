#include "UniformsPanel.h"

UniformsPanel::UniformsPanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxScrolled<wxPanel>(parent, wxID_ANY, position, size),
	_lines(std::vector<UniformLine>())
{
    auto mainSizer = new wxBoxSizer(wxVERTICAL);
    _subSizer = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(new wxButton(this, (int)Ids::Add, wxT("Add uniform")), 0, wxEXPAND);
    mainSizer->Add(_subSizer, 1, wxEXPAND);

    Connect((int)Ids::Add, wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler(UniformsPanel::AddButtonHandler));

    SetSizer(mainSizer);
    SetScrollRate(2, 2);
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

    _subSizer->Add(newLine, 0, wxEXPAND | wxALL, 5);
    _subSizer->FitInside(this);
    Layout();

    return newLine;
}

void UniformsPanel::AddButtonHandler(wxCommandEvent& event)
{
    AddUniform();
}
