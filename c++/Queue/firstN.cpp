#include <bits/stdc++.h>
using namespace std;

void printFirstN(int n) {
    queue<string> q;
    q.push("5");
    q.push("6");

    for (int count = 0; count < n; count++) {
        string curr = q.front();
        q.pop();

        cout << curr << " ";

        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main() {
    int n = 10;
    printFirstN(n);
    return 0;
}
