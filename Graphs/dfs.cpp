#include<bits/stdc++.h>
using namespace std;

class Solution {

    private :

     void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ls){
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
      }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
         vector<int> vis(n, 0); // visited array 
          int start = 0; // start DFS from node 0
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
    
    
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
    vector<int> res = obj.dfs(adj);

      cout << "DFS Traversal: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}

// TC - O(N) + O(2E)
// SC - O(3N) --- one for queue , one for vis, one for dfs which is equal to O(N)