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
	for (int i = 0; i < list.size(); i++) {
		if (!list.at(i)->IsPopped()) {
			for (int j = i + 1; j < list.size() - 1; j++) {
				if (!list.at(j)->IsPopped() && list.at(i)->CollidedWith(list.at(j))) {

					//for (int i = 0; i < list.size() - 1; i++) {
					//	for (int j = i + 1; j < list.size(); j++) {
					//		if (!list.at(i)->IsPopped() && !list.at(j)->IsPopped() && list.at(i)->CollidedWith(list.at(j))) {

								// What needs to happen here
								// 1. call setscores
								// 2. if dart hits lamb/balloon combo (or vice versa) add a balloong only object and lamb only object to vector

								// if the two objects collide, decide what to do

					list[i]->setScores(list[j]);
					
					// if dart hits sheep and pops its balloon, spawn a separate popped balloon and sheep object
					if ((list[i]->typeOfObject() == 0 && list[j]->typeOfObject() == 2) ||
						(list[i]->typeOfObject() == 2 && list[j]->typeOfObject() == 0))
					{
						wxMessageDialog* f = new wxMessageDialog(nullptr,
							wxT("Ok"), wxT("Object list cpp Dart hit balloon"), wxOK);
						//f->ShowModal();

						// we need to now add a ballon-only object and a lamb only object to the vector (list)
						// create the popped balloon object
						// create the lamb only image 
						// set their x/y locations appropriately
						// inside of the move() function for a popped balloon object, just decrement a counter, when counter hits 0, this->scores = 0;
						// inside of the move() function for a falling lamb object, just increment y value, when y value exceeds clientarea, this->scores = 0;

						if ((list[i]->typeOfObject() == 2)) { // create a new PoppedBalloon object
							std::pair<int, int> tempCoords = list[i]->getLoc();
							MyObject* poppedBalloon = new PoppedBalloon(tempCoords.first, tempCoords.second, list[i]->getPanel(), list[i]->getScore());
							MyObject* fallingSheep = new Sheep(tempCoords.first, tempCoords.second + 168, list[i]->getPanel(), list[i]->getScore());
							list.push_back(fallingSheep);
							DeleteBalloon(); // deletes current balloon and replaces it with popped to avoid changing vector size
							list[i] = poppedBalloon;
						}

						if ((list[j]->typeOfObject() == 2)) { // same as above but if the balloon was at j
							std::pair<int, int> tempCoords = list[j]->getLoc();
							MyObject* poppedBalloon = new PoppedBalloon(tempCoords.first, tempCoords.second, list[j]->getPanel(), list[j]->getScore());
							MyObject* fallingSheep = new Sheep(tempCoords.first, tempCoords.second + 168, list[j]->getPanel(), list[j]->getScore());
							list.push_back(fallingSheep);
							DeleteBalloon();
							list[j] = poppedBalloon;
							//list.push_back(poppedBalloon);
						}

						//MyObject* tmpBalloon = new PoppedBalloon(MyObject::xy_Current.first, MyObject::xy_Current.second);
						// list.pushback(tmpBalloon);
						// create lamb object as well and push back onto vector

					}
				}
			}
		}
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
