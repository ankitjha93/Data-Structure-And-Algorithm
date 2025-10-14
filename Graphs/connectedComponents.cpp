#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<int> adj[V];
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        vector<int> vis(V, 0);
        int count = 0;

        // Run DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, // component 1: 0-1-2
        {3, 4}, {4, 5}  // component 2: 3-4-5
    };

    Solution obj;
    cout << "Number of Components: " << obj.findNumberOfComponent(V, edges) << endl;

    return 0;
}
