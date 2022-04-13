#include "Bomb.h"
using namespace std;

Bomb::Bomb(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	// load the image transparent so we won't get weird effects on overlap
	image.LoadFile("./bomb.bmp", wxBITMAP_TYPE_BMP);

	// Now, you need to make the images transparent so we don't
	// see the full rectangle of the image. Notice that each image 
	// has white pixels filling the area outside of the actual object 
	// we want to show - You can use that to your advantage
	// Do some searching on wxWidgets and image transparency	
}

// You write this is the derived classes.
// Move function for VBot - Must handle walls properly.
// Must use x and y.  Must use properties of image and panel.
void Bomb::Move() {
	// get the size of the draw panel
	wxSize tempSize = drawPanel->GetClientSize();

	// Now, decide how to move the bomb with every tick of the clock
}

int Bomb::popScore() {
	return -5;
}

int Bomb::typeOfObject() {
	return type;
}