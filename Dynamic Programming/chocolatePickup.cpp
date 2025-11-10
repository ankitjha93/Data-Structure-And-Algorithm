#include <bits/stdc++.h>
using namespace std;

int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
    {
        return -1e8;
    }

    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    //  explore all paths of alice and bob simultaneously

    int maxi = -1e8;

    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];

            else
                value = grid[i][j1] + grid[i][j2];

            value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    return f(0, 0, c - 1, r, c, grid);
}

int main()
{
}

// TC - O(3^n * 3^n)
// SC - O(N)

// Memoization

int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
    {
        return -1e8;
    }

    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    //  explore all paths of alice and bob simultaneously

    int maxi = -1e8;

    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];

            else
                value = grid[i][j1] + grid[i][j2];

            value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c - 1, r, c, grid, dp);
}

int main()
{
}

// TC - O(n*m*m) *9
// SC - O(n*m*m) +O(n)

// Tabulation

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;

                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];

                        else
                            value = grid[i][j1] + grid[i][j2];

                            if(j1+dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)

                        value += dp[i + 1] [j1 + dj1] [j2 + dj2];

                        else 
                           value += -1e8;
                        maxi = max(maxi, value);
                    }
                }

             dp[i][j1][j2] = maxi;
            }
        }
    }
return dp[0][0][m-1];
}

// TC - O(n*m*m) *9
// SC - O(n*m*m)

// Space Optimization

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    // Write your code here.

    // int dp[r][c][c];
    // 1d -> two variable
    // 2D -> 1D dp
    // 3D -> 2D dp

  
    vector<vector<int>> front(m ,vector<int>(m,0));
    vector<vector<int>> cur(m, vector<int>(m,0));


    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;

                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];

                        else
                            value = grid[i][j1] + grid[i][j2];

                            if(j1+dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)

                        value += front[j1 + dj1] [j2 + dj2];

                        else 
                           value += -1e8;
                        maxi = max(maxi, value);
                    }
                }

             cur[j1][j2] = maxi;
            }
        }

        front = cur;
    }
return front[0][m-1];

}

int main()
{
}

// TC - O(n*m*m) 
// SC - O(m*m)