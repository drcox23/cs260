#include "stack.h"
#include <fstream>
#include <cassert>

stack::stack() : top(NULL)
{
  //tbd;
}

stack::~stack()
{
  //tbd;
  stackNode *curr = top;
  while (top)
  {
    curr = top->next;
    delete top;
    top = curr;
  }
  top = NULL;
}

stack::stack(const stack &xStack)
{
  if (xStack.top == NULL)
    top = NULL;
  else
  {
    top = new stackNode;
    assert(top != NULL);
    top->data = xStack.top->data;

    stackNode *lastNode = top;
    stackNode *srcnode = xStack.top->next;

    while (srcnode)
    {
      lastNode->next = new stackNode;
      assert(lastNode->next != NULL);
      lastNode = lastNode->next;
      lastNode->data = srcnode->data;

      srcnode = srcnode->next;
    }
    lastNode->next = NULL;
  }
}

const stack &stack::operator=(const stack &xStack)
{
  if (this == &xStack)
    return *this;

  else
  {
    stackNode *curr = top;

    while (top)
    {
      curr = top->next;
      delete top;
      top = curr;
    }

    if (!xStack.top)
      top = NULL;

    else
    {
      top = new stackNode;
      assert(top != NULL);
      top->data = xStack.top->data;

      stackNode *lastNode = top;
      stackNode *srcnode = xStack.top->next;

      while (srcnode)
      {
        lastNode->next = new stackNode;
        assert(lastNode->next);
        lastNode = lastNode->next;
        lastNode->data = srcnode->data;

        srcnode = srcnode->next;
      }
      lastNode->next = NULL;
    }
    return *this;
  }
}

bool stack::push(const event &eData)
{
  stackNode *newNode = new stackNode;
  newNode->data = eData;
  newNode->next = NULL;

  newNode->next = top;
  top = newNode;

  return true;
}

bool stack::pop(event &eData)
{
  bool status = false;

  stackNode *temp;

  if (!isEmpty())
  {
    eData = top->data;
    temp = top;
    top = top->next;
    delete temp;

    status = true;
  }
  return status;
}

bool stack::isEmpty() const
{
  return top == NULL;
}

bool stack::peek(event &eData) const
{
  bool status = false;
  if (!isEmpty())
  {
    eData = top->data;
    status = true;
  }
  return status;
}

/*
ostream &operator<<(ostream &out, stack &stk)
{
  stackNode *curr;

  cout << "Data in the stack: \n " << endl;

  for (curr = stk.top; curr; curr = curr->next)

    cout << '\t' << curr->data << endl;

  return out;
}
*/