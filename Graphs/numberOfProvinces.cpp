#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adjLs[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // Convert adjacency matrix to adjacency list
        vector<int> adjLs[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};

int main() {
    int V = 3;
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution obj;
    int res = obj.numProvinces(adj, V);

    cout << "Number of Provinces: " << res << endl;

    return 0;
}


// TC - O(N) + O(V + 2E)
// SC - O(N) + O(N) --- one for vis, one for dfs which is equal to O(N)