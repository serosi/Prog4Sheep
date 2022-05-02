// MyObject is an abstract base class for balloons, sheep, and darts.
#include "MyObject.h"

void MyObject::Show(wxPaintDC& dc) {
	// as long as the image has been created, draw it!
	if (image.IsOk())
		dc.DrawBitmap(image, xy_Current.first, xy_Current.second, true);
	else
		wxMessageBox("MyObject image invalid. Program will now crash! :(");
}

// check coordinates and return whether an object was collided with
bool MyObject::CollidedWith(MyObject* b) const {
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

// This function sets the scores for the balloons and darts
void MyObject::setScores(MyObject* b)
{
	// update the score
	long value;
	currentScore->GetLabel().ToLong(&value);

	// EXTRA CREDIT: make the popped balloon object disappear after 30 ticks
	counter++;

	// if this object is dart and passed in object is balloon
	if ((this->typeOfObject() == 0 && b->typeOfObject() >= 2 && b->typeOfObject() <= 5)) {
		value += b->popScore();
		b->scores = 0;
	}

	// if passed in object is dart and this is balloon
	if (this->typeOfObject() >= 2 && this->typeOfObject() <= 5 && b->typeOfObject() == 0) {
		value += this->popScore();
		b->scores = 0;
	}
	// if both objects are darts
	if (this->typeOfObject() == 0 && b->typeOfObject() == 0) {
		value += this->popScore();
		b->scores = 0;
		this->scores = 0;
	}

	// if the counter reaches 30, despawn the popped balloon object
	if (counter >= 30 && (this->typeOfObject() == 6 || b->typeOfObject() == 6)) {
		this->scores = 0;
	}

	// update the score
	wxString strLong = wxString::Format(wxT("%ld"), value);
	currentScore->SetLabel(strLong);
}