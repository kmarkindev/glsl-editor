#include "UniformLine.h"

IUniformDTO* UniformLine::GetUniformDTO()
{
    auto name = _nameCtrl->GetValue().ToStdString();
    auto type = GetUniformType();

    //TODO: use State

    if (type == wxT("Bool"))
    {
        return new UniformDTO<bool>(name, _boolCheckbox->GetValue());
    }
    else if (type == wxT("Float"))
    {
        double value = 0;
        _floatXCtrl->GetValue().ToDouble(&value);
        return new UniformDTO<float>(name, value);
    }
    else if (type == wxT("Float2"))
    {
        double value = 0;
        double value2 = 0;
        _float2XCtrl->GetValue().ToDouble(&value);
        _float2YCtrl->GetValue().ToDouble(&value2);
        return new UniformDTO<glm::vec2>(name, glm::vec2(value, value2));
    }
    else if (type == wxT("Float3"))
    {
        double value = 0;
        double value2 = 0;
        double value3 = 0;
        _float3XCtrl->GetValue().ToDouble(&value);
        _float3YCtrl->GetValue().ToDouble(&value2);
        _float3ZCtrl->GetValue().ToDouble(&value3);
        return new UniformDTO<glm::vec3>(name, glm::vec3(value, value2, value3));
    }
    else if (type == wxT("Float4"))
    {
        double value = 0;
        double value2 = 0;
        double value3 = 0;
        double value4 = 0;
        _float4XCtrl->GetValue().ToDouble(&value);
        _float4YCtrl->GetValue().ToDouble(&value2);
        _float4ZCtrl->GetValue().ToDouble(&value3);
        _float4WCtrl->GetValue().ToDouble(&value4);
        return new UniformDTO<glm::vec4>(name, glm::vec4(value, value2, value3, value4));
    }
    else
        return nullptr;
}

UniformLine::UniformLine(wxWindow *parent, UniformsPanel* mainPanel)
    : wxPanel(parent, wxID_ANY),
    _mainPanel(mainPanel)
{
    SetSize(wxSize(100, 50));

    // TODO: use flyweight
    auto typeList = new wxArrayString();
    typeList->Add(wxT("Bool"));
    typeList->Add(wxT("Float"));
    typeList->Add(wxT("Float2"));
    typeList->Add(wxT("Float3"));
    typeList->Add(wxT("Float4"));

    _deleteBtn = new wxButton(this, (int)Ids::Delete, wxT("X"));
    _deleteBtn->SetSize(wxSize(50, 50));
    _nameCtrl = new wxTextCtrl(this, wxID_ANY);
    _typeCtrl = new wxComboBox(this, (int)Ids::ComboBox,
        wxT("Bool"), wxDefaultPosition, wxDefaultSize, *typeList, wxCB_READONLY);
    Connect((int)Ids::ComboBox, wxEVT_COMBOBOX, wxCommandEventHandler(UniformLine::OnTypeSelectedHandler));
    Connect((int)Ids::Delete, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(UniformLine::DeleteButtonHandler));

    CreateInputControls();
    ShowBool();

    _sizer = new wxBoxSizer(wxHORIZONTAL);
    _sizer->Add(_deleteBtn, 0, wxEXPAND);
    _sizer->Add(_nameCtrl, 0, wxEXPAND);
    _sizer->Add(_typeCtrl, 0, wxEXPAND);
    _sizer->Add(_boolPanel, 0, wxEXPAND);
    _sizer->Add(_floatPanel, 0, wxEXPAND);
    _sizer->Add(_float2Panel, 0, wxEXPAND);
    _sizer->Add(_float3Panel, 0, wxEXPAND);
    _sizer->Add(_float4Panel, 0, wxEXPAND);

    SetSizer(_sizer);
}

void UniformLine::CreateInputControls()
{
    // qui spem ponitur (give up hope everDyone who enters here)

    // FIX: fix control sizes. Now it's too large

    wxBoxSizer* sizer = nullptr;

    // Bool
    _boolPanel = new wxPanel(this);
    _boolPanel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_boolCheckbox = new wxCheckBox(_boolPanel, wxID_ANY, wxT("Is True")), 0, wxEXPAND | wxALL, 2);
    _boolCheckbox->SetSize(wxSize(50, 50));
    // Float
    _floatPanel = new wxPanel(this);
    _floatPanel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_floatXCtrl = new wxTextCtrl(_floatPanel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    // Float2
    _float2Panel = new wxPanel(this);
    _float2Panel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_float2XCtrl = new wxTextCtrl(_float2Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    sizer->Add(_float2YCtrl = new wxTextCtrl(_float2Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    // Float3
    _float3Panel = new wxPanel(this);
    _float3Panel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_float3XCtrl = new wxTextCtrl(_float3Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    sizer->Add(_float3YCtrl = new wxTextCtrl(_float3Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    sizer->Add(_float3ZCtrl = new wxTextCtrl(_float3Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    // Float4
    _float4Panel = new wxPanel(this);
    _float4Panel->SetSizer(sizer = new wxBoxSizer(wxHORIZONTAL));
    sizer->Add(_float4XCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    sizer->Add(_float4YCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    sizer->Add(_float4ZCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
    sizer->Add(_float4WCtrl = new wxTextCtrl(_float4Panel, wxID_ANY), 0, wxEXPAND | wxALL, 2);
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

void UniformLine::OnTypeSelectedHandler(wxCommandEvent& event)
{
    auto value = _typeCtrl->GetValue();

    if(value == wxT("Bool"))
        ShowBool();
    else if(value == wxT("Float"))
        ShowFloat();
    else if(value == wxT("Float2"))
        ShowFloat2();
    else if(value == wxT("Float3"))
        ShowFloat3();
    else if(value == wxT("Float4"))
        ShowFloat4();
    else
        assert(false);

    _sizer->Layout();
}

void UniformLine::DeleteButtonHandler(wxCommandEvent& event)
{
    auto main = _mainPanel;
    Destroy();
    main->RefreshList();
}

std::string UniformLine::GetUniformType()
{
    return _typeCtrl->GetValue().ToStdString();
}
