/*#include<bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int> &nums, int k){
    int n = nums.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        map<int, int>mpp;
        for(int j = i; j < n; j++){
            mpp[nums[j]]++;
            if(mpp.size() == k) cnt = cnt + 1;
            else if(mpp.size() > k) break;
        }
    }
    return cnt;
}
     
int main(){
 
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
  
   
   int ans = subarraysWithKDistinct(nums, k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(N^2)
// SC = O(N)*/


// Optimal Solution


#include<bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int k){
  
    int n = nums.size();
    int l = 0, r = 0, cnt = 0;
    unordered_map<int,int>mpp;
    while(r < n){
        mpp[nums[r]]++;
        while(mpp.size() > k){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l = l + 1;
        }
        if(mpp.size() <= k){
            cnt = cnt + (r -l + 1);
        }
        r = r + 1;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int> &nums, int k){
    return atMost(nums, k) - atMost(nums, k - 1);
}
     
int main(){
 
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
  
   
   int ans = subarraysWithKDistinct(nums, k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(2*2N)
// SC = O(2*N)