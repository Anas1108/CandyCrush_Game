#include "drawTriangle.h"


drawTriangle::drawTriangle()
{
}

drawTriangle::drawTriangle( int type, Coordinates cord, Cell *TempCellObj, float x1, float y1, float x2, float y2, float x3, float y3):Shapes(type, cord,TempCellObj)
{
     x_cord1 = x1;
     y_cord1 = y1;
     x_cord2 = x2;
     y_cord2 = y2;
     x_cord3 = x3;
     y_cord3 = y3;
    
}
int drawTriangle::getX_cord1()
{
     return x_cord1;
}
void drawTriangle::setX_cord1(int x)
{
     x_cord1 = x;
}
int drawTriangle::getX_cord2()
{
     return x_cord2;
}
void drawTriangle::setX_cord2(int x)
{
     x_cord2 = x;
}
int drawTriangle::getX_cord3()
{
     return x_cord3;
}
void drawTriangle::setX_cord3(int x)
{
     x_cord3 = x;
}
int drawTriangle::getY_cord2()
{
     return y_cord2;
}
void drawTriangle::setY_cord2(int x)
{
     y_cord2 = x;
}
int drawTriangle::getY_cord3()
{
     return y_cord3;
}
void drawTriangle::setY_cord3(int x)
{
     y_cord3 = x;
}
int drawTriangle::getY_cord1()
{
     return y_cord1;
}
void drawTriangle::setY_cord1(int x)
{
     y_cord1 = x;
}
void drawTriangle::Display()
{
     DrawTriangle(getX_cord1(),getY_cord1(),getX_cord2(),getY_cord2(),getX_cord3(),getY_cord3(),colors[TRIANGLE_COLOR]);
}
drawTriangle::~drawTriangle()
{
}
