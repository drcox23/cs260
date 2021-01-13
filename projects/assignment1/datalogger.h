// Doug Cox
// CS260
// header file for datalogger for site_survey

#include "linkedlist.h"

using namespace std;

class DataLogger
{
public:
  void addData();
  void removeSector();
  void containsSector();
  void printReport();
  void printSectorList();
};
