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
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0)
                mpp.erase(arr[l]);
                l++;
            }
        
        if(mpp.size() <= k){
            int len = r -l+1;
            maxLen = max(maxLen, len);
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

// TC = O(2N)
// SC = O(3)