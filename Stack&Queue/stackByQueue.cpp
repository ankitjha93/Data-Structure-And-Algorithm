#include <bits/stdc++.h>

using namespace std;

class st
{
  queue<int> q;

  void push(x)
  {
    s = q.size();
    q.push(x);
    for (int i = 0; i < s; i++)
    {
      q.push(q.top());
      q.pop();
    }
  }

  int pop()
  {
    q.pop();
  }

  int top()
  {
    return q.top();
  }
};

int main()
{
}