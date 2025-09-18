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


      int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
          vector<vector<int>> pSum(n, vector<int>(m, 0));
        int maxArea = 0;
   
        for(int  j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){

                sum += matrix[i][j] -'0';

                if(matrix[i][j] == '0') sum = 0;
                pSum[i][j] = sum;
            }
        }

        for(int i = 0; i < n; i++){
            maxArea = (max(maxArea, largestRectangleArea2(pSum[i])));
        }

        return maxArea;
    }
    
};

int main()
{
  
    Solution obj;
vector<vector<char>> matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};
    int res = obj.maximalRectangle(matrix);
    cout<<"Maximal Rectangle is  :"<<res;
      
}