#include<bits/stdc++.h>
using namespace std;

// void printMaxK(int arr[], int n, int k){
//     for(int i = 0; i < n-k+1; i++){
//         int mx = arr[i];
//         for(int j = i + 1; j < i + k; j++){
//             mx = max(arr[j], mx);
//             cout<<mx<<" ";
//         }
//     }
// }


#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

// void printMaxK(int arr[], int n, int k){
//     for(int i = 0; i < n-k+1; i++){
//         int mx = arr[i];
//         for(int j = i + 1; j < i + k; j++){
//             mx = max(arr[j], mx);
//             cout<<mx<<" ";
//         }
//     }
// }


#include <bits/stdc++.h>
using namespace std;

void printMaxK(int arr[], int n, int k) {
    deque<int> dq;

    // Process first k elements (first window)
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    // Process rest of the elements
    for (int i = k; i < n; i++) {
        // Print maximum of previous window
        cout << arr[dq.front()] << " ";

        // Remove elements that are out of this window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller elements in current window
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // Print max of last window
    cout << arr[dq.front()] << endl;
}

int main() {
    int arr[] = {10, 8, 5, 12, 15, 7, 6};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    printMaxK(arr, n, k);
    return 0;
}

// TC - O(N)