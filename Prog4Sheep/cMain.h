#pragma once
#include <wx/wx.h>
#include "cGameViewPanel.h"
#include "cGameControlPanel.h"
#include "MyObjectList.h"

// forward declarations:
// *********************
// Forward declarations allow us to eliminate circular
// definitions. They are a good indication that the objects
// in our system might be a bit more coupled together than
// they need to be.
// The reason for this forward declaration is because the
// cGameControlPanel needs to know about the cGameViewPanel.
// Thus, it's implementation can't be complete until cGameViewPanel
// is complete, and cGameViewPanel can't be complete until 
// cGameControlPanel is complete, and ... on and on - a circular
// definition.
// However, we are using pointers, which have a known size, so,
// technically, the implementations CAN be complete, we just have
// to let the compiler know to RELAX, there will be a complete
// definition for the linker and at run time, just allocate space
// for your pointers and do your job!
// Again, ideally, we want to completely de-couple the view objects
// from control / model objects in our design. But, this gets tricky
// and, if we want some special functionality, then maybe just go 
// ahead and couple things together a little bit :)
// In OOAD, you will learn about ways to truly decouple objects in 
// your design (we will lightly discuss this in SE2730)
// *****************************************************************
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

	// cMain owns the MyObjectList, it's a nice central
	// location where we can pass the pointer to our panels.
	// Different designs are possible here, but this isn't too
	// bad :) Still, we would like to de-couple the views from
	// are model / control objects. You'll learn in OOAD :)
	MyObjectList* m_objList = nullptr;

public:
	virtual bool OnInit();
};

