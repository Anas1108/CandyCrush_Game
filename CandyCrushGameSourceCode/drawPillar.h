#pragma once
#include "util.h"
#include "Shapes.h"

#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"AppStructConsts.h"
#include "drawRoundRectangle.h"
#include"Cell.h"
#include <iostream>
#include<string>
using namespace std;
class drawPillar:public Shapes
{
private:
     float PillarRoundAngle;
     float height;
     float width;
public:
     drawPillar();
     drawPillar( int type, Coordinates cord, Cell *TempCellObj, float hght,float wid,float roundAng);
     float getPillarRoundAngle();
     void setPillarRoundAngle(float);
     float getHeight();
     float getWidth();
     void setHeight(float);
     void setWidth(float);
     void Display();
     ~drawPillar();
};

