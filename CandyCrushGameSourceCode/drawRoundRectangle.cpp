#include "drawRoundRectangle.h"

drawRoundRectangle::drawRoundRectangle()
{
}
drawRoundRectangle::drawRoundRectangle( int type, Coordinates cord, Cell* TempCellObj, float hght, float wid, float roundAng) :Shapes( type, cord,TempCellObj)
{
     height = hght;
     width = wid;
     RectroundAngle = roundAng;
}
float drawRoundRectangle::getHeight()
{
     return height;
}
void drawRoundRectangle::setHeight(float x)
{
     height = x;
}
float drawRoundRectangle::getWidth()
{
     return width;
}
void drawRoundRectangle::setWidth(float x)
{
     width = x;
}
float drawRoundRectangle::getRectroundAngle()
{
     return RectroundAngle;
}
void drawRoundRectangle::setRectroundAngle(float x)
{
     RectroundAngle = x;
}
void drawRoundRectangle::Display()
{
     DrawRoundRect(coord.x, coord.y, getHeight(), getWidth(), colors[RECTANGLE_COLOR], RectroundAngle);
}
drawRoundRectangle::~drawRoundRectangle()
{
}
