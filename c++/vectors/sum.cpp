#include <bits/stdc++.h>
using namespace std;

int sumMe(vector<int> arr, int n) {
    return accumulate(arr.begin(), arr.end(), 0);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    cout << sumMe(arr, n);  // Output: 15
}
