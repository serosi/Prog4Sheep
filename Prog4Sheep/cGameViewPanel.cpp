#include "cGameViewPanel.h"

// implement the event table - map events like button clicks
// and mouse interactions to actual callback functions in our code
wxBEGIN_EVENT_TABLE(cGameViewPanel, wxPanel)
EVT_PAINT(OnPaint)
EVT_TIMER(10003, OnTimer)
wxEND_EVENT_TABLE()

cGameViewPanel::cGameViewPanel(wxFrame* parent, MyObjectList* list)
	: wxPanel(parent, wxID_ANY)
{
	// Set the parent of the cGameViewPanel 
	m_parent = parent;

	// Set a pointer to the MyObjectList maintained in cMain
	m_objList = list;

	// animation timer
	m_timer = new wxTimer(this, 10003);
	m_timer->Start(24);

	// There's a lot fewer controls created here because the view panel 
	// is our game's drawing surface - this is where game objects will appear
}

cGameViewPanel::~cGameViewPanel()
{
}

void cGameViewPanel::OnPaint(wxPaintEvent& event)
{
	// create a device context
	wxPaintDC dc(this);

	wxBitmap* background = new wxBitmap("./background.bmp", wxBITMAP_TYPE_BMP);
	dc.DrawBitmap(*background, 0, 0, false);

	// The MyObjectList pointer shouldn't be nullptr, but check
	// just in case before invoking the ShowAll() function
	if (m_objList != nullptr)
		m_objList->ShowAll(dc);
}

void cGameViewPanel::OnTimer(wxTimerEvent& event)
{
	// The MyObjectList pointer shouldn't be nullptr, but check
	// just in case before invoking the MoveAll() function
	if (m_objList != nullptr)
		m_objList->MoveAll();

	// Force a re-draw
	Refresh();
	Update();
}

