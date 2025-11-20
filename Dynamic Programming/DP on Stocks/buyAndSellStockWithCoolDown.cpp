#include<bits/stdc++.h>
using namespace std;


int f(int ind, int buy, vector<int> &prices){
      if(ind >= prices.size()) return 0;

      if(buy == 1){
         return max(-prices[ind] + f(ind + 1, 0, prices),
                           0 + f(ind + 1, 1, prices));
      }
    //   ind = n - 1;

    return max(prices[ind] + f(ind + 2, 1, prices),

                        0 + f(ind + 1, 0, prices));
}

int maxProfit(vector<int>& prices) {
        return f(0,1, prices);
    }

int main(){
   int n;
    cin >> n;                 // number of days

    vector<int> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];    // input prices
    }

    cout << maxProfit(prices) << endl;
    return 0;
    
}

// TC - O(2^n)
// SC - O(n)


// Memoization

int f(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){

      if(ind >= prices.size()) return 0;

      if(dp[ind][buy] != -1) return dp[ind][buy];

      if(buy == 1){
         return dp[ind][buy] =  max(-prices[ind] + f(ind + 1, 0, prices, dp),
                   0 + f(ind + 1, 1, prices, dp));
      }
    //   ind = n - 1;

    return dp[ind][buy] = 
    max(prices[ind] + f(ind + 2, 1, prices, dp),

               0 + f(ind + 1, 0, prices, dp));
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0,1, prices, dp);
    }


// TC - O(n * 2)
// SC - O(n * 2) + O(n)

// Tabulation

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    

       for(int ind = n-1; ind >= 0; ind--){
         for(int buy = 0; buy <= 1; buy++){
               if(buy == 1){
          dp[ind][buy] =  max(-prices[ind] + dp[ind + 1][0],
                   0 + dp[ind + 1][1]);
      }else
    //   ind = n 
          dp[ind][buy] = 
                       max(prices[ind] + dp[ind + 2][1],

               0 + dp[ind + 1][0]);
         }
       }
       return dp[0][1];
    }


// TC - O(n * 2 * 3)
// SC - O(n * 2 * 3)

//  removing one  internal for loop

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<int> front1(2,0);
    
    vector<int> front2(2, 0);
    vector<int> cur(2, 0);

       for(int ind = n-1; ind >= 0; ind--){
        
        
          cur[1] =  max(-prices[ind] + front1[0],
                   0 + front1[1]);
    
    //   ind = n 
          cur[0] = 
                       max(prices[ind] + front2[1],

                                                0 + front1[0]);
         
       front2 = front1;
       front1 = cur;

        }

       return cur[1];
}

// TC - O(n)
// SC - O(6)