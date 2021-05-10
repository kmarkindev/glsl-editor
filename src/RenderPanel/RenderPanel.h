#pragma once

#include "../Renderer/Renderer.h"

#include <glad/glad.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>

class RenderPanel : public wxPanel
{
public:
	RenderPanel(wxWindow* parent,
		wxPoint position = wxDefaultPosition, wxSize size = wxDefaultSize);

	void Render(Shader* shader);

private:
	wxGLCanvas* _glCanvas;
	wxGLContext* _glContext;
	Renderer* _renderer;
};