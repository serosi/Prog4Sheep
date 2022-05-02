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
	m_view = view;
	m_objList = list;

	wxFont myFont = wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

	m_launchBtn = new wxButton(this, 10001, "Launch Sheep");
	m_fireBtn = new wxButton(this, 10002, "Throw Dart");


	m_scoreText = new wxStaticText(this, wxID_ANY, "Score: ");
	m_scoreText->SetFont(myFont);

	m_scoreValue = new wxStaticText(this, wxID_ANY, "0");
	m_scoreValue->SetFont(myFont);

	// create the size and add all controls
	wxBoxSizer* sizerViewPanel = new wxBoxSizer(wxHORIZONTAL);
	sizerViewPanel->Add(m_launchBtn, 0, wxEXPAND | wxALL, 5);
	sizerViewPanel->Add(m_fireBtn, 0, wxEXPAND | wxALL, 5);
	sizerViewPanel->Add(m_scoreText, 0, wxEXPAND | wxALL, 5);
	sizerViewPanel->Add(m_scoreValue, 1, wxEXPAND | wxALL, 5);
	this->SetSizerAndFit(sizerViewPanel);
}

cGameControlPanel::~cGameControlPanel()
{

}

void cGameControlPanel::OnButtonLaunch(wxCommandEvent& evt)
{
	MyObject* balloon;

	// random starting position along the bottom of view panel
	wxSize tempSize = m_view->GetClientSize();
	// random x start location (between 100 and panel width - 100)
	int startX = (rand() % (tempSize.GetX() - 100)) + 100;
	// hardcoded y start location (100 pixels from bottom)
	int startY = tempSize.GetY() - 150;

	// create the balloon now that we have all starting parameters
	switch ((int)(rand() % 4)) // random one of 4 colors
	{
	case 1: // blue
		balloon = new BlueBalloon(startX, startY, m_view, m_scoreValue);
		break;
	case 2: // red
		balloon = new RedBalloon(startX, startY, m_view, m_scoreValue);
		break;
	case 3: // green
		balloon = new GreenBalloon(startX, startY, m_view, m_scoreValue);
		break;
	default: // yellow
		balloon = new YellowBalloon(startX, startY, m_view, m_scoreValue);
		break;
	}

	// add to list if not nullptr
	if (m_objList != nullptr)
		m_objList->AddToList(balloon);
}

void cGameControlPanel::OnButtonFire(wxCommandEvent& evt)
{
	// points to the newly created balloon object
	MyObject* dart;

	// don't really need this if we are always starting along the left border of the panel, but you might want to do some extra credit
	wxSize tempSize = m_view->GetClientSize();

	// hardcode a spot along the left border to release the dart
	int startX = 5;
	int startY = 50;

	dart = new Dart(startX, startY, m_view, m_scoreValue);

	// add the dart to the object list
	// The MyObjectList pointer shouldn't be nullptr, but check just in case before adding the object
	if (m_objList != nullptr)
		m_objList->AddToList(dart);
}
