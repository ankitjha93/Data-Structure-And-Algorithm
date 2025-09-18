#include <bits/stdc++.h>
using namespace std;

void reverseK(queue<int> &q, int k) {
    if (q.empty() || k > (int)q.size() || k <= 0) {
        return;
    }

    stack<int> s;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back elements from stack (reversed part)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining elements (n-k) to the back
    int rem = q.size() - k;
    for (int i = 0; i < rem; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 7; i++) {
        q.push(i); // queue = 1 2 3 4 5 6 7
    }

    int k = 4;
    reverseK(q, k);

    cout << "Queue after reversing first " << k << " elements:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
