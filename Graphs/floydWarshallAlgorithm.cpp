#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
           int n = dist.size();
           for(int i = 0; i < n; i++){
              for(int j = 0;  j < n; j++){
                  if(dist[i][j] == -1){
                      dist[i][j] = 1e9;
                  }
                  if(i == j) dist[i][j] = 0;
              }
           }

           for(int k = 0; k < n; k++){
              for(int i = 0; i < n; i++){
                   for(int j = 0; j < n; j++){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                   }
              }
           }

           for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++){
                    if(dist[i][j] == 1e9){
                         dist[i][j] = -1;
                    }
               }
           }


        //    if contains negative cycles

        // for(int i = 0; i < n; i++){
        //      if(dist[i][j] < 0){
        //           return -1 0r print the statement
        //      }
        // }
        
    }
};


int main() {
      vector<vector<int>> dist = {
        {0, 3, -1},
        {2, 0, -1},
        {-1, 7, 0}
    };

    Solution s;
    s.floydWarshall(dist);

    for (auto &row : dist) {
        for (auto &x : row)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// TC - O(N^3)
// SC - O(N^2)