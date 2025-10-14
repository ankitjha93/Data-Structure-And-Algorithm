#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
         vector<int> adj[V];
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); // directed graph
        }

         int indegree[V] = {0};
         for(int i = 0; i < V; i++){
              for(auto it : adj[i]){
                 indegree[it]++;
              }
         }

         queue<int> q;

          for(int i = 0; i < V; i++){
              if(indegree[i] == 0){
                  q.push(i);
              }
          }

          vector<int> topo;
          while(!q.empty()){
             int node = q.front();
             q.pop();
             topo.push_back(node);

            //  node is in your topo sort, so please remove it from the degree

            for(auto it : adj[node]){
                  indegree[it]--;
                  if(indegree[it] == 0) q.push(it);
            }
          }
        
          return topo;
    }
};

int main() {
        int V = 5;
    vector<vector<int>> edges;

    // Example edges (DAG)
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});

    Solution obj;
    vector<int> topo = obj.topoSort(V, edges);

    cout << "Topological Sort: ";
    for(auto node : topo){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

// TC - O(V + E)
// SC - O(N) + O(N) -- which is equal to O(N), one for indegree ans one for queue