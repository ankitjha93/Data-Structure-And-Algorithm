#include<bits/stdc++.h>
using namespace std;

struct Data{
     int start;
     int end;
     int pos;

};

   
  bool cmp(Data val1, Data val2) {
    if (val1.end == val2.end) 
        return val1.pos < val2.pos; // tie-breaker by position
    return val1.end < val2.end;
}

class Solution{
	public:

   int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<Data> arr(n);
        for(int i = 0; i < n; i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }
        sort(arr.begin(), arr.end(), cmp);

        int cnt = 1;
        int freeTime = arr[0].end;
        vector<int> ds = {arr[0].pos};

        for(int i = 1; i <= n - 1; i++){
            if(arr[i].start > freeTime){
                cnt = cnt + 1;
                freeTime = arr[i].end;
                ds.push_back(arr[i].pos);
            }
        }
        
        return cnt;
    }
};

int main(){
   Solution sol;

   
  
vector<int> start = {1, 3, 0, 5, 8, 5};
vector<int> end = {2, 4, 6, 7, 9, 9};

int ans = sol.maxMeetings(start,end);
 cout<<ans;
  
}

// TC - O(2N + NlogN)
// SC - O(3*N) + // Depends O(N)