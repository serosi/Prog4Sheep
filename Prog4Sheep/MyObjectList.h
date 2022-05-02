#pragma once
#include <wx/wx.h>		
#include <vector>		
#include "MyObject.h"
//EXTRA CREDIT:
#include "PoppedRed.h" // for extra credit: summon a sprite of the popped balloon
#include "PoppedYellow.h"
#include "PoppedGreen.h"
#include "PoppedBlue.h"
#include "Sheep.h" // also for extra credit: summon a sprite of the sheep

class MyObjectList {
public:
	// constructor and destructor
	MyObjectList();
	~MyObjectList();

	// This method is called by the control Panel and adds an 
	// object pointer to the list (object created by control panel)
	void AddToList(MyObject* currentBot);

	// loops through the list and moves each balloon according to the 
	// move algorithm implemented individually in each object
	void MoveAll();

	// Loops through the list and shows every bot 
	void ShowAll(wxPaintDC& dc);

	// Checks if the balloons have collided with eachother and pop balloons / Darts
	void CheckCollides();

	// how many active objects are current in the game?
	int getSize() { return list.size(); }

	int getNumType(int key) {
		int type = 0;
		for (int i = 0; i < list.size(); i++)
			if (list[i]->typeOfObject() == key) type++;
		return type;
	}

private:
	std::vector<MyObject*> list;

	// This method deletes popped objects from the list
	void DeleteBalloon();
};