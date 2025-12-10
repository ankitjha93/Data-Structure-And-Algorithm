#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        vector<vector<int>> mergedInterval;

        for(auto it : intervals){
             if(it[0] <= tempInterval[1]){
                 tempInterval[1] = max(it[1], tempInterval[1]);
             }else{
                 mergedInterval.push_back(tempInterval);
                 tempInterval = it;
             }
        }

        mergedInterval.push_back(tempInterval);
        return mergedInterval;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    vector<vector<int>> result = sol.merge(intervals);

    for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;

}

// TC - O(nlogn) + O(n)
// SC - O(n)