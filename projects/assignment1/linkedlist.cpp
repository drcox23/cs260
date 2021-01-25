// Doug Cox
// CS260
// implementation file for linkedlist for site_survey program

#include "linkedlist.h"

using namespace std;

void LinkedList::addToList(int sector, int exposure, int speed)
{
  SurveyData *dataAdd = new SurveyData(sector, exposure, speed);

  Node *newNode = new Node;
  newNode->data = dataAdd;
  newNode->nextSector = NULL;
  newNode->nextExposure = NULL;
  newNode->nextSpeed = NULL;

  // *** Insert for sectorHead ***
  if (!sectorHead)
  {
    sectorHead = newNode;
    return;
  }

  Node *current = sectorHead;
  Node *previous = NULL;

  while (current)
  {
    if (current->data->getSector() > dataAdd->getSector())
    {
      newNode->nextSector = current;

      if (!previous)
      {
        sectorHead = newNode;
      }
      else
      {
        previous->nextSector = newNode;
      }
      return;
    }
    previous = current;
    current = current->nextSector;
  }
  previous->nextSector = newNode;

  // *** Insert for exposureHead ***
  if (!exposureHead)
  {
    exposureHead = newNode;
    return;
  }

  current = exposureHead;
  previous = NULL;
  while (current)
  {
    if (current->data->getExposure() > dataAdd->getExposure())
    {
      newNode->nextExposure = current;

      if (!previous)
      {
        exposureHead = newNode;
      }
      else
      {
        previous->nextExposure = newNode;
      }
      return;
    }
    previous = current;
    current = current->nextExposure;
  }
  previous->nextExposure = newNode;

  // ***Insert for speedHead ***
  if (!speedHead)
  {
    speedHead = newNode;
    return;
  }
  current = speedHead;
  previous = NULL;
  while (current)
  {
    if (current->data->getSpeed() > dataAdd->getSpeed())
    {
      newNode->nextSpeed = current;

      if (!previous)
      {
        speedHead = newNode;
      }
      else
      {
        previous->nextSpeed = newNode;
      }
      return;
    }
    previous = current;
    current = current->nextSpeed;
  }
  previous->nextSpeed = newNode;
}

void LinkedList::print()
{
  //***Sector Print***
  cout << "---------------------------------------------------------------------- "
       << "\nData values" << endl
       << "----------------------------------------------------------------------" << endl;
  cout
      << "Data by Sector" << endl;

  Node *secList = sectorHead;

  while (secList)
  {
    cout << "Sector: #" << secList->data->getSector() << " " << secList->data->getExposure() << "\% exposure, " << secList->data->getSpeed() << " km/hr windspeed" << endl;
    secList = secList->nextSector;
  }

  //***Exposure Print***
  cout << "Data by Exposure" << endl;

  Node *expList = exposureHead;
  while (expList)
  {
    cout << "Sector: #" << expList->data->getSector() << " " << expList->data->getExposure() << "\% exposure, " << expList->data->getSpeed() << " km/hr windspeed" << endl;
    expList = expList->nextExposure;
  }

  //***Speed Print***
  cout << "Data by Speed" << endl;

  Node *spdList = speedHead;

  while (spdList)
  {
    cout << "Sector: #" << spdList->data->getSector() << " " << spdList->data->getExposure() << "\% exposure, " << spdList->data->getSpeed() << " km/hr windspeed" << endl;
    spdList = spdList->nextSpeed;
  }

  cout << "----------------------------------------------------------------------" << endl
       << "Averages per Sector" << endl
       << "----------------------------------------------------------------------" << endl;

  Node *currSec = sectorHead;

  for (int i = 0; i < sectorHead->data->getSector(); i++)
  {
    cout << "Sector: #" << i << " --no data--" << endl;
  }

  while (currSec)
  {
    int sectorCheck = currSec->data->getSector();
    int exposureSum = 0;
    int speedSum = 0;
    int sectorCount = 0;

    while (currSec && currSec->data->getSector() == sectorCheck)
    {
      exposureSum += currSec->data->getExposure();
      speedSum += currSec->data->getSpeed();
      sectorCount++;

      currSec = currSec->nextSector;
    }
    cout << "Sector: #" << sectorCheck << " " << (exposureSum / sectorCount) << "\% exposure, " << (speedSum / sectorCount) << " km/hr windspeed" << endl;

    if (currSec)
    {
      for (int i = 1; i < (currSec->data->getSector() - sectorCheck); i++)
      {
        cout << "Sector: #" << sectorCheck + i << " --no data--" << endl;
      }
    }
  }

  cout << "----------------------------------------------------------------------" << endl
       << "Histogram data for exposure" << endl
       << "----------------------------------------------------------------------" << endl;

  Node *currExp = exposureHead;

  for (int i = 1; i < exposureHead->data->getExposure(); i++)
  {
    cout << i << ", " << 0 << endl;
  }

  while (currExp)
  {
    int expCheck = currExp->data->getExposure();
    int exposureCount = 0;

    while (currExp && currExp->data->getExposure() == expCheck)
    {
      exposureCount++;
      currExp = currExp->nextExposure;
    }
    cout << expCheck << ", " << exposureCount << endl;

    if (currExp)
    {
      for (int i = 1; i < (currExp->data->getExposure() - expCheck); i++)
      {
        cout << expCheck + i << ", " << 0 << endl;
      }
    }
  }

  cout << "----------------------------------------------------------------------" << endl
       << "Histogram data for speed" << endl
       << "----------------------------------------------------------------------" << endl;

  Node *currSpd = speedHead;

  for (int i = 1; i < currSpd->data->getSpeed(); i++)
  {
    cout << i << ", " << 0 << endl;
  }

  while (currSpd)
  {
    int spdCheck = currSpd->data->getSpeed();
    int speedCount = 0;

    while (currSpd && currSpd->data->getSpeed() == spdCheck)
    {
      speedCount++;
      currSpd = currSpd->nextSpeed;
    }
    cout << spdCheck << ", " << speedCount << endl;

    if (currSpd)
    {
      for (int i = 1; i < (currSpd->data->getSpeed() - spdCheck); i++)
      {
        cout << spdCheck + i << ", " << 0 << endl;
      }
    }
  }
}

bool LinkedList::sectorContains(int sectorCheck)
{
  Node *previous = NULL;
  Node *current = sectorHead;

  if (current && current->data->getSector() == sectorCheck)
  {
    return true;
  }

  while (current && current->data->getSector() != sectorCheck)
  {
    if (current->data->getSector() == sectorCheck)
    {
      return true;
    }
    previous = current;
    current = current->nextSector;
  }
  return false;
}

void LinkedList::sectorRemove(int remSector)
{
  while (sectorContains(remSector))
  {
    Node *current = sectorHead;
    Node *previous = NULL;
    while (current && current->data->getSector() == remSector)
    {
      if (!previous)
      {
        sectorHead = sectorHead->nextSector;
      }
      previous->nextSector = current->nextSector;
      previous->nextExposure = current->nextExposure;
      previous->nextSpeed = current->nextSpeed;
      delete current;
    }
    previous = current;
    current = current->nextSector;
  }
}

LinkedList::LinkedList()
{
  sectorHead = NULL;
  exposureHead = NULL;
  speedHead = NULL;
}

LinkedList::~LinkedList()
{
  /*
  while (sectorHead)
  {
    Node *tempSec = sectorHead->nextSector;
    delete sectorHead;
    sectorHead = tempSec;
  }

  while (exposureHead)
  {
    Node *tempSec = exposureHead->nextExposure;
    delete exposureHead;
    exposureHead = tempSec;
  }

  while (speedHead)
  {
    Node *tempSec = speedHead->nextSpeed;
    delete speedHead;
    speedHead = tempSec;
  }
  */

  Node *curr = NULL;
  while (sectorHead != NULL)
  {
    curr = sectorHead;
    sectorHead = curr->nextSector;
    delete curr->data;
    delete curr;
  }

  Node *currExp = NULL;
  while (exposureHead != NULL)
  {
    currExp = exposureHead;
    exposureHead = currExp->nextExposure;
    delete currExp->data;
    delete currExp;
  }

  Node *currSpeed = NULL;
  while (speedHead != NULL)
  {
    currSpeed = speedHead;
    speedHead = currSpeed->nextSpeed;
    delete currSpeed->data;
    delete currSpeed;
  }
}

LinkedList::LinkedList(const LinkedList &cpy)
{
  sectorHead = cpy.sectorHead;
  exposureHead = cpy.exposureHead;
  speedHead = cpy.speedHead;
}

const LinkedList LinkedList::operator=(const LinkedList &cpy)
{
  if (this != &cpy)
  {
    //delete sectorHead;
    sectorHead = cpy.sectorHead;

    //delete exposureHead;
    exposureHead = cpy.exposureHead;

    //delete speedHead;
    speedHead = cpy.speedHead;
  }
  return *this; //return this object
}
