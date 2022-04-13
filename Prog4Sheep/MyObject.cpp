// 
// MyObject is an abstract base class for balloons and bombs.
// 
#include "MyObject.h"

void MyObject::Show(wxPaintDC& dc)
{
	// as long as the image has been created, draw it!
	if (image.IsOk())
	{
		// draw the image to the graphics object
		dc.DrawBitmap(image, xy_Current.first, xy_Current.second, true);
	}
	else
	{
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

// This function sets the Scores for the balloons and bombs
void MyObject::setScores(MyObject* b)
{
	// need to update the score:
	// grab the current score from the textbox on your control panel
	// convenient enough place to store the overall score :)
	long value;
	currentScore->GetLabel().ToLong(&value);

	// Now, you need to decide how to update value based on the 
	// different types of collisions:
	// - Is this a bomb and did it miss all balloons (input b is nullptr)?
	// - balloon vs. bomb?
	// - bomb vs. balloon?
	// - balloon vs. balloon?
	// - bomb vs. bomb?
	// You need to figure out how to test for these scenarios and what to
	// do.

	// I'll give you a hint though, in every branch, you want to follow
	// this logic:
	// 1. add popScore() to value 
	// 2. set scores = 0 for each object, that's what tells the program
	//    that the object is popped (or exploded in the case of bombs)!


	// once we're done, update the overall score
	// set the textbox with the new score
	wxString strLong = wxString::Format(wxT("%ld"), value);
	currentScore->SetLabel(strLong);
}