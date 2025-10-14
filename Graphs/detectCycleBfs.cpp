#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detect(int src, vector<vector<int>>& adj, int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // If visited and not parent => cycle found
                else if (parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& adj) {
         int vis[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Example undirected graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // Uncomment this edge to create a cycle
    // adj[4].push_back(1);
    // adj[1].push_back(4);

    Solution obj;
    bool hasCycle = obj.isCycle(V, adj);

    if (hasCycle)
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}



// TC - O(N + 2E) + O(N)
// SC - O(N) + O(N) -- which is equal to O(N)