#include<bits/stdc++.h>
using namespace std;


int getMaxVal(int arr[], int n, int k){
     sort(arr, arr + n, greater<int>());
     int res = 0;
     for(int i = 0; i < k; i++){
          res =  res + arr[i];
     }

     return res;
}

int main(){
   
    
   return 0;
}