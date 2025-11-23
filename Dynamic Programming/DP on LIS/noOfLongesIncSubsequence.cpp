#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
     vector<int> dp (n, 1), cnt(n, 1);

    int maxi = 1;

  
    

    for(int i = 0; i < n; i++){
       
        
         for(int prev = 0; prev < i; prev++){
             if(heights[prev] < heights[i] && 1 + dp[prev] > dp[i]){


                 dp[i] = 1 + dp[prev];

                //  inherit

                cnt[i] = cnt[prev];
             
                 
             }else if(heights[prev] < heights[i] && 1 + dp[prev] == dp[i]){
                //   increase the count
                cnt[i] += cnt[prev];
             }
         }
     
        maxi =  max(maxi, dp[i]);  // store the len of LIS


         
    }


    int nos = 0;
    for(int i = 0; i < n; i++){
         if(dp[i] == maxi) nos += cnt[i];
    }

    return nos;
}

int main(){
      
     vector<int> arr = {1,3,5,4,7};
    cout << findNumberOfLIS(arr) << endl;
    
}

// TC - O(n^2)
// SC - O(n)