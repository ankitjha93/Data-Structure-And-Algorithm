#include<bits/stdc++.h>
using namespace std;

int LCSubStr(string &s1, string &s2)
{

    // Write your code here
    int n = s1.size();
    int m = s2.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++){
         for(int j = 1; j <= m; j++){
             if(s1[i-1] == s2[j-1]){ 
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            
            }
             else dp[i][j] = 0;
         }
    }
    return ans;

}


int main(){
      string s1 = "abcjklp";
    string s2 = "acjkp";
    cout << "Length of Longest Common Substring: " << LCSubStr(s1, s2);
    return 0;
    
}

// TC - O(n*m)  + O(n + m)
// SC - O(n*m) + O(L)


// Space Optimization

int LCSubStr(string &s1, string &s2)
{

    // Write your code here
     int n = s1.size();
    int m = s2.size();
      vector<int> prev(m+1, 0), cur(m + 1, 0);

    // for(int j = 0; j <= m; j++) dp[0][j] = 0;
    // for(int i = 0; i <= n; i++) dp[i][0] = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++){
         for(int j = 1; j <= m; j++){
             if(s1[i-1] == s2[j-1]){ 
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            
            }
             else cur[j] = 0;
         }
         prev = cur;
    }
    return ans;

}

// TC - O(n*m)  + O(n + m)
// SC - O(m) + O(L)
