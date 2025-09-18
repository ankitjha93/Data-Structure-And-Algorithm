#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :
     vector<int> nextGreaterElement(vector<int> &nums){
        int n = nums.size();
        vector<int> nge(n,-1);
        stack<int> st;

        for(int i = n-1;i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i])
                st.pop();
        
        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();
         st.push(nums[i]);
        }
        return nge;
     }
};

int main()
{
    Solution obj;
    vector<int> nums = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> res = obj.nextGreaterElement(nums);
    cout<<"The next greater elements are :"<<endl;
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    
    
}