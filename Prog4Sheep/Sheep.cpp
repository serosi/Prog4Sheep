#include "Sheep.h"

Sheep::Sheep(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue) {
	image.LoadFile("./sheep_falling.bmp", wxBITMAP_TYPE_BMP);
	image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
}

Sheep::~Sheep() {

}

// This method moves the sheep
void Sheep::Move() {
	wxSize tempSize = drawPanel->GetClientSize();

	xy_Current.second -= y_SPEED;
	if (xy_Current.second < 0 - 0 /* image.GetHeight() */) {
		scores = 0;
	}
}

//This method returns the score for the sheep
int Sheep::popScore() {
	return 0;
}

//This method returns the type of the object
int Sheep::typeOfObject() {
	return type;
}