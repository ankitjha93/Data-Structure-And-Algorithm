#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

     vector<int> rank, parent, size;

     public :

         DisjointSet(int n){
            //    rank.resize(n+1, 0);
               size.resize(n+1);
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

        //  void unionByRank(int u, int v){
        //       int ulp_u = findUpar(u);
        //       int ulp_v = findUpar(v);
        //       if(ulp_u == ulp_v) return;
        //       if(rank[ulp_u] < rank[ulp_v]){
        //           parent[ulp_u] = ulp_v;
        //       }else if(rank[ulp_v] < rank[ulp_u]){
        //          parent[ulp_v] = ulp_u;
        //       }else{
        //          parent[ulp_v] = ulp_u;
        //          rank[ulp_u]++;
        //       }
        //  }

         void unionBySize(int u, int v){
             int ulp_u = findUpar(u);
             int ulp_v = findUpar(v);
             if(ulp_u == ulp_v) return;

             if(size[ulp_u] < size[ulp_v]){
                 parent[ulp_u] = ulp_v;
                 size[ulp_v] += size[ulp_u];
             }else{
                  parent[ulp_v] = ulp_u;
                  size[ulp_u] += size[ulp_v];
             }
         }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
          // Convert edges to {wt, {u, v}} format
        vector<pair<int, pair<int, int>>> edgeList;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            edgeList.push_back({wt, {u, v}});
        }

        // Sort edges by weight
        sort(edgeList.begin(), edgeList.end());

        DisjointSet ds(V);
        int mstWt = 0;

        // Pick edges one by one
        for (auto it : edgeList) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // If u and v belong to different components, take the edge
            if (ds.findUpar(u) != ds.findUpar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
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
        {2, 4, 7}
    };

    Solution obj;
    cout << "Minimum Spanning Tree Weight: " << obj.kruskalsMST(V, edges) << endl;

    return 0;
     
}

// TC - O(E log E) + O(E * 4 * alpha * 2)
// SC - O(V + E)