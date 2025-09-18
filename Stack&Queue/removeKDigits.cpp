#include <bits/stdc++.h>

using namespace std;

class Solution{
   public :

   

     string removeKDigits(string num, int k){
            stack<char> st;
            for(int i = 0 ; i < num.size();i++){
                while(!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')){
                    st.pop();
                    k = k-1;
                }
                st.push(num[i]);
            }
       
             while(k > 0){
                st.top();
                k--;
             }
              if(st.empty()) return "0";

              string res = "";
               while(!st.empty()){
              res.push_back(st.top());
                st.pop();
               }

               while(res.size() != 0 && res.back() == '0')
                 res.pop_back();
                 reverse(res.begin(), res.end());
                 if(res.empty()) return  "0";
                 return res;
        
        
     }
};

int main()
{
  
    Solution obj;
    string num = "10200";
    int k = 1;
    string res = obj.removeKDigits(num, k);
    cout<<"removed k digits is  :"<<res;
      
}