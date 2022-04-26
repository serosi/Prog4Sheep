#pragma once
#include "MyObject.h"
#include <cstdlib>



class Bomb : public MyObject {

public:
	Bomb(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);

	// This Method moves moves the bomb
	virtual void Move();

	// This method returns the score for the bomb
	virtual int popScore();

	// This method returns the type of special type of balloon which is actually bomb
	virtual int typeOfObject();

private:
	// we can set a type value for each derived object
	// ideally, you would create an enumeration for all types
	int type = 0;

	// Bombs move right at a constant rate
	int x_SPEED = 6;

};