#pragma once
#include <wx/wx.h>
#include "MyObject.h"
#include <cstdlib>
#include <ctime>  // this is for randomizing the color of the balloon with
						// rand using time as the seed

class YellowBalloon : public MyObject {

public:
	YellowBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);

	// This Method moves the yellow balloons
	virtual void Move();

	//This method returns the score for the yellow balloon
	virtual int popScore();

	//This method returns the type of the object
	virtual int typeOfObject();

private:
	// we can set a type value for each derived object
	// ideally, you would create an enumeration for all types
	int type = 2;
	int startPt;
	bool goingRight;

	// the remaining attributes relate to speed and random drift
	int MAX_WALK = 15;
	int x_SPEED = -2;
	int y_SPEED = 3;
};