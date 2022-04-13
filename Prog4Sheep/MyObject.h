#pragma once
// 
// MyObject is an abstract base class for balloons and bombs.
//  - all objects in our game derive from this class!
//
#include <wx/wx.h>	// wxWidgets Graphical Framework
#include <cstddef>	// including for nullptr declaration
#include <utility>  // using some STL objects here (std::pair)

class MyObject
{
public:
	// **************************************************************
	// An OOP Design note here: this isn't the best way to design
	// connections between our control / model objects and the view
	// objects - the best way to design things is to make it so
	// our control / model objects don't KNOW about the view objects.
	// That way, we have flexibility for maintaining this code in
	// the future; we can swap out a different graphical framework
	// and re-use our control / model objects without need to change
	// their code. This is somewhat advanced and hard to learn, so we 
	// are going with the easier route of coupling the view and 
	// control / model objects. Easy to implement, hard to maintain.
	// Two types of coupling demonstrated in MyObject constructor:
	// 1. Data coupling - we are using as little data as necessary 
	//    (wxStaticText *) to couple one thing 
	// 2. Stamp coupling - using the WHOLE class that contains the 
	//    data (wxPanel*) - this results in some of the forward
	//    declarations you see around the given code. In fact, 
	//    forward declarations are a good sign your code is too 
	//    coupled (there could be a better design!) 
	// **************************************************************
	// constructor
	MyObject(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	{
		// std::pair is a convenient way to store (x,y) data
		xy_Current = std::pair<int, int>(startX, startY);

		drawPanel = drawingPanel;	// panel from main form we are drawing on
		scores = 100;				// just a positive integer to indicate "balloon" hasn't popped

		// this is for access to the control panel's score text box
		currentScore = scoreValue;

		// Note, the image needs to be loaded in the constructor
		// of derived objects - we want a different image for
		// each object type, right?
	}

	// destructor
	virtual ~MyObject() { }

	// pure virtual function for different movements of objects
	// You MUST implement this function separately in each object
	virtual void Move() = 0;

	// pure virtual function for different scores of objects
	// You MUST implement this function separately in each object
	virtual int popScore() = 0;

	// pure virtual function to specify the type of object 
	// This way, you can distinguish the different types of objects
	// without having to know their specific type beforehand
	// - Each MyObject should define their own value
	// - For example, Bomb = 0, RedBalloon = 1, etc.
	virtual int typeOfObject() = 0;

	// Returns whether a balloon is popped 
	bool IsPopped() const { return scores <= 0; }

	// Shows objects on the screen.
	// You do not need to override this function in all the different objects
	virtual void Show(wxPaintDC& dc);

	// Checks if the balloons and bombs collided with one another
	// This function evaluates whether image boundaries are overlapping
	bool CollidedWith(MyObject* b) const;

	// Calculates points of object collisions
	// bomb vs nothing (bomb went past right border without hitting anything)
	// bomb vs bomb = point deduction
	// bomb vs balloon = post increase (according to popScore())
	void setScores(MyObject* b);

	// get the object's current (x, y) location
	std::pair<int, int> getLoc() { return xy_Current; }

	// inheritable attributes
protected:
	std::pair<int, int> xy_Current;	// Current position as a std::pair

	wxPanel* drawPanel;				// Panel on which to show the object
	wxStaticText* currentScore;		// for access to current overall score from GUI stored in textbox 
	wxImage image;					// Image displayed for the object

	int scores;						// positive integer value indicates not popped or exploded
									// this would probably make more sense as a Bool
	int type;						// Type of Object - might help identify 
									// ballon vs bomb or extra features									
};