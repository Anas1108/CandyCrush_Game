#include "drawPillar.h"

drawPillar::drawPillar()
{
}
drawPillar::drawPillar( int type, Coordinates cord, Cell* TempCellObj, float hght, float wid, float roundAng):Shapes( type, cord,TempCellObj)
{
     height = hght;
     width = wid;
     PillarRoundAngle = roundAng;
}
float drawPillar::getHeight()
{
     return height;
}
void drawPillar::setHeight(float x)
{
     height = x;
}
float drawPillar::getWidth()
{
     return width;
}
void drawPillar::setWidth(float x)
{
     width = x;
}


float drawPillar::getPillarRoundAngle()
{
     return PillarRoundAngle;
}
void drawPillar::setPillarRoundAngle(float x)
{
     PillarRoundAngle = x;
}
void drawPillar::Display()
{
     DrawRoundRect(coord.x,coord.y,getHeight(),getWidth(), colors[PILLAR_COLOR],PillarRoundAngle);
}
drawPillar::~drawPillar()
{
}
