#pragma once
#include "util.h"
#include "Shapes.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"AppStructConsts.h"
#include"Cell.h"
using namespace std;
class drawRoundRectangle: public Shapes
{
private:
     float RectroundAngle;
     float height;
     float width;
public:
     drawRoundRectangle();
     drawRoundRectangle(int type, Coordinates cord, Cell* TempCellObj, float hght, float wid, float roundAng);
     float getHeight();
     float getWidth();
     void setHeight(float);
     void setWidth(float);
     float getRectroundAngle();
     void setRectroundAngle(float);
     void Display();
     ~drawRoundRectangle();

};

