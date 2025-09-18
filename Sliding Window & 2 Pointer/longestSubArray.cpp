#include<bits/stdc++.h>
using namespace std;

int longestSubArray(vector<int> &arr, int k){
    int l = 0;
    int r = 0;
    int sum = 0;
    int maxLen = 0;
    int n = arr.size();
    while(r < n){
       sum += arr[r];
      if(sum >k){
        sum -= arr[l];
        l++;
      }
      if(sum <= k){
        maxLen = max(maxLen, r-l+1);
        r++;
      }
    }
    return maxLen;
}
     
int main(){
   vector<int>arr = {2,5,1,10,10};
   int k = 12;
   int ans = longestSubArray(arr, k);
   cout<<"length of  the longest subArray is :"<<ans<<endl;

}