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
#include"drawYellowBox.h"
#include "Mode.h"
#include<sstream> 
using namespace std;
class ProjectManager
{
private:

     int  NoOfShapes;
     int  NoOfGridCells;
     Shapes **shapesArr;
     drawSquare squareTempObj;
     int RandomGenerateID;
     drawGrid gridObj;
     DisplayScreen ScreenObj;
     int FirstSelectedCell;
     int SecondSelectedCell;

     Shapes* selectedShape;
     bool isValidMove;
     int mCurrentMouseX;
     int mCurrentMouseY;

     bool isMouseLeftButtonDown;
     bool IskeyPressed;
     int RowWiseMatchedShapeTypes[GRID_NUMBER_OF_ROWS][MAXIMUM_GROUPED_CELLS];
     bool hintchk;
     float ProgressLineInitialXCord;
     float ProgressLineFinalXCord;
     Mode modeObj;
     int TotalScoreOfLevel = 0;
     bool LevelUpgrade;
     bool isSoundON;
     int currentDisplayedPage;

public:

     
     ProjectManager();
     Shapes* GetRandomShape(int i);
     void DisplayShapes();
     void IsGroupFormedInRow();
     void IsGroupFormedInColumn();
     void FirstSelectedCellNumber(int x, int y);
     void SecondSelectedCellNumber(int x, int y);
     void SwappingSelectedCells();
     int getMatchRowCounter(int *arr);
     void  DrawRectangleOnSelectedCell();
     void drawUnfilledRect(int x, int y);

     int getcurrentDisplayedPage();
     void  setcurrentDisplayedPage(int);

     Shapes* getShapeOfSpecificCell(int cellNo);
     void AddOffsetToShapeOfSpecificCell(int cellNo);     
     void DisplaySelectedShape();

     bool getisValidMove();
     int getmCurrentMouseX();
     int getmCurrentMouseY();
     bool getisMouseLeftButtonDown();
     bool getIskeyPressed();

     bool getLevelUpgrade();
     void setLevelUpgrade(bool);
    
     bool getisSoundON();
     void setisSoundON(bool);

     void setisValidMove(bool);
     void setmCurrentMouseX(int);
     void setmCurrentMouseY(int);
     void setisMouseLeftButtonDown(bool);
     void setIskeyPressed(bool);
     void SolveMatchedGems(int rowNmbr);
     void GetShapeForUpgradeCell(int upgradedCell);
    bool checkValidMove();
    DisplayScreen* getScreenObj();
    Mode* getmodeObj();
    void UpdateScore(int counter);
    void WhenHintButtonPressed();
    void DisplayProgressBar();
    bool gethintchk();
    void sethintchk(bool);
    void setProgressLineInitialXCord(float);
    float  getProgressLineInitialXCord();
    void setProgressLineFinalXCord(float);
    float  getProgressLineFinalXCord();
    void  UpdateProgressLineFinalXCord(int counter);
    void GetShapeForUpgradeCellInColumn(int upgradedCell);
    void CalculateTotalScoreOfLevel();

     ~ProjectManager(); 
};

