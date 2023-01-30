#pragma once
class Mode
{
private:
     bool NormalMode;
     bool TimetrialMode;
public:
     Mode();
     void setNormalMode(bool);
     bool getNormalMode();
     void setTimeTrialMode(bool);
     bool getTimeTrialMode();
     ~Mode();
};

