#include "event.h"

using namespace std;
struct Node
{
  event *data;
  Node *next;
};

class LinkedList
{
public:
  LinkedList();
  ~LinkedList();
  LinkedList(const LinkedList &cpy);
  const LinkedList operator=(const LinkedList &cpy);

  void addToList(int, structure_type);
  bool takeFromBack(int);

  int currentSect;

private:
  Node *head;
  Node *tail;
};