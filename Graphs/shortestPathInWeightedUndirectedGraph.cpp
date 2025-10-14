#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n+1];
        for(auto it : edges){
             adj[it[0]].push_back({it[1], it[2]});
             adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        dist[1] = 0;
        pq.push({0,1});
        while (!pq.empty())
        {
            /* code */
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            for(auto it : adj[node]){
                 int adjNode = it.first;
                 int edW = it.second;
                 if(dis + edW < dist[adjNode]){
                     dist[adjNode] = dis + edW;
                     pq.push({dist[adjNode], adjNode});
                     parent[adjNode] = node;
                 }
            }
        }

        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;

        while(parent[node] != node){
             path.push_back(node);
             node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
        
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
    vector<int> res = obj.shortestPath(V, E, edges); // src = 0 internally

    cout << "Shortest path from 0 to " << V << ":\n";
    for (auto node : res) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}

// Time Complexity: O((V + E) log V) ≈ O(E log V) + O(N) for the traversal
// Space Complexity: O(V + 2E)