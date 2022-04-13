#include "cMain.h"

// cMain constructor - we must use the member initialization
// list to initialize the necessary parameters of the parent
// class wxFrame 
cMain::cMain()
	: wxFrame(nullptr, wxID_ANY, "Program 4 - Balloon Game")
{
	// First, we need to create the MyObjectList!
	m_objList = new MyObjectList();

	// For Program 4, we will get a bit more sophiscated with
	// our layour design. When using a Graphical Framework, we 
	// typically create panels to group related objects on and
	// a use a panel (or more than one) as a drawing surface

	// To get you started, I am creating two panels. The top
	// one will have game control elements like the fire button
	// and current score (it's up to you to add extras)

	// I have provided starter code so that you have a nice
	// starting point with wxWidgets and a layout that is reasonable

	// Create the game view panel, this is where we'll draw the 
	// actual gameplay objects like balloons and bombs.
	// need to create it first so we can pass a pointer to control
	m_GameViewPanel = new cGameViewPanel(this, m_objList);

	// Create the game control panel (will hold fire button and score)
	m_GameControlPanel = new cGameControlPanel(this, m_GameViewPanel, m_objList);

	// getting the client size of the frame to avoid calculating
	// how wide the borders are on the frame, just use the width
	// returned by GetClientSize to fully fill the width of the frame
	// and hardcode a value for height, I'm choosing 100 pixels
	wxSize tempSize = this->GetClientSize();
	m_GameControlPanel->SetSize(wxSize(tempSize.GetWidth(), 100));

	// finally, let's use a sizer so that the panel expands its
	// width anytime the user adjusts the screen size
	// Watch the video tutorial link I included in the Program 4
	// handout to find out what wxEXPAND | wxALL, 5 does in the
	// sizer's Add() function :) 
	wxBoxSizer* sizerMainFrame = new wxBoxSizer(wxVERTICAL);
	sizerMainFrame->Add(m_GameControlPanel, 0, wxEXPAND | wxALL, 5);

	// again, I'd like the panel to expand if the user resizes
	// the area, so I'm going to initialize the size relative to
	// the main frame and add a sizer to automatically take care of
	// re-sizing for me! Notice that I set the second parameter in 
	// the sizer's Add() function to 1 - this is the 
	// expansion/proportion factor. I don't need to bother
	// setting the size of this panel now, it will expand
	// in all directions to fill the client size of the main frame
	sizerMainFrame->Add(m_GameViewPanel, 1, wxEXPAND | wxLEFT | wxBOTTOM | wxRIGHT, 5);
	this->SetSizerAndFit(sizerMainFrame);

	// Finally, I want my main view frame to start out with a good size.
	// So, I manually set this after I'm done - my program did
	// not cooperate when I tried to initialize this in the member
	// initialization list once I added the sizers, so I just do it
	// here instead after adding the sizer-related functionality
	this->SetSize(wxSize(1080, 720));
}

cMain::~cMain()
{
	// only need to clean up dynamic memory related to 
	// NON-wxWidgets objects - wxWidgets cleans up its own
	// GUI elements to prevent crashes due to unhandled events
	// that might refer to child objects, etc. watch the tutorial
	// video I linked in class or talk to me if you are interested
	// in exploring this further

	// cMain owns the MyObjectList, it should be the ONLY class 
	// deleting it!
	if (m_objList != nullptr) delete m_objList;
}

bool cMain::OnInit()
{
	// nothing to do here for now, maybe your extra credit will need
	// some initialization :)

	return true;
}