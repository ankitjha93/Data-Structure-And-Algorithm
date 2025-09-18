#include<bits/stdc++.h>

using namespace std;

class Solution{

    public :
    // k : find kth smallest element and return using this function
    int minCost(vector<int> &arr) {
        // code here
        int n = arr.size();
       priority_queue<int, vector<int>, greater<int>> pq;
        
       for(int i = 0; i < n;i++){
         pq.push(arr[i]);
       }

       int cost = 0;

       while(pq.size() > 1){
        int a = pq.top();
        pq.pop();

        int b = pq.top();
          pq.pop();

          int sum  = a + b;
          cost = cost + sum;
          pq.push(sum);
       }
        
       return cost;
    }
};

int main(){
    Solution sol;
   vector<int> arr = {4, 3, 2, 6};

   

   int ans = sol.minCost(arr);
   cout<<ans;
}


// TC : O(nlogn)
// SC : O(n)