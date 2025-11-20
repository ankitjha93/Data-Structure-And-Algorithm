#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    //  int n =  prices.size();

    
     vector<vector<int>> after(2, vector<int>(k + 1,0));
     vector<vector<int>> cur(2, vector<int>(k + 1,0));


    for(int ind = n-1; ind >= 0; ind--){
         for(int buy = 0; buy <= 1; buy++){
             for(int cap = 1; cap <= k; cap++){
                  if(buy == 1){
                     cur[buy][cap] = max(-prices[ind] + after[0][cap],
                                              0 + after[1][cap]);
                  }else
                     cur[buy][cap] = max(prices[ind] + after[1][cap-1],
                    
                                             0 + after[0][cap]); 

                    
                  
             }
         }
         after = cur;
    }

    return after[1][k];
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    cout << maximumProfit(prices, n, k);
    return 0;
    
}


// Another Variation

int f(int ind, int tranNo, vector<int> &prices, int n , int k){
      if(ind == n || tranNo == 2*k) return 0;

      if(tranNo % 2 == 0){  // buy
          return max(-prices[ind] + f(ind + 1, tranNo + 1, prices, n, k),
        
                        0 + f(ind + 1, tranNo , prices, n, k));
      }
       return  max(prices[ind] + f(ind + 1, tranNo + 1, prices, n, k),
    
             0 + f(ind + 1, tranNo, prices, n, k));
         
      
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    return f(0, 0, prices, n, k);
    
    
}


// Memoization

int f(int ind, int tranNo, vector<int> &prices, int n , int k, vector<vector<int>> &dp){
      if(ind == n || tranNo == 2*k) return 0;

      if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
 
      if(tranNo % 2 == 0){  // buy
          return dp[ind][tranNo] =  max(-prices[ind] + f(ind + 1, tranNo + 1, prices, n, k, dp),
        
                        0 + f(ind + 1, tranNo , prices, n, k, dp));
      }
       return  dp[ind][tranNo] =  max(prices[ind] + f(ind + 1, tranNo + 1, prices, n, k, dp),
    
             0 + f(ind + 1, tranNo, prices, n, k, dp));
         
      
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return f(0, 0, prices, n, k, dp);
    
    
}

// Tabulation


int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
     

     for(int ind = n-1; ind >= 0; ind--){
          for(int tranNo = 2 * k - 1; tranNo >= 0; tranNo--){
                 if(tranNo % 2 == 0){  // buy
                      dp[ind][tranNo] =  max(-prices[ind] + dp[ind + 1][tranNo + 1],
        
                        0 + dp[ind + 1][tranNo]);
      }else
           dp[ind][tranNo] =  max(prices[ind] + dp[ind + 1][tranNo + 1],
    
                                  0 + dp[ind + 1][tranNo]);
         
          }
     }
     return dp[0][0];
}

// Space Optimization

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.

    vector<int> after(2 *k + 1, 0);
    vector<int> cur(2 * k + 1);
     

     for(int ind = n-1; ind >= 0; ind--){
          for(int tranNo = 2 * k - 1; tranNo >= 0; tranNo--){
                 if(tranNo % 2 == 0){  // buy
                      cur[tranNo] =  max(-prices[ind] + after[tranNo + 1],
        
                        0 + after[tranNo]);
      }else
           cur[tranNo] =  max(prices[ind] + after[tranNo + 1],

                                  0 + after[tranNo]);
         
          }
          after = cur;
     }
     return after[0];
}

// TC - O(n * 2 * k)
// SC - O(n * k)