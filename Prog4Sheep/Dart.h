#pragma once
#include "MyObject.h"
#include <cstdlib>



class Dart : public MyObject {

public:
	Dart(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);

	// This Method moves moves the Dart
	virtual void Move();

	// This method returns the score for the Dart
	virtual int popScore();

	// This method returns the type of special type of balloon which is actually Dart
	virtual int typeOfObject();

	bool clicked = false;

private:
	// we can set a type value for each derived object
	// ideally, you would create an enumeration for all types
	int type = 0;

	// Darts move right at a constant rate
	int x_SPEED = 6;
	int y_SPEED = 2;

};