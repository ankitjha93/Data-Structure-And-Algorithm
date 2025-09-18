#include <bits/stdc++.h>
using namespace std;

int purchaseMax(int arr[], int n, int sum) {
    // Min-heap for item costs
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    int res = 0;

    // Keep buying cheapest items until sum runs out
    while (!pq.empty() && pq.top() <= sum) {
        sum -= pq.top();
        pq.pop();
        res++;
    }
    return res;
}

int main() {
    int arr[] = {1, 12, 5, 111, 200};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;

    cout << "Maximum items that can be purchased: "
         << purchaseMax(arr, n, sum) << endl;

    return 0;
}
