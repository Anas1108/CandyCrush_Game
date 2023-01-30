#pragma once
using namespace std;
class Cell
{
private:
    bool IsOccupied;
    int cellNo;
public:
     Cell();
     Cell(bool is_occupied,int cell_no);
     bool getIsOccupied();
     void setIsOccupied(bool);
     int getcellNo();
     void setcellNo(int);
     ~Cell();
};

