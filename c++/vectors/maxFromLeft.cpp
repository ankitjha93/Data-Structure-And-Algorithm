#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  vector<int> maximum_from_left(vector<int>& arr) {
    // Your code here
      vector<int> result;
    if(arr.empty()) return result;
    
    int maxLeft = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > maxLeft){
            result.push_back(i);
            maxLeft = arr[i];
        }
    }
    return result;
    
}
};

int main(){

     Solution sol;
    vector<int> v = {4, 3, 5, 2, 6};
    // int x = 1;

    vector<int> ans = sol.maximum_from_left(v);
    for(auto x : ans){
        cout<<x<<" ";
    }

}