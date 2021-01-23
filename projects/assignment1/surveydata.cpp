// Doug Cox
// CS260
// implementation file of surveydata for survey-site program

#include <iostream>
#include "surveydata.h"

using namespace std;

int SurveyData::getSector()
{
  return sector;
}

int SurveyData::getExposure()
{
  return exposure;
}

int SurveyData::getSpeed()
{
  return speed;
}

SurveyData::SurveyData()
{
  sector = -1;
  exposure = -1;
  speed = -1;
}

SurveyData::SurveyData(int xsector, int xexposure, int xspeed)
{
  sector = xsector;
  exposure = xexposure;
  speed = xspeed;
}

SurveyData::SurveyData(const SurveyData &cpy)
{
  sector = cpy.sector;
  exposure = cpy.exposure;
  speed = cpy.speed;
}

SurveyData::~SurveyData()
{
  //tbd
}

const SurveyData SurveyData::operator=(const SurveyData &cpy)
{
  if (this != &cpy)
  {

    sector = cpy.sector;
    exposure = cpy.exposure;
    speed = cpy.speed;
  }
  return *this; //return this object
}
