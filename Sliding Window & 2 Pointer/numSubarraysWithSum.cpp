#include<bits/stdc++.h>
using namespace std;

int atMost(vector<int> &nums, int goal){
      int n = nums.size();
      if(goal < 0) return 0;
      int l = 0, r = 0, sum = 0, cnt = 0;
      while(r < n){
        sum = sum + nums[r];
        while(sum > goal){
            sum  = sum  - nums[l];
            l = l + 1;;
        }
        cnt = cnt + (r-l+1);
        r = r + 1;
      }
      return cnt;
}

int numSubarraysWithSum(vector<int> &nums, int goal){

    return atMost(nums, goal) - atMost(nums, goal - 1);
}


     
int main(){
 
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
  
   
   int ans = numSubarraysWithSum(nums, goal);
   cout<<"longest character Replacement are :"<<ans<<endl;
   return 0;

}

// TC = O(2*2N)
// SC = O(1)