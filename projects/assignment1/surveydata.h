// Doug Cox
// CS260
// header file for surveydata for survey site program

#include <iostream>

using namespace std;

class SurveyData
{
public:
  int getSector();
  int getExposure();
  int getSpeed();
  void setSector(int);
  void setExposure(int);
  void setSpeed(int);

  SurveyData();              // default constructor
  SurveyData(int, int, int); // constructor with member parameters
  ~SurveyData();             // deconstructor

private:
  int sector;
  int exposure;
  int speed;
};
