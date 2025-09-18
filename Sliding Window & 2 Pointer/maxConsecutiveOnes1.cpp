#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr, int k){
    
     int n = arr.size();
     int maxLen = 0;
     int l = 0, r = 0, zeroes = 0;

     while(r < arr.size()){
        if(arr[r] == 0) zeroes++;
        while(zeroes > k){
            if(arr[l] == 0) zeroes--;
            l++;
        }
        if(zeroes <= k){
            int len = r -l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
     }
    
     return maxLen;

    
}
     
int main(){
   vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
   int k = 2;
   int ans = maxConsecutiveOnes(arr,k);
   cout<<"length of  the longest subArray is :"<<ans<<endl;

}

// TC = O(2N)
// SC = O(1)