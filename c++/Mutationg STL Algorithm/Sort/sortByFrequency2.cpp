#include<bits/stdc++.h>
using namespace std;

void sortByFreq(int arr[], int n){
      unordered_map<int, int> m;

      for(int i = 0; i < n; i++){
         m[arr[i]]++;
      }

      vector<int> freq[n+1];


    //   No ordering in case of tie

    //   for(auto x : m){
    //      freq[x.second].push_back(x.first);
    //   }
    

    // for ordering in case fo tie


    for(int i = 0; i < n; i++){
         int f = m[arr[i]];
         if(f != -1)
         {
            freq[f].push_back(arr[i]);
            m[f] = -1;
         }
    }
      int index = 0;

      for(int i = n ; i > 0; i++){
         for(int x : freq[i])

           for(int  j = 0; j < i; j++){
             arr[index++] = x;
           }
      }
}

int main(){
   return 0;
}