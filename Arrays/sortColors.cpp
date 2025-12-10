#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high){
             if(nums[mid] == 0){
                 swap(nums[mid], nums[low]);
                 low++;
                 mid++;
             }else if(nums[mid] == 1){
                  mid++;
             }else{
                 swap(nums[mid], nums[high]);
                 high--;
             }
        }
    }
};


int main() {
   Solution obj;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    obj.sortColors(nums);

    for (int val : nums)
        cout << val << " ";

    return 0;
}


// TC - O(n)
// SC - O(1)