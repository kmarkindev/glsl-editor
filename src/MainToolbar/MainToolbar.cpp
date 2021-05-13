#include "MainToolbar.h"

MainToolbar::MainToolbar(wxWindow* parent)
	: wxToolBar(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORZ_TEXT)
{
	renderBitmap = LoadToolbarBitmap(wxT("resources/toolbar_render.png"));
	startRenderBitmap = LoadToolbarBitmap(wxT("resources/toolbar_render_start.png"));
	stopRenderBitmap = LoadToolbarBitmap(wxT("resources/toolbar_render_pause.png"));
	plusFontSizeBitmap = LoadToolbarBitmap(wxT("resources/toolbar_font_plus.png"));
	minusFontSizeBitmap = LoadToolbarBitmap(wxT("resources/toolbar_font_minus.png"));

	AddTool(wxID_ANY, wxT("Render"), *renderBitmap, wxT("Renders loaded shader on the canvas"));
	AddTool(wxID_ANY, wxT("Start"), *startRenderBitmap, wxT("Starts render loop"));
	AddTool(wxID_ANY, wxT("Stop"), *stopRenderBitmap, wxT("Pauses render loop"));

	AddSeparator();

	AddTool(wxID_ANY, wxT("Font size"), *plusFontSizeBitmap, wxT("Increases font size of shader code"));
	AddTool(wxID_ANY, wxT("Font size"), *minusFontSizeBitmap, wxT("Decreases font size of shader code"));

	Realize();
}

MainToolbar::~MainToolbar()
{
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