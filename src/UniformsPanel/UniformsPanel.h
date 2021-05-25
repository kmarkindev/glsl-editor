#pragma once

#include "UniformLine.h"
#include "IUniformDTO.h"

#include <wx/wx.h>
#include <string>
#include <vector>

class UniformsPanel : public wxScrolled<wxPanel>
{
public:
	UniformsPanel(wxWindow* parent,
		wxPoint position = wxDefaultPosition, wxSize size = wxDefaultSize);
	std::vector<IUniformDTO> GetUniforms();
	UniformLine* AddUniform();

private:
    std::vector<UniformLine> _lines;
};