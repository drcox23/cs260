#include "dlist.h"

//put the implmenetation of the required functions here
int count(node *head)
{
  int nodeCount = 0;

  if (!head)
  {
    return nodeCount;
  }

  node *newNode = new node;
  newNode = head;

  if (!newNode->next)
  {
    return nodeCount;
  }
  else
  {
    nodeCount++;
    return count(newNode->next);
  }
}

int removeValue(node *&head, int value)
{
  int nodesRemoved = 0;

  if (!head)
  {
    return nodesRemoved;
  }

  node *newNode = new node;
  newNode = head;

  if (!newNode->next && newNode->data != value)
  {
    return nodesRemoved;
  }
  else if (!newNode->next)
  {
    newNode->previous = NULL;

    delete newNode;
    nodesRemoved++;
    return nodesRemoved;
  }
  else
  {
    if (newNode->data == value)
    {
      node *temp = newNode;
      if (!newNode->previous)
      {
        newNode->next->previous = NULL;
        newNode = newNode->next;
        delete temp;
        nodesRemoved = 1 + removeValue(newNode, value);
      }
      else
      {
        node *prev = newNode->previous;
        prev->next = newNode->next;
        newNode->next->previous = prev;
        delete temp;
        nodesRemoved = 1 + removeValue(prev->next, value);
      }
    }

    else
    {
      nodesRemoved = nodesRemoved + 1;
      return removeValue(newNode->next, value);
    }
  }
}