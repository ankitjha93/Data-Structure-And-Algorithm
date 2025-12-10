#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }

        return maxProfit;
    }
};


int main() {
  Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << obj.maxProfit(prices) << endl;

    return 0;
}


// TC - O(n)
// SC - O(1)