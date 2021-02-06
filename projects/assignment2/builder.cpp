#include "builder.h"

#include <iostream>

void builder::setBuilderNum(int xbuilderNum)
{
  builderNum = xbuilderNum;
}

void builder::addRequest(int sectorNum, structure_type type)
{
  cout << "Builder #" << builderNum << ": Received request to build a " << str(type) << " in sector " << sectorNum << endl;
  list.addToList(sectorNum, type);
}

bool builder::doCycle()
{
  if (!list.takeFromBack(builderNum))
  {
    return false;
  }
  else
  {
    return true;
  }
}

void builder::returnHome()
{
  cout << "yet to implement" << endl;
}