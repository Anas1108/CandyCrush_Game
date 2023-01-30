#include "Cell.h"



Cell::Cell()
{
     IsOccupied=false;
     cellNo=-1;
}

Cell::Cell(bool is_occupied, int cell_no)
{
     IsOccupied = is_occupied;
     cellNo = cell_no;
}
bool Cell::getIsOccupied()
{
     return IsOccupied;
}
void Cell::setIsOccupied(bool x)
{
     IsOccupied = x;
}
int Cell::getcellNo()
{
     return cellNo;
}
void Cell::setcellNo(int x)
{
     cellNo =x;
}
Cell::~Cell()
{
}
