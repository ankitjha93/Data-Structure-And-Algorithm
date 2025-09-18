#include<bits/stdc++.h>
using namespace std;

void printRepeating(int arr[], int n){
    //   for(int i = 1; i < n; i++){
    //     bool flag = false;

    //     for(int j = 0; j < i; j++){
    //         if(arr[j] == arr[i]){
    //             flag = true;
    //             break;
    //         }
    //     }

    //     if(flag == true){
    //         cout<<arr[i]<<" ";
    //     }
    //   }


    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
        }else{
            cout<<arr[i]<<" ";
        }
    }

}

int main(){

}