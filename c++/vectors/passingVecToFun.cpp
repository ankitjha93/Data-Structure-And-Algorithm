#include<bits/stdc++.h>

using namespace std;

void func(vector<int> &v){
    v.push_back(10);
    v.push_back(20);
}

int main(){
  vector<int> v = {5,7,8};

  func(v);

  for(auto x : v){
    cout<<x<<" ";
  }
}