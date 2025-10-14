#include <bits/stdc++.h>
using namespace std;

class Solution {
     private : 
    
    
     void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
            vis[node] = 1;
            for(auto it : adj[node]){
                 if(!vis[it]){
                      dfs(it , vis, st, adj);
                 }
            }
            st.push(node);
     }


  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here

         vector<int> adj[V];
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); // directed graph
        }
        
        int vis[V] = {0};
        
        stack<int> st;
        for(int i = 0; i < V; i++){
              if(!vis[i]){
                   dfs(i, vis, st, adj);
              }
        }
        
        vector<int> ans;
        while(!st.empty()){
             ans.push_back(st.top());
             st.pop();
        }
        
        return ans;
        
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
// SC - O(N) + O(N) -- which is equalt to O(N), one for vis ans one for stack