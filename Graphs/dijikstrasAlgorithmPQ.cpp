#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
          priority_queue<pair<int ,int>,vector<pair<int,int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        
        pq.push({0, S});
        
        while(!pq.empty()){
             int dis = pq.top().first;
             int node = pq.top().second;
             pq.pop();
             
             for(auto it : adj[node]){
                  int edgeWeight = it[1];
                  int adjNode = it[0];
                  
                  if(dis + edgeWeight < dist[adjNode]){
                       dist[adjNode] = dis + edgeWeight;
                       pq.push({dist[adjNode], adjNode});
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
