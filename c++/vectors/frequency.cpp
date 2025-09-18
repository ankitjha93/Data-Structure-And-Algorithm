#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findFrequency(vector<int> arr, int x) {
        // Your code here
        return count(arr.begin(), arr.end(), x);
    }
};

int main(){

     Solution sol;
    vector<int> v = {1,1,1,1,1};
    int x = 1;

    int ans = sol.findFrequency(v, x);
    cout<<ans;

}