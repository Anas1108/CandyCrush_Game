#include "drawSquare.h"


drawSquare::drawSquare()
{
}
drawSquare::drawSquare( int type, Coordinates cord, Cell* TempCellObj, float tempSize): Shapes( type, cord,TempCellObj)
{
     size = tempSize;
}
float drawSquare::getSize()
{
     return size;
}
void drawSquare::setSize(float x)
{
     size = x;
}
void drawSquare::Display()
{
     DrawSquare(coord.x,coord.y,getSize(),colors[SQUARE_COLOR]);
}
drawSquare::~drawSquare()
{
}
