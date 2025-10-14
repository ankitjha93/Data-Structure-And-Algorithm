#include<bits/stdc++.h>
using namespace std;

class Solution {

    private :

     int timer = 1;

     private:

        void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> & bridges){
              vis[node] = 1;
              tin[node] = low[node] = timer;
              timer++;

              for(auto it : adj[node]){
                 if(it == parent) continue;
                 if(vis[it] == 0){
                     dfs(it, node, vis, adj, tin, low, bridges);
                     low[node] = min(low[node], low[it]);
                    //  node -- it

                    if(low[it] > tin[node]){
                         bridges.push_back({it, node});
                    }
                 }else{
                        // back edge
                         low[node] = min(low[node], tin[it]);
                    }
              }
        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
          vector<int> adj[n];
          for(auto it : connections){
             adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
          }

          vector<int> vis(n,0);

          int tin[n];
          int low[n];

          vector<vector<int>> bridges;

          dfs(0, -1,vis, adj, tin, low, bridges);
          return bridges;
    }
};


int main(){
      int n = 4;
    vector<vector<int>> connections = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3}
    };

    Solution obj;
    vector<vector<int>> result = obj.criticalConnections(n, connections);

    cout << "Bridges in the graph are:\n";
    for (auto &bridge : result) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
    
}

// TC - O(V + 2E)
// SC - O(V + 2E) + O(3N)