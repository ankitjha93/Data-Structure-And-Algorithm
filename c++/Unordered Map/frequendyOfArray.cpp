#include<bits/stdc++.h>
using namespace std;

int printFreq(int arr[], int n){
    unordered_map<int, int> m;

    for(int i = 0; i < n; i++){
          m[arr[i]]++;
    }

    for(auto x : m){
         cout<<x.first<<" "
           <<x.second<<endl;
    }
}

int main(){

}