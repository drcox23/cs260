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

  if (!list.checktail())
  {
    return false;
  }
  else
  {
    int sectNum = list.getTailSector();
    structure_type infoType = list.getTailStructure();

    event stackData = event(sectNum, infoType);

    newStack.push(stackData);

    list.takeFromBack(builderNum);

    return true;
  }
}

void builder::returnHome()
{
  //cout << "yet to implement" << endl;
  if (!newStack.isEmpty())
  {
    newStack.takeFromTop(builderNum);
  }

  return;
}