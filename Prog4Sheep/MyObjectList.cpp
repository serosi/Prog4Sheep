#include "MyObjectList.h"

// constructor
MyObjectList::MyObjectList() {}

// destructor
MyObjectList::~MyObjectList()
{
	// delete objects in vector
	for (auto i = 0; i < list.size(); i++) {
		if (list[i] != nullptr)
			delete (list[i]);
	}
		
	list.clear();
}

// move all objects in the list and check for collisions and delete popped objects
void MyObjectList::MoveAll() {
	for (auto it = list.begin(); it != list.end(); it++)
		(*it)->Move();
	// now check for collisions and delete popped objects
	CheckCollides();
	DeleteBalloon();
}

// check for collisions among objects in the list
void MyObjectList::CheckCollides() {
	// if the list is empty, there is nothing to do
	if (list.empty()) return;

	// check for collisions between objects
	for (int i = 0; i < list.size(); i++) {
		if (!list.at(i)->IsPopped()) {
			for (int j = i + 1; j < list.size(); j++) {
				if (j != list.size() && !list.at(j)->IsPopped() && list.at(i)->CollidedWith(list.at(j))) {
					list[i]->setScores(list[j]);

					// if dart hits sheep and pops its balloon, spawn a separate popped balloon and sheep object
					// this is here and not in setScores because it needs to create new objects

					if (list[i]->typeOfObject() >= 2 && list[i]->typeOfObject() <= 5 && list[j]->typeOfObject() == 0) { // create a new PoppedBalloon object
						std::pair<int, int> tempCoords = list[i]->getLoc();
						MyObject* poppedBalloon;
						switch (list[i]->typeOfObject()) {
						case 2: // red
							poppedBalloon = new PoppedRed(tempCoords.first, tempCoords.second, list[i]->getPanel(), list[i]->getScore());
							break;
						case 3: // yellow
							poppedBalloon = new PoppedYellow(tempCoords.first, tempCoords.second, list[i]->getPanel(), list[i]->getScore());
							break;
						case 4: // green
							poppedBalloon = new PoppedGreen(tempCoords.first, tempCoords.second, list[i]->getPanel(), list[i]->getScore());
							break;
						default: // blue
							poppedBalloon = new PoppedBlue(tempCoords.first, tempCoords.second, list[i]->getPanel(), list[i]->getScore());
							break;
						}

						// create a new falling sheep object 168 pixels under the popped balloon (popped balloon sprite is 168 pixels tall)
						MyObject* fallingSheep = new Sheep(tempCoords.first, tempCoords.second + 168, list[i]->getPanel(), list[i]->getScore());
						list.push_back(fallingSheep);
						DeleteBalloon(); // deletes current balloon and replaces it with popped to avoid changing vector size
						list[i] = poppedBalloon; // replaces previous object in list with popped balloon
					}

					else if (list[j]->typeOfObject() >= 2 && list[j]->typeOfObject() <= 5 && list[i]->typeOfObject() == 0) { // create a new PoppedBalloon object
						std::pair<int, int> tempCoords = list[j]->getLoc();
						MyObject* poppedBalloon;
						switch (list[j]->typeOfObject()) {
						case 2: // red
							poppedBalloon = new PoppedRed(tempCoords.first, tempCoords.second, list[j]->getPanel(), list[j]->getScore());
							break;
						case 3: // yellow
							poppedBalloon = new PoppedYellow(tempCoords.first, tempCoords.second, list[j]->getPanel(), list[j]->getScore());
							break;
						case 4: // green
							poppedBalloon = new PoppedGreen(tempCoords.first, tempCoords.second, list[j]->getPanel(), list[j]->getScore());
							break;
						default: // blue
							poppedBalloon = new PoppedBlue(tempCoords.first, tempCoords.second, list[j]->getPanel(), list[j]->getScore());
							break;
						}

						// create a new falling sheep object 168 pixels under the popped balloon
						MyObject* fallingSheep = new Sheep(tempCoords.first, tempCoords.second + 168, list[j]->getPanel(), list[j]->getScore());
						list.push_back(fallingSheep);
						DeleteBalloon(); // deletes current balloon and replaces it with popped to avoid changing vector size
						list[j] = poppedBalloon; // replaces previous object in list with popped balloon
					}
				}
			}
		}
	}
	return;
}

// remove any popped balloons from the list
void MyObjectList::DeleteBalloon() {
	int size = list.size();
	for (int it = size - 1; it >= 0; it--) {
		if (list[it]->IsPopped()) {
			delete list[it];
			list.erase(list.begin() + it);
		}
	}
	return;
}

// show all objects in the list individually
void MyObjectList::ShowAll(wxPaintDC& dc) {
	// loop through list & invoke Show() on all objects
	for (auto it = list.begin(); it < list.end(); it++) {
		(*it)->Show(dc);
	}
}

// adds an object to the list
void MyObjectList::AddToList(MyObject* inObject) {
	list.push_back(inObject);
}
