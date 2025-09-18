#include <bits/stdc++.h>

using namespace std;

class Stack
{
  int size;
  int *arr;
  int top;

public:
  Stack()
  {
    top = -1;
    size = 1000;
    arr = new int[size];
  }

  void push(int x)
  {
    top = top + 1;
    arr[top] = x;
  }

  int pop()
  {
    int x = arr[top];
    top--;
    return x;
  }

  int Top()
  {
    return arr[top];
  }

  int size()
  {
    return top + 1;
  }
};

int main()
{
}