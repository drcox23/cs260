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

  //cout << "check this function " << newNode->data->getSector() << endl;

  if (!sectorHead)
  {
    sectorHead = newNode;
    cout << "This is a check" << endl;
    return;
  }

  Node *current = sectorHead;
  Node *previous = NULL;

  //cout << "This is current" << current->data->getSector();

  while (current)
  {
    if (current->data->getSector() > newNode->data->getSector())
    {
      newNode->next = current;
      //current = newNode;
      //cout << current->data->getSector() << " & " << current->data->getExposure();

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
}

void LinkedList::print()
{
  cout << "Data by Sector" << endl;

  Node *secList = sectorHead;

  while (secList)
  {
    cout << "Sector: #" << secList->data->getSector() << " " << secList->data->getExposure() << "\% exposure, " << secList->data->getSpeed() << " km/hr windspeed" << endl;
    secList = secList->next;
  }
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
