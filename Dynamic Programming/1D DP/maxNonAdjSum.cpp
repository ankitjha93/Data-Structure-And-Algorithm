
// Memoization

// #include <bits/stdc++.h>
// using namespace std;

// int f(int ind, vector<int> &nums, vector<int> &dp){
//      if(ind == 0) return nums[ind];
//      if(ind < 0) return 0;

//      if(dp[ind] != -1) return dp[ind];

//      int pick = nums[ind] + f(ind - 2, nums, dp);
//      int notPick = 0 + f(ind - 1, nums, dp);

//      return dp[ind] = max(pick, notPick);
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return f(n-1, nums, dp);

// }

// TC - O(N)
// SC - O(N) + O(N)


// Tabulation


// #include <bits/stdc++.h>
// using namespace std;

// int maximumNonAdjacentSum(vector<int> &nums){
//     // Write your code here.
//     int n = nums.size();
//     vector<int> dp(n, 0);

//      if (n == 0) return 0;
//     if (n == 1) return nums[0];

//     dp[0] = nums[0];

//     int neg = 0;

//     for(int i = 1; i < n; i++){
//          int take = nums[i]; if(i > 0) take += dp[i-2];
//          int notTake = 0 + dp[i-1];

//          dp[i] = max(take, notTake);
//     }
//     return dp[n-1];
// }

// int main() {
   
//     vector<int> nums = {2, 1, 4, 9};
//     cout << maximumNonAdjacentSum(nums); // Output: 11
//     return 0;
// }

// TC - O(N)
// SC - O(N) 



// Space Optimization


#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
   
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < n; i++){
         int take = nums[i];

         if(i > 1) take += prev2;

         int notTake = 0 + prev;

         int curi = max(take, notTake);

         prev2 = prev;
         prev = curi;
    }

    return prev;
}

int main() {
   
    vector<int> nums = {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(nums); // Output: 11
    return 0;
}

// TC - O(N)
// SC - O(1) 
