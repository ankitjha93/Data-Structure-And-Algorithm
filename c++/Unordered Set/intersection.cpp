#include<bits/stdc++.h>
using namespace std;

void intersection(int arr[], int m, int b[], int n){
    //  for(int i = 0; i < m; i++){
    //     bool flag = false;
    //     for(int j = 0; j < n; j++){
    //          if(a[i] == b[j]){
    //             flag = true;
    //             break;
    //          }
    //     }
    //     if(flag == true){
    //         cout<<arr[i]<<" ";
    //     }
    //  }

    unordered_set<int> s;
    for(int j = 0; j < n; j++){
        s.insert(b[j]);
    }

    for(int i = 0; i < m; i++){
        if(s.find(a[i]) == s.end())
          cout<<a[i]<<" ";
    }
}

int main(){

}

// TC - O(n + m)
// SC - O(n) -- auxiliary space