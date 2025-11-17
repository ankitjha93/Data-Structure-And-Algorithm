#include<bits/stdc++.h>
using namespace std;

class Solution {

    private:

     int f(int i, int j, string s, string t){
          if(j < 0) return 1;
          if(i < 0) return 0;

          if(s[i] == t[j]){
             return f(i-1, j-1,s, t) + f(i-1, j, s,t);
          }

          return f(i-1, j,s,t);
     }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        return f(n-1, m-1, s, t);
    }
};

int main(){
      Solution sol;
    string s = "babgbag";
    string t = "bag";
    cout << sol.numDistinct(s, t);   // Expected output: 5
    return 0;
    
}

// TC - O(2^n * 2^m) ~ exponential
// SC - O(n + m)


// Memoization

class Solution {

    private:

     int f(int i, int j, string &s, string &t , vector<vector<int>> &dp){

          if(j < 0) return 1;
          if(i < 0) return 0;

          if(dp[i][j] != -1) return dp[i][j];

          if(s[i] == t[j]){
             return dp[i][j] =  f(i-1, j-1,s, t, dp) + f(i-1, j, s,t, dp);
          }

          return dp[i][j] =  f(i-1, j,s,t, dp);
     }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n-1, m-1, s, t, dp);
    }
};

// TC - O(n * m)
// SC - O(n + m) + O(n + m)


//  1 based indexing

class Solution {

    private:

     int f(int i, int j, string &s, string &t , vector<vector<int>> &dp){

          if(j == 0) return 1;
          if(i == 0) return 0;

          if(dp[i][j] != -1) return dp[i][j];

          if(s[i-1] == t[j-1]){
             return dp[i][j] =  f(i-1, j-1,s, t, dp) + f(i-1, j, s,t, dp);
          }

          return dp[i][j] =  f(i-1, j,s,t, dp);
     }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(n, m, s, t, dp);
    }
};

// Tabulation

  int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
             for(int j = 1; j <= m; j++){
                 if(s[i-1] == t[j-1]){
                     dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                 }else{
                     dp[i][j] = dp[i-1][j];
                 }
             }
        }

        return dp[n][m];
  }

    // TC - O(n * m)
// SC - O(n + m)


// Space Optimization

int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<double> prev(m+1, 0), cur(m + 1, 0);

        prev[0] = cur[0] = 1;

        // for(int i = 0; i <= n; i++) dp[i][0] = 1;
        // for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
             for(int j = 1; j <= m; j++){
                 if(s[i-1] == t[j-1]){
                     cur[j] = prev[j-1] + prev[j];
                 }else{
                     cur[j] = prev[j];
                 }
             }
             prev = cur;
        }

        return (int)prev[m];
  }

    // TC - O(n * m)
// SC - O(m)


// converting it into 1d

int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<double> prev(m+1, 0);

        prev[0] =  1;

        // for(int i = 0; i <= n; i++) dp[i][0] = 1;
        // for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
             for(int j = m; j >= 1; j--){
                 if(s[i-1] == t[j-1]){
                     prev[j] = prev[j-1] + prev[j];
                 }
                 
             }
        }

        return (int)prev[m];
  }

      // TC - O(n * m)
// SC - O(m)
