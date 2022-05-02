#pragma once
#include <wx/wx.h>
#include "RedBalloon.h"
#include "YellowBalloon.h"
#include "GreenBalloon.h"
#include "BlueBalloon.h"
#include "Dart.h"
#include "MyObjectList.h"

class cGameControlPanel : public wxPanel
{
public:
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

