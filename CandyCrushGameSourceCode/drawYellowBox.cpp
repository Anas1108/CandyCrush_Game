#include "drawYellowBox.h"


drawYellowBox::drawYellowBox()
{
}
drawYellowBox::drawYellowBox(int type, Coordinates cord, Cell* TempCellObj, float tempBoxSize) : Shapes(type, cord, TempCellObj)
{
     BoxSize = tempBoxSize;
}
float drawYellowBox::getBoxSize()
{
     return BoxSize;
}
void drawYellowBox::setBoxSize(float x)
{
     BoxSize = x;
}
void drawYellowBox::Display()
{
     DrawSquare(coord.x, coord.y, getBoxSize(), colors[YELLOW_BOX_COLOR]);
}
drawYellowBox::~drawYellowBox()
{
}

