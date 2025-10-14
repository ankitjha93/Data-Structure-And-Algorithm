#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
           vector<int> adj[N];
           for(auto it : edges){
             adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
           }

           int dist[N];
           for(int i = 0; i < N; i++) dist[i] = 1e9;
           dist[src] = 0;
           queue<int> q;
           q.push(src);

           while (!q.empty())
           {
            /* code */
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                 if(dist[node] + 1 < dist[it]){
                     dist[it] = 1 + dist[node];
                     q.push(it);
                 }
            }
           }

           vector<int> ans(N, -1);
           for(int i = 0; i < N; i++){
             if(dist[i] != 1e9){
                 ans[i] = dist[i];
             }
           }

           return ans;
           
    }
};

int main() {
     int V = 5;
    vector<vector<int>> edges;

    // Example edges (chain 0-1-2-3-4)
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});

    Solution obj;
    vector<int> res = obj.shortestPath(edges, V, edges.size(), 0); // src = 0

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> " << res[i] << "\n";
    }

    return 0;
}

// TC - O(V + 2E) -- as it is undirected graph
// SC - O(3N) -- one for queue, one adj, and one for dist