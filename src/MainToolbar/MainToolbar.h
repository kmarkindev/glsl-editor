#pragma once

#include <wx/wx.h>

class MainToolbar : public wxToolBar
{
public:
	MainToolbar(wxWindow* parent);
	~MainToolbar();
private:
	wxBitmap* LoadToolbarBitmap(wxString path);

	wxBitmap* renderBitmap;
	wxBitmap* startRenderBitmap;
	wxBitmap* stopRenderBitmap;
	wxBitmap* plusFontSizeBitmap;
	wxBitmap* minusFontSizeBitmap;
};