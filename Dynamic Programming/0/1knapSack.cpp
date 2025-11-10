#include<bits/stdc++.h>
using namespace std;

int f(int ind, int W, vector<int> &wt, vector<int> &val){
     if(ind == 0){
        if(wt[0] <= W) return val[0];
        return 0;
     }

     int notTake = 0 + f(ind - 1, W, wt, val);
     int take = INT_MIN;

     if(wt[ind] <= W){
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val);
     }
     return max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return f(n-1,maxWeight, weight, value);
}

int main(){
  vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    cout << knapsack(wt, val, wt.size(), W);
}

// TC - O(2^n)
// SC - O(n)

// Memoization

int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
     if(ind == 0){
        if(wt[0] <= W) return val[0];
        return 0;
     }

     if(dp[ind][W] != -1) return dp[ind][W];

     int notTake = 0 + f(ind - 1, W, wt, val, dp);
     int take = INT_MIN;

     if(wt[ind] <= W){
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
     }
     return dp[ind][W] =  max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	return f(n-1,maxWeight, weight, value, dp);
}

// TC - O(n*w)
// SC - O(n*w) + O(n)

// Tabulation

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
	
    for(int W = wt[0]; W <= maxWeight; W++) dp[0][W] = val[0];

    for(int ind = 1; ind < n; ind++){
         for(int W = 0; W <= maxWeight; W++){
            
              int notTake = 0 + dp[ind - 1][W];
     int take = INT_MIN;

     if(wt[ind] <= W){
        take = val[ind] + dp[ind -1][W - wt[ind]];
         }

         dp[ind][W] = max(take, notTake);

        }
}
return dp[n-1][maxWeight];
}

// TC - O(n*w)
// SC - O(n*w) 

// Space Optimization

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
  
    vector<int> prev(maxWeight + 1, 0), cur(maxWeight + 1, 0);

	
    for(int W = wt[0]; W <= maxWeight; W++) prev[W] = val[0];

    for(int ind = 1; ind < n; ind++){
         for(int W = 0; W <= maxWeight; W++){
            
              int notTake = 0 + prev[W];
     int take = INT_MIN;

     if(wt[ind] <= W){
        take = val[ind] + prev[W - wt[ind]];
         }

         cur[W] = max(take, notTake);

        }

        prev = cur;
}
return prev[maxWeight];
}

// TC - O(n*w)
// SC - O(W)

//    for(int W = maxWeight; W >=  0; W--) prev[W] = val[0]; --- previous row

// one row optimization

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
  
    vector<int> prev(maxWeight + 1, 0);

	
   for(int W = wt[0]; W <= maxWeight; W++) prev[W] = val[0];

    for(int ind = 1; ind < n; ind++){
         for(int W = maxWeight; W >= 0; W--){
            
              int notTake = 0 + prev[W];
     int take = INT_MIN;

     if(wt[ind] <= W){
        take = val[ind] + prev[W - wt[ind]];
         }

         prev[W] = max(take, notTake);

        }

   
        
}
return prev[maxWeight];
}


