#include<bits/stdc++.h>
using namespace std;

// Recursion

int f(int i , int j, vector<vector<int>> &triangle){
    int n = triangle.size();
      if(i == n-1) return triangle[n-1][j];
      int down = triangle[i][j] + f(i+1, j, triangle);
      int diagonal = triangle[i][j] + f(i+1, j+1, triangle);

      return min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    return f(0, 0,triangle);
	 
}


int main(){
      
      vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 9, 6, 10}
    };

    cout << minimumPathSum(triangle); // Output: 14 (1 + 3 + 6 + 4)
    return 0;
}

// TC - O(2^n)
// SC - O(N)


// Memoization

int f(int i , int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
    int n = triangle.size();
      if(i == n-1) return triangle[n-1][j];

      if(dp[i][j] != -1) return dp[i][j];
      int down = triangle[i][j] + f(i+1, j, triangle,dp);
      int diagonal = triangle[i][j] + f(i+1, j+1, triangle,dp);

      return  dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n,-1));
    return f(0, 0,triangle,dp);
	 
}

// TC - O(n*n)
// SC - O(n) + O(n*n)

//  Tabulation

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.

    int dp[n][n];

    for(int j = 0; j < n; j++){
         dp[n-1][j] = triangle[n-1][j];

    }

    for(int i = n-2; i >= 0; i--){
         for(int j = i; j >= 0; j--){
            
             int down = triangle[i][j] + dp[i+1][j];
             int diagonal = triangle[i][j] + dp[i+1][j+1];

             dp[i][j] = min(down, diagonal);
         }
    }

    return dp[0][0];
}

// TC - O(n*n)
// SC - O(n*n)