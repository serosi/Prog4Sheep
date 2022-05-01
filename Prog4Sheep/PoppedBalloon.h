#pragma once
#include "MyObject.h"
class PoppedBalloon : public MyObject
{
public:
   PoppedBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);
   ~PoppedBalloon();
	// This Method moves the popped sheep
	virtual void Move();

	//This method returns the score for the popped sheep
	virtual int popScore();

	//This method returns the type of the object
	virtual int typeOfObject();

private:
   int y_SPEED = -5;
	int type = 3;
	int counter = 0;
};

