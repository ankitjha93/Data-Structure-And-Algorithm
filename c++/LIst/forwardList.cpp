#include<bits/stdc++.h>
using namespace std;



// int main(){
//   forward_list<int> l = {10,15,20};
//   l.push_front(5);
//   l.push_front(3);
//   l.pop_front();

//   for(int x : l){
//     cout<<x<<" ";
//   }
//   return 0;
// }


// int main(){

//     forward_list<int> l;
//     l.assign(5,10);  //five times 10
//     l.assign({10,20,30,10});
//     l.remove(10);
//     forward_list<int> l2; l2.assign(l.begin(), l.end());
//     for(auto it = l.begin(); it != l.end(); it++){
//         cout<<(*it)<<" ";
//     }
//     return 0;
// }


// more functions of forward_list

int main(){
    forward_list<int> l1 = {15,20,30};
    forward_list<int> l2 = {20,30};
    l1.empty();
    l1.clear();
    l1.reverse();
    l1.merge(l2);
    l1.sort();
    auto it = l1.insert_after(l1.begin(), 10);
    it = l1.insert_after(it, {2,3,53});
    it = l1.emplace_after(it, 40);
    it = l1.erase_after(it, l1.end());

    for(auto x : l1){
    cout<<x<<" ";
    }
    return 0;
}

// Time Complexities

// insert_after() -> O(1) for one item & O(m) for m items
// erase_after() - same
// emplace_after() -
// push_front() - O(1)
// pop_front() - O(1)
// reverse() - O(n)
// sort() - O(nlogn)
// remove() - O(n)
// assign() - O(1) for one item & O(m) for m items

// forward_list is a singly linked list
