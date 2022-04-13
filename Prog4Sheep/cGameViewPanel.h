#pragma once
#include <wx/wx.h>
#include "MyObjectList.h"

// it's better design to add controls to a panel and
// attach panels to our top-level frame - this gives
// a lot more control and flexibility to our designs!
// ****
// The cGameViewPanel is where we will draw game elements
// like balloons and bombs, etc.
class cGameViewPanel : public wxPanel
{
public:
	cGameViewPanel(wxFrame* parent, MyObjectList* list);
	~cGameViewPanel();

private:
	wxFrame* m_parent = nullptr;
	wxTimer* m_timer = nullptr;
	MyObjectList* m_objList = nullptr;

public:
	void OnPaint(wxPaintEvent& event);
	void OnTimer(wxTimerEvent& event);

	// need to declare the event table in header
	// this event table is relative to the panel
	wxDECLARE_EVENT_TABLE();
};

