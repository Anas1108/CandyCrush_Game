#pragma once
#include "util.h"
#include <iostream>
#include<string>
#include"AppStructConsts.h"
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"Cell.h"
using namespace std;
class Shapes
{
protected:
     Coordinates coord;
     float* color;
     int shapeType;
     Cell* cellObj;
public:
     Shapes();
     Shapes( int type, Coordinates TempCord, Cell*);
     int getShapeType();
     void setShapeType(int);
     Cell* getcellObj();
     void setcellObj(Cell*);

     Coordinates* getCoordObj();
     void setCoordObj(Coordinates*);

     virtual void Display();


     ~Shapes();
};

