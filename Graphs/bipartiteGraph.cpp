#include <bits/stdc++.h>
using namespace std;

class Solution {
    private : 

      bool dfs(int node, int col, int color[], vector<int> adj[]){
         color[node] = col;
         for(auto it : adj[node]){
             if(color[it] == -1){
                 if(dfs(it, !col, color, adj) == false) return false;
             }else if(color[it] == col){
                 return false;
             }
         }
         return true;
      }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
          vector<int> adj[V];
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        int color[V];
        for(int i = 0; i < V;i++){
             color[i] = -1;
        }

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, adj) == false) return false;
            }
        }
        return true;
    }
};

int main() {
       int V = 5;
    vector<vector<int>> edges;

    // Example edges
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});

    // Uncomment to make it non-bipartite
    // edges.push_back({4, 1});

    Solution obj;
    bool isBip = obj.isBipartite(V, edges);

    if (isBip)
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is not Bipartite\n";

    return 0;
}

// TC - O(V + E)
// SC - O(V + E)