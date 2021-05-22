#include "UniformsPanel.h"

UniformsPanel::UniformsPanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxPanel(parent, wxID_ANY, position, size),
	_lines(std::vector<UniformLine>())
{

}

std::vector<IUniformDTO> UniformsPanel::GetUniforms()
{
    return std::vector<IUniformDTO>();
}
