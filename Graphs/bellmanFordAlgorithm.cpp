#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        // Initialize distance array
        vector<int> dist(V, 1e8);
        dist[src] = 0;

          // Relax all edges V-1 times
        for(int i = 0; i < V-1;i++){
             for(auto it : edges){ 
                 int u = it[0];
                 int v = it[1];
                 int wt = it[2];

                 if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                      dist[v] = dist[u] + wt;
                 }
             }
        }

        // Nth relaxation to check negative cycle

        for(auto it : edges){
              int u = it[0];
                 int v = it[1];
                 int wt = it[2];

                 if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                      return {-1};
                 }
        }
        return dist;
    }
};


int main() {
      int V = 5; 
    vector<vector<int>> edges = {
        {0,1,-1},{0,2,4},{1,2,3},{1,3,2},
        {1,4,2},{3,2,5},{3,1,1},{4,3,-3}
    };
    int src = 0;

    Solution obj;
    vector<int> ans = obj.bellmanFord(V, edges, src);

    if(ans.size() == 1 && ans[0] == -1) {
        cout << "Negative cycle detected\n";
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for(int d : ans) cout << d << " ";
        cout << "\n";
    }

    return 0;
    
}

// TC - O(V*E)
// SC - O(V)