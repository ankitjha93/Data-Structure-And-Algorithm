/*#include<bits/stdc++.h>

using namespace std;

class Solution{

    public :
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());

       
        return arr[k-1];
    }

};

int main(){
    Solution sol;
   vector<int> arr = {7, 10, 4, 3, 20, 15};
   int k = 3;

   int ans = sol.kthSmallest(arr, k);
   cout<<ans;
}*/




// using heap

#include<bits/stdc++.h>

using namespace std;

class Solution{

    public :
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;

        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }

        for(int i = k; i < arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }

        return pq.top();
        
    }
};

int main(){
    Solution sol;
   vector<int> arr = {7, 10, 4, 3, 20, 15};
   int k = 3;

   int ans = sol.kthSmallest(arr, k);
   cout<<ans;
}


// TC : O(nlogk)
// SC : O(k)