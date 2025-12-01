#include<bits/stdc++.h>
using namespace std;

// Recursion

int f(int ind, vector<int> &num, int k){
    int n  = num.size();
      if(ind == n) return 0;
      int len = 0;
      int maxi = INT_MIN;
      int maxAns = INT_MIN;
      for(int j = ind; j < min(ind+k, n); j++){
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + f(j+1, num, k);
            maxAns = max(maxAns, sum);
      }
      return maxAns;
}

int maximumSubarray(vector<int> &num, int k){
    // Write your code here.
    int n = num.size();
    return f(0, num, k);
}

int main(){
    
      int n, k;
    cin >> n >> k;

    vector<int> num(n);
    for(int i = 0; i < n; i++) cin >> num[i];

    cout << maximumSubarray(num, k);
    return 0;
    
}

// TC - O(n^2)
// SC - O(n)


// Memoization

int f(int ind, vector<int> &num, int k, vector<int> &dp){
    int n  = num.size();
      if(ind == n) return 0;
      int len = 0;
      int maxi = INT_MIN;
      int maxAns = INT_MIN;

      if(dp[ind] != -1) return dp[ind];

      for(int j = ind; j < min(ind+k, n); j++){
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + f(j+1, num, k, dp);
            maxAns = max(maxAns, sum);
      }
      return dp[ind]  = maxAns;
}

int maximumSubarray(vector<int> &num, int k){
    // Write your code here.
    int n = num.size();
    vector<int> dp(n,-1);
    return f(0, num, k, dp);
}

// TC - O(n) * O(k)
// SC - O(n) + O(n)



// Tabulation

int maximumSubarray(vector<int> &num, int k){
    // Write your code here.
    int n = num.size();
    vector<int> dp(n + 1, 0);

   for(int ind = n-1; ind >= 0; ind--){
          int len = 0;
      int maxi = INT_MIN;
      int maxAns = INT_MIN;


      for(int j = ind; j < min(ind+k, n); j++){
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j+1];
            maxAns = max(maxAns, sum);
      }
     dp[ind]  = maxAns;
   }
   return dp[0];

}

// TC - O(n * k) 
// SC - O(n)