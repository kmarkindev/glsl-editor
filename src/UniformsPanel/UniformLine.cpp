#include "UniformLine.h"

IUniformDTO* UniformLine::GetUniformDTO()
{
    return new UniformDTO<bool>(_nameCtrl->GetValue().ToStdString(), true);
}

UniformLine::UniformLine(wxWindow *parent)
    : wxPanel(parent, wxID_ANY)
{
    SetSize(wxSize(100, 50));

    // TODO: need flyweight
    auto typeList = new wxArrayString();
    typeList->Add(wxT("Bool"));
    typeList->Add(wxT("Float"));
    typeList->Add(wxT("Float2"));
    typeList->Add(wxT("Float3"));
    typeList->Add(wxT("Float4"));

    _nameCtrl = new wxTextCtrl(this, wxID_ANY);
    _typeCtrl = new wxComboBox(this, wxID_ANY,
        wxT("Bool"), wxDefaultPosition, wxDefaultSize,*typeList,wxCB_READONLY);

    CreateInputControls();
    ShowBool();

    auto sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(_nameCtrl, 1, wxEXPAND);
    sizer->Add(_typeCtrl, 0, wxEXPAND);
    sizer->Add(_boolPanel, 1, wxEXPAND);
    sizer->Add(_floatPanel, 1, wxEXPAND);
    sizer->Add(_float2Panel, 1, wxEXPAND);
    sizer->Add(_float3Panel, 1, wxEXPAND);
    sizer->Add(_float4Panel, 1, wxEXPAND);

    SetSizer(sizer);
}

void UniformLine::CreateInputControls()
{
    // qui spem ponitur (give up hope everyone who enters here)

    // TODO: fix control sizes. Now it's too large

    wxBoxSizer* sizer = nullptr;

    // Bool
    _boolPanel = new wxPanel(this);
    _boolPanel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_boolCheckbox = new wxCheckBox(_boolPanel, wxID_ANY, wxT("Is True")), 1, wxEXPAND | wxALL, 2);
    _boolCheckbox->SetSize(wxSize(50, 50));
    // Float
    _floatPanel = new wxPanel(this);
    _floatPanel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_floatXCtrl = new wxTextCtrl(_floatPanel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    // Float2
    _float2Panel = new wxPanel(this);
    _float2Panel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_float2XCtrl = new wxTextCtrl(_float2Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    sizer->Add(_float2YCtrl = new wxTextCtrl(_float2Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    // Float3
    _float3Panel = new wxPanel(this);
    _float3Panel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_float3XCtrl = new wxTextCtrl(_float3Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    sizer->Add(_float3YCtrl = new wxTextCtrl(_float3Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    sizer->Add(_float3ZCtrl = new wxTextCtrl(_float3Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    // Float4
    _float4Panel = new wxPanel(this);
    _float4Panel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_float4XCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    sizer->Add(_float4YCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    sizer->Add(_float4ZCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
    sizer->Add(_float4WCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 1, wxEXPAND | wxALL, 2);
}

void UniformLine::ShowBool()
{
    HideActivePanel();
    _boolPanel->Show(true);
}

void UniformLine::ShowFloat()
{
    HideActivePanel();
    _floatPanel->Show(true);
}

void UniformLine::ShowFloat2()
{
    HideActivePanel();
    _float2Panel->Show(true);
}

void UniformLine::ShowFloat3()
{
    HideActivePanel();
    _float3Panel->Show(true);
}

void UniformLine::ShowFloat4()
{
    HideActivePanel();
    _float4Panel->Show(true);
}

void UniformLine::HideActivePanel()
{
    _boolPanel->Show(false);
    _floatPanel->Show(false);
    _float2Panel->Show(false);
    _float3Panel->Show(false);
    _float4Panel->Show(false);
}
