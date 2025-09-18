#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :

   vector<int> findNSE(vector<int> &nums){
    int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i])
             st.pop();
              nse[i] = st.empty() ? n : st.top();
              st.push(i);
        }
        return nse;
   }

   vector<int> findPSEE(vector<int> &nums){
    int n = nums.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i])
             st.pop();
              psee[i] = st.empty() ? -1 : st.top();
              st.push(i);
        }
        return psee;
   }


     int largestRectangleArea(vector<int> &nums){
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);

        int maxi = 0;

        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i]*(nse[i]-psee[i]-1));
        }
        return maxi;
        

      
            
        
     }
};

int main()
{
  
    Solution obj;
    vector<int> nums = {2,1,5,6,2,3};
    int res = obj.largestRectangleArea(nums);
    cout<<"Largest Rectangle area is  :"<<res;
      
}