#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

     vector<int> rank, parent, size;

     public :
    //    vector<int> rank, parent, size;

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
             maxRow = max(maxRow, it[0]);
             maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds (maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it : stones){
              int nodeRow = it[0];
              int nodeCol = it[1] + maxRow + 1;

              ds.unionBySize(nodeRow, nodeCol);

              stoneNodes[nodeRow] = 1;
              stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for(auto it : stoneNodes){
              if(ds.findUpar(it.first) == it.first){
                  cnt++;
              }
        }

        return n - cnt; 
    }
};

int main(){
       
     int n;
    cout << "Enter number of stones: ";
    cin >> n;

    vector<vector<int>> stones(n, vector<int>(2));
    cout << "Enter stone positions (row col):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> stones[i][0] >> stones[i][1];
    }

    Solution obj;
    int ans = obj.maxRemove(stones, n);

    cout << "Maximum stones that can be removed: " << ans << endl;
    return 0;
}

// TC - 
// SC - 