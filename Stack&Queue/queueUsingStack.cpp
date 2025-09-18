#include <bits/stdc++.h>

using namespace std;

class Q
{
  stack<int> s1, s2;

  // void push(x)
  // {
  //   while (s1.size())
  //   {
  //     s2.push(s1.top());

  //     s1.pop();
  //   }

  //   s1.push(x);

  //   while (s2.size())
  //   {
  //     s1.push(s2.top());
  //     s2.pop();
  //   }
  // }

  // int top()
  // {
  //   s1.top();
  // }

  // int pop()
  // {
  //   s1.pop();
  // }

  // optimize

  void push(x)
  {
    s1.push(x);
  }

  int pop()
  {
    if (s2.size() != 0)
      s2.pop();
    else
    {
      while (s1.size())
      {
        s2.push(s1.top())
            s1.pop();

        s2.pop();
      }
    }
    }

  int top()
  {
    if (s2.empty() != 0)
      return s2.top();
  }
  else
  {
    while (s1.size())
    {
      s2.push(s1.top());
      s1.pop();
    }
    return s2.top();
  }
};

int main()
{
}