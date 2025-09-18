#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort in descending order using lambda
    sort(arr, arr + n, [](int a, int b) {
        return a > b;
    });

    // Print sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}