#pragma once
#include "util.h"
#include"Shapes.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"AppStructConsts.h"
#include"Cell.h"
using namespace std;
class drawTriangle: public Shapes
{
private:
     int x_cord1;
     int y_cord1;
     int x_cord2;
     int y_cord2;
     int x_cord3;
     int y_cord3;

     Coordinates vertex1;
     Coordinates vertex2;
     Coordinates vertex3;
public:
     drawTriangle();
     drawTriangle( int type, Coordinates cord, Cell* TempCellObj, float x1, float y1, float x2, float y2, float x3, float y3);
     int getX_cord1();
     void setX_cord1(int);
     int getX_cord2();
     void setX_cord2(int);
     int getX_cord3();
     void setX_cord3(int);
     int getY_cord1();
     void setY_cord1(int);
     int getY_cord2();
     void setY_cord2(int);
     int getY_cord3();
     void setY_cord3(int);
     void Display();
     ~drawTriangle();
};

