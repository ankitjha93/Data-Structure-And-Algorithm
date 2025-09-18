#include<bits/stdc++.h>

using namespace std;


void corresPair(int a[], int b[], int n, pair<int, int> res[]) {
    // your code here
   for(int i = 0 ; i < n; i++){
    res[i] = {a[i], b[i]};
   }

}


int main(){
   int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    pair<int, int> res[n];

    corresPair(a, b, n, res);

    for (int i = 0; i < n; i++) {
        cout << "(" << res[i].first << ", " << res[i].second << ") ";
    }

    return 0;
}