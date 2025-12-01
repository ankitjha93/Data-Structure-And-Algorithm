#include<bits/stdc++.h>
using namespace std;

  int findMaxConsecutiveOnes(vector<int>& nums) {
        
         int n = nums.size();
        //  if(n < 0) return 0;
         int cnt = 0;
         int maxi = 0;

         for(int i = 0; i < n; i++){
             if(nums[i] == 1){ 
                cnt++;
                maxi = max(maxi, cnt);
             }else{
                 cnt = 0;
             }
         }
         return maxi;
    }

int main(){
       vector<int> nums = {1, 1, 0, 1, 1, 1};

   
       

    // Get answer
    int ans = findMaxConsecutiveOnes(nums);

    // Print result
    cout << "The maximum consecutive 1's are " << ans;
    return 0;
}

// TC - O(n)
// SC - O(1)