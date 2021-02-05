#include "builder.h"

#include <iostream>

void builder::setBuilderNum(int xbuilderNum)
{
  builderNum = xbuilderNum;
}

void builder::addRequest(int sectorNum, structure_type type)
{
  //tbd
  list.addToList(sectorNum, type);
}

bool builder::doCycle()
{
  if (!list.takeFromBack())
  {
    return false;
  }
  else
  {
    return false;
  }
}

void builder::returnHome()
{
  cout << "yet to implement" << endl;
}