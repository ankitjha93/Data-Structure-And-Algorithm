#include <bits/stdc++.h>

using namespace std;

class QueueLinkedList
{
  // public:
  Node *start, end;
  size = 0;

  void push(x)
  {
    Node *temp = new Node(x);
    if (start == NULL)
    {
      start = end = temp;
    }
    else
    {
      end->next = temp;
      size += 1;
    }
  }

  int pop()
  {
    if (start == NULL)
    {
      temp = start;
      start = start->next;
      delete temp;
      size -= 1;
    }
  }

  int top()
  {
    if (start == NULL)
    {
      return start->val;
    }
  }
};

int main()
{
}