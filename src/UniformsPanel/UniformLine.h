#pragma once

#include "UniformsPanel.h"
#include "IUniformDTO.h"
#include "UniformDTO.h"

#include <wx/wx.h>
#include <string>

class UniformsPanel;

class UniformLine : public wxPanel
{
public:

    UniformLine(wxWindow* parent, UniformsPanel* mainPanel);

    IUniformDTO* GetUniformDTO();

private:
    wxButton* _deleteBtn;
    wxTextCtrl* _nameCtrl;
    wxComboBox* _typeCtrl;
    wxBoxSizer* _sizer;
    UniformsPanel* _mainPanel;

    //TODO: move to separate classes

    // Bool
    wxPanel* _boolPanel;
    wxCheckBox* _boolCheckbox;
    // Float
    wxPanel* _floatPanel;
    wxTextCtrl* _floatXCtrl;
    // Float2
    wxPanel* _float2Panel;
    wxTextCtrl* _float2XCtrl;
    wxTextCtrl* _float2YCtrl;
    // Float3
    wxPanel* _float3Panel;
    wxTextCtrl* _float3XCtrl;
    wxTextCtrl* _float3YCtrl;
    wxTextCtrl* _float3ZCtrl;
    // Float4
    wxPanel* _float4Panel;
    wxTextCtrl* _float4XCtrl;
    wxTextCtrl* _float4YCtrl;
    wxTextCtrl* _float4ZCtrl;
    wxTextCtrl* _float4WCtrl;

    void CreateInputControls();
    void ShowBool();
    void ShowFloat();
    void ShowFloat2();
    void ShowFloat3();
    void ShowFloat4();
    void HideActivePanel();

    void OnTypeSelectedHandler(wxCommandEvent& event);
    void DeleteButtonHandler(wxCommandEvent& event);

    std::string GetUniformType();

    enum class Ids : int 
    {
        ComboBox = wxID_LAST + 1,
        Delete,
    };

};
