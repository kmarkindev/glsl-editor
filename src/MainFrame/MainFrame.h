#pragma once

#include "../RenderPanel/RenderPanel.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/Shader.h"

#include <wx/wx.h>
#include <string>

class MainFrame : public wxFrame
{
public:
	MainFrame(wxWindow* parent);
protected:
	RenderPanel* _renderPanel;

	void OnClick(wxCommandEvent& event);
private:
	Shader* _shader;
};