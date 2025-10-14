#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:
       void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
            vis[node] = 1;
            for(auto it : adj[node]){
                  if(!vis[it]){
                     dfs(it, vis, adj,st);
                  }
            }
            st.push(node);
       }

       private :

         void dfs3(int node, vector<int> &vis, vector<int> adjT[]){
                vis[node] = 1;
                for(auto it : adjT[node]){
                     if(!vis[it]){
                         dfs3(it,vis, adjT);
                     }
                }
         }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();

        vector<int> vis(n, 0);
        stack<int> st;
// O(V+E)
        for(int i = 0; i < n; i++){
              if(!vis[i]){
                 dfs(i, vis, adj, st);
              }
        }

        vector<int> adjT[n];

        // O(V +E)

        for(int i  = 0; i < n; i++){
             vis[i] = 0;
             for(auto it : adj[i]){
                // i  -> it
                // it -> i

                adjT[it].push_back(i);
             }
        }

        int scc = 0;
        // O(V + E)
        while(!st.empty()){
              int node = st.top();
              st.pop();
              if(!vis[node]){
                 scc++;
                 dfs3(node, vis, adjT);
              }
        }
        return scc;
        
    }
};


int main(){
     
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " directed edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    int result = obj.kosaraju(adj);

    cout << "\nNumber of Strongly Connected Components: " << result << endl;

    return 0; 
}


// TC - O(V + E) + O(V + E) + O(V + E)
// SC - O(2 * V) + O(V + E)