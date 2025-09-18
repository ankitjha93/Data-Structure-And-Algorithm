#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int, greater<int>> s; // decreasing
    s.insert(10);
    s.insert(5);
    s.insert(20);

    auto it = s.find(10);
    if(it == s.end()){
        cout<<"not Found";
    }
    cout<<"found";
    

    // for(int x : s){
    //     cout<<x<<" ";
    // }

    for(auto it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }

    return 0;
}

/*
  insert()
  begin()
  end()
  rbegin()
  rend()        
  erase()
  clear()
  find() or count()


  lower_bound()
  upper_bound()


  **Red Black Tree


//  internal working and time complexities

begin(), end()
rbegin(), rend()
cbegin(), cend()   --------  O(1)
size(), empty()

insert(), find()
count(), lower_bound(),       ------> O(logn)
upper_bound(), erase(val)



erase(it) -------------- Amortized        O(1)


// set for user defined data type


struct Test{
int x;
bool.operator<(const Test &t) const{

     return (this->x < t.x);
  }
}


*/