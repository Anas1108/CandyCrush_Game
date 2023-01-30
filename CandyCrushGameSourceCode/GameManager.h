#pragma once
#include "util.h"
#include"Shapes.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"drawSquare.h"
#include"DrawCircle.h"
#include"drawPillar.h"
#include"drawRoundRectangle.h"
#include"drawTriangle.h"
#include <stdlib.h> 
#include<time.h>
#include "drawPillar.h"
#include "AppStructConsts.h"
#include"drawGrid.h"
#include"DisplayScreen.h"
#include"Cell.h"
using namespace std;
class GameManager
{
private:
     
    int  NoOfShapes;
    int  NoOfGridCells;
    Shapes **shapesArr;
    drawSquare squareTempObj;
    int RandomGenerateID;
    drawGrid gridObj;
    DisplayScreen ScreenObj;
public:
     bool IskeyPressed;
     GameManager();
     Shapes* GetRandomShape(int i);
     void DisplayShapes();
     void IsGroupFormedInRow();
     void IsGroupFormedInColumn();
     //void AssighnShapeToGrid();
     ~GameManager();
};

