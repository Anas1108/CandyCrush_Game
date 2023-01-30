#include "ProjectManager.h"
ProjectManager::ProjectManager()
{
     isMouseLeftButtonDown = false;
     FirstSelectedCell=-1;
     SecondSelectedCell=-1;
     RandomGenerateID = 0;
     srand(time(0));
     shapesArr = new Shapes*[TOTAL_GRID_CELLS];
     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          shapesArr[i] = new Shapes();
          shapesArr[i] = GetRandomShape(i);
     }
     IskeyPressed = false;
     isValidMove = false;
     mCurrentMouseX = 400;
     mCurrentMouseY = 400;
     hintchk = false;
     CalculateTotalScoreOfLevel();
     ProgressLineInitialXCord=500;
     ProgressLineFinalXCord = 500;
     LevelUpgrade = false;
     isSoundON = true;
     currentDisplayedPage = -1;
} 
int ProjectManager::getcurrentDisplayedPage()
{
     return currentDisplayedPage;
}
void  ProjectManager::setcurrentDisplayedPage(int x)
{
     currentDisplayedPage = x;
}
bool ProjectManager::getisSoundON()
{
     return  isSoundON;
}
void ProjectManager::setisSoundON(bool x)
{
     isSoundON = x;
}
bool ProjectManager::getLevelUpgrade()
{
     return LevelUpgrade;
}
void ProjectManager::setLevelUpgrade(bool x)
{
     LevelUpgrade = x;
}
void ProjectManager::CalculateTotalScoreOfLevel()
{
     TotalScoreOfLevel = ScreenObj.getLevelNmbr() * 100;
}

void ProjectManager::setProgressLineInitialXCord(float x)
{
     ProgressLineInitialXCord = x;
}
float  ProjectManager::getProgressLineInitialXCord()
{
     return ProgressLineInitialXCord;
}
void ProjectManager::setProgressLineFinalXCord(float x)
{
     ProgressLineFinalXCord = x;
}
float  ProjectManager::getProgressLineFinalXCord()
{
     return ProgressLineFinalXCord;
}
bool ProjectManager::getisValidMove()
{
     return isValidMove;
}
int ProjectManager::getmCurrentMouseX()
{
     return mCurrentMouseX;
}
int ProjectManager::getmCurrentMouseY()
{
     return mCurrentMouseY;
}


bool ProjectManager::getisMouseLeftButtonDown()
{
     return isMouseLeftButtonDown;
}
bool ProjectManager::getIskeyPressed()
{
     return IskeyPressed;
}

void ProjectManager::setisValidMove(bool x)
{
     isValidMove = x;
}
void ProjectManager::setmCurrentMouseX(int x)
{
     mCurrentMouseX = x;
}

void ProjectManager::setmCurrentMouseY(int x)
{
     mCurrentMouseY = x;
}
void ProjectManager::setisMouseLeftButtonDown(bool x)
{
     isMouseLeftButtonDown = x;
}
void ProjectManager::setIskeyPressed(bool x)
{
     IskeyPressed = x;
}
DisplayScreen*  ProjectManager::getScreenObj()
{
     return &ScreenObj;
}
Mode* ProjectManager::getmodeObj()
{
     return &modeObj;
}

bool  ProjectManager::gethintchk()
{
     return hintchk;
}
void  ProjectManager::sethintchk(bool x)
{
     hintchk = x;
}

void ProjectManager::DisplayShapes()
{ 

     
          for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
          {
               if (shapesArr[i]->getcellObj()->getIsOccupied())
               {
                    shapesArr[i]->Display();
               }
          }
          


}

void ProjectManager::DisplaySelectedShape()
{
     if (isMouseLeftButtonDown)
     {
          selectedShape->getCoordObj()->x = mCurrentMouseX;
          selectedShape->getCoordObj()->y = mCurrentMouseY;

          if((mCurrentMouseX> 295 && mCurrentMouseX< 625) && (mCurrentMouseY < 375 && mCurrentMouseY>50))
          selectedShape->Display();
          else
          {
               shapesArr[FirstSelectedCell]->getcellObj()->setIsOccupied(true);
          }
     }
}
void ProjectManager::WhenHintButtonPressed()
{
     int BackCounter = 1;
     int forwardCounter = 1;
     int upwardCounter = 1;
     int downwardCounter = 1;
     int AllShapesTypes[INITIAL_POPULATED_GRID_CELLS];


     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          AllShapesTypes[i] = shapesArr[i]->getShapeType();
     }
     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          BackCounter = 1;
          forwardCounter = 1;
          upwardCounter = 1;
          downwardCounter = 1;
          if (AllShapesTypes[i] == AllShapesTypes[i+1] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i +1))
          {
               forwardCounter++;
          }
          if (AllShapesTypes[i] == AllShapesTypes[i-1] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i -1))
          {
               BackCounter++;
          }
          if (AllShapesTypes[i] == AllShapesTypes[i - 6] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i - 6))
          {
               upwardCounter++;
          }
          if (AllShapesTypes[i] == AllShapesTypes[i + 6] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i + 6))
          {
               downwardCounter++;
          }
          int x = -1;
          int y = -1;
          ///////////////////////////////////////////check in row/////////////////////////////////////////////////////////////
          if (forwardCounter == 2)
          {
               //000
               //1101
               if (AllShapesTypes[i] == AllShapesTypes[i + 3] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i + 3))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i + 1).x;
                    y = gridObj.ConvertCellNumToCoordinates(i + 1).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i + 3).x;
                    y = gridObj.ConvertCellNumToCoordinates(i + 3).y;
                    drawUnfilledRect(x, y);
               }
               //001
               //110 
               if (AllShapesTypes[i] == AllShapesTypes[(i + 2) - 6] && (gridObj.GetRowNumFromCell(i) - 1) == gridObj.GetRowNumFromCell((i + 2) - 6))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i + 1).x;
                    y = gridObj.ConvertCellNumToCoordinates(i + 1).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i + 2) - 6).x;
                    y = gridObj.ConvertCellNumToCoordinates((i + 2) - 6).y;
                    drawUnfilledRect(x, y);
               }
               //110
               //001
               if (AllShapesTypes[i] == AllShapesTypes[(i + 2) + 6] && (gridObj.GetRowNumFromCell(i) + 1) == gridObj.GetRowNumFromCell((i + 2) + 6))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i + 1).x;
                    y = gridObj.ConvertCellNumToCoordinates(i + 1).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i + 2) + 6).x;
                    y = gridObj.ConvertCellNumToCoordinates((i + 2) + 6).y;
                    drawUnfilledRect(x, y);
               }

          }
          if (BackCounter == 2)
          {
               //000
               //1011
               if (AllShapesTypes[i] == AllShapesTypes[i - 3] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i - 3))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 1).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 1).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 3).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 3).y;
                    drawUnfilledRect(x, y);
               }
               //100
               //011 
               if (AllShapesTypes[i] == AllShapesTypes[(i - 2) - 6] && (gridObj.GetRowNumFromCell(i) - 1) == gridObj.GetRowNumFromCell((i - 2) - 6))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 1).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 1).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i - 2) - 6).x;
                    y = gridObj.ConvertCellNumToCoordinates((i - 2) - 6).y;
                    drawUnfilledRect(x, y);
               }
               //011
               //100
               if (AllShapesTypes[i] == AllShapesTypes[(i - 2) + 6] && (gridObj.GetRowNumFromCell(i) + 1) == gridObj.GetRowNumFromCell((i - 2) + 6))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 1).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 1).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i - 2) + 6).x;
                    y = gridObj.ConvertCellNumToCoordinates((i - 2) + 6).y;
                    drawUnfilledRect(x, y);
               }
          }
          if (forwardCounter == 1)
          {
               if (AllShapesTypes[i] == AllShapesTypes[i + 2] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i + 2))
               {
                    //010
                    //101
                    if (AllShapesTypes[i] == AllShapesTypes[(i + 1) - 6] && (gridObj.GetRowNumFromCell(i) - 1) == (gridObj.GetRowNumFromCell((i + 1) - 6)))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i + 2).x;
                         y = gridObj.ConvertCellNumToCoordinates(i + 2).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i + 1) - 6).x;
                         y = gridObj.ConvertCellNumToCoordinates((i + 1) - 6).y;
                         drawUnfilledRect(x, y);
                    }
                    //101
                    //010
                    if (AllShapesTypes[i] == AllShapesTypes[(i + 1) + 6] && (gridObj.GetRowNumFromCell(i) + 1) == (gridObj.GetRowNumFromCell((i + 1) + 6)))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i + 2).x;
                         y = gridObj.ConvertCellNumToCoordinates(i + 2).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i + 1) + 6).x;
                         y = gridObj.ConvertCellNumToCoordinates((i + 1) + 6).y;
                         drawUnfilledRect(x, y);
                    }

               }
          }
          if (BackCounter == 1)
          {
               if (AllShapesTypes[i] == AllShapesTypes[i - 2] && (gridObj.GetRowNumFromCell(i)) == (gridObj.GetRowNumFromCell(i - 2)))
               {
                    //010
                    //101
                    if (AllShapesTypes[i] == AllShapesTypes[(i - 1) - 6] && (gridObj.GetRowNumFromCell(i) - 1) == (gridObj.GetRowNumFromCell((i - 1) - 6)))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i - 2).x;
                         y = gridObj.ConvertCellNumToCoordinates(i - 2).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i - 1) - 6).x;
                         y = gridObj.ConvertCellNumToCoordinates((i - 1) - 6).y;
                         drawUnfilledRect(x, y);
                    }
                    //101
                    //010
                    if (AllShapesTypes[i] == AllShapesTypes[(i - 1) + 6] && (gridObj.GetRowNumFromCell(i) + 1) == (gridObj.GetRowNumFromCell((i - 1) + 6)))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i - 2).x;
                         y = gridObj.ConvertCellNumToCoordinates(i - 2).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i - 1) + 6).x;
                         y = gridObj.ConvertCellNumToCoordinates((i - 1) + 6).y;
                         drawUnfilledRect(x, y);
                    }

               }
          }

          /////////////////////////////////////////////check in column/////////////////////////////////////////////////////////////
          


          if (upwardCounter == 2)
          {
               //1
               //0
               //1
               //1
               if (AllShapesTypes[i] == AllShapesTypes[i - 18] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i - 18))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 6).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 6).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 18).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 18).y;
                    drawUnfilledRect(x, y);
               }
               //00
               //01
               //10
               //10
               if (AllShapesTypes[i] == AllShapesTypes[(i - 12) + 1] && (gridObj.GetColNumFromCell(i) + 1) == gridObj.GetColNumFromCell((i - 12) + 1))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 6).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 6).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i - 12) + 1).x;
                    y = gridObj.ConvertCellNumToCoordinates((i - 12) + 1).y;
                    drawUnfilledRect(x, y);
               }
               //00
               //10
               //01
               //01
               if (AllShapesTypes[i] == AllShapesTypes[(i - 12) - 1] && (gridObj.GetColNumFromCell(i) - 1) == gridObj.GetColNumFromCell((i - 12) - 1))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i - 6).x;
                    y = gridObj.ConvertCellNumToCoordinates(i - 6).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i - 12) - 1).x;
                    y = gridObj.ConvertCellNumToCoordinates((i - 12) - 1).y;
                    drawUnfilledRect(x, y);
               }
          }

          if (downwardCounter == 2)
          {
               //00
               //10
               //10
               //01
               if (AllShapesTypes[i] == AllShapesTypes[(i + 12)+1] && gridObj.GetColNumFromCell(i)+1 == gridObj.GetColNumFromCell((i + 12) + 1))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i +6).x;
                    y = gridObj.ConvertCellNumToCoordinates(i +6).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i + 12) + 1).x;
                    y = gridObj.ConvertCellNumToCoordinates((i + 12) + 1).y;
                    drawUnfilledRect(x, y);
               }
               //00
               //01
               //01
               //10
               if (AllShapesTypes[i] == AllShapesTypes[(i + 12) - 1] && (gridObj.GetColNumFromCell(i) - 1) == gridObj.GetColNumFromCell((i + 12) - 1))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i +6).x;
                    y = gridObj.ConvertCellNumToCoordinates(i +6).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i + 12) - 1).x;
                    y = gridObj.ConvertCellNumToCoordinates((i + 12) - 1).y;
                    drawUnfilledRect(x, y);
               }
               //10
               //10
               //00
               //10
               if (AllShapesTypes[i] == AllShapesTypes[(i + 18) ] && (gridObj.GetColNumFromCell(i)) == gridObj.GetColNumFromCell((i+18)))
               {
                    x = gridObj.ConvertCellNumToCoordinates(i).x;
                    y = gridObj.ConvertCellNumToCoordinates(i).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates(i +6).x;
                    y = gridObj.ConvertCellNumToCoordinates(i +6).y;
                    drawUnfilledRect(x, y);
                    x = gridObj.ConvertCellNumToCoordinates((i +18)).x;
                    y = gridObj.ConvertCellNumToCoordinates((i +18)).y;
                    drawUnfilledRect(x, y);
               }
          }
          if (upwardCounter == 1)
          {
               if (AllShapesTypes[i] == AllShapesTypes[i -12] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i -12))
               {
                    //00
                    //10
                    //01
                    //10
                    if (AllShapesTypes[i] == AllShapesTypes[(i -6) +1] && (gridObj.GetColNumFromCell(i) + 1) == (gridObj.GetColNumFromCell(((i - 6) + 1))))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i -12).x;
                         y = gridObj.ConvertCellNumToCoordinates(i -12).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i - 6) + 1).x;
                         y = gridObj.ConvertCellNumToCoordinates((i - 6) + 1).y;
                         drawUnfilledRect(x, y);
                    }
                    //00
                    //01
                    //10
                    //01
                    if (AllShapesTypes[i] == AllShapesTypes[(i -6) -1] && (gridObj.GetColNumFromCell(i) - 1) == (gridObj.GetColNumFromCell((i - 6) - 1)))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i -12).x;
                         y = gridObj.ConvertCellNumToCoordinates(i - 12).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i - 6) - 1).x;
                         y = gridObj.ConvertCellNumToCoordinates((i - 6) - 1).y;
                         drawUnfilledRect(x, y);
                    }

               }
          }
          if (downwardCounter == 1)
          {
               if (AllShapesTypes[i] == AllShapesTypes[i + 12] && (gridObj.GetColNumFromCell(i)) == (gridObj.GetColNumFromCell(i + 12)))
               {
                   // 00
                   // 10
                   // 01
                   // 10
                    if (AllShapesTypes[i] == AllShapesTypes[(i + 6) +1] && (gridObj.GetColNumFromCell(i) + 1) == (gridObj.GetColNumFromCell((i + 6) + 1)))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i + 12).x;
                         y = gridObj.ConvertCellNumToCoordinates(i + 12).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i + 6) + 1).x;
                         y = gridObj.ConvertCellNumToCoordinates((i + 6) + 1).y;
                         drawUnfilledRect(x, y);
                    }
                   // 00
                   // 01
                   // 10
                   // 01
                    if (AllShapesTypes[i] == AllShapesTypes[(i + 6) - 1] && (gridObj.GetColNumFromCell(i) - 1) == (gridObj.GetColNumFromCell((i + 6) - 1)))
                    {
                         x = gridObj.ConvertCellNumToCoordinates(i).x;
                         y = gridObj.ConvertCellNumToCoordinates(i).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates(i + 12).x;
                         y = gridObj.ConvertCellNumToCoordinates(i + 12).y;
                         drawUnfilledRect(x, y);
                         x = gridObj.ConvertCellNumToCoordinates((i + 6) - 1).x;
                         y = gridObj.ConvertCellNumToCoordinates((i + 6) - 1).y;
                         drawUnfilledRect(x, y);
                    }

               }
          }
      }
}   
    
Shapes* ProjectManager::GetRandomShape(int i)
{
     RandomGenerateID = rand() % 5 + 1;

     cout << "Generated Shape Type= " << RandomGenerateID << endl;

     switch (RandomGenerateID)
     {

     case SHAPE_CIRCLE:
     {
          Coordinates c= gridObj.ConvertCellNumToCoordinates(i);
          c.x = c.x + CIRCLE_OFFSET_X;
          c.y = c.y + CIRCLE_OFFSET_Y;
          return new Drawcircle(SHAPE_CIRCLE,c,new Cell(true,i),CIRCLE_RADIUS);
          break;
     }
     case SHAPE_SQUARE:
     {
          Coordinates c= gridObj.ConvertCellNumToCoordinates(i);
          c.x = c.x + SQUARE_OFFSET_X;
          c.y = c.y + SQUARE_OFFSET_Y;

          return new drawSquare(SHAPE_SQUARE, c, new Cell(true, i), SQUARE_SIZE);
          break;
     }
     case SHAPE_YELLOW_BOX:
     {
          Coordinates c = gridObj.ConvertCellNumToCoordinates(i);
          c.x = c.x + YELLOW_BOX_OFFSET_X;
          c.y = c.y + YELLOW_BOX_OFFSET_Y;

          return new drawYellowBox(SHAPE_YELLOW_BOX, c, new Cell(true, i),YELLOW_BOX_SIZE);
          break;
     }
     case SHAPE_ROUND_RECTANGLE:
     {
          Coordinates c= gridObj.ConvertCellNumToCoordinates(i);
          c.x = c.x + ROUND_RECTANGLE_OFFSET_X;
          c.y = c.y+ ROUND_RECTANGLE_OFFSET_Y;

          return new drawRoundRectangle(SHAPE_ROUND_RECTANGLE, c, new Cell(true, i),
               RECTANGLE_HEIGHT, RECTANGLE_WIDTH, RECTANGLE_ROUND_ANGLE);
          break;
     }
     case SHAPE_PILLAR:
     {
          Coordinates c= gridObj.ConvertCellNumToCoordinates(i);
          c.x = c.x+ PILLAR_OFFSET_X;
          c.y = c.y+ PILLAR_OFFSET_Y;
          return new drawPillar(SHAPE_PILLAR, c, new Cell(true, i),PILLAR_HEIGHT, PILLAR_WIDTH, PILLAR_ROUND_ANGLE);
          break;
     }

     }


}
void ProjectManager::IsGroupFormedInRow()
{
     int rowNmbr = 0;
     int counter = 1;
     int AllShapesTypes[INITIAL_POPULATED_GRID_CELLS];
     int MatchedShapeTypes[MAXIMUM_GROUPED_CELLS];
     
     int typeCounter = 0;

     for (int i = 0; i < GRID_NUMBER_OF_ROWS; i++)
     {
          for (int j = 0; j < MAXIMUM_GROUPED_CELLS; j++)
          {
               RowWiseMatchedShapeTypes[i][j] = -1;
          }

     }


     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          AllShapesTypes[i] = shapesArr[i]->getShapeType();
     }
     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          counter = 1;
          typeCounter = 0;
          for (int j = 0; j < MAXIMUM_GROUPED_CELLS; j++)
          {
               MatchedShapeTypes[j] = 0;
          }
          MatchedShapeTypes[typeCounter] = i;
          typeCounter++;
          if (AllShapesTypes[i] == AllShapesTypes[i + 1] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i + 1))
          {
               MatchedShapeTypes[typeCounter] = i + 1;
               typeCounter++;
               counter++;
               if (AllShapesTypes[i] == AllShapesTypes[i + 2] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i + 2))
               {
                    MatchedShapeTypes[typeCounter] = i + 2;
                    typeCounter++;
                    counter++;
                    if (AllShapesTypes[i] == AllShapesTypes[i + 3] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i + 3))
                    {
                         MatchedShapeTypes[typeCounter] = i + 3;
                         typeCounter++;
                         counter++;
                    }
               }
          }

          if (AllShapesTypes[i] == AllShapesTypes[i - 1] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i - 1))
          {
               MatchedShapeTypes[typeCounter] = i - 1;
               typeCounter++;
               counter++;
               if (AllShapesTypes[i] == AllShapesTypes[i - 2] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i - 2))
               {
                    MatchedShapeTypes[typeCounter] = i - 2;
                    typeCounter++;
                    counter++;
                    if (AllShapesTypes[i] == AllShapesTypes[i - 3] && gridObj.GetRowNumFromCell(i) == gridObj.GetRowNumFromCell(i - 3))
                    {
                         MatchedShapeTypes[typeCounter] = i - 3;
                         typeCounter++;
                         counter++;
                    }
               }
          }


          if (counter >= 3)
          {
               //displayOff the same gems in row
               for (int j = 0; j < counter; j++)
               {
                    shapesArr[MatchedShapeTypes[j]]->getcellObj()->setIsOccupied(false);
                    RowWiseMatchedShapeTypes[gridObj.GetRowNumFromCell(i)][j] = MatchedShapeTypes[j];                  
               }
               SolveMatchedGems(rowNmbr);
               

          }
          

     }

}
void ProjectManager::UpdateScore(int counter)
{


     int score = ScreenObj.getScore();
     
     if (counter == 3)
     {

          score = score + 1;
          ScreenObj.setScore(score);
     }
     if (counter == 4)
     {
          score = score + (1*2);
          ScreenObj.setScore(score);
     }
     if (counter == 5)
     {
          score = score + (1 * 3);
          ScreenObj.setScore(score);
     }
     if (counter == 6)
     {
          score = score + (1 * 4);
          ScreenObj.setScore(score);
     }
     
     UpdateProgressLineFinalXCord(score);
}
void  ProjectManager::UpdateProgressLineFinalXCord(int score)
{
     float fScore = score;
     float fTotalScoreOfLevel = TotalScoreOfLevel;

     ProgressLineFinalXCord = ProgressLineInitialXCord + (fScore / fTotalScoreOfLevel) * 500;
     cout << "ProgressLineFinalXCord= " << ProgressLineFinalXCord <<"Score= "<<score<<endl;


}
void ProjectManager::SolveMatchedGems(int rowNmbr)
{

     ////////////////////////solving ka code
     int a = 0;

     for (int i = 0; i < GRID_NUMBER_OF_ROWS; i++)
     {
          cout << "Row Number:" << i << endl;
          for (int j = 0; j < MAXIMUM_GROUPED_CELLS; j++)
          {
                
               if (RowWiseMatchedShapeTypes[i][0] > 0)
               {
                    cout << RowWiseMatchedShapeTypes[i][j] << ",";
               }
          }
          cout << endl;

     }
     for (int i = 0; i < GRID_NUMBER_OF_ROWS; i++)
     {
          if (RowWiseMatchedShapeTypes[i][0] >= 0)   // group exists for this row
          {
               cout << "i=" << i << endl;
               int matchCellCounter = getMatchRowCounter(RowWiseMatchedShapeTypes[i]);
               UpdateScore(matchCellCounter);
               /* for (int y = 0; RowWiseMatchedShapeTypes[i][y]>0; y++)
                {
                     matchCellCounter++;
                }*/
               cout << "matchCellCounter=" << matchCellCounter << endl;
               //for (int z = 0; z < MAXIMUM_GROUPED_CELLS; z++)
               {

                    //upper row take below position
                    //rowNmbr = gridObj.GetRowNumFromCell(i);
                    rowNmbr = i;
                    int upgradedCell = 0;
                    for (int j = 0; j <= rowNmbr; j++)
                    {
                         if (j == rowNmbr)
                         {
                              for (int k = 0; k < matchCellCounter; k++)
                              {
                                   upgradedCell = RowWiseMatchedShapeTypes[i][k] - (rowNmbr * 6);

                                   shapesArr[upgradedCell] = new Shapes();

                                   shapesArr[upgradedCell] = GetRandomShape(upgradedCell);
                                   cout << "(j == rowNmbr) ===> Assigning  shape " << shapesArr[upgradedCell]->getShapeType() << " for  cell No: " << upgradedCell << endl;

                              }

                         }
                         else
                         {

                              for (int k = 0; k < matchCellCounter; k++)
                              {
                                   upgradedCell = RowWiseMatchedShapeTypes[i][k] - (j * 6);

                                   int prevX = shapesArr[upgradedCell]->getCoordObj()->x;
                                   int prevY = shapesArr[upgradedCell]->getCoordObj()->y;

                                   cout << "Replacing cell No: " << upgradedCell << " with cell No:" << upgradedCell - 6 << endl;
                                   GetShapeForUpgradeCell(upgradedCell);
                              }
                         }
                    }
               }

          }
     }
}
void ProjectManager::GetShapeForUpgradeCell(int upgradedCell)
{

 switch (shapesArr[upgradedCell - 6]->getShapeType())
      {

                  case SHAPE_CIRCLE:
                  {
                       Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
                       c.x = c.x + CIRCLE_OFFSET_X;
                       c.y = c.y + CIRCLE_OFFSET_Y;

                       /*c.x = prevX;
                       c.y = prevY;*/


                       shapesArr[upgradedCell] = new Drawcircle(SHAPE_CIRCLE, c, new Cell(true, upgradedCell), CIRCLE_RADIUS);
                       break;
                  }
                  case SHAPE_SQUARE:
                  {
                       Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
                       c.x = c.x + SQUARE_OFFSET_X;
                       c.y = c.y + SQUARE_OFFSET_Y;

                       //c.x = prevX;
                       //c.y = prevY;


                       shapesArr[upgradedCell] = new drawSquare(SHAPE_SQUARE, c, new Cell(true, upgradedCell), SQUARE_SIZE);
                       break;
                  }
                  case SHAPE_YELLOW_BOX:
                  {
                       /*Coordinates c = gridObj.ConvertCellNumToCoordinates(i);
                       int  x_cord1 = c.x + TRIANGLE_OFFSET_X1;
                       int  y_cord1 = c.y + TRIANGLE_OFFSET_Y1;
                       int  x_cord2 = c.x + TRIANGLE_OFFSET_X2;
                       int  y_cord2 = c.y + TRIANGLE_OFFSET_Y2;
                       int  x_cord3 = c.x + TRIANGLE_OFFSET_X3;
                       int  y_cord3 = c.y + TRIANGLE_OFFSET_Y3;
                       return new drawTriangle(SHAPE_TRIANGLE, c, new Cell(true, i), x_cord1, y_cord1, x_cord2, y_cord2, x_cord3, y_cord3);*/
                       Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
                       c.x = c.x + YELLOW_BOX_OFFSET_X;
                       c.y = c.y + YELLOW_BOX_OFFSET_Y;

                       shapesArr[upgradedCell] = new drawYellowBox(SHAPE_YELLOW_BOX, c, new Cell(true, upgradedCell), YELLOW_BOX_SIZE);
                       break;
                  }
                  case SHAPE_ROUND_RECTANGLE:
                  {
                       Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
                       c.x = c.x + ROUND_RECTANGLE_OFFSET_X;
                       c.y = c.y + ROUND_RECTANGLE_OFFSET_Y;

                       //c.x = prevX;
                       //c.y = prevY;


                       shapesArr[upgradedCell] = new drawRoundRectangle(SHAPE_ROUND_RECTANGLE, c, new Cell(true, upgradedCell),
                            RECTANGLE_HEIGHT, RECTANGLE_WIDTH, RECTANGLE_ROUND_ANGLE);
                       break;
                  }
                  case SHAPE_PILLAR:
                  {
                       Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
                       c.x = c.x + PILLAR_OFFSET_X;
                       c.y = c.y + PILLAR_OFFSET_Y;
                       
                       //c.x = prevX;
                       //c.y = prevY;

                       
                       shapesArr[upgradedCell] = new drawPillar(SHAPE_PILLAR, c, new Cell(true, upgradedCell), PILLAR_HEIGHT, PILLAR_WIDTH, PILLAR_ROUND_ANGLE);
                       break;
                  }

         }
         
}

int ProjectManager::getMatchRowCounter(int *arr)
{
     int counter = 0;
     for (int  i = 0; i < MAXIMUM_GROUPED_CELLS; i++)
     {
          int temp = arr[i];
          if (arr[i]>=0)
          {
               counter++;
          }
     }
     return counter;
}

void ProjectManager::IsGroupFormedInColumn()
{
     int counter = 1;
     int AllShapesTypes[INITIAL_POPULATED_GRID_CELLS];
     int MatchedShapeTypes[MAXIMUM_GROUPED_CELLS];
     int typeCounter = 0;
     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          AllShapesTypes[i] = shapesArr[i]->getShapeType();
     }
     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          counter = 1;
          typeCounter = 0;
          for (int j = 0; j < MAXIMUM_GROUPED_CELLS; j++)
          {
               MatchedShapeTypes[j] = 0;
          }
          MatchedShapeTypes[typeCounter] = shapesArr[i]->getcellObj()->getcellNo();
          typeCounter++;
          if (AllShapesTypes[i] == AllShapesTypes[i + 6] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i + 6))
          {
               MatchedShapeTypes[typeCounter] = i + 6;
               typeCounter++;
               counter++;
               if (AllShapesTypes[i] == AllShapesTypes[i + 12] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i + 12))
               {
                    MatchedShapeTypes[typeCounter] = i + 12;
                    typeCounter++;
                    counter++;
                    if (AllShapesTypes[i] == AllShapesTypes[i + 18] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i + 18))
                    {
                         MatchedShapeTypes[typeCounter] = i + 18;
                         typeCounter++;
                         counter++;
                    }
               }
          }

          if (AllShapesTypes[i] == AllShapesTypes[i - 6] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i - 6))
          {
               MatchedShapeTypes[typeCounter] = i - 6;
               typeCounter++;
               counter++;
               if (AllShapesTypes[i] == AllShapesTypes[i - 12] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i - 12))
               {
                    MatchedShapeTypes[typeCounter] = i - 12;
                    typeCounter++;
                    counter++;
                    if (AllShapesTypes[i] == AllShapesTypes[i - 18] && gridObj.GetColNumFromCell(i) == gridObj.GetColNumFromCell(i - 18))
                    {
                         MatchedShapeTypes[typeCounter] = i - 18;
                         typeCounter++;
                         counter++;
                    }
               }
          }
          if (counter >= 3)
          {
               for (int j = 0; j < counter; j++)
               {
                    //shapesArr[MatchedShapeTypes[j]]->getcellObj()->setIsOccupied(false);
                    GetShapeForUpgradeCellInColumn(shapesArr[MatchedShapeTypes[j]]->getcellObj()->getcellNo());
               }
               UpdateScore(counter);
          }
     }
}
void ProjectManager::GetShapeForUpgradeCellInColumn(int upgradedCell)
{
     RandomGenerateID = rand() % 5 + 1;

     switch (RandomGenerateID)
     {

     case SHAPE_CIRCLE:
     {
          Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
          c.x = c.x + CIRCLE_OFFSET_X;
          c.y = c.y + CIRCLE_OFFSET_Y;
          shapesArr[upgradedCell] = new Drawcircle(SHAPE_CIRCLE, c, new Cell(true, upgradedCell), CIRCLE_RADIUS);
          break;
     }
     case SHAPE_SQUARE:
     {
          Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
          c.x = c.x + SQUARE_OFFSET_X;
          c.y = c.y + SQUARE_OFFSET_Y;
          shapesArr[upgradedCell] = new drawSquare(SHAPE_SQUARE, c, new Cell(true, upgradedCell), SQUARE_SIZE);
          break;
     }
     case SHAPE_YELLOW_BOX:
     {
          Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
          c.x = c.x + YELLOW_BOX_OFFSET_X;
          c.y = c.y + YELLOW_BOX_OFFSET_Y;

          shapesArr[upgradedCell] = new drawYellowBox(SHAPE_YELLOW_BOX, c, new Cell(true, upgradedCell), YELLOW_BOX_SIZE);
          break;
     }
     case SHAPE_ROUND_RECTANGLE:
     {
          Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
          c.x = c.x + ROUND_RECTANGLE_OFFSET_X;
          c.y = c.y + ROUND_RECTANGLE_OFFSET_Y;
          shapesArr[upgradedCell] = new drawRoundRectangle(SHAPE_ROUND_RECTANGLE, c, new Cell(true, upgradedCell),
               RECTANGLE_HEIGHT, RECTANGLE_WIDTH, RECTANGLE_ROUND_ANGLE);
          break;
     }
     case SHAPE_PILLAR:
     {
          Coordinates c = gridObj.ConvertCellNumToCoordinates(upgradedCell);
          c.x = c.x + PILLAR_OFFSET_X;
          c.y = c.y + PILLAR_OFFSET_Y;
          shapesArr[upgradedCell] = new drawPillar(SHAPE_PILLAR, c, new Cell(true, upgradedCell), PILLAR_HEIGHT, PILLAR_WIDTH, PILLAR_ROUND_ANGLE);
          break;
     }

     }

}
void ProjectManager::drawUnfilledRect(int x,int y)
{
     if (hintchk)
     {
          if((x> 295 && x< 625) && (y < 375 && y>50))
          {
               glColor3f(0.0, 0.0, 1.0);
               glLineWidth(30);

               glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

               glBegin(GL_POLYGON);
               glVertex2i(x, y);
               glVertex2i(x + GRID_CELL_SIZE, y);
               glVertex2i(x + GRID_CELL_SIZE, y + GRID_CELL_SIZE);
               glVertex2i(x, y + GRID_CELL_SIZE);
               glEnd();

               glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
          }

     }
     else
     {
          glColor3f(1.0, 0.0, 0.0);
          glLineWidth(30);

          glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

          glBegin(GL_POLYGON);
          glVertex2i(x, y);
          glVertex2i(x + GRID_CELL_SIZE, y);
          glVertex2i(x + GRID_CELL_SIZE, y + GRID_CELL_SIZE);
          glVertex2i(x, y + GRID_CELL_SIZE);
          glEnd();

          glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
     }
        
}

void  ProjectManager::DrawRectangleOnSelectedCell()
{
     int CellXcord, CellYcord;
     if(!hintchk)
     {
          if (FirstSelectedCell > 0)
          {
               CellXcord = gridObj.ConvertCellNumToCoordinates(FirstSelectedCell).x;
               CellYcord = gridObj.ConvertCellNumToCoordinates(FirstSelectedCell).y;
               drawUnfilledRect(CellXcord, CellYcord);
          }
          else if (SecondSelectedCell > 0)
          {
               CellXcord = gridObj.ConvertCellNumToCoordinates(SecondSelectedCell).x;
               CellYcord = gridObj.ConvertCellNumToCoordinates(SecondSelectedCell).y;
               drawUnfilledRect(CellXcord, CellYcord);
          }
          else
          {
               drawUnfilledRect(300, 350);
          }
     }
    
}

void ProjectManager::FirstSelectedCellNumber(int x, int y)
{
     FirstSelectedCell = gridObj.GetCellNumFromCordinates(x, y);
     cout << " first selected cell nmbr is" << FirstSelectedCell << "\n";

     selectedShape = getShapeOfSpecificCell(FirstSelectedCell);

     shapesArr[FirstSelectedCell]->getcellObj()->setIsOccupied(false);

     DrawRectangleOnSelectedCell();

     SecondSelectedCell = -1;

}
void ProjectManager::SecondSelectedCellNumber(int x, int y)
{
     SecondSelectedCell = gridObj.GetCellNumFromCordinates(x, y);
     cout << " Second selected cell nmbr is" << SecondSelectedCell << "\n";
          
     isValidMove =  checkValidMove();

     if (isValidMove)
     {
          SwappingSelectedCells();
     }
     else
     {
          shapesArr[FirstSelectedCell]->getcellObj()->setIsOccupied(true);
     }
     FirstSelectedCell = -1;

}
void ProjectManager::SwappingSelectedCells()
{
     Shapes* tempShape = getShapeOfSpecificCell(FirstSelectedCell);  
     shapesArr[FirstSelectedCell] = getShapeOfSpecificCell(SecondSelectedCell);
     shapesArr[FirstSelectedCell]->getCoordObj()->x = tempShape->getCoordObj()->x;
     shapesArr[FirstSelectedCell]->getCoordObj()->y = tempShape->getCoordObj()->y;
     shapesArr[SecondSelectedCell] = tempShape;
     shapesArr[SecondSelectedCell]->getCoordObj()->x = getShapeOfSpecificCell(SecondSelectedCell)->getCoordObj()->x;
     shapesArr[SecondSelectedCell]->getCoordObj()->y = getShapeOfSpecificCell(SecondSelectedCell)->getCoordObj()->y;
     AddOffsetToShapeOfSpecificCell(SecondSelectedCell);
     AddOffsetToShapeOfSpecificCell(FirstSelectedCell);
     
}


Shapes* ProjectManager::getShapeOfSpecificCell(int cellNo)
{    
    
     switch (shapesArr[cellNo]->getShapeType())
     {

          case SHAPE_CIRCLE:
          {
               Coordinates c = gridObj.ConvertCellNumToCoordinates(cellNo);
               return new Drawcircle(SHAPE_CIRCLE, c, new Cell(true, cellNo), CIRCLE_RADIUS);
               break;
          }
          case SHAPE_SQUARE:
          {
               Coordinates c = gridObj.ConvertCellNumToCoordinates(cellNo);
               return new drawSquare(SHAPE_SQUARE, c, new Cell(true, cellNo), SQUARE_SIZE);
               break;
          }
          case SHAPE_YELLOW_BOX:
          {
              /* Coordinates c = gridObj.ConvertCellNumToCoordinates(cellNo);

               int  x_cord1 = c.x + TRIANGLE_OFFSET_X1;
               int  y_cord1 = c.y + TRIANGLE_OFFSET_Y1;
               int  x_cord2 = c.x + TRIANGLE_OFFSET_X2;
               int  y_cord2 = c.y + TRIANGLE_OFFSET_Y2;
               int  x_cord3 = c.x + TRIANGLE_OFFSET_X3;
               int  y_cord3 = c.y + TRIANGLE_OFFSET_Y3;
*/

               Coordinates c = gridObj.ConvertCellNumToCoordinates(cellNo);
               return new drawYellowBox(SHAPE_YELLOW_BOX, c, new Cell(true, cellNo), YELLOW_BOX_SIZE);
               break;
          }
          case SHAPE_ROUND_RECTANGLE:
          {
               Coordinates c = gridObj.ConvertCellNumToCoordinates(cellNo);
               return new drawRoundRectangle(SHAPE_ROUND_RECTANGLE, c, new Cell(true, cellNo),
                    RECTANGLE_HEIGHT, RECTANGLE_WIDTH, RECTANGLE_ROUND_ANGLE);
               break;
          }
          case SHAPE_PILLAR:
          {
               Coordinates c = gridObj.ConvertCellNumToCoordinates(cellNo);
               return new drawPillar(SHAPE_PILLAR, c, new Cell(true, cellNo), PILLAR_HEIGHT, PILLAR_WIDTH, PILLAR_ROUND_ANGLE);
               break;
          }

     }

}


void ProjectManager::AddOffsetToShapeOfSpecificCell(int cellNo)
{

     switch (shapesArr[cellNo]->getShapeType())
     {

     case SHAPE_CIRCLE:
     {
          shapesArr[cellNo]->getCoordObj()->x = shapesArr[cellNo]->getCoordObj()->x + CIRCLE_OFFSET_X;
          shapesArr[cellNo]->getCoordObj()->y = shapesArr[cellNo]->getCoordObj()->y + CIRCLE_OFFSET_Y;
          break;
     }
     case SHAPE_SQUARE:
     {
         
          shapesArr[cellNo]->getCoordObj()->x = shapesArr[cellNo]->getCoordObj()->x + SQUARE_OFFSET_X;
          shapesArr[cellNo]->getCoordObj()->y = shapesArr[cellNo]->getCoordObj()->y + SQUARE_OFFSET_Y;
          break;
     }
     case SHAPE_YELLOW_BOX:
     {
         /* Coordinates c = gridObj.ConvertCellNumToCoordinates(cellNo);

          int  x_cord1 = c.x + TRIANGLE_OFFSET_X1;
          int  y_cord1 = c.y + TRIANGLE_OFFSET_Y1;
          int  x_cord2 = c.x + TRIANGLE_OFFSET_X2;
          int  y_cord2 = c.y + TRIANGLE_OFFSET_Y2;
          int  x_cord3 = c.x + TRIANGLE_OFFSET_X3;
          int  y_cord3 = c.y + TRIANGLE_OFFSET_Y3;
          break;*/
          shapesArr[cellNo]->getCoordObj()->x = shapesArr[cellNo]->getCoordObj()->x + YELLOW_BOX_OFFSET_X;
          shapesArr[cellNo]->getCoordObj()->y = shapesArr[cellNo]->getCoordObj()->y + YELLOW_BOX_OFFSET_Y;
          break;
     }
     case SHAPE_ROUND_RECTANGLE:
     {
         
          shapesArr[cellNo]->getCoordObj()->x = shapesArr[cellNo]->getCoordObj()->x + ROUND_RECTANGLE_OFFSET_X;
          shapesArr[cellNo]->getCoordObj()->y = shapesArr[cellNo]->getCoordObj()->y + ROUND_RECTANGLE_OFFSET_Y;
          break;
     }
     case SHAPE_PILLAR:
     {
        
          shapesArr[cellNo]->getCoordObj()->x = shapesArr[cellNo]->getCoordObj()->x +PILLAR_OFFSET_X;
          shapesArr[cellNo]->getCoordObj()->y = shapesArr[cellNo]->getCoordObj()->y + PILLAR_OFFSET_Y;
          break;
     }

     }

}

bool ProjectManager::checkValidMove()
{  
     int AllShapesTypes[INITIAL_POPULATED_GRID_CELLS];
     for (int i = 0; i < INITIAL_POPULATED_GRID_CELLS; i++)
     {
          AllShapesTypes[i] = shapesArr[i]->getShapeType();
     }
     if (
          SecondSelectedCell == FirstSelectedCell + 1 ||
          SecondSelectedCell == FirstSelectedCell - 1 ||
          SecondSelectedCell == FirstSelectedCell + GRID_NUMBER_OF_ROWS ||
          SecondSelectedCell == FirstSelectedCell - GRID_NUMBER_OF_ROWS
          )
     {
          if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell-1] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell-2])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 1] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 2])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell - 6] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell - 12])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 6] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 12])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell  -12] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell -18])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 12] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 18])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell -2] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell +1])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell - 1] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 2])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell -12] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell +6])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell - 6] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 12])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell - 1] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 1])
          {
               isValidMove = true;
               return isValidMove;
          }
          else if (AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell - 6] &&
               AllShapesTypes[FirstSelectedCell] == AllShapesTypes[SecondSelectedCell + 6])
          {
               isValidMove = true;
               return isValidMove;
          }
          else
          {
               isValidMove = false;
          }
         
     }   
     else
     {
          isValidMove = false;
     }
     return isValidMove;
}
void ProjectManager::DisplayProgressBar()

{
     if (modeObj.getNormalMode())
     {
          
          if (ProgressLineFinalXCord >=1000)
          {
               LevelUpgrade=true;
               PlaySound(NULL, 0, 0);
               if (isSoundON)
               {
                    PlaySound(TEXT("Celebration.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
               }
               DrawString(400,500, "You Won", colors[WHITE]);
               ScreenObj.setLevelNmbr(ScreenObj.getLevelNmbr()+1);
               CalculateTotalScoreOfLevel();
               ProgressLineInitialXCord = 500;
               ProgressLineFinalXCord = 500;
               ScreenObj.setScore(0);
          }
          else
          {
               DrawLine(ProgressLineInitialXCord, 545, ProgressLineFinalXCord, 545, 50, colors[RED]);
          }
          
     }
     if (modeObj.getTimeTrialMode())
     {


     }
     //DrawLine(500, 545,ProgressLineInitialXCord, 545, 50, colors[RED]);//between line
     //ProgressLineInitialXCord = ProgressLineInitialXCord + 3;
     //cout << "DisplayProgressBar Called" << endl;
}

ProjectManager::~ProjectManager()
{
}


