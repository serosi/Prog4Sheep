#include "cGameControlPanel.h"

// implement the event table - map events like button clicks
// and mouse interactions to actual callback functions in our code
wxBEGIN_EVENT_TABLE(cGameControlPanel, wxPanel)
EVT_BUTTON(10001, OnButtonLaunch)
EVT_BUTTON(10002, OnButtonFire)
wxEND_EVENT_TABLE()

cGameControlPanel::cGameControlPanel(wxFrame* parent, wxPanel* view, MyObjectList* list)
	: wxPanel(parent, wxID_ANY)
{
	// Set the parent of the cGameControlPanel 
	m_parent = parent;

	// Set a pointer to the cGameViewPanel
	// better ways to do this to avoid coupling, like using
	// signals and custom events, you'll learn more in OOAD
	m_view = view;

	// Set a pointer to the MyObjectList maintained in cMain
	m_objList = list;

	// I'm adding the following elements for basic control
	// - a FIRE! button 
	// - a textbox to display "Score: "
	// - a textbox to actually display the current score
	// - a wxFont description to change the size of the text
	// - and a button for launching balloons
	// I'm also creating a sizer to make adding the gui elements a bit easier

	// I looked up how to change the font size of a wxStaticText box using
	// Mr. Google and used the first bit of code that made sense
	wxFont myFont = wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

	// I could specify the size of the buttons, but you can look into that if you like!
	// There are programmatic ways to generate unique IDs in wxWidgets
	// like the function wxNewId() or the defined wxID_HIGHEST
	// But, keeping it simple for starter code - you can hardcode
	// IDs if you want, just makes the code a bit hard to maintain
	m_launchBtn = new wxButton(this, 10001, "Launch Sheep");
	m_fireBtn = new wxButton(this, 10002, "Throw Dart");

	//m_scoreText = new wxStaticText(this, wxID_ANY, "Score: ", wxPoint(170, 20), wxSize(120, 50));
	m_scoreText = new wxStaticText(this, wxID_ANY, "Score: ");
	m_scoreText->SetFont(myFont);

	//m_scoreValue = new wxStaticText(this, wxID_ANY, "0", wxPoint(290, 20), wxSize(120, 50));
	m_scoreValue = new wxStaticText(this, wxID_ANY, "0");
	m_scoreValue->SetFont(myFont);

	// finally, create the size and add all controls
	// watch the tutorial video I posted in the Program 4 handout if you are 
	// interested in what some of the parameters do!
	wxBoxSizer* sizerViewPanel = new wxBoxSizer(wxHORIZONTAL);
	sizerViewPanel->Add(m_launchBtn, 0, wxEXPAND | wxALL, 5);
	sizerViewPanel->Add(m_fireBtn, 0, wxEXPAND | wxALL, 5);
	sizerViewPanel->Add(m_scoreText, 0, wxEXPAND | wxALL, 5);
	sizerViewPanel->Add(m_scoreValue, 1, wxEXPAND | wxALL, 5);
	this->SetSizerAndFit(sizerViewPanel);

	// We could make this control panel look WAY nicer and add more gameplay
	// options for the user - that could be worth a little extra credit ;)
}

cGameControlPanel::~cGameControlPanel()
{
	// only need to clean up dynamic memory related to 
	// NON-wxWidgets objects - wxWidgets cleans up its own
	// GUI elements to prevent crashes due to unhandled events
	// that might refer to child objects, etc. watch the tutorial
	// video I linked in class or talk to me if you are interested
	// in exploring this further
}

void cGameControlPanel::OnButtonLaunch(wxCommandEvent& evt)
{
	// I have given you the basic starting point for creating
	// and drawing a yellow balloon to the screen
	// But, I have erased my Move() code for Balloon. So, it
	// is created and just sits there forever!

	// create a yellow balloon randomly along the bottom of the view panel
	// Need a MyObject to pass to MyObjectList
	MyObject* balloon;

	// random starting position along the bottom of view panel
	wxSize tempSize = m_view->GetClientSize();
	// random x start location (between 100 and panel width - 100)
	int startX = (rand() % (tempSize.GetX() - 100)) + 100;
	// hardcoded y start location (100 pixels from bottom)
	int startY = tempSize.GetY() - 350;

	// create the Balloon now that we have all starting parameters
	balloon = new Balloon(startX, startY, m_view, m_scoreValue);

	// add the balloon to the object list
	// The MyObjectList pointer shouldn't be nullptr, but check
	// just in case before adding the object
	if (m_objList != nullptr)
		m_objList->AddToList(balloon);
}

void cGameControlPanel::OnButtonFire(wxCommandEvent& evt)
{
	// I have given you the basic starting point for creating
	// and drawing a Dart to the screen
	// But, I have erased my Move() code for the Dart. So, it
	// is created and just sits there forever!

	// points to the newly created balloon object
	MyObject* dart;

	// don't really need this if we are always starting along the left border of the panel, but you might want to do some extra credit
	wxSize tempSize = m_view->GetClientSize();

	// hardcode a spot along the left border to release the Dart or, experiment with firing options for extra credit!
	int startX = 5;
	int startY = 50;

	dart = new Dart(startX, startY, m_view, m_scoreValue);

	// add the Dart to the object list
	// The MyObjectList pointer shouldn't be nullptr, but check just in case before adding the object
	if (m_objList != nullptr)
		m_objList->AddToList(dart);
}

void cGameControlPanel::OnFireDart(wxPoint& mousePt)
{
	
}
