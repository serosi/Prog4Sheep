#pragma once
#include "MyObject.h"
class RedBalloon :
    public MyObject
{
public:
	RedBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);
	~RedBalloon();

	// This method moves the red balloons
	virtual void Move();

	//This method returns the score for the red balloon
	virtual int popScore();

	//This method returns the type of the object
	virtual int typeOfObject();

private:
	// we can set a type value for each derived object
	int type = 2;
	int startPt;
	bool goingRight;

	// the remaining attributes relate to speed and random drift
	int MAX_WALK = 15;
	int x_SPEED = 1;
	int y_SPEED = 3;
};

