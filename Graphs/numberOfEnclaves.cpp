#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
             for(int j = 0; j < m; j++){
                //   first row, first col, last row, last col
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                     if(grid[i][j] == 1){
                         q.push({i,j});
                         vis[i][j] = 1;
                     }
                }
             }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        while (!q.empty())
        {
            /* code */
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // treverse all 4 directions
            for(int i = 0; i < 4; i++){
                 int nrow = row + delRow[i];
                 int ncol = col + delCol[i];
                 if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                     q.push({nrow, ncol});
                     vis[nrow][ncol] = 1;
                 }
            }

        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
             for(int j = 0; j < m; j++){
                 if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
             }
        }
        
        return cnt;
        
    }
};
int main() {
      vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Solution obj;
    cout << "Number of enclaves = " << obj.numberOfEnclaves(grid) << endl;

    return 0;
}


 
// TC - O(n*m * 4) + O(n) -- which is equal to O(n*m)
// SC - O(n*m)