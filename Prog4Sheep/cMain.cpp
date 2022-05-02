#include "cMain.h"

cMain::cMain()
	: wxFrame(nullptr, wxID_ANY, "Program 4: Sheep Balloon Game")
{
	// First, we need to create the MyObjectList!
	m_objList = new MyObjectList();

	m_GameViewPanel = new cGameViewPanel(this, m_objList);

	// Create the game control panel (will hold fire button and score)
	m_GameControlPanel = new cGameControlPanel(this, m_GameViewPanel, m_objList);

	// getting the client size of the frame
	wxSize tempSize = this->GetClientSize();
	m_GameControlPanel->SetSize(wxSize(tempSize.GetWidth(), 100));

	wxBoxSizer* sizerMainFrame = new wxBoxSizer(wxVERTICAL);
	sizerMainFrame->Add(m_GameControlPanel, 0, wxEXPAND | wxALL, 5);

	sizerMainFrame->Add(m_GameViewPanel, 1, wxEXPAND | wxLEFT | wxBOTTOM | wxRIGHT, 5);
	this->SetSizerAndFit(sizerMainFrame);

	this->SetClientSize(wxSize(1376, 816));
}

cMain::~cMain()
{
	if (m_objList != nullptr) delete m_objList;
}

bool cMain::OnInit()
{
	return true;
}