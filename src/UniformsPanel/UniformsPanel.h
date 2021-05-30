#pragma once

#include "UniformLine.h"
#include "IUniformDTO.h"

#include <wx/wx.h>
#include <string>
#include <vector>

class UniformLine;

class UniformsPanel : public wxScrolled<wxPanel>
{
public:
	UniformsPanel(wxWindow* parent,
		wxPoint position = wxDefaultPosition, wxSize size = wxDefaultSize);
	std::vector<IUniformDTO*> GetUniforms();
	UniformLine* AddUniform();
	void RefreshList();

private:
	wxBoxSizer* _subSizer;

	void AddButtonHandler(wxCommandEvent& event);

	enum class Ids : int
	{
		Add = wxID_LAST + 1
	};
};