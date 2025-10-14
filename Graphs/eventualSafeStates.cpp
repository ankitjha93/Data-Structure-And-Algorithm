#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
         vector<int> adjRev[V];
         int indegree[V] = {0};
         for(int i = 0; i < V; i++){
            //  i -> it
            // it -> i

            for(auto it : adj[i]){
                  adjRev[it].push_back(i);
                  indegree[i]++;
            }
         }

         queue<int> q;
         vector<int> safeNodes;
         for(int i = 0; i < V; i++){
             if(indegree[i] == 0){
                 q.push(i);
             }
         }

         while(!q.empty()){
             int node = q.front();
             q.pop();
             safeNodes.push_back(node);
             for(auto it : adjRev[node]){
                 indegree[it]--;
                 if(indegree[it] == 0){
                     q.push(it);
                 }
             }
         }

         sort(safeNodes.begin(), safeNodes.end());
         return safeNodes;
    }
};


int main() {
      int V = 5;
    vector<int> adj[5];

    // Example edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);

    Solution obj;
    vector<int> safe = obj.eventualSafeNodes(V, adj);

    cout << "Safe nodes: ";
    for(int node : safe){
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}

// TC - O(V + E) + O(NlogN) -- as it is directed graph and for sorting
// SC - O(2N) + O(Rev) -- one for queue, and one for indegree