#include "linkedlist.h"

void LinkedList::addToList(int sectorNum, structure_type type)
{
  event *eventData = new event(sectorNum, type);

  Node *newNode = new Node;
  newNode->data = eventData;
  newNode->next = NULL;

  if (!head)
  {
    head = tail = newNode;
    return;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }
}

bool LinkedList::takeFromBack(int builderNum)
{
  if (!tail)
  {

    return false;
  }

  if (currentSect == tail->data->getSectorNum())
  {
    cout << "Builder #" << builderNum << ": Building a " << str(tail->data->getStructureType()) << " in sector " << currentSect << endl;

    //take from back, add to stack

    //remove Node
    Node *removeTail = new Node;
    removeTail = tail;

    Node *prevTail = new Node;
    prevTail = head;

    if (head == tail)
    {
      head = NULL;
      tail = NULL;
    }
    else
    {

      while (prevTail->next != tail)
      {
        prevTail = prevTail->next;
      }

      tail = prevTail;
      tail->next = NULL;
    }
    delete removeTail;

    return true;
  }
  else
  {
    cout << "Builder #" << builderNum << ": Moving to sector " << tail->data->getSectorNum() << endl;

    currentSect = tail->data->getSectorNum();
    cout << "Builder #" << builderNum << ": Building a " << str(tail->data->getStructureType()) << " in sector " << currentSect << endl;

    //take from back, add to stack

    //remove Node
    Node *removeTail = new Node;
    removeTail = tail;

    Node *prevTail = new Node;
    prevTail = head;

    if (head == tail)
    {
      head = NULL;
      tail = NULL;
    }
    else
    {

      while (prevTail->next != tail)
      {
        prevTail = prevTail->next;
      }

      tail = prevTail;
      tail->next = NULL;
    }
    delete removeTail;

    return true;
  }
}

LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
}

LinkedList::~LinkedList()
{
  Node *curr = NULL;
  while (head != NULL)
  {
    curr = head;
    head = curr->next;
    delete curr->data;
    delete curr;
  }

  Node *tCurr = NULL;
  while (tail != NULL)
  {
    tCurr = tail;
    tail = tCurr->next;
    delete tCurr->data;
    delete tCurr;
  }
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