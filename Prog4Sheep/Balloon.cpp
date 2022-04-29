#include "Balloon.h"
using namespace std;

Balloon::Balloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	// load the image transparent so we won't get weird effects on overlap

	int numColors = 4;
	int selColor = (int)(rand() % numColors);
	char balloonColor; // keep track of color for different point values

	switch (selColor)
	{
	case 1: // blue
		image.LoadFile("./sheep_balloon_blue.bmp", wxBITMAP_TYPE_BMP);
		break;
	case 2: // red
		image.LoadFile("./sheep_balloon_red.bmp", wxBITMAP_TYPE_BMP);
		break;
	case 3: // green
		image.LoadFile("./sheep_balloon_green.bmp", wxBITMAP_TYPE_BMP);
		balloonColor = 'g';
		break;
	default: // yellow
		image.LoadFile("./sheep_balloon_yellow.bmp", wxBITMAP_TYPE_BMP);
		balloonColor = 'y';
		break;
	}

	// Gets the color value at 1, 1 which is magenta for each image & ignores it to mimic transparency
	image.SetMaskColour(image.GetRed(1,1), image.GetGreen(1,1), image.GetBlue(1,1));
	startPt = startX;
	goingRight = true;
}


// You write this is the derived classes.
// Move function for VBot - Must handle walls properly.
// Must use x and y.  Must use properties of image and drawPanel.
void Balloon::Move() {
	// get the size of the draw panel
	wxSize tempSize = drawPanel->GetClientSize();

	// Now, decide how to move yellow balloons with each tick of the clock

	xy_Current.second -= y_SPEED;


	// for making the sheep drift side to side:
	if (xy_Current.first <= startPt + MAX_WALK && goingRight) {
		xy_Current.first+=x_SPEED; // if the sheep is supposed to be going right, keep going right
	}
	if (xy_Current.first >= startPt + MAX_WALK)
		goingRight = false; // if max drift is reached, sheep is no longer going right
	if (!goingRight) { // if sheep is not going right, it is going left
		xy_Current.first-=x_SPEED; // so make it go left
		if (xy_Current.first <= startPt)
			goingRight = true; // if it reaches original starting point, go right again
	}

	// if the sheep goes out of view, have it come up from the bottom of the screen
	if (xy_Current.second < 0 - image.GetHeight()) {
		xy_Current.second = tempSize.y;
	}

}

// This method returns the score for popping a yellow balloon
int Balloon::popScore() {
	return 10;
}

// This returns the "type" of object this is (int value you define)
int Balloon::typeOfObject() {
	return type;
}