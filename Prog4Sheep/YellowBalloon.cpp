#include "YellowBalloon.h"

YellowBalloon::YellowBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
   : MyObject(startX, startY, drawingPanel, scoreValue) {
   image.LoadFile("./sheep_balloon_yellow.bmp", wxBITMAP_TYPE_BMP);
   image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
	startPt = startX; // extra credit: make the balloon move side to side by defining a starting point
	goingRight = true; // and setting the direction
}

YellowBalloon::~YellowBalloon() {

}

// This method moves the balloons
void YellowBalloon::Move() {
	// get the size of the draw panel
	wxSize tempSize = drawPanel->GetClientSize();

	xy_Current.second -= y_SPEED;


	// for making the sheep drift side to side:
	if (xy_Current.first <= startPt + MAX_WALK && goingRight) {
		xy_Current.first += x_SPEED; // if the sheep is supposed to be going right, keep going right
	}
	if (xy_Current.first >= startPt + MAX_WALK)
		goingRight = false; // if max drift is reached, sheep is no longer going right
	if (!goingRight) { // if sheep is not going right, it is going left
		xy_Current.first -= x_SPEED; // so make it go left
		if (xy_Current.first <= startPt)
			goingRight = true; // if it reaches original starting point, go right again
	}

	// if the sheep goes out of view, have it come up from the bottom of the screen
	if (xy_Current.second < 0 - image.GetHeight()) {
		xy_Current.second = tempSize.y;
	}
}

//This method returns the score for the balloon
int YellowBalloon::popScore() {
   return 10;
}

//This method returns the type of the object
int YellowBalloon::typeOfObject() {
   return type;
}