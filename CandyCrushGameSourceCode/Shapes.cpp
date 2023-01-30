#include "Shapes.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

Shapes::Shapes()
{
    // color = colors[CIRCLE_COLOR];
     shapeType = -1;
     coord.x = 0;
     coord.y = 0;
}
Shapes::Shapes(int type, Coordinates TempCord,Cell *TempCellObj)
{

     shapeType =type;
     coord.x = TempCord.x;
     coord.y = TempCord.y;
     cellObj = TempCellObj;
}
Cell* Shapes::getcellObj()
{
     return cellObj;
}
void Shapes::setcellObj(Cell* obj)
{
     cellObj = obj;
}
//int Shapes::getcellNo()
//{
//     return cellNo;
//}
//void Shapes::setcellNo(int x)
//{
//     cellNo = x;
//}

int Shapes::getShapeType()
{
     return shapeType;
}
void Shapes::setShapeType(int type)
{
     shapeType = type;
}

Coordinates* Shapes::getCoordObj()
{
     return &coord;
}
void Shapes::setCoordObj(Coordinates* c)
{
     coord = *c;
}

void Shapes::Display()
{

}

Shapes::~Shapes()
{
}
