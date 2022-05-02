#pragma once
#include "MyObject.h"
class GreenBalloon :
	public MyObject
{
public:
	GreenBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);
	~GreenBalloon();

	// This Method moves the yellow balloons
	virtual void Move();

	//This method returns the score for the yellow balloon
	virtual int popScore();

	//This method returns the type of the object
	virtual int typeOfObject();

private:
	// we can set a type value for each derived object
	int type = 4;
	int startPt; // extra credit: for moving the balloon side to side
	bool goingRight;

	// the remaining attributes relate to speed and random drift
	int MAX_WALK = 15;
	int x_SPEED = 1;
	int y_SPEED = 3;
};

