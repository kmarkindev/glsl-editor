#include "RenderPanel.h"

RenderPanel::RenderPanel(wxWindow* parent, wxPoint position, wxSize size)
	: wxPanel(parent, wxID_ANY, position, size)
{
	_shader = nullptr;

	wxGLAttributes attribs;
	attribs.Defaults().EndList();

	wxGLContextAttrs contextAttrs;
	contextAttrs.CoreProfile().OGLVersion(3, 3).EndList();

	_glCanvas = new wxGLCanvas(this, attribs, wxID_ANY);
	_glContext = new wxGLContext(_glCanvas, nullptr, &contextAttrs);

	auto sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(_glCanvas, 1, wxSHAPED | wxALIGN_CENTER);
	SetSizer(sizer);

	_glCanvas->SetCurrent(*_glContext);
	_renderer = Renderer::GetInstance();

	SetBackgroundColour(wxColor("white"));
}

void RenderPanel::Render()
{
	if (!_shader)
		return;

	auto rect = _glCanvas->GetRect();

	_glCanvas->SetCurrent(*_glContext);
	_renderer->SetViewport(0, 0, rect.width, rect.height);
	_renderer->Render(_shader);
	_glCanvas->SwapBuffers();
}

void RenderPanel::SetShader(Shader* shader)
{
	_shader = shader;
}

const Shader* RenderPanel::GetShader()
{
	return _shader;
}
