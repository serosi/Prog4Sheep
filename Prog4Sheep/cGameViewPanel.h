#pragma once
#include <wx/wx.h>
#include "MyObjectList.h"

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

