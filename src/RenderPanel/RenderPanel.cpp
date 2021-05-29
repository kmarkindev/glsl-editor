#include "RenderPanel.h"

RenderPanel::RenderPanel(wxWindow* parent, MainFrame* mainFrame,
	wxPoint position, wxSize size)
	: wxPanel(parent, wxID_ANY, position, size),
	_mainFrame(mainFrame)
{
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
}

void RenderPanel::Render(Shader* shader)
{
	assert(shader != nullptr);

	_mainFrame->SetupUniforms();

	auto rect = _glCanvas->GetRect();

	_glCanvas->SetCurrent(*_glContext);
	_renderer->SetViewport(0, 0, rect.width, rect.height);
	_renderer->Render(shader);
	_glCanvas->SwapBuffers();
}

std::tuple<int, int> RenderPanel::GetCanvasSize()
{
	auto rect = _glCanvas->GetRect();
	return std::make_tuple(rect.width, rect.height);
}
