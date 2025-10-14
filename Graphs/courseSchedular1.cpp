#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(int V, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> adj[V];
        
        for(auto it : prerequisites){
            adj[it.first].push_back(it.second);
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
         
        //  int cnt = 0;
          while(!q.empty()){
             int node = q.front();
             q.pop();
             topo.push_back(node);
            // cnt++;

            //  node is in your topo sort, so please remove it from the degree

            for(auto it : adj[node]){
                  indegree[it]--;
                  if(indegree[it] == 0) q.push(it);
            }
          }
        
          if(topo.size() == V) return true;
          return false;

    }
};

int main() {
      int V = 5;
    vector<pair<int, int>> prerequisites;

    // Example edges
    prerequisites.push_back({0, 1});
    prerequisites.push_back({1, 2});
    prerequisites.push_back({2, 3});
    prerequisites.push_back({3, 4});

    // Uncomment this to introduce a cycle: 4 -> 1
    // prerequisites.push_back({4, 1});

    Solution obj;
    bool possible = obj.isPossible(V, prerequisites.size(), prerequisites);

    if (possible)
        cout << "Graph does not contain a cycle\n";
    else
        cout << "Graph contains a cycle\n";

    return 0;
}

// TC - O(V + E) -- as it is directed graph
// SC - O(2N) -- one for queue, and one for indegree