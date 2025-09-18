#include<bits/stdc++.h>
using namespace std;



// int main(){
//  deque<int> dq = {10,20,30};
//  dq.push_front(5);
//  dq.push_back(50);
//  for(auto x : dq){
//     cout<<x<<" ";
//  }
//  cout<<dq.front()<<" "<<dq.back();
//  return 0;
// }


int main(){
    deque<int> dq = {10,15,30,5,12};
    auto it = dq.begin();
    it++;

    dq.insert(it,20);
    dq.pop_front();
    dq.pop_back();

    cout<<dq.size();
    return 0;
}

// push_back() - O(1)
// push_front() - O(1)
// pop_front() - O(1)
// pop_back() - O(1)

// insert - O(n)
// delete - O(n)

