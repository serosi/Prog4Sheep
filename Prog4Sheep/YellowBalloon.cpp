#include "YellowBalloon.h"
using namespace std;

YellowBalloon::YellowBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
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
		balloonColor = 'b';
		break;
	case 2: // red
		image.LoadFile("./sheep_balloon_red.bmp", wxBITMAP_TYPE_BMP);
		balloonColor = 'r';
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
}

// You write this is the derived classes.
// Move function for VBot - Must handle walls properly.
// Must use x and y.  Must use properties of image and drawPanel.
void YellowBalloon::Move() {
	// get the size of the draw panel
	wxSize tempSize = drawPanel->GetClientSize();



	// Now, decide how to move yellow balloons with each tick of the clock

	int xCoord = xy_Current.first;
	int yCoord = xy_Current.second;


}

// This method returns the score for popping a yellow balloon
int YellowBalloon::popScore() {
	return 10;
}

// This returns the "type" of object this is (int value you define)
int YellowBalloon::typeOfObject() {
	return type;
}