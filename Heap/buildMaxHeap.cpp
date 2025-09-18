#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void heapifyDown(vector<int> &nums,int ind){
        int n = nums.size();
         int smallest = ind;
         int lChild = 2 * ind + 1;
         int rChild = 2 * ind + 2;

         if(lChild < n && nums[lChild] > nums[smallest]){
            smallest = lChild;
         }

        if(rChild < n && nums[rChild] > nums[smallest]){

            smallest = rChild;
        }

            if(smallest != ind){
                swap(nums[ind], nums[smallest]);
                heapifyDown(nums, smallest);
            }
      }


    void buildMinHeap(vector<int> &nums) {
         int n = nums.size();
         for(int i = n/2 - 1; i >= 0; i--){
            heapifyDown(nums, i);
         }
    }
};


int main(){
   vector<int> nums = {6, 5, 2, 7, 1, 7};
    Solution sol;

    sol.buildMinHeap(nums);

    cout << "Max Heap: ";
    for(int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}