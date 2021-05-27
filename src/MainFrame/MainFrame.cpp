#include "MainFrame.h"

MainFrame::MainFrame(wxWindow* parent)
	: wxFrame(parent, wxID_ANY, wxT("GLSL Editor"), wxDefaultPosition, wxSize(800, 600))
{
	SetupPanels();

	auto src = "#version 330 core \nout vec4 FragColor;\nvoid main()\n{\n\tFragColor = vec4(0.3, 0.2, 0.2, 1);\n}";
	_codePanel->SetSrc(src);

	_shader = new Shader(src);
}

void MainFrame::LoadSrc(std::string newSrc)
{
	_shader->SetSrc(newSrc);
}

std::string MainFrame::GetSrc()
{
	return _codePanel->GetSrc();
}

void MainFrame::SetSrc(std::string newSrc)
{
	_codePanel->SetSrc(newSrc);
}

void MainFrame::IncreaseFontSize()
{
	int size = _codePanel->GetFontSize() + 2;
	if (size < 35)
		_codePanel->SetFontSize(size);
}

void MainFrame::DecreaseFontSize()
{
	int size = _codePanel->GetFontSize() - 2;
	if(size > 0)
		_codePanel->SetFontSize(size);
}

void MainFrame::RenderShader()
{
	_renderPanel->Render(_shader);
}

void MainFrame::SetupUniforms()
{
	//clear shader uniforms
	//get uniforms from _uniformsPanel
	//apply them to Shader
}

void MainFrame::SetupPanels()
{
	auto mainSplitter = new wxSplitterWindow(this, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE | wxSP_BORDER);
	_codePanel = new CodePanel(mainSplitter, wxDefaultPosition);

	auto rightPanelSplitter = new wxSplitterWindow(mainSplitter, wxID_ANY,
		wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE | wxSP_BORDER);
	_renderPanel = new RenderPanel(rightPanelSplitter, this);
    _uniformsPanel = new UniformsPanel(rightPanelSplitter);

	mainSplitter->SetMinimumPaneSize(200);
	mainSplitter->SetSashGravity(1.0f);
	mainSplitter->SplitVertically(_codePanel, rightPanelSplitter);

	rightPanelSplitter->SetSashGravity(0.0f);
	rightPanelSplitter->SetMinimumPaneSize(100);
	rightPanelSplitter->SplitHorizontally(_renderPanel, _uniformsPanel);

	_toolbar = new MainToolbar(this, this);
	SetToolBar(_toolbar);
}
