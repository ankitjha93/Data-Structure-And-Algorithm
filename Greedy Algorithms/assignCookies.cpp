#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         int n = g.size();
         int m = s.size();
         sort(g.begin(), g.end());
         sort(s.begin(), s.end());
         int l = 0, r = 0;

         while(l < m && r < n){
            if(g[r] <= s[l]){
                r = r + 1;
            }
            l = l + 1;
         }
         return r;
    }
};

int main(){
    Solution sol;
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    
    int ans = sol.findContentChildren(g,s);
    
    cout<<ans;


}

// TC - O(NlogN + MlogM + M)
// SC - O(1)
