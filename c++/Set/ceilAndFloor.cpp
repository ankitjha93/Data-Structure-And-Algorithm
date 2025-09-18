#include<bits/stdc++.h>
using namespace std;


/*

getFloor() = largest value smaller than or equal to x 
getCeil() = smallest value greater than or equal to x
*/


set<int> s;

void Insert(int x){
    s.insert(x);
}


bool Search(int x){
     return (s.find(x) != s.end());
}

void Delete(int x){
     s.erase(x);
}

int getCeiling(int x){
    auto it = s.lower_bound(x);
    if(it == s.end())
     return INT_MAX;

     else *it;
}


int getFloor(int x){
     auto it = s.lower_bound(x);
      if(it == s.begin()){
        if(*it == x) return x;
        else return INT_MIN;
      }else{
        it--
        return *it;
      }
}

int main(){

}