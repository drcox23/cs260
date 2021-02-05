
using namespace std;

struct stackNode
{
  //event *stackData;

  stackNode *next;
};

class stack
{
public:
  stack();
  ~stack();

private:
  stackNode *top;
};