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


     vector<int> findNGE(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

     vector<int> findPGEE(vector<int> &nums) {
        int n = nums.size();
        vector<int> pgee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }


     long long sumOfSubarrayRanges(vector<int> &nums){
            
       
        
        vector<int>nse = findNSE(nums);
        vector<int>psee = findPSEE(nums);
        long long minSum = 0;

        for(int i = 0; i < nums.size(); i++){
            int left = i-psee[i];
            int right = nse[i]-i;

            minSum = (minSum + (left * right ) * nums[i] );
            
        }

        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);
        long long maxSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            maxSum = (maxSum + (left * right) * nums[i]);
        }

        return (maxSum - minSum);
        
     }
};

int main()
{
  
    Solution obj;
    vector<int> nums = {-37988,-14446,-34454,-85916,44628,-63469,2405,76071,43291,499,-43933,-10950,22587,45756,36078,49794,81866,-70327,80649,19025,82130,-53646,99394,63520,20667,41291,80388,-82451,-17666,52744,-84498,30104,41847,67932,-89959,-42134,-79079,80796,-27089,9691,-26248,-31934,-20681,33506,16422,-98706,-16321,847,55516,-85834,-3479,-58562,77791,62111,-15830,33478,79046,-47470,-54997,-56231,11301,3998,73631,47168,66983,98655,-31405,-11411,50967,-15908,37346,73429,-95644,83331,74868,-23201,70451,73304,38820,-32124,80413,-23607,65237,88536,29905,-35443,-36683,64419,-25056,73050,17960,16070,54748,76597,74972,-73098,74704,55261,-38420,-42739,15098,-8078,82487,-34954,-38895,39994,35077,-36851,87932,7216,-87758,-27817,66742,77803,-16270,41596,-14558,28610,4151,-2590,-73414,56156,93465,31128,-19581,-44840,-87553,-79674,-2016,3190,62008};
    int res = obj.sumOfSubarrayRanges(nums);
    cout<<"sum of subarray Ranges is  :"<<res;
      
}