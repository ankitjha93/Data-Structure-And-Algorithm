#include<bits/stdc++.h>
using namespace std;

// void printDist(int arr[], int n){
//     for(int i = 0; i < n; i++){
//         bool flag = false;
//         for(int j = 0; j < i; j++){
//             if(arr[i] == arr[j]){
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag == false){
//             cout<<arr[i]<<" ";
//         
//     }
// }

// void printDist(int arr[], int n){
//     unordered_set<int> s;
//     for(int i = 0; i < n; i++){
//         s.insert(arr[i]);
//     }

//     for(auto x : s){
//         cout<<x<<" ";
//     }
// }

void printDist(int arr[], int n){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(arr[i])== s.end()){
            cout<<arr[i]<<" ";
            s.insert(arr[i]);
        }
    }
}



int main(){
   int arr[] = {10,8,10,10,7};
   int n = sizeof(arr)/sizeof(arr[0]);
    printDist(arr, n);
}

// TC - O(n^2)


// Optimal Solution

void printDist(int arr[], int n){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(arr[i])== s.end()){
            cout<<arr[i]<<" ";
            s.insert(arr[i]);
        }
    }
}



int main(){
   int arr[] = {10,8,10,10,7};
   int n = sizeof(arr)/sizeof(arr[0]);
    printDist(arr, n);
}


// TC - O(N)
