#include "PoppedBlue.h"

PoppedBlue::PoppedBlue(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	image.LoadFile("./popped_blue.bmp", wxBITMAP_TYPE_BMP);
	image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
}

PoppedBlue::~PoppedBlue() {
}

void PoppedBlue::Move() {
	wxSize tempSize = drawPanel->GetClientSize();
	xy_Current.second -= y_SPEED;

	if (xy_Current.second > tempSize.y) {
		scores = 0;
	}
}
int PoppedBlue::popScore() {
	return 0;
}

//This method returns the type of the object
int PoppedBlue::typeOfObject() {
	return type;
}