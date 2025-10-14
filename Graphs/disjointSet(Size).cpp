// **    Union By Size

#include<bits/stdc++.h>
using namespace std;

// class DisjointSet{

//      vector<int> rank, parent, size;

//      public :

//          DisjointSet(int n){
//                size.resize(n+1);
//                parent.resize(n+1);
//                for(int i = 0; i <= n; i++){
//                  parent[i] = i;
//                  size[i] = 1;
//                }
//          }


//          int findUpar(int node){
//               if(node == parent[node])
//                  return node;

//                   return parent[node] = findUpar(parent[node]);
//          }

//          void unionBySize(int u, int v){
//              int ulp_u = findUpar(u);
//              int ulp_v = findUpar(v);
//              if(ulp_u == ulp_v) return;

//              if(size[ulp_u] < size[ulp_v]){
//                  parent[ulp_u] = ulp_v;
//                  size[ulp_v] += size[ulp_u];
//              }else{
//                   parent[ulp_v] = ulp_u;
//                   size[ulp_u] += size[ulp_v];
//              }
//          }
// };


class DisjointSet{
     private:
       
    vector<int> parent, size;


    public:
    DisjointSet(int n){
       size.resize(n+1);
       parent.resize(n+1);
       for(int i = 0; i <= n; i++){
           parent[i] = i;
           size[i] = 1;
       }
     }

       int findUpar(int node){
           if(node == parent[node]){
                return node;
           }

           return parent[node] = findUpar(parent[node]);
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

int main(){

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // if 3 and 7 same or not
    if(ds.findUpar(3) == ds.findUpar(7)){
         cout<<"Same"<<endl;
    }else{
         cout<<"Not Same"<<endl;
    }

    ds.unionBySize(3,7);

    if(ds.findUpar(3) == ds.findUpar(7)){
         cout<<"Same"<<endl;
    }else{
         cout<<"Not Same"<<endl;
    }
     return 0;
}

// TC - O(4 alpha)


