#pragma once

#include "../RenderPanel/RenderPanel.h"
#include "../CodePanel/CodePanel.h"
#include "../UniformsPanel/UniformsPanel.h"
#include "../MainToolbar/MainToolbar.h"

#include <wx/wx.h>
#include <wx/splitter.h>
#include <string>

class MainToolbar;
class RenderPanel;

class MainFrame : public wxFrame
{
public:
	MainFrame(wxWindow* parent);

	/* Mediator methods */
	void LoadSrc(std::string newSrc);
	std::string GetSrc();
	void SetSrc(std::string newSrc);
	void IncreaseFontSize();
	void DecreaseFontSize();
	void RenderShader();
	void SetupUniforms();

private:
	RenderPanel* _renderPanel;
	CodePanel* _codePanel;
	UniformsPanel* _uniformsPanel;
	Shader* _shader;
	MainToolbar* _toolbar;

	void SetupPanels();
};