#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
     void heapifyDown(vector<int> &nums,int ind){
        int n = nums.size();
         int largest = ind;
         int lChild = 2 * ind + 1;
         int rChild = 2 * ind + 2;

         if(lChild < n && nums[lChild] > nums[largest]){
            largest = lChild;
         }

        if(rChild < n && nums[rChild] > nums[largest]){

            largest = rChild;
        }

            if(largest != ind){
                swap(nums[ind], nums[largest]);
                heapifyDown(nums, largest);
            }
      }

    vector<int> minToMaxHeap(vector<int> nums) {
      int n = nums.size();
         for(int i = n/2 -1; i >= 0;i--){
            heapifyDown(nums, i);
         }
         return nums;
    }
};

int main(){
   Solution sol;
   vector<int> nums = {10, 20, 30, 21, 23};
   vector<int> ans = sol.minToMaxHeap(nums);
    for(auto x : ans){
        cout<<x<<" ";
    }
}

// TC - O(N)
// SC - O(1)