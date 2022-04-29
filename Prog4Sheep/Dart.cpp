#include "Dart.h"
using namespace std;


Dart::Dart(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	// load the image transparent so we won't get weird effects on overlap
	image.LoadFile("./dart_right.bmp", wxBITMAP_TYPE_BMP);
	image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
	//image = image.Rotate(((-50) / 180), wxPoint(image.GetWidth() / 2, image.GetHeight() / 2));

	// Now, you need to make the images transparent so we don't
	// see the full rectangle of the image. Notice that each image 
	// has white pixels filling the area outside of the actual object 
	// we want to show - You can use that to your advantage
	// Do some searching on wxWidgets and image transparency	
}

// You write this is the derived classes.
// Move function for VBot - Must handle walls properly.
// Must use x and y.  Must use properties of image and panel.
void Dart::Move() {
	// get the size of the draw panel
	wxSize tempSize = drawPanel->GetClientSize();
	clicked = false;

	//if (clicked) {
		xy_Current.first += x_SPEED;
		xy_Current.second += y_SPEED;

		if (xy_Current.first > tempSize.x || xy_Current.second > tempSize.y) {
			// delete
		}
	//}


	// Now, decide how to move the Dart with every tick of the clock
}

int Dart::popScore() {
	return -5;
}

int Dart::typeOfObject() {
	return type;
}
