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

	// The idea here is that there are well-defined steps for moving everything!
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
	bool isHit = false;
	for (int i = 0; i < list.size()-1; i++) {
		for (int j = i+1; j < list.size(); j++) {
			//if (list.at(i) != list.at(j) && !list.at(i)->IsPopped() && !list.at(j)->IsPopped() &&	list.at(i)->CollidedWith(list.at(j))) {
			if (!list.at(i)->IsPopped() && !list.at(j)->IsPopped() && list.at(i)->CollidedWith(list.at(j))) {

				// different scenarios to look for - 1 Dart 2 balloons 
				// Dart vs Dart
				// Dart vs balloon
				// balloon vs Dart

				MyObject* tmp;
				if (list.at(i)->typeOfObject() == 0) {
					tmp = list.at(j);
				} else {
					tmp = list.at(i);
				}

				//if (tmp->typeOfObject() == 0) { // if dart hits dart
				//	wxMessageDialog* f = new wxMessageDialog(nullptr,
				//		wxT("Ok"), wxT("Dart hit a dart"), wxOK);
				//	//f->ShowModal();
				//	//MyObject* tmpBalloon = new PoppedBalloon(tmp->getLoc());
				//}
				if (tmp->typeOfObject() == 2) {
					wxMessageDialog* f = new wxMessageDialog(nullptr,
						wxT("Ok"), wxT("Dart hit balloon"), wxOK);
					//f->ShowModal();
				}
				
				else if (tmp->typeOfObject() == 0) {
					wxMessageDialog* f = new wxMessageDialog(nullptr,
						wxT("Ok"), wxT("Balloon hit dart"), wxOK);
					//f->ShowModal();
				}
				list.at(i)->setScores(list.at(j));
				isHit = true;
			}
		}
	}

	if (isHit) {
		std::vector<MyObject*> tempVect;
		for (int i = 0; i < list.size(); i++) {
			if (list.at(i)->typeOfObject() != 0) {
				tempVect.push_back(list.at(i));
			}
		}
		list = tempVect;
	}
	

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
