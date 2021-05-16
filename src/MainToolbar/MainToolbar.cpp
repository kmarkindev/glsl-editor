#include "MainToolbar.h"

MainToolbar::MainToolbar(wxWindow* parent, RenderPanel* renderPanel)
	: wxToolBar(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORZ_TEXT)
{
	_randerPanel = renderPanel;
	_renderTimer = new wxTimer(this, (int)Ids::RenderTimer);

	LoadBitmaps();
	SetupButtons();
	BindEvents();
}

MainToolbar::~MainToolbar()
{
	_renderTimer->Stop();

	delete renderBitmap;
	delete startRenderBitmap;
	delete stopRenderBitmap;
	delete plusFontSizeBitmap;
	delete minusFontSizeBitmap;
}

wxBitmap* MainToolbar::LoadToolbarBitmap(wxString path)
{
	auto image = wxImage(path, wxBITMAP_TYPE_PNG);
	image.Rescale(30, 30);

	return new wxBitmap(image);
}

void MainToolbar::LoadBitmaps()
{
	renderBitmap = LoadToolbarBitmap(wxT("resources/toolbar_render.png"));
	startRenderBitmap = LoadToolbarBitmap(wxT("resources/toolbar_render_start.png"));
	stopRenderBitmap = LoadToolbarBitmap(wxT("resources/toolbar_render_pause.png"));
	plusFontSizeBitmap = LoadToolbarBitmap(wxT("resources/toolbar_font_plus.png"));
	minusFontSizeBitmap = LoadToolbarBitmap(wxT("resources/toolbar_font_minus.png"));
}

void MainToolbar::SetupButtons()
{
	AddTool((int)Ids::Render, wxT("Render"), *renderBitmap,
		wxT("Renders loaded shader on the canvas"));
	AddTool((int)Ids::StartRenderLoop,
		wxT("Start"), *startRenderBitmap, wxT("Starts render loop"));
	AddTool((int)Ids::StopRenderLoop,
		wxT("Stop"), *stopRenderBitmap, wxT("Pauses render loop"));

	AddSeparator();

	AddTool((int)Ids::AddFontSize, wxT("Font size"),
		*plusFontSizeBitmap, wxT("Increases font size of shader code"));
	AddTool((int)Ids::SubFontSize, wxT("Font size"),
		*minusFontSizeBitmap, wxT("Decreases font size of shader code"));

	EnableTool((int)Ids::StopRenderLoop, false);

	Realize();
}

void MainToolbar::BindEvents()
{
	Connect((int)Ids::Render, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(MainToolbar::RenderButtonHandler));
	Connect((int)Ids::StartRenderLoop, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(MainToolbar::StartRenderButtonHandler));
	Connect((int)Ids::StopRenderLoop, wxEVT_COMMAND_TOOL_CLICKED,
		wxCommandEventHandler(MainToolbar::StopRenderButtonHandler));
	Connect((int)Ids::RenderTimer, wxEVT_TIMER,
		wxCommandEventHandler(MainToolbar::RenderTimerHandler));
}

void MainToolbar::RenderButtonHandler(wxCommandEvent& event)
{
	_renderTimer->StartOnce();
}

void MainToolbar::StartRenderButtonHandler(wxCommandEvent& event)
{
	EnableTool((int)Ids::Render, false);
	EnableTool((int)Ids::StartRenderLoop, false);
	EnableTool((int)Ids::StopRenderLoop, true);

	_renderTimer->Start(16);
}

void MainToolbar::StopRenderButtonHandler(wxCommandEvent& event)
{
	EnableTool((int)Ids::Render, true);
	EnableTool((int)Ids::StartRenderLoop, true);
	EnableTool((int)Ids::StopRenderLoop, false);

	_renderTimer->Stop();
}

void MainToolbar::RenderTimerHandler(wxCommandEvent& event)
{
	_randerPanel->Render();
}
