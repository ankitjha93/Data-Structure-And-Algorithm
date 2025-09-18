#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        int n = bt.size();
        sort(bt.begin(), bt.end());
        long long t = 0;
        long long wtTime = 0;
        for(int i = 0; i < n; i++){
            wtTime = wtTime + t;
            t = t + bt[i];
        }
        return (wtTime/n);
    }
};

int main(){
    Solution sol;
  vector<int> bt = {4, 1, 3, 7, 2};
   int ans = sol.solve(bt);
   cout<<ans;
   
}

// TC - O(N) + O(NlogN)
// SC - O(1)