#include <iostream>
#include "list.h"

using namespace std;

void reverse(node *head, node *&newHead)
{
  if (!head)
  {
    return;
  }

  if (!head->next)
  {
    newHead = head;
    return;
  }

  reverse(head->next, newHead);
  head->next->next = head;
  head->next = NULL;
}

void removeLast(node *&head)
{

  if (!head)
  {
    return;
  }

  if (!head->next)
  {
    node *temp = new node;
    temp = head;
    head = head->next;
    delete temp;
  }
  removeLast(head->next);
}
