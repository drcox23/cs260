#include <iostream>
#include "structuretype.h"

using namespace std;

class event
{
public:
  event();
  event(int, structure_type);
  ~event();

  int getSectorNum();
  structure_type getStructureType();

private:
  int sectorNum;
  structure_type type;
};