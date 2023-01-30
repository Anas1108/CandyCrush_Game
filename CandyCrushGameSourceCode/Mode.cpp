#include "Mode.h"
Mode::Mode()
{
     TimetrialMode = false;
     NormalMode = true;
}
void Mode::setNormalMode(bool x)
{
     NormalMode = x;
}
bool Mode::getNormalMode()
{
     return NormalMode;
}
void Mode::setTimeTrialMode(bool x)
{
     TimetrialMode = x;
}
bool Mode::getTimeTrialMode()
{
     return TimetrialMode;
}

Mode::~Mode()
{
}
