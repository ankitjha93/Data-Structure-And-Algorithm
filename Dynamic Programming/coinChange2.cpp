#include<bits/stdc++.h>
using namespace std;

// Recursion

long f(int ind, int T, int *a){
     if(ind == 0){
        return (T % a[0] == 0);
     }

     long notTake = f(ind - 1, T,a);
     long take = 0;
     if(a[ind] <= T) take = f(ind, T - a[ind], a);
     return take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    return f(n-1, value, denominations);
}

// TC - O(2^n)
// SC - O(n)


// Memoization

long f(int ind, int T, int *a, vector<vector<long>> &dp){
     if(ind == 0){
        return (T % a[0] == 0);
     }
if(dp[ind][T] != -1) return dp[ind][T];
     long notTake = f(ind - 1, T,a, dp);
     long take = 0;
     if(a[ind] <= T) take = f(ind, T - a[ind], a, dp);
     return dp[ind][T] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n-1, value, denominations, dp);
}

// TC - O(n*sum)
// SC - O(n*sum) + O(n)

// Tabulation

long countWaysToMakeChange(int *a, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
   
    for(int T = 0; T <= value;T++){
         dp[0][T] = (T % a[0] == 0);
    }

    for(int ind = 1; ind < n; ind++){
         for(int T = 0; T <= value; T++){
             long notTake = dp[ind - 1][T];
             long take = 0;
             if(a[ind] <= T) take = dp[ind][T-a[ind]];

             dp[ind][T] = take + notTake;
         }
    }

    return dp[n-1][value];
}

// TC - O(n*sum)
// SC - O(n*sum)


// Space Optimization

long countWaysToMakeChange(int *a, int n, int value)
{
    //Write your code here
    // vector<vector<long>> dp(n, vector<long>(value + 1, 0));

    vector<long> prev(value + 1, 0), cur(value + 1, 0);
   
    for(int T = 0; T <= value;T++){
         prev[T] = (T % a[0] == 0);
    }

    for(int ind = 1; ind < n; ind++){
         for(int T = 0; T <= value; T++){
             long notTake = prev[T];
             long take = 0;
             if(a[ind] <= T) take = cur[T-a[ind]];

             cur[T] = take + notTake;
         }
         prev = cur;
    }

    return prev[value];
}


// TC - O(n*sum)
// SC - O(sum)