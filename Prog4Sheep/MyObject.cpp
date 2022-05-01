// 
// MyObject is an abstract base class for balloons and Darts.
// 
#include "MyObject.h"

void MyObject::Show(wxPaintDC& dc)
{
	// as long as the image has been created, draw it!
	if (image.IsOk()) {
		// draw the image to the graphics object
		dc.DrawBitmap(image, xy_Current.first, xy_Current.second, true);
	}
	else {
		wxMessageBox("MyObject Image Invalid, program will now crash! :(");
	}
}

// Don't rewrite or override this one, unless it's for 
// extra credit! You shouldn't be overriding to make
// your life easier, but to implement something even more
// complicated :)
bool MyObject::CollidedWith(MyObject* b) const
{
	// make sure the passed in object is valid
	if (b == nullptr)
		return false;

	// collision boundaries for both objects
	int x_left = xy_Current.first;
	int x_right = xy_Current.first + (image.GetWidth());
	int y_top = xy_Current.second;
	int y_bottom = xy_Current.second + (image.GetHeight());

	std::pair<int, int> bLoc = b->getLoc();
	int bx_left = bLoc.first;
	int bx_right = bx_left + (b->image.GetWidth());
	int by_top = bLoc.second;
	int by_bottom = by_top + (b->image.GetHeight());

	// at this point, scene is set for testing collision boundary
	return ((x_right >= bx_left && bx_right >= x_left) && (y_bottom >= by_top && by_bottom >= y_top));
}

// This function sets the Scores for the balloons and Darts
void MyObject::setScores(MyObject* b)
{
	// update the score
	long value;
	currentScore->GetLabel().ToLong(&value);
	wxSize tempSize = drawPanel->GetClientSize();
	std::pair<int, int> tempCoordsOrig = this->getLoc();
	std::pair<int, int> tempCoordsSec = b->getLoc();

	 // to make the popped balloon object disappear after some amount of time
	counter++;

	// I'll give you a hint though, in every branch, you want to follow
	// this logic:
	// 1. add popScore() to value 
	// 2. set scores = 0 for each object, that's what tells the program
	//    that the object is popped (or exploded in the case of Darts)!

	// we only care about setting dart objects and lamb/balloon objects in this function
	// balloon only objects and lamb only objects will take care of themselves (this->scores = 0) in their move function

	// if dart hits balloon or balloon hits dart
	if ((this->typeOfObject() == 0 && b->typeOfObject() == 2)) {
		value += b->popScore();
		b->scores = 0;
		wxMessageDialog* f = new wxMessageDialog(nullptr, wxT("Ok"), wxT("b Dart hit balloon"), wxOK);
		//f->ShowModal();
	}
	if ((this->typeOfObject() == 2 && b->typeOfObject() == 0)) {
		value += this->popScore();
		b->scores = 0;
		wxMessageDialog* f = new wxMessageDialog(nullptr, wxT("Ok"), wxT("this Dart hit balloon"), wxOK);
		//f->ShowModal();
	}
	// if dart hits dart
	if (this->typeOfObject() == 0 && b->typeOfObject() == 0) {
		value += this->popScore();
		b->scores = 0;
		wxMessageDialog* f = new wxMessageDialog(nullptr, wxT("Ok"), wxT("SCORES Dart hit dart"), wxOK);
		//f->ShowModal();
	}

	if (counter >= 30 && (this->typeOfObject() == 3 || b->typeOfObject() == 3)) {
		this->scores = 0;
	}

	if (this->typeOfObject() == 4 && tempCoordsOrig.second -50 > tempSize.y) {
		this->scores = 0;
	}

	if (b->typeOfObject() == 4 && tempCoordsSec.second -50 > tempSize.y) {
		b->scores = 0;
	}

	// once we're done, update the overall score
	// set the textbox with the new score
	wxString strLong = wxString::Format(wxT("%ld"), value);
	currentScore->SetLabel(strLong);
}