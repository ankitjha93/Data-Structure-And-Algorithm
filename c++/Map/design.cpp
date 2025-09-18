#include<bits/stdc++.h>
using namespace std;

map<int, string> m;

void add(int price, string name){
    m[price] = name;      //  -----// O(log n)
}

string find(int price){
    auto res = m.find(price);
    if(res == m.end())    //--------//O(log n)
      return " ";

      else 
       return res->second;
}

void printSorted(){
    for(auto x : m)

      cout<<x.second<<" "   //-----O(n)
         <<x.first<<endl;
}


void pringGreaterSorted(int price){
     auto it = m.upper_bound(price);
     while(it != m.end()){
        cout<<it->second<<" "               //O(n)
           <<it->first<<endl;
           it++;
     }
    }

    void printSmallerSorted(int price){
         auto it1 = m.lower_bound(price);
         for(auto it2 = m.begin(); it2 != it1; it2++){     //O(n)
             cout<<it2->second<<" "
                <<it2->first<<endl;
         }
    }

int main(){

}