#include<bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
    vector<int> dp (n, 1), hash(n);

    int maxi = 1;

    int lastIndex = 0;

    sort(heights.begin(), heights.end());

    for(int i = 0; i < n; i++){
        hash[i] = i;
         for(int prev = 0; prev < i; prev++){
             if(heights[i] % heights[prev] == 0 && 1 + dp[prev] > dp[i]){

                 dp[i] = 1 + dp[prev];
                hash[i] = prev;
             }
         }
     
         if(dp[i] > maxi){
             maxi = dp[i];
             lastIndex = i;
         }
    }

    vector<int> temp;

    temp.push_back(heights[lastIndex]);
    while(hash[lastIndex] != lastIndex){
         lastIndex = hash[lastIndex];
         temp.push_back(heights[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    // for(auto it : temp) cout<<it<<" ";
    // cout<<endl;

    return temp;
}

int main(){
       vector<int> arr = {1, 16, 7, 8, 4};
    vector<int> ans = divisibleSet(arr);

    for(int x : ans) 
        cout << x << " ";
    cout << endl;
}

// TC - O(n^2) + O(n)
// SC - O(n)