#include<bits/stdc++.h>
using namespace std;

// void printGreater(int arr[], int n){
//      for(int i = 0; i < n; i++){
//          int count = 0;
//          for(int j = 0; j < n; j++){
//             if(j != i && arr[j] > arr[i])
//              count++;
//          }
//          cout<<count<<" ";
//      }  
// }             


//TC - O(n^2)




void printGreater(int arr[], int n){
     map<int, int> m;
     for(int i = 0; i < n; i++){
         m[arr[i]]++;

         int cum_freq = 0;

         for(auto it = m.rbegin(); it != m.rend(); it++){
             int freq = it->second;
             it->second = cum_freq;
             cum_freq += freq;
         }

         for(int i = 0; i < n; i++){
            cout<<m[arr[i]]<<" ";
         }
     }
}

int main(){

    int arr[] = {4, 2, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printGreater(arr, n);

    return 0;
}