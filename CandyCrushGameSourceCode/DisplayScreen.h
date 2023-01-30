#pragma once
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include"AppStructConsts.h"
using namespace std;
class DisplayScreen
{
private:
     string playerName;
     int LevelNmbr;
     int score;
public:
     DisplayScreen();
     string getPlayerName();
     void setPlayerName(string);
     int getLevelNmbr();
     void setLevelNmbr(int);
     int getScore();
     void setScore(int);
     ~DisplayScreen();
};
