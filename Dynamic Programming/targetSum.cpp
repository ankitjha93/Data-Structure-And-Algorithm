#include <bits/stdc++.h> 
using namespace std;

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
    int n = arr.size();
 
    vector<int> prev(k+1,0), cur(k+1,0);


if(arr[0] == 0) prev[0] = 2;
else prev[0] = 1;

    // num[0] = 0

  
  if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= k; sum++){
             
   int notTake = prev[sum];
   int take =  0;

   

   if(arr[ind] <= sum) take = prev[sum - arr[ind]];

   cur[sum] = (take + notTake);
        }

        prev = cur;
    }

    return prev[k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalSum = 0;
    for(auto &it : arr) totalSum += it;

    if(totalSum -d < 0 || (totalSum - d) % 2) return false;
    return findWays(arr, (totalSum-d)/2);
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    return countPartitions(n, target, arr);
}