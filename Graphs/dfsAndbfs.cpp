#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function for DFS
    void dfsUtil(int node, vector<int> adj[], vector<int>& vis, vector<int>& res) {
        vis[node] = 1;
        res.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsUtil(it, adj, vis, res);
            }
        }
    }

public:
    // DFS Traversal
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> res;

        // handle disconnected graphs
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsUtil(i, adj, vis, res);
            }
        }
        return res;
    }

    // BFS Traversal
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> res;
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    res.push_back(node);

                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    int V = 6;
    vector<int> adj[V];

    // Example graph (undirected, disconnected)
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);

    Solution obj;

    vector<int> dfsRes = obj.dfsOfGraph(V, adj);
    vector<int> bfsRes = obj.bfsOfGraph(V, adj);

    cout << "DFS Traversal: ";
    for (int x : dfsRes) cout << x << " ";
    cout << endl;

    cout << "BFS Traversal: ";
    for (int x : bfsRes) cout << x << " ";
    cout << endl;

    return 0;
}
