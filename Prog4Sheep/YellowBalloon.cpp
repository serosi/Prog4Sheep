#include "YellowBalloon.h"
using namespace std;

YellowBalloon::YellowBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	// load the image transparent so we won't get weird effects on overlap
	image.LoadFile("./yellowBalloon.bmp", wxBITMAP_TYPE_BMP);

	/// Now, you need to make the images transparent so we don't
	// see the full rectangle of the image. Notice that each image 
	// has white pixels filling the area outside of the actual object 
	// we want to show - You can use that to your advantage
	// Do some searching on wxWidgets and image transparency	
}

// You write this is the derived classes.
// Move function for VBot - Must handle walls properly.
// Must use x and y.  Must use properties of image and drawPanel.
void YellowBalloon::Move() {
	// get the size of the draw panel
	wxSize tempSize = drawPanel->GetClientSize();

	// Now, decide how to move yellow balloons with each tick of the clock
}

// This method returns the score for popping a yellow balloon
int YellowBalloon::popScore() {
	return 10;
}

// This returns the "type" of object this is (int value you define)
int YellowBalloon::typeOfObject() {
	return type;
}