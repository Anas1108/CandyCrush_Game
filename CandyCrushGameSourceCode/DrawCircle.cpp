#include "DrawCircle.h"
Drawcircle::Drawcircle()
{
}

Drawcircle::Drawcircle( int type, Coordinates cord,Cell *TempCellObj, float radius): Shapes(type,cord, TempCellObj)
{
     rad = radius;
}

float Drawcircle::getRadius()
{
     return rad;
}
void Drawcircle::setRadius(float x)
{
     rad = x;
}

void Drawcircle::Display()
{
     DrawCircle(coord.x, coord.y, getRadius(),colors[CIRCLE_COLOR]);
}
Drawcircle::~Drawcircle()
{
}


