// Doug Cox
// CS260
// implementation file for datalogger for site_survey

#include "datalogger.h"

using namespace std;

void datalogger::addData(int sector, int exposure, int speed)
{
  list.addToList(sector, exposure, speed);
}

void datalogger::removeSector(int)
{
  //tbd
  cout << "removeSector here" << endl;
}

bool datalogger::containsSector(int)
{
  return false;
}

void datalogger::printReport()
{
  list.print();
}

void datalogger::printSectorList()
{
  //tbd
  cout << "printSectorList here" << endl;
}
