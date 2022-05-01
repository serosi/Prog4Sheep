#pragma once
#include <wx/wx.h>
#include "Balloon.h"
#include "Dart.h"
#include "MyObjectList.h"

// it's better design to add controls to a panel and
// attach panels to our top-level frame - this gives
// a lot more control and flexibility to our designs!
// ****
// The cGameControlPanel is where we will draw game control
// elements like the "Fire" button
class cGameControlPanel : public wxPanel
{
public:
	// the control panel will know about the view panel
	// better ways to handle this to minimize coupling
	// again, you'll learn about them in OOAD
	cGameControlPanel(wxFrame* parent, wxPanel* view, MyObjectList* list);
	~cGameControlPanel();

	// I will want to access this externally
	wxStaticText* m_scoreValue = nullptr;

private:
	wxFrame* m_parent = nullptr;
	wxPanel* m_view = nullptr;
	wxButton* m_fireBtn = nullptr;
	wxButton* m_launchBtn = nullptr;
	wxStaticText* m_scoreText = nullptr;
	MyObjectList* m_objList = nullptr;

public:
	void OnButtonLaunch(wxCommandEvent& evt);
	void OnButtonFire(wxCommandEvent& evt);

	// need to declare the event table in header
	// this event table is relative to the panel
	wxDECLARE_EVENT_TABLE();
};

