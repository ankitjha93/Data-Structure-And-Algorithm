#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& heights, int n)
{
	// Write your code here.

    vector<int> dp1 (n, 1);

     for(int i = 0; i < n; i++){
    
        
         for(int prev = 0; prev < i; prev++){
             if(heights[prev] < heights[i] && 1 + dp1[prev] > dp1[i]){


                 dp1[i] = 1 + dp1[prev];
             }
         }
    }


      vector<int> dp2 (n, 1);

     for(int i = n-1; i >= 0; i--){
    
        
         for(int prev =  n-1; prev > i; prev--){
             if(heights[prev] < heights[i] && 1 + dp2[prev] > dp2[i]){


                 dp2[i] = 1 + dp2[prev];
             }
         }
    }

    int maxi = 0;

    for(int i = 0; i < n; i++){
         maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    
    return maxi;

}

int main(){
      
       vector<int> arr = {1, 4, 3, 2, 5, 2, 1};
    cout << longestBitonicSubsequence(arr, arr.size()) << endl;
    
}

// TC - O(n^2)
// SC - O(n)