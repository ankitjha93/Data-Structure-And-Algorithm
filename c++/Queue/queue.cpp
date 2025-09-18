#include<bits/stdc++.h>
using namespace std;



int main(){
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);

  while (q.empty() == false)
  {
    /* code */
    cout<<q.front()<<" ";
    cout<<q.back()<<endl;
    q.pop();
  }
  

  cout<<q.front()<<" "<<q.back()<<endl;

  q.pop();

  q.size();

    cout<<q.front()<<" "<<q.back()<<endl;


}

/*

push()
pop()
front()    ------> O(1)
back()
empty()
size()

*/



/*
empty()
size()
front()
back()              ---------> list, dequeue
push_back()
pop_front()
*/

/*
queue is a container adapter
*/