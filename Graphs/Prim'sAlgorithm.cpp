#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here

        vector<vector<int>> adj[V];

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // O(E)
        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> vis(V,0);

        // {wt, node}

        pq.push({0,0});

        int sum = 0;

        // E log E + E log E
        //  E log E

        while ( !pq.empty())
        {
            /* code */

            // log E

            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if(vis[node] == 1) continue;
            // add it to the mst
            
            vis[node] = 1;
            sum += wt;

            // E log E
            for(auto it : adj[node]){
                  int adjNode = it[0];
                  int edW = it[1];
                  if(!vis[adjNode]){
                     pq.push({edW, adjNode});
                  }
            }
        }
        

        return sum;
        
    }
};

int main(){
     
     int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    Solution obj;
    cout << "MST weight = " << obj.spanningTree(V, edges) << endl;

    return 0;
}

// TC - O(E log V)
// SC - O(V + E)