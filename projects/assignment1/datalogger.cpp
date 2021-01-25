// Doug Cox
// CS260
// implementation file for datalogger for site_survey

#include "datalogger.h"

using namespace std;

void datalogger::addData(int sector, int exposure, int speed)
{
  list.addToList(sector, exposure, speed);
}

void datalogger::removeSector(int remSector)
{
  list.sectorRemove(remSector);
}

bool datalogger::containsSector(int sectorCheck)
{
  return list.sectorContains(sectorCheck);
}

void datalogger::printReport()
{
  list.print();
}

void datalogger::printSectorList()
{
  list.printBadSectors();
}
