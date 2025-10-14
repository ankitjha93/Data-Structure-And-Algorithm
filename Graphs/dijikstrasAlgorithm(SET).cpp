#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
          
         set<pair<int, int>> st;
         vector<int> dist(V, 1e9);

         st.insert({0,S});
         dist[S] = 0;

         while(!st.empty())
         {
            /* code */

            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto it : adj[node]){
                 int adjNode = it[0];
                 int edgW = it[1];

                 if(dis + edgW < dist[adjNode]){
                    //  erase if it existed
                    if(dist[adjNode] != 1e9)
                         st.erase({dist[adjNode], adjNode});

                         dist[adjNode] = dis + edgW;
                         st.insert({dist[adjNode], adjNode});
                    
                 }
            }
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

    // build adjacency list
    vector<vector<int>> adj[V];
    for (auto e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected graph
    }

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, 0); // src = 0

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << res[i] << "\n";
    }

    return 0;
}

// Time Complexity: O((V + E) log V) ≈ O(E log V)
// Space Complexity: O(V + 2E)