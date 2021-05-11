#pragma once

#include "../RenderPanel/RenderPanel.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/Shader.h"
#include "../CodePanel/CodePanel.h"
#include "../UniformsPanel/UniformsPanel.h"

#include <wx/wx.h>
#include <wx/splitter.h>
#include <string>

class MainFrame : public wxFrame
{
public:
	MainFrame(wxWindow* parent);

private:
	RenderPanel* _renderPanel;
	CodePanel* _codePanel;
	UniformsPanel* _uniformsPanel;
	Shader* _shader;

	void SetupPanels();
};