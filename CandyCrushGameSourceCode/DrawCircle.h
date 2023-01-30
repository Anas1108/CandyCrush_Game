#pragma once
#include "util.h"
#include "Shapes.h"
#include <iostream>
#include<string>
#include"AppStructConsts.h"
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"Cell.h"
using namespace std;

class Drawcircle: public Shapes
{
private:
     float rad;
public:
     Drawcircle();
     Drawcircle(int type, Coordinates cord,Cell* cellNo,float radius);
     float getRadius();
     void setRadius(float);
     void Display();
     ~Drawcircle();
};
