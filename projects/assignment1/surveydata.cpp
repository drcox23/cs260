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
  sector = 0;
  exposure = 0;
  speed = 0;
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