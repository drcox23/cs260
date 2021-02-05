#include "linkedlist.h"

void LinkedList::addToList(int sectorNum, structure_type type)
{
  event *eventData = new event(sectorNum, type);

  Node *newNode = new Node;
  newNode->data = eventData;
  newNode->next = NULL;

  if (!head)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    head->next = head;
    head = newNode;
  }
}

bool LinkedList::takeFromBack()
{
  if (!tail)
  {
    cout << "list is empty" << endl;
    return false;
  }
  cout << "tail sectorNum test" << tail->data->getSectorNum() << endl;
  return true;
}

LinkedList::LinkedList()
{
  //tbd;
}

LinkedList::~LinkedList()
{
  //tbd;
}

LinkedList::LinkedList(const LinkedList &cpy)
{
  head = cpy.head;
  tail = cpy.tail;
}

const LinkedList LinkedList::operator=(const LinkedList &cpy)
{
  if (this != &cpy)
  {
    head = cpy.head;

    tail = cpy.tail;
  }
  return *this; //return this object
}