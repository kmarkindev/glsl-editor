#include <wx/wx.h>

class LeftPanel : public wxPanel
{
public:

	LeftPanel(wxWindow* parent, wxStaticText* label)
		: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(100, 300))
	{
		this->label = label;
		plusButton = new wxButton(this, PLUS_BUTTON_ID, wxT("+"), wxPoint(10, 10), wxSize(50, 20));
		minusButton = new wxButton(this, MINUS_BUTTON_ID, wxT("-"), wxPoint(10, 70), wxSize(50, 20));
		counter = 0;
		
		Connect(PLUS_BUTTON_ID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnPlusButtonClicked));
		Connect(MINUS_BUTTON_ID, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LeftPanel::OnMinusButtonClicked));
		
		UpdateLabel();
	}

private:

	wxButton* plusButton;
	wxButton* minusButton;
	int counter;

	wxStaticText* label;

	const int PLUS_BUTTON_ID = 101;
	const int MINUS_BUTTON_ID = 102;

	void UpdateLabel()
	{
		wxString str;

		str.Printf(wxT("Counter: %d"), counter);

		label->SetLabelText(str);
	}

	void OnPlusButtonClicked(wxCommandEvent& event)
	{
		counter++;
		UpdateLabel();
	}

	void OnMinusButtonClicked(wxCommandEvent& event)
	{
		counter--;
		UpdateLabel();
	}
};

class MainFrame : public wxFrame
{

public:

	MainFrame()
		: wxFrame(nullptr, wxID_ANY, wxT("Main Frame"), wxDefaultPosition, wxSize(400, 400))
	{
		textField = new wxStaticText(this, wxID_ANY, wxT(""), wxPoint(250, 20), wxSize(100, 50));
		leftPanel = new LeftPanel(this, textField);
	}

private:

	LeftPanel* leftPanel;
	wxStaticText* textField;

};

class App : public wxApp
{
public:

	bool OnInit()
	{
		MainFrame* frame = new MainFrame();
		frame->Show();

		return true;
	}

};

IMPLEMENT_APP(App);