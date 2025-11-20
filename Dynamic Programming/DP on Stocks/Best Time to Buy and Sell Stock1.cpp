#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for(int i = 1; i < n; i++){
         int cost = prices[i] - mini;
         maxProfit = max(maxProfit, cost);
         mini = min(mini, prices[i]);
    }
    return maxProfit;
}

int main(){
      int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    cout << maximumProfit(prices);

    return 0;
}


// TC - O(n)
// SC - O(1)