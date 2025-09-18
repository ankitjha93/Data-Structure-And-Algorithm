#include<bits/stdc++.h>
using namespace std;



int main(){
   multiset<int> ms;
   ms.insert(10);
   ms.insert(20);
   ms.insert(10);
   ms.insert(40);

//    for(auto x : ms){
//     cout<<x<<" ";
//    }

   cout<<ms.count(10);

   auto it = ms.lower_bound(20);
   auto it = ms.upper_bound(20);

   cout<<(*it) <<" "<<(*it);

   auto it = ms.equal_range(20);   // pair<multiset<int>::iterator,
                                                   // <multiset<int>::iterator>
   cout<<(*it).first<<" "<<(*it).second;

   return 0;
}