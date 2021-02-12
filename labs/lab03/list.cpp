#include <iostream>
#include "list.h"

using namespace std;

void reverse(node *head, node *&newHead)
{
  node *first;
  node *rest;

  if (!head)
  {
    return;
  }

  first = head;
  rest = first->next;

  if (!head)
  {
    newHead = first;
    return;
  }

  reverse(rest, newHead);
  rest->next = first;
  first->next = NULL;
}

void removeLast(node *&head)
{

  if (!head)
  {
    return;
  }
}
