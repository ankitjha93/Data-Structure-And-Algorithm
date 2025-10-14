#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
   vector<int> bfs(vector<vector<int>> &adj) {
    int n = adj.size();          // number of vertices
    vector<int> vis(n, 0);       // visited array
    vector<int> bfs;             // store result
    queue<int> q;

    vis[0] = 1;                  // start BFS from node 0
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // traverse all neighbors
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
};

int main(){
     int V = 5; // number of vertices
    vector<vector<int>> adj(V);

    // Example graph (undirected)
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    Solution obj;
    vector<int> res = obj.bfs(adj);

    cout << "BFS Traversal: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}

// TC - O(N) + O(2E)
// SC - O(3N) --- one for queue , one for vis, one for bfs which is equal to O(N)