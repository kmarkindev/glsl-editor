#include "RenderPanel.h"

RenderPanel::RenderPanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxPanel(parent, wxID_ANY, position, size)
{
	wxGLAttributes attribs;
	attribs.Defaults().EndList();

	wxGLContextAttrs contextAttrs;
	contextAttrs.CoreProfile().OGLVersion(3, 3).EndList();

	_glCanvas = new wxGLCanvas(this, attribs, wxID_ANY);
	_glContext = new wxGLContext(_glCanvas, nullptr, &contextAttrs);

	auto sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(_glCanvas, 1, wxEXPAND);
	SetSizer(sizer);

	_glCanvas->SetCurrent(*_glContext);
	_renderer = Renderer::GetInstance();

	SetBackgroundColour(wxColor("white"));
}

void RenderPanel::Render(Shader* shader)
{
	auto rect = _glCanvas->GetRect();

	_glCanvas->SetCurrent(*_glContext);
	_renderer->SetViewport(0, 0, rect.width, rect.height);
	_renderer->Render(shader);
	_glCanvas->SwapBuffers();
}