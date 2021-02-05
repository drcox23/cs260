#include "event.h"

event::event()
{
  sectorNum == -1;
  type == 0;
}

event::event(int xsectorNum, structure_type xtype)
{
  sectorNum = xsectorNum;
  type = xtype;
}

event::~event()
{
  //tbd;
}

int event::getSectorNum()
{
  return sectorNum;
}

structure_type event::getStructureType()
{
  return type;
}