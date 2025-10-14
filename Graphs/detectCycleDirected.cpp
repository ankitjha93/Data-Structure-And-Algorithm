#include <bits/stdc++.h>
using namespace std;

class Solution {

    private : 

      bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]){ 
          vis[node] = 1;

           pathVis[node] = 1;

            // traverse for adjacent nodes
            for(auto it : adj[node]){
                //  when the node is not visited
                if(!vis[it]){
                     if(dfsCheck(it, adj, vis, pathVis) == true)
                      return true;
                }
                // if the node has been previously visited but it has to be visited on the same path

                 else if(pathVis[it]){
                      return true;
                 }
            }

            pathVis[node] = 0;
            return false;
      }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here

          vector<int> adj[V];
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); // undirected graph
        }
        
        int vis[V] = {0}; 
        int pathVis[V] = {0};

        for(int i = 0; i < V; i++){
             if(!vis[i]){
                 if(dfsCheck(i, adj, vis, pathVis) == true)
                  return true;
             }
        }
        return false;
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

    // Uncomment this to introduce a cycle: 4 -> 1
    // edges.push_back({4, 1});

    Solution obj;
    bool hasCycle = obj.isCyclic(V, edges);

    if (hasCycle)
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}

// TC - O(V + E) -- as it is directed graph
// SC - O(2N) -- one for vis, and one for pathVis