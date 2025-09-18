/*#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:

    bool validParenthesis(string &s, int ind, int cnt){
        int n = s.length();
           if(cnt < 0) return false;
           if(ind == n){
            return (cnt == 0);
           }
           if(s[ind] == '(')
            return validParenthesis(s, ind + 1, cnt + 1);
        if(s[ind] == ')') 
          return validParenthesis(s, ind + 1, cnt - 1);

          return validParenthesis(s, ind + 1, cnt + 1) || validParenthesis(s, ind + 1, cnt - 1) || validParenthesis(s, ind + 1, cnt);
    }

    bool checkValidString(string s) {
         return validParenthesis(s, 0,0);
    }
};

int main(){
   Solution sol;

   
   string s = "()";
   int ans = sol.checkValidString(s);
   cout<<ans;
  
}

// TC - O(3^N)
// SC - O(N)*/

// Optima Solution

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:

    bool checkValidString(string s) {
       
       int n = s.size();
       int min = 0;
       int max = 0;
       for(int i = 0; i < n; i++){
        if(s[i] == '('){
            min = min  + 1;
            max = max + 1;
        }else if(s[i] == ')'){
            min = min - 1;
            max = max - 1;
        }else{
            min = min - 1;
            max = max + 1;
        }
        if(min < 0) min = 0;
        if(max < 0) return false;
       }
       return (min == 0);
    }
};

int main(){
   Solution sol;

   
   string s = "()";
   bool ans = sol.checkValidString(s);
   cout<<ans;
  
}

// TC - O(N)
// SC - O(1)