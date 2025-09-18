#include<bits/stdc++.h>
using namespace std;

// int main(){
//    priority_queue<int> pq;

//    priority_queue<int, vector<int>, greater<int>> pq;

//    pq.push(10);
//    pq.push(15);
//    pq.push(5);

//    cout<<pq.size()<<" ";
//    cout<<pq.top()<<" ";

//    while(pq.empty() == false){
//     cout<<pq.top()<<" ";
//     pq.pop();
//    }
//    return 0;

// }


// int main(){
//     int arr[] = {10,5,15};
//     priority_queue<int> pq(arr, arr + 3);   ---->// O(N)

//     while(pq.empty() == false){
//         cout<<pq.top()<<" ";
//         pq.pop();
//     }
// }

/*

push()    -----> O(N)
pop()

empty()
size()     -------> O(1)
top()

*/

struct Person{
   int age;
   float ht;
   Person(int a, float h){
      age = a;
      ht = h;
   }
};


struct myCmp{
    bool operator() (Person const &p1, Person const &p2){
        p1.ht < p2.ht;
    }
};

int main(){
    priority_queue<Person, vector<Person>, myCmp> pq;
}