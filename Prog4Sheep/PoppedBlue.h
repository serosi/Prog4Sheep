#pragma once
#include "MyObject.h"
class PoppedBlue : public MyObject
{
public:
	PoppedBlue(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);
	~PoppedBlue();
	// This Method moves the popped sheep
	virtual void Move();

	//This method returns the score for the popped sheep
	virtual int popScore();

	//This method returns the type of the object
	virtual int typeOfObject();

	bool IsPopped() const { return scores <= 0; }

private:
	int y_SPEED = -5;
	int type = 6;
	int counter = 0;
};

