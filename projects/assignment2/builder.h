#include <iostream>
#include "linkedlist.h"
#include "stack.h"

using namespace std;

class builder
{
public:
  void setBuilderNum(int);
  void addRequest(int, structure_type);
  bool doCycle();
  void returnHome();

private:
  int builderNum;
  stack newStack;
  LinkedList list;
};
