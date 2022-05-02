#pragma once
#include <wx/wx.h>
#include "cGameViewPanel.h"
#include "cGameControlPanel.h"
#include "MyObjectList.h"

class cGameControlPanel;

// the top-level frame for our application
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

private:
	cGameViewPanel* m_GameViewPanel = nullptr;
	cGameControlPanel* m_GameControlPanel = nullptr;

	MyObjectList* m_objList = nullptr;

public:
	virtual bool OnInit();
};

