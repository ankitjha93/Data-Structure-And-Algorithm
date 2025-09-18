#include<bits/stdc++.h>
using namespace std;

// list is a doubly linked list
// int main(){
//     list<int> l;
//     l.push_back(10);
//     l.push_back(20);
//     l.push_front(5);

//     for(auto x : l){
//         cout<<x<<" ";
//     }
//     return 0;
// }

// int main(){
//     list<int> l = {10,2,5,20};
//     l.pop_front();
//     l.pop_back();
//     for(auto it = l.begin(); it != l.end(); it++){
//        cout<<(*it)<<" ";
//     }
//     return 0;
// }

// int main(){
//     list<int> l = {10,20,30};
//     auto it = l.begin();
//     it++;
//     it = l.insert(it, 15);
//     l.insert(it, 2, 7);
//     cout<<l.front()<<" "<<l.back();
//     cout<<" "<<l.size();
//     return 0;
// }

int main(){
    list<int> l = {10,20,30,40,20, 40};
    auto it = l.begin();
    it = l.erase(it);
    l.remove(40);
    for(auto x: l){
        cout<<x<<" ";
    }
    return 0;
}

// Time Complexities


// O(1)

// front()
// back()
// size()
// begin()
// end()

// erase(it)
// push_front()
// pop_front()
// push_back()
// pop_back()



// O(n)

// reverse()
// unique() //remove consecutive duplicate elements
// remove()

// O(nlogn)

// sort()