#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
     bool canJump(vector<int>& nums) {
         int n = nums.size();
         int maxInd = 0;
         for(int i = 0; i < n; i++){
            if(i > maxInd) return false;
            maxInd = max(maxInd, i + nums[i]);
         }
         return true;
    }
};

int main(){
    Solution sol;
  vector<int> nums = {2,3,1,1,4};
   bool ans = sol.canJump(nums);
   cout<<ans;
   
}

// TC - O(N) 
// SC - O(1)