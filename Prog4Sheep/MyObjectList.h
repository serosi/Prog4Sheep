#pragma once
#include <wx/wx.h>		// wxWdigets Framework
#include <vector>		// std::vector to hold MyObject *s
#include "MyObject.h"	// Abstract Base Class for objects in our game

// MyObjectList is a container for our drawable game objects
// it stores them all in a std::vector (do some research) and
// provides functionality for the list as a whole. For example,
// we can MoveAll() objects in the list at the same time on 
// every tick of our animation timer, and we can ShowAll() to
// invoke the Show() function on all MyObjects in the list - 
// this is useful for the OnPaint() event in the cGameViewPanel
//
// Notice that MyObjectList doesn't need to know about derived
// objects such as Bomb, RedBalloon, etc. - it doesn't care, it
// knows what functionality a MyObject has, and that's all it
// needs to perform it's job!

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

	// Checks if the balloons have collided with eachother and pop balloons / bombs
	void CheckCollides();

	// how many active objects are current in the game?
	int getSize() { return list.size(); }

	// count up the number of objects of a certain type
	// My simple example doesn't use this, but maybe it will
	// come in handle for extra credit functionality?
	int getNumType(int key)
	{
		int type = 0;
		for (int i = 0; i < list.size(); i++)
			if (list[i]->typeOfObject() == key) type++;
		return type;
	}

private:
	// for this project, I am allowing you to use a std::vector object
	// do a search for "C++ vector example" to learn how to manage 
	// a vector - it's worth the effort, they are much easier to work
	// with than coding a linked list for a dynamically-sized container
	std::vector<MyObject*> list;

	// This method deletes popped objects from the list
	void DeleteBalloon();
};