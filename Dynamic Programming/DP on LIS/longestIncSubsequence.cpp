#include<bits/stdc++.h>
using namespace std;

int f(int ind, int prev_ind, vector<int> &arr, int n){
      if(ind == n) return 0;

      int len = 0 + f(ind + 1, prev_ind, arr, n);
      if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
         len = max(len, 1 + f(ind + 1, ind, arr, n));
      }
      return len; 
}

vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
    return f(0, -1, arr, n);
}

int main(){
    
     vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();

    vector<int> ans = printingLongestIncreasingSubsequence(arr, n);

    for(int x : ans) cout << x << " ";
    cout << endl;
}

// TC - O(2^n)
// SC - O(n)


// Memoization

int f(int ind, int prev_ind, vector<int> & heights, int n, vector<vector<int>> &dp){
      if(ind == n) return 0;

      if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];
      int len = 0 + f(ind + 1, prev_ind, heights, n, dp);
      if(prev_ind == -1 || heights[ind] > heights[prev_ind]){
         len = max(len, 1 + f(ind + 1, ind, heights, n, dp));
      }
      return dp[ind][prev_ind + 1] =  len; 
}

int LIS(vector<int> &heights, int n){	
	// Write your code here.	
	  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0,  -1,heights, n, dp);
}

// TC - O(n * n)
// SC - O(n * n) + O(n)

// Tabulation

int LIS(vector<int> &heights, int n){	
	// Write your code here.	
	  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

       for(int ind = n-1; ind >= 0; ind--){
         for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
              int len = 0 + dp[ind + 1][prev_ind + 1];

              if(prev_ind == -1 || heights[ind] > heights[prev_ind]){
               len = max(len, 1 +  dp[ind + 1][ind + 1]);
         }
         dp[ind][prev_ind + 1] =  len; 
       }
}

return dp[0][-1 + 1];
}

// TC - O(n * 2)
// SC - O(n * 2)


// Space Optimization

int LIS(vector<int> &heights, int n){	
	// Write your code here.	
	 vector<int> next(n + 1, 0), cur(n + 1, 0);

       for(int ind = n-1; ind >= 0; ind--){
         for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
              int len = 0 + next[prev_ind + 1];

              if(prev_ind == -1 || heights[ind] > heights[prev_ind]){
               len = max(len, 1 +  next[ind + 1]);
         }
         cur[prev_ind + 1] =  len; 
       }
       next = cur;
}

return next[-1 + 1];
}


    // TC - O(n * 2)
// SC - O(2)



//  Another approach

int LIS(vector<int> &heights, int n){	
	// Write your code here.	
    vector<int> dp (n, 1);

    int maxi = 1;

    for(int i = 0; i < n; i++){
         for(int prev = 0; prev < i; prev++){
             if(heights[prev] < heights[i]){
                 dp[i] = max(dp[i], 1 + dp[prev]);
             }
         }

         maxi = max(maxi, dp[i]);
    }

    return maxi;
    
}

// TC - O(n^2)
// SC - O(n)


// printing LIS

int LIS(vector<int> &heights, int n){	
	// Write your code here.	
    vector<int> dp (n, 1), hash(n);

    int maxi = 1;

    int lastIndex = 0;

    for(int i = 0; i < n; i++){
        hash[i] = i;
         for(int prev = 0; prev < i; prev++){
             if(heights[prev] < heights[i] && 1 + dp[prev] > dp[i]){


                 dp[i] = 1 + dp[prev];
                hash[i] = prev;
             }
         }
     
         if(dp[i] > maxi){
             maxi = dp[i];
             lastIndex = i;
         }
    }

    vector<int> temp;

    temp.push_back(heights[lastIndex]);
    while(hash[lastIndex] != lastIndex){
         lastIndex = hash[lastIndex];
         temp.push_back(heights[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    for(auto it : temp) cout<<it<<" ";
    cout<<endl;

    return maxi;
    
}


// TC - O(n^2)
// SC - O(n)


// binary search approach

int LIS(vector<int> &heights, int n){	
	// Write your code here.	
   
    vector<int> temp;
    temp.push_back(heights[0]);
    int len = 1;
    for(int i = 1; i < n; i++){
         if(heights[i] > temp.back()){
              temp.push_back(heights[i]);
              len++;
         }else{
            // int ind = lower_bound(temp.begin(), temp.end(), heights[i]);

            // temp[ind] = heights[i];

             auto it = lower_bound(temp.begin(), temp.end(), heights[i]);

            *it = heights[i];
         }
    }

    return len;
    
}

// TC - O(n * logn)  ---- bs
// SC - O(n)  --- temp


