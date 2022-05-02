#include "PoppedGreen.h"

PoppedGreen::PoppedGreen(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	image.LoadFile("./popped_green.bmp", wxBITMAP_TYPE_BMP);
	image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
}

PoppedGreen::~PoppedGreen() {

}

void PoppedGreen::Move() {
	wxSize tempSize = drawPanel->GetClientSize();
	xy_Current.second -= y_SPEED;

	if (xy_Current.second > tempSize.y) {
		scores = 0;
	}
}
int PoppedGreen::popScore() {
	return 0;
}

//This method returns the type of the object
int PoppedGreen::typeOfObject() {
	return type;
}