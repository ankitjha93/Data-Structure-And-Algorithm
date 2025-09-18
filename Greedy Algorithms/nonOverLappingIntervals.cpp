#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int n = intervals.size();
         sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
             return a[1] < b[1];
         });
         int cnt = 1;

         int lastEndTime = intervals[0][1];

         for(int i = 1; i < n; i++){
             if(intervals[i][0] >= lastEndTime){
                cnt = cnt + 1;
                lastEndTime = intervals[i][1];
             }
         }
         return n - cnt;
    }
};

int main(){
  Solution sol;
  vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4},{1,3}};
//   vector<int> newInterval = {2,5};

  int ans = sol.eraseOverlapIntervals(intervals);
 
 
  cout<<ans;
  }


// TC - O(NlogN) + O(N)
// SC - O(1)