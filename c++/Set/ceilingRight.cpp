#include<bits/stdc++.h>
using namespace std;

void printCeiling(int arr[], int n){
     for(int i = 0; i < n; i++){
        int diff = INT_MAX;
        for(int j = i + 1; j < n; j++){
             if(arr[j] >= arr[i])
               diff = min(diff, arr[j] - arr[i]);

               if(diff == INT_MAX){
                cout<<-1<<" ";
               }else{
                cout<<(arr[i] + diff)<<" ";
               }
        }
     }
}


void printCeilingRight(int arr[], int n){
     set<int> s;
     int res[n];
     for(int i = n-1; i >= 0; i--){
        auto it = s.lower_bound(arr[i]);
        if(it == s.end())
          res[i] = -1;
          else

           res[i] = *it;

           s.insert(arr[i]);
     }

     for(int i = 0; i < n; i++){
        cout<<res[i]<<" ";
     }
}

int main(){

}


// TC - O(N)