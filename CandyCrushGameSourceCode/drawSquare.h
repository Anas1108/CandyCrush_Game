#pragma once
#include "util.h"
#include "Shapes.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"AppStructConsts.h"
#include"Cell.h"
using namespace std;
class drawSquare: public Shapes
{
private:
     float size;
     
public:
     drawSquare();
     drawSquare( int type, Coordinates cord, Cell* TempCellObj, float tempSize);
     float getSize();
     void setSize(float);
     void Display();
     ~drawSquare();
};

