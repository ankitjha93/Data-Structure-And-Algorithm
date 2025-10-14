#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {

    private :

      void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st){
           vis[node] = 1;
           for(auto it : adj[node]){
             int v = it.first;
             if(!vis[v]){
                 topoSort(v, adj, vis, st);
             }
           }

           st.push(node);
      }


  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
         // Step 1: Build adjacency list
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological Sort
        int vis[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }
        
        // Step 3: Distance array
        vector<int> dist(V, 1e9);
        dist[0] = 0;  // source is 0 (can be parameterized)

        // Step 4: Relax edges in topo order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Convert unreachable distances to -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};

int main() {
      int V = 5, E = 6;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 3, 4}
    };

    Solution obj;
    vector<int> res = obj.shortestPath(V, E, edges); // source = 0

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << res[i] << "\n";
    }

    return 0;
}

// TC - O(V + E) -- as it is directed graph
// SC - O(v + E) 