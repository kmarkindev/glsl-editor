#include "MainFrame.h"

MainFrame::MainFrame(wxWindow* parent)
	: wxFrame(parent, wxID_ANY, wxT("GLSL Editor"), wxDefaultPosition, wxSize(400, 400))
{
	auto sizer = new wxBoxSizer(wxHORIZONTAL);

	_renderPanel = new RenderPanel(this);

	auto button = new wxButton(this, 1001, wxT("Render"), wxDefaultPosition, wxSize(100, 50));
	Connect(1001, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnClick));

	sizer->Add(button, 1);
	sizer->Add(_renderPanel, 2, wxEXPAND);

	SetSizerAndFit(sizer);

	auto src = "#version 330 core \n out vec4 FragColor; uniform vec3 test; void main() { FragColor = vec4(test.x, test.y, test.z, 1); }";
	_shader = new Shader(src);
	_shader->Uniform3f("test", glm::vec3(0.2f, 0.3f, 0.3f));
}

void MainFrame::OnClick(wxCommandEvent& event)
{
	_renderPanel->Render(_shader);
}
