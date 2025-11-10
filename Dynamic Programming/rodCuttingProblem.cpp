#include<bits/stdc++.h>
using namespace std;

// Recursion

int f(int ind, int N, vector<int> &price){
     if(ind == 0){
         return N * price[0];
     }

     int notTake = 0 + f(ind -1, N, price);
     int take = INT_MIN;
     int rodLength = ind + 1;
     if(rodLength <= N){
         take = price[ind] + f(ind, N - rodLength, price);
     }
     return max(take, notTake);
}



int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    return f(n-1, n , price);
}

int main(){
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter the price for each piece length (1 to " << n << "): ";
    for (int i = 0; i < n; i++) cin >> price[i];

    int maxProfit = cutRod(price, n);

    cout << "\nMaximum obtainable value from rod of length " << n << " is: " << maxProfit << endl;

    return 0;
}

// TC - O(2^n)
// SC - O(n)


// Memoization

int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
     if(ind == 0){
         return N * price[0];
     }

     if(dp[ind][N] != -1) return dp[ind][N];
     int notTake = 0 + f(ind -1, N, price ,dp);
     int take = INT_MIN;
     int rodLength = ind + 1;
     if(rodLength <= N){
         take = price[ind] + f(ind, N - rodLength, price, dp);
     }
     return dp[ind][N] =  max(take, notTake);
}



int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n + 1, -1));
    return f(n-1, n , price, dp);
}

// TC - O(n*sum)
// SC - O(n*sum) + O(n)

// Tabulation

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n + 1, 0));
    
    for(int N = 0; N <= n; N++){
         dp[0][N] = N * price[0];
    }

    for(int ind = 1; ind <= n; ind++){
         for(int N = 0; N <= n; N++){
                int notTake = 0 + dp[ind - 1][N];
     int take = INT_MIN;
     int rodLength = ind + 1;
     if(rodLength <= N){
         take = price[ind] + dp[ind][N- rodLength];
     }
    dp[ind][N] =  max(take, notTake);
         }
    }
    return dp[n-1][n];
}


// TC - O(n*sum)
// SC - O(n*sum)


// Space Optimization


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
         take = price[ind] + cur[N- rodLength];
     }
    cur[N] =  max(take, notTake);
         }
         prev = cur;
    }
    return prev[n];
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