#include<bits/stdc++.h>
using namespace std;



int main(){
  multimap<int, int> mp;
    mp.insert({10,5});
    mp.insert({50, 1});
    mp.insert({20,3});
    mp.insert({20,2});

    // auto it1 = mp.lower_bound(20),
    //      it2 = mp.upper_bound(20);


    //      cout<<(*it1).first<<endl;
    //      cout<<(*it2).first<<endl;



    auto it = mp.equal_range(20);
    for(auto itr = it.first; itr != it.second; itr++){
         cout<<itr->first<<" "
           <<itr->second<<endl;
    }
         return 0;






//   mp.insert({10,20});
//   mp.insert({5,50});
//   mp.insert({10, 25});

//   cout<<mp.count(10)<<endl;
//   mp.erase(10);
//   cout<<mp.count(10);

  return 0;
}