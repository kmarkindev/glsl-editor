#include "UniformsPanel.h"

UniformsPanel::UniformsPanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxPanel(parent, wxID_ANY, position, size),
	_lines(std::vector<UniformLine>())
{

    new UniformLine(this);
    new UniformLine(this);
    new UniformLine(this);
    new UniformLine(this);
    new UniformLine(this);
    new UniformLine(this);
    new UniformLine(this);
    new UniformLine(this);
    new UniformLine(this);

}

std::vector<IUniformDTO> UniformsPanel::GetUniforms()
{
    return std::vector<IUniformDTO>();
}
