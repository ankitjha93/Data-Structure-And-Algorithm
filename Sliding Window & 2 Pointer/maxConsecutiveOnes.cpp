#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr, int k){
    
     int maxLen = 0;
     int n = arr.size();
     for(int i = 0; i < n; i++){
        int zeroes = 0;
        for(int j = i; j < n; j++){
            if(arr[j] == 0)
              zeroes++;

              if(zeroes <= k){
                int len = j-i+1;
                maxLen = max(maxLen, len);
              }else{
                break;
              }
        }
       
        
     }

     return maxLen;
    

    
}
     
int main(){
   vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
   int k = 2;
   int ans = maxConsecutiveOnes(arr,k);
   cout<<"length of  the longest subArray is :"<<ans<<endl;

}

// TC = O(n^2)
// SC = O(1)