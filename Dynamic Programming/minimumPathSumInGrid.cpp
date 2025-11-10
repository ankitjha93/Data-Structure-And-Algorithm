#include<bits/stdc++.h>
using namespace std;

// Recursion

// int f(int i, int j, vector<vector<int>>& grid){
//      if(i == 0 && j == 0) return grid[0][0];
//      if(i < 0 || j < 0) return 1e9+7;
     
//      int up = grid[i][j] + f(i-1,j, grid);
//      int left = grid[i][j] + f(i, j-1, grid);

//      return min(up,left);
// }
// int minSumPath(vector<vector<int>> &grid) {
//     // Write your code here.
//     int n = grid.size();
//     int m = grid[0].size();
//     return f(n-1, m-1,grid);
// }

int main(){
       vector<vector<int>> grid = {{5, 9, 6},
                                {11, 5, 2}};
    cout << minSumPath(grid) << endl; // Output: 21
    return 0;
}

// TC - O(2^m*n)
// SC - O(path length)


// Memoization

int f(int i, int j, vector<vector<int>>& grid,vector<vector<int>> &dp){
     if(i == 0 && j == 0) return grid[0][0];
     if(i < 0 || j < 0) return 1e9+7;
     
     if(dp[i][j] != -1) return dp[i][j];
     int up = grid[i][j] + f(i-1,j, grid, dp);
     int left = grid[i][j] + f(i, j-1, grid, dp);

     return dp[i][j] =  min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1, m-1,grid,dp);
}

// TC - O(n*m)
// SC - O((n-1)+ (m-1)) + O(n * m)