#include<bits/stdc++.h>
using namespace std;

int f(int ind, int T, vector<int> &nums){
     if(ind == 0){ 
        if(T % nums[0] == 0) return T/ nums[0];

        return 1e9;
     }

     int notTake = 0 + f(ind - 1, T, nums);
     int take = INT_MAX;

    if(nums[ind] <= T) take = 1 + f(ind, T - nums[ind], nums);

    return min(take, notTake);
}

int minimumElements(vector<int> &num, int target)
{
    // Write your code here.
    int n = num.size();
    int ans = f(n-1, target, num);
    if(ans >= 1e9) return -1;
    return ans;
}

int main(){
   vector<int> coins = {1, 2, 5};
    int target = 11;
    cout << minimumElements(coins, target); // Output: 3 (5+5+1)
    
}

// TC - O(2^n)
// SC - O(n)

// Memoization

int f(int ind, int T, vector<int> &nums, vector<vector<int>> &dp){
     if(ind == 0){ 
        if(T % nums[0] == 0) return T/ nums[0];

        return 1e9;
     }

     if(dp[ind][T] != -1) return dp[ind][T];
     int notTake = 0 + f(ind - 1, T, nums, dp);
     int take = INT_MAX;

    if(nums[ind] <= T) take = 1 + f(ind, T - nums[ind], nums, dp);

    return dp[ind][T] =  min(take, notTake);
}

int minimumElements(vector<int> &num, int target)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = f(n-1, target, num, dp);
    if(ans >= 1e9) return -1;
    return ans;
}

// TC - O(n*w)
// SC - O(n*w) + O(n)

// Tabulation

int minimumElements(vector<int> &nums, int target)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1,  0));

    for(int T = 0; T <= target; T++){
         if( T % nums[0] == 0) dp[0][T] = T/nums[0];

         else dp[0][T] = 1e9;
    }


    for(int ind = 1; ind < n; ind++){
         for(int T = 0; T <= target; T++){
             int notTake = 0 + dp[ind - 1][T];
             int take = INT_MAX;
             if(nums[ind] <= T){
                take = 1 + dp[ind][T - nums[ind]];
             }

             dp[ind][T] = min(take, notTake);
         }
    }
    int ans = dp[n-1][target];
    if(ans >= 1e9) return -1;
    return ans;
}

// TC - O(n*w)
// SC - O(n*w) 

// Space Optimization

int minimumElements(vector<int> &nums, int target)
{
    // Write your code here.
    int n = nums.size();
  
    vector<int> prev(target + 1, 0), cur(target + 1, 0);

    for(int T = 0; T <= target; T++){
         if( T % nums[0] == 0) prev[T] = T/nums[0];

         else prev[T] = 1e9;
    }


    for(int ind = 1; ind < n; ind++){
         for(int T = 0; T <= target; T++){
             int notTake = 0 + prev[T];
             int take = INT_MAX;
             if(nums[ind] <= T){
                take = 1 + cur[T - nums[ind]];
             }

             cur[T] = min(take, notTake);
         }
         prev = cur;
    }
    int ans = prev[target];
    if(ans >= 1e9) return -1;
    return ans;
}

// TC - O(n*w)
// SC - O(W)

