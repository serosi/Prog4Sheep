#include "Dart.h"
using namespace std;


Dart::Dart(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue)
	: MyObject(startX, startY, drawingPanel, scoreValue)
{
	// load the image transparent so we won't get weird effects on overlap
	image.LoadFile("./dart_right.bmp", wxBITMAP_TYPE_BMP);
	image.SetMaskColour(image.GetRed(1, 1), image.GetGreen(1, 1), image.GetBlue(1, 1));
}

void Dart::Move() {
	// get the size of the draw panel
	wxSize tempSize = drawPanel->GetClientSize();

		xy_Current.first += x_SPEED;
		xy_Current.second += y_SPEED;

		if (xy_Current.first > tempSize.x || xy_Current.second > tempSize.y) {
			this->scores = 0;
		}
}

int Dart::popScore() {
	return -5;
}

int Dart::typeOfObject() {
	return type;
}
