/*

1. graph contains nodes and edges
2.There are two types of graph directed and undirected graphs
3.In directed graph all the edges are directed,
4.Cycles in a graph ---- start from a node & end at that node.
5.Path -- Contain a lot of nodes and each of them are reacheable
6.Degrees in Graph -- no. of nodes pass through that particular node. Property -- Total degree of a graph = 2 * edges.
7. In directed Graph - Indegree(node) and OutDegree(node) means no. of nodes toward that node and away from that node.
8. Edge Weight -- weight associated to that particular edge...

*/

// Adjacency Matrix

#include<bits/stdc++.h>
using namespace std;

int main(){ 
   int n, m;
   cin>>n>>m;
// graph here
   int adj[n+1][m+1];

   for(int i = 0; i < m; i++){
    int u, v;
    cin>>u>>v;
    adj[u][v] = 1;
    adj[v][u] = 1;
   }
   return 0;
}

// Adjacency List

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        // for undirected graph , O(2E)
        adj[u].push_back(v);
        adj[v].push_back(u);

        // for directed graph , O(E)

         adj[u].push_back(v);
    }
    return 0;
}

// TC - O(M)
// SC - O(N^2)





