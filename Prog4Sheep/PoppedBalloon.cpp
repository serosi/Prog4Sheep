#include "PoppedBalloon.h"

PoppedBalloon::PoppedBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	image.LoadFile("./popped_yellow.bmp", wxBITMAP_TYPE_BMP);
	image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
}

PoppedBalloon::~PoppedBalloon() {

}

void PoppedBalloon::Move() {
	wxSize tempSize = drawPanel->GetClientSize();
	xy_Current.second -= y_SPEED;



	if (xy_Current.second < 0 -0 /* image.GetHeight() */ ) {
		this->scores = 0;
	}
}
int PoppedBalloon::popScore() {
	return 0;
}

//This method returns the type of the object
int PoppedBalloon::typeOfObject() {
	return type;
}
