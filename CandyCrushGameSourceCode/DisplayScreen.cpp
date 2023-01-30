#include "DisplayScreen.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;



DisplayScreen::DisplayScreen()
{
     playerName = " ";
     LevelNmbr = 1;
     score = 0;
}
string DisplayScreen::getPlayerName()
{
     return playerName;
}
void DisplayScreen::setPlayerName(string x)
{
      playerName=x;
}
int DisplayScreen::getLevelNmbr()
{
     return LevelNmbr;
}

void DisplayScreen::setLevelNmbr(int x)
{
     LevelNmbr = x;
}
int DisplayScreen::getScore()
{
     return score;
}

void DisplayScreen::setScore(int x)
{
     score = x;
}
DisplayScreen::~DisplayScreen()
{
}