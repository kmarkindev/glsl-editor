#pragma once

#include "../RenderPanel/RenderPanel.h"

#include <wx/wx.h>

class MainToolbar : public wxToolBar
{
public:
	MainToolbar(wxWindow* parent, RenderPanel* renderPanel);
	~MainToolbar();

private:
	RenderPanel* _randerPanel;
	wxTimer* _renderTimer;

	wxBitmap* LoadToolbarBitmap(wxString path);

	wxBitmap* renderBitmap;
	wxBitmap* startRenderBitmap;
	wxBitmap* stopRenderBitmap;
	wxBitmap* plusFontSizeBitmap;
	wxBitmap* minusFontSizeBitmap;

	void LoadBitmaps();
	void SetupButtons();
	void BindEvents();

	void RenderButtonHandler(wxCommandEvent& event);
	void StartRenderButtonHandler(wxCommandEvent& event);
	void StopRenderButtonHandler(wxCommandEvent& event);
	void RenderTimerHandler(wxCommandEvent& event);

	enum class Ids : int
	{
		Render = wxID_LAST + 1,
		StartRenderLoop,
		StopRenderLoop,
		AddFontSize,
		SubFontSize,
		RenderTimer
	};
};