// Doug Cox
// CS 260
// header file for linked list class for survey-site program

#include <iostream>
#include "surveydata.h"

using namespace std;

struct Node
{
  SurveyData *data;
  Node *next;
};

class LinkedList
{
public:
  void addToList(int, int, int);
  void print();

  ~LinkedList(); //deconstructor

private:
  Node *sectorHead;
  Node *exposureHead;
  Node *speedHead;
};
