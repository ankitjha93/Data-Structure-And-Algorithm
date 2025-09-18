#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isHeap(vector<int>& nums) {
           int n = nums.size();
           for(int i = n/2 - 1; i >= 0; i--){
              int left = 2 * i + 1;
              int right = 2 * i + 2;
              if(left < n && nums[left] < nums[i]) return false;
             if(right < n && nums[right] < nums[i]) return false;
           }
           return true;
    }
};

int main(){
   Solution sol;
   vector<int> nums = {10, 20, 30, 21, 23};
   cout<<bool(sol.isHeap(nums));
}

// TC - O(N/2)
// SC - O(1)