#include<bits/stdc++.h>
using namespace std;

// Recursion

int f(int ind, int sum, vector<int> &arr){
   if(sum == 0) return 1;
   if(ind == 0) return arr[0] == sum;

   int notTake = f(ind - 1, sum, arr);
   int take =  0;

   if(arr[ind] <= sum) take = f(ind - 1, sum - arr[ind],arr);
   
   return take + notTake;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
  
    return f(n-1, k, arr);
}

int main(){
       vector<int> arr = {1, 2, 3};
    int k = 3;
    cout << findWays(arr, k);
}

// TC - O(2^n)
// SC - O(n)


// Memoization

int f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp){
  if(ind == 0){
       if(sum == 0 && arr[0] == 0) return 2;
       if(sum == 0 || sum == arr[0]) return 1;
       return 0;
   }

     if(dp[ind][sum] != -1) return dp[ind][sum];

   int notTake = f(ind - 1, sum, arr,dp);
   int take =  0;

   

   if(arr[ind] <= sum) take = f(ind - 1, sum - arr[ind],arr, dp);
   
   return  dp[ind][sum] =  take + notTake;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int totSum = 0;
    for(auto &it : arr) totSum += it;

    if(totSum - d < 0 || (totSum - d) % 2) return false;
    return findWays(arr, (totSum - d)/2);
         
    
}

// TC - O(n*sum)
// SC - O(n*sum) + O(n)

// Tabulation

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1,  0));

    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    // num[0] = 0

    if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= k; sum++){
             
   int notTake = dp[ind - 1][sum];
   int take =  0;

   

   if(arr[ind] <= sum) take = dp[ind - 1][sum - arr[ind]];

   dp[ind][sum] = take + notTake;
        }
    }

    return dp[n-1][k];
}

// TC - O(n*sum)
// SC - O(n*sum)


// Space Optimization

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
 
    vector<int> prev(k+1,0), cur(k+1,0);

 
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    // num[0] = 0

    if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= k; sum++){
             
   int notTake = prev[sum];
   int take =  0;

   

   if(arr[ind] <= sum) take = prev[sum - arr[ind]];

   cur[sum] = take + notTake;
        }

        prev = cur;
    }

    return prev[k];
}


// TC - O(n*sum)
// SC - O(sum)