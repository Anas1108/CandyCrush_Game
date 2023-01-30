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
#include"AppStructConsts.h"
using namespace std;
class drawGrid:public Shapes
{
private:
     int NoOfrows;
     int NoOfcolumns;
     int gridInitialX_comp;
     int gridInitialY_comp;

     //drawSquare squareTempObj;
     //Drawcircle circleTempObj;
     //drawPillar pillarTempObj;
     //drawRoundRectangle roundRectTempObj;
     //drawTriangle triangleTempObj;
   /*  int gridCellXcordinates[TOTAL_GRID_CELLS];
     int gridCellYcordinates[TOTAL_GRID_CELLS];*/
public:
     drawGrid();
     int getGridInitialX_comp();
     void setGridInitialX_comp(int);
     int getGridInitialY_comp();
     void setGridInitialY_comp(int);
     void DisplayGrid();
     int getNoOfrows();
     void setNoOfrows(int);
     int getNoOfcolumns();
     void setNoOfcolumns(int);
    // int* GetGridCellXcordinates();
     //int* GetGridCellYcordinates();
     Coordinates ConvertCellNumToCoordinates(int cellNo);
     int GetRowNumFromCell(int cellNo);
     int GetColNumFromCell(int cellNo);
     int GetCellNumFromCordinates(int x,int y);


     ~drawGrid();
};

