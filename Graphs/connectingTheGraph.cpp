#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

    //  vector<int> rank, parent, size;

     public :
       vector<int> rank, parent, size;

         DisjointSet(int n){
            size.resize(n+1);
               rank.resize(n+1, 0);
               parent.resize(n+1);
               for(int i = 0; i <= n; i++){
                 parent[i] = i;
                 size[i] = 1;
               }
         }


         int findUpar(int node){
              if(node == parent[node])
                 return node;

                  return parent[node] = findUpar(parent[node]);
         }

         void unionByRank(int u, int v){
              int ulp_u = findUpar(u);
              int ulp_v = findUpar(v);
              if(ulp_u == ulp_v) return;
              if(rank[ulp_u] < rank[ulp_v]){
                  parent[ulp_u] = ulp_v;
              }else if(rank[ulp_v] < rank[ulp_u]){
                 parent[ulp_v] = ulp_u;
              }else{
                 parent[ulp_v] = ulp_u;
                 rank[ulp_u]++;
              }
         }

           void unionBySize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;

            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
       }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it : edge){
              int u = it[0];
              int v = it[1];
              if(ds.findUpar(u) == ds.findUpar(v)){
                  cntExtras++;
              }else{
                   ds.unionBySize(u,v);
              }
        }

        int cntC = 0;
        for(int i = 0; i < n; i++){
              if(ds.parent[i] == i) cntC++;
        }

        int ans = cntC -1;
        if(cntExtras >= ans) return ans;
        return -1;
        
    }
};

int main(){
        int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    int result = obj.Solve(n, edges);

    if (result != -1)
        cout << "Minimum operations to connect all components: " << result << endl;
    else
        cout << "Not possible to connect all components" << endl;
     return 0;
// }

// Total Time Complexity: O(N + E * α(N))
// Space Complexity: O(N) (for parent, rank, and size vectors)