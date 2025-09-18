#include <bits/stdc++.h>
using namespace std;

vector<int> sortVector(vector<int> v) {
    sort(v.begin(), v.end()); // Sort in ascending order
    return v;
}

vector<int> reverseVector(vector<int> v) {
    reverse(v.begin(), v.end()); // Reverse the vector
    return v;
}

int main() {
    vector<int> v = {5, 1, 4, 2, 3};

    v = sortVector(v);     // Sorted: 1 2 3 4 5
    v = reverseVector(v);  // Reversed: 5 4 3 2 1

    for (int x : v) {
        cout << x << " ";
    }
}
