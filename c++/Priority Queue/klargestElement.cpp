#include <bits/stdc++.h>
using namespace std;

void printklargest(int arr[], int n, int k) {
    // Min heap of size k
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Step 1: push first k elements
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Step 2: check remaining elements
    for (int i = k; i < n; i++) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Step 3: print k largest (in ascending order, since min-heap)
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    int arr[] = {5, 12, 11, -1, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "K largest elements are: ";
    printklargest(arr, n, k);

    return 0;
}


// TC - O(k + (n-k) * logk) + O(klogk)
