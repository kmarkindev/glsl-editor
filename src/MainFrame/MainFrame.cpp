#include "MainFrame.h"

MainFrame::MainFrame(wxWindow* parent)
	: wxFrame(parent, wxID_ANY, wxT("GLSL Editor"), wxDefaultPosition, wxSize(800, 600))
{
	SetupPanels();

	auto src = "#version 330 core \n out vec4 FragColor; uniform vec3 test; void main() { FragColor = vec4(test.x, test.y, test.z, 1); }";
	_shader = new Shader(src);
	_shader->Uniform3f("test", glm::vec3(0.2f, 0.3f, 0.3f));
}

void MainFrame::SetupPanels()
{
	auto mainSplitter = new wxSplitterWindow(this, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE | wxSP_BORDER);
	_codePanel = new CodePanel(mainSplitter, wxDefaultPosition);

	auto rightPanelSplitter = new wxSplitterWindow(mainSplitter, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE | wxSP_BORDER);
	_renderPanel = new RenderPanel(rightPanelSplitter);
	_uniformsPanel = new UniformsPanel(rightPanelSplitter);

	mainSplitter->SetMinimumPaneSize(200);
	mainSplitter->SetSashGravity(1.0f);
	mainSplitter->SplitVertically(_codePanel, rightPanelSplitter);

	rightPanelSplitter->SetSashGravity(0.0f);
	rightPanelSplitter->SetMinimumPaneSize(100);
	rightPanelSplitter->SplitHorizontally(_renderPanel, _uniformsPanel);
}
