#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :
     int rainWaterTrap(vector<int> &nums){
        int n = nums.size();
        int lMax = 0, rMax = 0, total = 0;
        int l = 0 ,r = n-1;

        while(l < r){
            if(nums[l] <= nums[r]){
                if(lMax > nums[l])
                 total += lMax - nums[l];

                 else lMax = nums[l];
                  l = l + 1;
            }else{
                if(rMax > nums[r])
                 total += rMax - nums[r];
                  else rMax = nums[r];
                   r = r - 1;
            }
        }
        
        return total;
        
     }
};

int main()
{
  
    Solution obj;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = obj.rainWaterTrap(nums);
    cout<<"rain water trapped is :"<<res;
    
    
   
    
    
    
}