// Doug Cox
// CS260
// header file for datalogger for site_survey

#include "linkedlist.h"

using namespace std;

class datalogger
{
public:
  void addData(int, int, int);
  void removeSector(int);
  bool containsSector(int);
  void printReport();
  void printSectorList();

private:
  LinkedList *list;
};
