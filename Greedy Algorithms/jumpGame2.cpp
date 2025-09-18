/*#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

  int minJump(int ind, vector<int> & nums){
    int n = nums.size();
        if(ind >= n - 1) return 0;
         int mini = INT_MAX;
         for(int i = 1; i <= nums[ind]; i++){
            if(ind + i < n){
                int next = minJump(ind + i, nums);
                if (next != INT_MAX) {
                    mini = min(mini, 1 + next); // add this jump
                }
            }

            // mini = min(mini, minJump(ind + i, nums));
         }
         return mini;
  }

    int jump(vector<int>& nums) {
        return minJump(0,nums);
    }
};

int main(){
    Solution sol;
  vector<int> nums = {2,3,1,1,4};
   int ans = sol.jump(nums);
   cout<<ans;
   
}

// TC - O(N^N) 
// SC - O(N)*/



// Optimal Solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int jump(vector<int>& nums) {
         int n = nums.size();
         int jumps = 0, l = 0, r = 0;
         while(r < n - 1){
            int farthest = 0;
            for(int i = l; i <= r;i++){
                farthest = max(i + nums[i], farthest);
            }
             l = r + 1;
            r = farthest;
            jumps = jumps + 1;
         }
        
         return jumps;
    }
};

int main(){
    Solution sol;
  vector<int> nums = {2,3,1,1,4};
   int ans = sol.jump(nums);
   cout<<ans;
   
}

// TC - O(N) 
// SC - O(1)