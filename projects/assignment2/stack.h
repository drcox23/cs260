#include "event.h"
using namespace std;

struct stackNode
{
  event data;
  stackNode *next;
};

class stack
{
public:
  stack();
  stack(const stack &);
  ~stack();

  const stack &operator=(const stack &);

  bool push(const event &);
  bool pop(event &);

  bool peek(event &) const;
  bool isEmpty(void) const;

  //friend ostream &operator<<(ostream &out, stack &);

private:
  stackNode *top;
};