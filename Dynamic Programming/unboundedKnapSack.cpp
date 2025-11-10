#include<bits/stdc++.h>
using namespace std;

// Recursion

int f(int ind, int W, vector<int> &val, vector<int> &wt){
     if(ind == 0){
        return ((int)(W/ wt[0])) * val[0];
     }

     int notTake = 0 + f(ind - 1, W, val, wt);
     int take = 0;
     if(wt[ind] <= W){
        take = val[ind] + f(ind, W  - wt[ind], val, wt);
     }

     return max(take, notTake);
}


int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    // Write Your Code Here.
    return f(n-1, w, val, wt);
}

int main(){
      vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    cout << unboundedKnapsack(val.size(), w, val, wt) << endl; // ✅ Output: 100
    return 0;
}

// TC - O(2^n)
// SC - O(n)


// Memoization

int f(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
     if(ind == 0){
        return ((int)(W/ wt[0])) * val[0];
     }

     if(dp[ind][W] != -1)  return dp[ind][W];
     int notTake = 0 + f(ind - 1, W, val, wt, dp);
     int take = 0;
     if(wt[ind] <= W){
        take = val[ind] + f(ind, W  - wt[ind], val, wt, dp);
     }

     return dp[ind][W] =  max(take, notTake);
}


int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n-1, w, val, wt, dp);
}

// TC - O(n*sum)
// SC - O(n*sum) + O(n)

// Tabulation

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    
    for(int W = 0; W <= w; W++){
         dp[0][W] = ((int)(W/ wt[0])) * val[0];
    }

    for(int ind = 1; ind < n; ind++){
         for(int W = 0; W <= w; W++){
              int notTake = 0 + dp[ind - 1][W];
     int take = 0;
     if(wt[ind] <= W){
        take = val[ind] + dp[ind][W - wt[ind]];
     }

      dp[ind][W] =  max(take, notTake);
         }
    }
    return dp[n-1][w];
}


// TC - O(n*sum)
// SC - O(n*sum)


// Space Optimization


int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    // Write Your Code Here.
    vector<int> prev(w + 1, 0), cur(w + 1, 0);
    
    for(int W = 0; W <= w; W++){
         prev[W] = ((int)(W/ wt[0])) * val[0];
    }

    for(int ind = 1; ind < n; ind++){
         for(int W = 0; W <= w; W++){
              int notTake = 0 + prev[W];
     int take = 0;
     if(wt[ind] <= W){
        take = val[ind] + cur[W - wt[ind]];
     }

      cur[W] =  max(take, notTake);
         }

         prev = cur;
    }
    return prev[w];
}


// TC - O(n*sum)
// SC - O(sum)


// 2d array ------- to ------- 1d array


int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    // Write Your Code Here.
    vector<int> prev(w + 1, 0);
    
    for(int W = 0; W <= w; W++){
         prev[W] = ((int)(W/ wt[0])) * val[0];
    }

    for(int ind = 1; ind < n; ind++){
         for(int W = 0; W <= w; W++){
              int notTake = 0 + prev[W];
     int take = 0;
     if(wt[ind] <= W){
        take = val[ind] + prev[W - wt[ind]];
     }

prev[W] =  max(take, notTake);
         }

      
         
    }
    return prev[w];
}