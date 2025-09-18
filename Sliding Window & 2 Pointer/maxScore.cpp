#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &nums, int k){
    int n = nums.size();
    int lSum = 0, rSum = 0, maxSum = 0;
    for(int i = 0; i < k; i++){
        lSum = lSum + nums[i];
         maxSum = lSum;

    }

    int rIndex = n-1;

    for(int i = k-1; i >= 0; i--){
        lSum = lSum - nums[i];
        rSum = rSum + nums[rIndex];
        rIndex = rIndex - 1;
        maxSum = max(maxSum, lSum + rSum);
    }

    return maxSum;

}
     
int main(){
 
    vector<int> nums = {1,2,3,4,5,6,1};
    int k = 3;
  
   
   int ans = maxScore(nums, k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(N)
// SC = O(1)