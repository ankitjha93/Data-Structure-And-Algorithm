#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :

   
     vector<int> asteriodCollision(vector<int> &nums){
         vector<int> st;

         for(int i = 0; i < nums.size(); i++){
             if(nums[i] > 0) st.push_back(nums[i]);
             else{
                while(!st.empty() && st.back() > 0 && st.back() < abs(nums[i])){
                    st.pop_back();
                }
                if(!st.empty() && st.back() == abs(nums[i])){
                    st.pop_back();
                }
                else if(st.empty() || st.back() < 0){
                    st.push_back(nums[i]);
                }
             }
             
        
             
            }
            
            
        return st;
     }
};

int main()
{
  
    Solution obj;
    vector<int> nums = {5, 10, -5};
    vector<int> res = obj.asteriodCollision(nums);
   
    
    cout << "Surviving asteroids: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
      
}