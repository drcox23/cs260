#include <iostream>
using namespace std;

int main()
{
  /*int *p;
  int x = 5;
  int y = 7;
  int z = 9;

  p = &x;
  *p = y;
  p = new int;
  *p = z;
  z = z + 2;
  cout << *p << " ";
  cout << x << " " << y << " " << z << endl;
  */

  int x = 5;
  for (int i = 0; i < x; i++)
  {
    cout << i % 2 << " ";
  }

  return 0;
}