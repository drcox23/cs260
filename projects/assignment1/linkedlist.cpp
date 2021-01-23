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
  newNode->next = NULL;

  // ***Insert for sectorHead ***
  if (!sectorHead)
  {
    sectorHead = newNode;
    return;
  }

  Node *current = sectorHead;
  Node *previous = NULL;

  while (current)
  {
    if (current->data->getSector() > newNode->data->getSector())
    {
      newNode->next = current;

      if (!previous)
      {
        sectorHead = newNode;
      }
      else
      {
        previous->next = newNode;
      }
      return;
    }
    previous = current;
    current = current->next;
  }
  previous->next = newNode;

  /*
  // *** Insert for exposureHead ***
  if (!exposureHead)
  {
    exposureHead = newNode;
    return;
  }

  Node *expCurrent = exposureHead;
  Node *expPrevious = NULL;

  while (expCurrent)
  {
    if (expCurrent->data->getSector() > newNode->data->getSector())
    {
      newNode->next = expCurrent;

      if (!expPrevious)
      {
        expCurrent = newNode;
      }
      else
      {
        expPrevious->next = newNode;
      }
      return;
    }
    expPrevious = expCurrent;
    expCurrent = expCurrent->next;
  }
  expPrevious->next = newNode;
*/
  /*
  // ***Insert for speedHead ***
  if (!sectorHead)
  {
    sectorHead = newNode;
    return;
  }

  Node *current = sectorHead;
  Node *previous = NULL;

  while (current)
  {
    if (current->data->getSector() > newNode->data->getSector())
    {
      newNode->next = current;

      if (!previous)
      {
        sectorHead = newNode;
      }
      else
      {
        previous->next = newNode;
      }
      return;
    }
    previous = current;
    current = current->next;
  }
  previous->next = newNode;
  */
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
    secList = secList->next;
  }

  /*
  //***Exposure Print***
  cout << "Data by Exposure" << endl;

  Node *expList = exposureHead;

  while (expList)
  {
    cout << "Sector: #" << expList->data->getSector() << " " << expList->data->getExposure() << "\% exposure, " << expList->data->getSpeed() << " km/hr windspeed" << endl;
    expList = expList->next;
  }
  /*
  /*
  //***Speed Print***
  cout << "Data by Speed" << endl;

  Node *spdList = speedHead;

  while (spdList)
  {
    cout << "Sector: #" << spdList->data->getSector() << " " << spdList->data->getExposure() << "\% exposure, " << spdList->data->getSpeed() << " km/hr windspeed" << endl;
    spdList = spdList->next;
  }
  */
}

LinkedList::LinkedList()
{
  sectorHead = NULL;
  exposureHead = NULL;
  speedHead = NULL;
  /*
  sectorHead = new Node;
  sectorHead->next = NULL;

  exposureHead = new Node;
  exposureHead->next = NULL;

  speedHead = new Node;
  speedHead->next = NULL;
  */
}

LinkedList::~LinkedList()
{

  while (sectorHead)
  {
    Node *tempSec = sectorHead->next;
    delete sectorHead;
    sectorHead = tempSec;
  }

  while (exposureHead)
  {
    Node *tempSec = exposureHead->next;
    delete exposureHead;
    exposureHead = tempSec;
  }

  while (speedHead)
  {
    Node *tempSec = speedHead->next;
    delete speedHead;
    speedHead = tempSec;
  }

  /*
  while (exposureHead != NULL)
  {
    currExp = exposureHead;
    exposureHead = currExp->next;
    delete currExp->data;
    delete currExp;
  }

  while (speedHead != NULL)
  {
    currSpeed = speedHead;
    speedHead = currSpeed->next;
    delete currSpeed->data;
    delete currSpeed;
  }
  */
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
