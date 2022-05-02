#pragma once
#include <wx/wx.h>	// wxWidgets Graphical Framework
#include <cstddef>	// including for nullptr declaration
#include <utility>  // using some STL objects here (std::pair)

class MyObject
{
public:
	// constructor
	MyObject(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue) {
		xy_Current = std::pair<int, int>(startX, startY);

		drawPanel = drawingPanel; // panel from main form we are drawing on
		scores = 100; // just a positive integer to indicate "balloon" hasn't popped

		// this is for access to the control panel's score text box
		currentScore = scoreValue;
	}

	// destructor
	virtual ~MyObject() { }

	// pure virtual function for different movements of objects
	virtual void Move() = 0;

	// pure virtual function for different scores of objects
	virtual int popScore() = 0;

	// pure virtual function to specify the type of object 
	virtual int typeOfObject() = 0;

	// Returns whether a balloon is popped 
	bool IsPopped() const { return scores <= 0; }

	// Shows objects on the screen.
	virtual void Show(wxPaintDC& dc);

	// Checks if the balloons and darts collided with one another
	// This function evaluates whether image boundaries are overlapping
	bool CollidedWith(MyObject* b) const;

	// Calculates points of object collisions
	void setScores(MyObject* b);

	int getCounter() { return counter; }

	// get the object's current (x, y) location
	std::pair<int, int> getLoc() { return xy_Current; }

	//EXTRA CREDIT: for creation of a popped balloon object in MyObjectList.cpp
	wxPanel* getPanel() { return drawPanel; };

	wxStaticText* getScore() { return currentScore; };

	// inheritable attributes
protected:
	std::pair<int, int> xy_Current;	// Current position as a std::pair

	wxPanel* drawPanel;					// Panel on which to show the object
	wxStaticText* currentScore;		// for access to current overall score from GUI stored in textbox 
	wxImage image;							// Image displayed for the object

	int scores;						// positive integer value indicates not popped or exploded
										// this would probably make more sense as a Bool
	int type;						// Type of Object - might help identify 
										// ballon vs Dart or extra features						
	int counter = 0; // extra credit: sets a counter to remove the popped balloon object after an amount of time
};