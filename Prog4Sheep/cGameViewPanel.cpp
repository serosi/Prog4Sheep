#include "cGameViewPanel.h"

// implement the event table - map events like button clicks
// and mouse interactions to actual callback functions in our code
wxBEGIN_EVENT_TABLE(cGameViewPanel, wxPanel)
EVT_PAINT(OnPaint)
EVT_TIMER(10003, OnTimer)
EVT_LEFT_DOWN(OnLeftClick)
wxEND_EVENT_TABLE()

cGameViewPanel::cGameViewPanel(wxFrame* parent, MyObjectList* list)
	: wxPanel(parent, wxID_ANY)
{
	// Set the parent of the cGameViewPanel 
	m_parent = parent;

	// Set a pointer to the MyObjectList maintained in cMain
	m_objList = list;

	// our animation timer - a 30ms timer
	// wouldn't it be nice if the user could adjust the refresh rate?
	// sounds like some extra credit to me :)
	m_timer = new wxTimer(this, 10003);
	//m_slider = new wxSlider();
	double fps = 165;
	// 1000 / fps gives the milliseconds between each frame
	m_timer->Start(500);

	// There's a lot fewer controls created here because the view panel 
	// is our game's drawing surface - this is where game objects will appear
}

cGameViewPanel::~cGameViewPanel()
{
	// only need to clean up dynamic memory related to 
	// NON-wxWidgets objects - wxWidgets cleans up its own
	// GUI elements to prevent crashes due to unhandled events
	// that might refer to child objects, etc. watch the tutorial
	// video I linked in class or talk to me if you are interested
	// in exploring this further
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

void cGameViewPanel::OnLeftClick(wxMouseEvent& event)
{
	wxPoint mousePt = event.GetPosition();
}
