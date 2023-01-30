#include "drawGrid.h"
drawGrid::drawGrid()
{
     NoOfrows=GRID_NUMBER_OF_ROWS;
     NoOfcolumns=GRID_NUMBER_OF_COLOMNS;
     gridInitialX_comp= GRID_OFFSET_X;
     gridInitialY_comp= GRID_OFFSET_Y;
}
int drawGrid::getGridInitialX_comp()
{
     return gridInitialX_comp;
}
void drawGrid::setGridInitialX_comp(int x)
{
     gridInitialX_comp = x;
}
int drawGrid::getGridInitialY_comp()
{
     return gridInitialY_comp;
}
void drawGrid::setGridInitialY_comp(int x)
{
     gridInitialY_comp = x;
}
int drawGrid::getNoOfrows()
{
     return NoOfrows;
}
void drawGrid::setNoOfrows(int x)
{
     NoOfrows = x;
}
int drawGrid::getNoOfcolumns()
{
     return NoOfcolumns;
}
void drawGrid::setNoOfcolumns(int x)
{
     NoOfcolumns = x;
}
void drawGrid::DisplayGrid()
{
     float initialXPosition = getGridInitialX_comp();
     float intialYPosition = getGridInitialY_comp();
     for (int row=0; row < NoOfrows; row++)
     {
          for (int column=0; column <NoOfcolumns; column++)
          {
               DrawSquare(getGridInitialX_comp(), getGridInitialY_comp(), GRID_CELL_SIZE,colors[GRID_COLOR]);
               setGridInitialX_comp(getGridInitialX_comp() + (GRID_CELL_SIZE + GRID_PADING));
          }
          setGridInitialX_comp(initialXPosition);
          setGridInitialY_comp(getGridInitialY_comp() - (GRID_CELL_SIZE + GRID_PADING));
     }
}

int drawGrid::GetRowNumFromCell(int cellNo)
{
     return cellNo / NoOfrows;
}

int drawGrid::GetColNumFromCell(int cellNo)
{
     return cellNo % NoOfcolumns;
}

Coordinates drawGrid::ConvertCellNumToCoordinates(int cellNo)
{
     Coordinates tempCoord;
     tempCoord.x = GRID_OFFSET_X + (GetColNumFromCell(cellNo) * (GRID_CELL_SIZE + GRID_PADING));

     tempCoord.y = GRID_OFFSET_Y - (GetRowNumFromCell(cellNo) * (GRID_CELL_SIZE + GRID_PADING));

     return tempCoord;
}
int drawGrid::GetCellNumFromCordinates(int x, int y)
{
     int cellnmbr = 0;
     int initialY=0;
     int initialX=0;
     int counter = 0;
   /*  for (int i = 0; i< TOTAL_GRID_CELLS; i++)
     {
          if ((x > initialX && y > initialY) && (x < (initialX + GRID_CELL_SIZE) && y < (initialY + GRID_CELL_SIZE)))
          {
               cellnmbr = i;
          }
     }*/
     for (int i = 0; i < NoOfrows; i++)
     {
          initialY = getGridInitialY_comp() - (i*(GRID_CELL_SIZE + GRID_PADING));
          for (int j = 0; j < NoOfcolumns; j++)
          {
               initialX = getGridInitialX_comp() + (j*(GRID_CELL_SIZE + GRID_PADING));
               if ((x > (initialX) && y < (initialY + GRID_CELL_SIZE)) && (x < (initialX + GRID_CELL_SIZE) && y>initialY))
               {
                    cellnmbr = counter;
               }
               counter++;
          }
     }
     return cellnmbr;
}

drawGrid::~drawGrid()
{
}
