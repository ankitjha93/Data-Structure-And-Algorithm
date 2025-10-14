#include<bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<string, int> m;
  m["gfg"] = 20;
  m["ide"] = 30;

  m.insert({"courses", 15});

  for(auto x : m){
    cout<<x.first<<" "<<x.second<<endl;
  }

  if(m.find("ide") != m.end()){
    cout<<"Found"<<endl;
  }else{
    cout<<"Not Found"<<endl;
  }
  
  for(auto it = m.begin(); it != m.end(); it++){
      cout<<it->first<<" "<<it->second<<endl;
  }

  auto it = m.find("ide");
  if(it != m.end()){
    cout<<(it->second);
  }

  if(m.count("ide") > 0){
     cout<<"Found";
  }else{
    cout<<"Not Found";
  }

  return 0;
}


/*

Time Complexities

  begin()
  end()         ------- O(1) in worst case
  size()
  empty()


  count()
  find()
  erase(key)    ----- O(1) on average
  insert()
  []
  at
*/