#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> p1, pair<int, int> p2){

     if(p1.second == p2.second)
       return p1.first < p2.first;

       return p1.second > p2.second;
}

void sortByFreq(int arr[], int n){
     unordered_map<int, int> m;
     for(int i = 0; i < n; i++){
         m[arr[i]]++;

         vector<pair<int, int>> v(m.begin(), m.end());

         sort(v.begin(), v.end(), myCmp);

         int x = 0;
 
         for(auto x : v)
           for(int j = 0; j < x.second; j++){
             arr[i++] = x.first;
           }
     }
}




int main(){
   return 0;
}