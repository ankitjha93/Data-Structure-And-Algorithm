#/*include<bits/stdc++.h>

using namespace std;

class Solution{

    public :
    // k : find kth smallest element and return using this function
    int kthLargest(vector<int> &arr, int k) {
        // code here
        
        sort(arr.rbegin(), arr.rend());
        return arr[k-1];
        
    }
};

int main(){
    Solution sol;
   vector<int> arr = {3,2,1,5,6,4};
   int k = 2;

   int ans = sol.kthLargest(arr, k);
   cout<<ans;
}


// TC : O(NlogN)
// SC : O(1)*/


// Better 


#include<bits/stdc++.h>

using namespace std;

class Solution{

    public :
    // k : find kth smallest element and return using this function
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }

        for(int i = k; i < n; i++){
            if(arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

int main(){
    Solution sol;
   vector<int> arr = {1,2,3,4,5};
   int k = 2;

   int ans = sol.kthLargest(arr, k);
   cout<<ans;
}


// TC : O(NlogN)
// SC : O(k)
