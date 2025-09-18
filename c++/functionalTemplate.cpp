#include<bits/stdc++.h>

using namespace std;

template <typename T>

T arrMax(T arr[], int n){
   T res = arr[0];
   for(int i = 0; i < n; i++){
    if(arr[i] > res)
     res = arr[i];
   }
   return res;
}

 int main(){
     int arr[] = {10,40,3};
     cout<<arrMax<int>(arr,3);
     return 0;
 }