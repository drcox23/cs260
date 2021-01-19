// Doug Cox
// CS260
// implementation file for linkedlist for site_survey program

#include "linkedlist.h"

using namespace std;

void LinkedList::addToList(int sector, int exposure, int speed)
{
  SurveyData *dataAdd = new SurveyData(sector, exposure, speed);

  //cout << "check this function" << dataAdd->getSector();

  Node *newNode = new Node;
  newNode->data = dataAdd;
  newNode->next = NULL;

  cout << "check this function " << dataAdd->getSector() << endl;

  if (!&sectorHead)
  {
    sectorHead = newNode;
    return;
  }

  /*

  Node *current = sectorHead;
  while (current != NULL)
  {
    if (newNode->data->getSector() < current->data->getSector())
    {
      current->next = current;
      current = newNode;
      return;
    }
  }
  */
}

void LinkedList::print()
{
  cout << "Data by Sector" << endl;
  /*
  Node *secList = sectorHead;
  while (!secList)
  {
    cout << "Sector: #" << secList->data->getSector() << " " << secList->data->getExposure() << "\% exposure, " << secList->data->getSpeed() << " km/hr windspeed" << endl;
  }
  */
}

LinkedList::~LinkedList()
{
  delete sectorHead;
  delete exposureHead;
  delete speedHead;
}