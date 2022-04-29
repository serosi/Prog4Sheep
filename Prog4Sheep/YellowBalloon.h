#pragma once
#include "Balloon.h"
class YellowBalloon :
    public Balloon
{
public:
   YellowBalloon(int startX, int startY, wxPanel* drawingPanel, wxStaticText* scoreValue);
   ~YellowBalloon();
private:
   int y_SPEED = 3;
};

