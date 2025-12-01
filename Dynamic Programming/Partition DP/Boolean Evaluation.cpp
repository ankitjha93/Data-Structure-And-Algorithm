#include<bits/stdc++.h>
using namespace std;

// Recursion

#define ll long long
int mod = 1e9 + 7;

long long f(int i, int j, int isTrue, string &exp){
     if(i > j) return 0;
     if(i == j){
         if(isTrue){
             return exp[i] == 'T';
         }else return exp[i] == 'F';
     }

     ll ways = 0;
     for(int ind = i + 1; ind <= j-1; ind+2){
         ll lT = f(i , ind-1, 1, exp);
         ll lF = f(i, ind -1, 0, exp);
         ll rT = f(ind + 1, j, 1, exp);
         ll rF = f(ind +1, j, 0, exp);

         if(exp[ind] == '&'){
             if(isTrue){
                 ways = (ways + (rT * lT) % mod) % mod; 
             }else ways = (ways + (rT * lF) % mod + (rF *lT) % mod + (rF * lF) % mod) % mod;
             
         }else if(exp[ind] == '|'){
             if(isTrue){
                 ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
             }else{
                 ways = (ways + (rF * lF) % mod) % mod;
             }
         }else{
            //  T^T = F, T^F = T, F^T = T, F^F = F
            if(isTrue){
                 ways = (ways + (lT * rF) % mod + (lF * rT) % mod)%mod;
            }else{
                 ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
            }
         }
     }
     return ways;
}

int evaluateExp(string & exp) {
    // Write your code here.
    return f(0, exp.size() -1, 1, exp);  
}

int main(){
      string exp;
    cin >> exp;
    cout << evaluateExp(exp);
    return 0;
}

// TC - O(n^3)
// SC - O(n^2)


// Memoization

long long f(int i, int j, int isTrue, string &exp,   vector<vector<vector<ll>>> &dp){
     if(i > j) return 0;
     if(i == j){
         if(isTrue){
             return exp[i] == 'T';

         }else return exp[i] == 'F';
     }

     if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

     ll ways = 0;
     for(int ind = i + 1; ind <= j-1; ind += 2){
         ll lT = f(i , ind-1, 1, exp, dp);
         ll lF = f(i, ind -1, 0, exp, dp);
         ll rT = f(ind + 1, j, 1, exp, dp);
         ll rF = f(ind +1, j, 0, exp, dp);

         if(exp[ind] == '&'){
             if(isTrue){
                 ways = (ways + (rT * lT) % mod) % mod; 
             }else ways = (ways + (rT * lF) % mod + (rF *lT) % mod + (rF * lF) % mod) % mod;
             
         }else if(exp[ind] == '|'){
             if(isTrue){
                 ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
             }else{
                 ways = (ways + (rF * lF) % mod) % mod;
             }
         }else{
            //  T^T = F, T^F = T, F^T = T, F^F = F
            if(isTrue){
                 ways = (ways + (lT * rF) % mod + (lF * rT) % mod)%mod;
            }else{
                 ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
            }
         }
     }
     return dp[i][j][isTrue] =  ways;
}

int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> 
      dp(n, vector<vector<ll>> (n, vector<ll>(2, -1)));
    return f(0, n -1, 1, exp, dp);
    
}

// TC - O(n^2 * n) ~ O(n^3)
// SC - O(n^2) + O(n)


