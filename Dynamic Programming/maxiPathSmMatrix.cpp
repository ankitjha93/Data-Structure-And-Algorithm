#include <bits/stdc++.h>
using namespace std;

// Recursion

int f(int i, int j, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];

    int up = matrix[i][j] + f(i - 1, j, matrix);
    int leftDiagonal = matrix[i][j] + f(i - 1, j - 1, matrix);

    int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, matrix);

    return max(up, max(leftDiagonal, rightDiagonal));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    int maxSum = -1e9;

    for (int col = 0; col < m; col++)
    {
        maxSum = max(maxSum, f(n - 1, col, matrix));
    }

    return maxSum;
}

int main()
{

    return 0;
}

// TC - O(3^n)
// SC - O(N)

// Memoization

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + f(i - 1, j, matrix, dp);
    int leftDiagonal = matrix[i][j] + f(i - 1, j - 1, matrix, dp);

    int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxSum = -1e9;

    for (int col = 0; col < m; col++)
    {
        maxSum = max(maxSum, f(n - 1, col, matrix, dp));
    }

    return maxSum;
}

// TC - O(n*m)
// SC - O(n) + O(n*m)

//  Tabulation

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    int dp[n][m];

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += dp[i - 1][j - 1];
            else
                leftDiagonal += -1e9; // invalid

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += dp[i - 1][j + 1];
            else
                rightDiagonal += -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = dp[n - 1][0];

    for (int j = 1; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }

    return maxi;
}
// TC - O(n*m)
// SC - O(n*m)

// Space Optimization

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

  
    vector<int> prev(m, 0), cur(m,0);

    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += prev[j - 1];
            else
                leftDiagonal += -1e9; // invalid

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += prev[j + 1];
            else
                rightDiagonal += -1e9;

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = cur;
    }
    
    int maxi = prev[0];

    for (int j = 1; j < m; j++)
    {
        maxi = max(maxi,prev[j]);
    }

    return maxi;
}

// TC - O(n*m)
// SC - O(n)