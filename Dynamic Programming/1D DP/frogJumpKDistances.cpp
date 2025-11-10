// #include<bits/stdc++.h>
// using namespace std;

// recursive



// int frogJump(vector<int> &heights, int k)
// {
//     // Write your code here.

        //   int n = heights.size();
//     if(n == 0) return 0;
//     int minSteps = INT_MAX;
//     for(int j = 1; j <= k; j++){
//         if(n-j >= 0){
//          int jumps = frogJump(n-j) + abs(heights[n] - heights[n-j]);
//          minSteps = min(minSteps, jumps);
//         }
//         return minSteps;
//     }
    
// }

// TC - O(N)*K
// SC - O(N) + O(N)

// Tabulation


#include <bits/stdc++.h>
using namespace std;

int frogJump(vector<int> &heights, int k) {
    int n = heights.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0; // Base case: No cost to stand on the first stone

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                dp[i] = min(dp[i], jump);
            }
        }
    }

    return dp[n - 1];
}

int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;

    cout << frogJump(heights, k);
    return 0;
}

// TC - O(N)*K
// SC - O(N)





