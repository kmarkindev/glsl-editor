#pragma once

#include "../MainFrame/MainFrame.h"

#include <wx/wx.h>

class MainFrame;

class MainToolbar : public wxToolBar
{
public:
	MainToolbar(wxWindow* parent, MainFrame* mainFrame);
	~MainToolbar();

private:
	MainFrame* _mainFrame;
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
	void IncreaseButtonHandler(wxCommandEvent& event);
	void DecreaseButtonHandler(wxCommandEvent& event);

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