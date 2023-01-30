#pragma once
#include "util.h"
#include "Shapes.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"AppStructConsts.h"
#include"Cell.h"
using namespace std;
class  drawYellowBox : public Shapes
{
private:
     float BoxSize;

public:
     drawYellowBox();
     drawYellowBox(int type, Coordinates cord, Cell* TempCellObj, float tempBoxSize);
     float getBoxSize();
     void setBoxSize(float);
     void Display();
     ~drawYellowBox();
};


