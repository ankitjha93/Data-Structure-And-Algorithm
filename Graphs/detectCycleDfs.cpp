#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    
  bool dfs(int node, int parent, int vis[], vector<int> adj[]){
     vis[node] = 1;
     for(auto adjacentNode : adj[node]){
          if(!vis[adjacentNode]){
             if(dfs(adjacentNode, node, vis, adj) == true)
               return true;
          }else if(adjacentNode != parent) return true;
     }
     return false;
  }

public:
    bool isCycle(int V, vector<int> adj[]) {
         int vis[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
              
                if(dfs(i,-1,vis, adj) == true) return true;
            }
        }
        return false;
    }
};

int main() {
     int V = 5;
   vector<int> adj[V]; 

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


 
// TC - O(N + 2E) + O(N) -- which is equal to O(N + 2E) --- O(N)  for the for loop which is not run completely always
// SC - O(N) + O(N) -- which is equal to O(N)