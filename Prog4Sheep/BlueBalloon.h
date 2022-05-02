#pragma once
#include "MyObject.h"
class BlueBalloon :
	public MyObject
{
public:
	BlueBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);
	~BlueBalloon();

	// This Method moves the yellow balloons
	virtual void Move();

	//This method returns the score for the yellow balloon
	virtual int popScore();

	//This method returns the type of the object
	virtual int typeOfObject();

private:
	// we can set a type value for each derived object
	// ideally, you would create an enumeration for all types
	int type = 5;
	int startPt;
	bool goingRight;

	// the remaining attributes relate to speed and random drift
	int MAX_WALK = 10;
	int x_SPEED = 1;
	int y_SPEED = 3;
};

