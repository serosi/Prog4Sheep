#pragma once
#include "MyObject.h"
#include <cstdlib>



class Dart : public MyObject {

public:
	Dart(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);

	// This method moves moves the dart
	virtual void Move();

	// This method returns the score for the dart
	virtual int popScore();

	// This method returns the type of special type of balloon which is actually dart
	virtual int typeOfObject();

private:
	int type = 0;

	// Darts move right at a constant rate
	int x_SPEED = 6;
	int y_SPEED = 2;

};