#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :

     int largestRectangleArea2(vector<int> &nums){
        
        stack<int> st;
        int maxArea = 0;
        int nse;
        int pse;
        int element;
        for(int i = 0 ; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                 element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();

                maxArea = max(nums[element] *(nse- pse - 1),maxArea);
            }
            st.push(i);

        }

        while(!st.empty()){
            nse = nums.size();
            element = st.top();
            st.pop();

          pse = st.empty() ? -1 : st.top();
           maxArea = max(nums[element] *(nse- pse - 1),maxArea);

        }
        return maxArea;
     }
    
};

int main()
{
  
    Solution obj;
    vector<int> nums = {2,1,5,6,2,3};
    int res = obj.largestRectangleArea2(nums);
    cout<<"Largest Rectangle area is  :"<<res;
      
}