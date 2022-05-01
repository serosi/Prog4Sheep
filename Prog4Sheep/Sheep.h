#pragma once
#include "MyObject.h"
class Sheep :
    public MyObject
{
public:
   Sheep(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);
   ~Sheep();
	
	// This method moves the sheep
	virtual void Move();

	//This method returns the score for the sheep
	virtual int popScore();

	//This method returns the type of the object
	virtual int typeOfObject();
private:
	int y_SPEED = -5;
	int type = 4;
};

