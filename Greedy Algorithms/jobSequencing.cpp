#include <bits/stdc++.h>
using namespace std;

class Solution {  
  public:  
    static bool comparison(vector<int>& a, vector<int>& b) {
        return a[2] > b[2]; // sort by profit
    }

    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        int n = Jobs.size();
        
        // Step 1: sort jobs by profit (descending order)
        sort(Jobs.begin(), Jobs.end(), comparison);

        // Step 2: find maximum deadline
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, Jobs[i][1]);
        }

        // Step 3: create slot array
        vector<int> slot(maxi + 1, -1);

        int countJobs = 0, jobProfit = 0;

        // Step 4: place jobs
        for (int i = 0; i < n; i++) {
            for (int j = Jobs[i][1]; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += Jobs[i][2];
                    break;
                }
            }
        }

        return {countJobs, jobProfit};
    } 
};

int main() {
    Solution ob;
    vector<vector<int>> Jobs = {
        {1,4,20}, {2,1,10}, {3,2,40}, {4,2,30}
    };

    vector<int> ans = ob.JobScheduling(Jobs);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}


// TC - O(NlogN) + O(N * maxDeadline)
// SC - O(maxDeadline)

