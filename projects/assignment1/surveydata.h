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

  SurveyData();              // default constructor
  SurveyData(int, int, int); // constructor with member parameters
  ~SurveyData();             // deconstructor

  SurveyData(const SurveyData &cpy);

  const SurveyData operator=(const SurveyData &cpy);

private:
  int sector;
  int exposure;
  int speed;
};
