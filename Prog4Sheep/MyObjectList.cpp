#include "MyObjectList.h"

// constructor
//MyObjectList::MyObjectList(wxPanel *drawingPanel, wxStaticText* scoreValue)
MyObjectList::MyObjectList()
{
	// nothing to initialize, unless you have some extra credit that 
	// needs to do additional things
}

// destructor
MyObjectList::~MyObjectList()
{
	// We need to delete any MyObject objects in the vector!
}

// move all objects in the list and check for collisions and delete
// popped objects
void MyObjectList::MoveAll()
{
	// I'll give you this function to save you a little time :)

	// The idea here is that there are well-defined steps for moving
	// everything!
	// 1. Loop through vector and call the Move() function for all objects
	// 2. Check for collisions now that objects have moved
	// 3. Delete any popped objects

	// move each object individually
	for (auto it = list.begin(); it != list.end(); it++)
	{
		(*it)->Move();
	}
	// now check for collisions and delete popped objects
	CheckCollides();
	DeleteBalloon();
}

// check for collisions among objects in the list
void MyObjectList::CheckCollides()
{
	// if the list is empty, there is nothing to do
	if (list.empty()) return;

	// OK, now how to we check for collisions between objects?

	return;
}

// remove any popped balloons from the list
void MyObjectList::DeleteBalloon()
{
	// OK, I'll give you this one as well :)
	int size = list.size();
	for (int it = size - 1; it >= 0; it--)
	{
		if (list[it]->IsPopped())
		{
			delete list[it];
			list.erase(list.begin() + it);
		}
	}

	return;
}

// show all objects in the list individually
void MyObjectList::ShowAll(wxPaintDC& dc)
{
	// Simply loop through our list and invoke Show() on all objects
	for (auto it = list.begin(); it < list.end(); it++) {
		(*it)->Show(dc);
	}
}

// add an object to the list
void MyObjectList::AddToList(MyObject* inObject)
{
	// another simple function, just add the input object to the list
	list.push_back(inObject);
}
