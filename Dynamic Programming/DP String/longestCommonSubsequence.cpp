#include<bits/stdc++.h>
using namespace std;

// Recursion

int f(int i, int j, string & str1, string &str2){
     if(i < 0 || j < 0) return 0;

     if(str1[i] == str2[j]) return 1 + f(i-1, j-1, str1, str2);

     return max(f(i-1, j, str1, str2), f(i, j-1, str1,str2));
}

int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int n = str1.size();
  int m = str2.size();

  return f(n-1, m-1, str1, str2);
  
}
int main(){
   
   string str1 = "abcde";
    string str2 = "ace";
    cout << "Length of LCS: " << getLengthOfLCS(str1, str2);
    return 0;
}

// TC - O(2^n)
// SC - O(n)


// Memoization

int f(int i, int j, string & str1, string &str2, vector<vector<int>> & dp){
     if(i < 0 || j < 0) return 0;

     if(dp[i][j] != -1) return dp[i][j];

     if(str1[i] == str2[j]) return dp[i][j] = 1 + f(i-1, j-1, str1, str2, dp);

     return dp[i][j] = max(f(i-1, j, str1, str2, dp), f(i, j-1, str1,str2, dp));
}

int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  
  int n = str1.size();
  int m = str2.size();

  vector<vector<int>> dp(n, vector<int>(m,-1));

  return f(n-1, m-1, str1, str2, dp);
  
}

// right shift by one index

int f(int i, int j, string & str1, string &str2, vector<vector<int>> & dp){
     if(i == 0 || j == 0) return 0;

     if(dp[i][j] != -1) return dp[i][j];

     if(str1[i-1] == str2[j-1]) return dp[i][j] = 1 + f(i-1, j-1, str1, str2, dp);

     return dp[i][j] = max(f(i-1, j, str1, str2, dp), f(i, j-1, str1,str2, dp));
}

int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  
  int n = str1.size();
  int m = str2.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

  return f(n, m, str1, str2, dp);
  
}

// TC - O(n*sum)
// SC - O(n*sum) + O(n)

// Tabulation

int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  
  int n = str1.size();
  int m = str2.size();

  vector<vector<int>> dp(n+1, vector<int>(m+1,0));

 
  for(int j = 0; j <= m ; j++) dp[0][j] = 0;
  for(int i = 0; i <= n; i++) dp[i][0] = 0;

  for(int i = 1; i <= n; i++){
     for(int j = 1; j <= m; j++){
         if(str1[i-1] == str2[j-1]) dp[i][j] == 1 + dp[i-1][j-1];

         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
     }
  }
     
  return dp[n][m];
  
  
}


// TC - O(n*sum)
// SC - O(n*sum)


// Space Optimization


int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  
  int n = str1.size();
  int m = str2.size();

 
  vector<int> prev(m+1, 0), cur(m+1, 0);

  for(int j = 0; j <= m; j++) prev[j] = 0;

  for(int i = 1; i <= n; i++){
     for(int j = 1; j <= m; j++){
         if(str1[i-1] == str2[j-1]) cur[j] = 1 + prev[j-1];

         else cur[j] = max(prev[j], cur[j-1]);
     }
     prev = cur;
  }
     
  return prev[m];
  
  
}


// TC - O(n*sum)
// SC - O(sum)


// 2d array ------- to ------- 1d array


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    
    vector<int> prev(n+1, 0), cur(n+1,0);
    
    for(int N = 0; N <= n; N++){
         prev[N] = N * price[0];
    }

    for(int ind = 1; ind <= n; ind++){
         for(int N = 0; N <= n; N++){
                int notTake = 0 + prev[N];
     int take = INT_MIN;
     int rodLength = ind + 1;
     if(rodLength <= N){
         take = price[ind] + prev[N- rodLength];
     }
    prev[N] =  max(take, notTake);
         }
    }
    return prev[n];
}