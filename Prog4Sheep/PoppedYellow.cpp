#include "PoppedYellow.h"

PoppedYellow::PoppedYellow(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	image.LoadFile("./popped_yellow.bmp", wxBITMAP_TYPE_BMP);
	image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
}

PoppedYellow::~PoppedYellow() {

}

void PoppedYellow::Move() {
	wxSize tempSize = drawPanel->GetClientSize();
	xy_Current.second -= y_SPEED;

	if (xy_Current.second > tempSize.y) {
		scores = 0;
	}
}
int PoppedYellow::popScore() {
	return 0;
}

//This method returns the type of the object
int PoppedYellow::typeOfObject() {
	return type;
}