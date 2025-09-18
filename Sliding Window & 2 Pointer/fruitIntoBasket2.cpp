#include<bits/stdc++.h>
using namespace std;

int fruitIntoBasket(vector<int> &arr){
    int n = arr.size();
    int l = 0, r = 0, maxLen = 0;
    map<int,int> mpp;
    int k = 2;
  
    while(r < n){
        mpp[arr[r]]++;
        while(mpp.size() > k){
        if(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0)
              mpp.erase(arr[l]);
              l++;
        }
    }
        if(mpp.size() <= k){
            maxLen = max(maxLen, r - l + 1);
            
        }
        
        r++;
    }

    return maxLen;
    
}
     
int main(){
   vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
  
   
   int ans = fruitIntoBasket(arr);
   cout<<"length of  the longest subArray is :"<<ans<<endl;

}

// TC = O(N)
// SC = O(1)