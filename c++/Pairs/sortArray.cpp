#include<bits/stdc++.h>

using namespace std;



void sortArray(int a[], char b[], int n) {

    // code here
    vector<pair<int, char>> vp;
    for(int i = 0; i < n;i++){
        vp.push_back({a[i], b[i]});
    }

    sort(vp.begin(), vp.end());
    
    for(int i = 0; i < n; i++){
        a[i] = vp[i].first;
        b[i] = vp[i].second;
    }
    // cout<<b;
    
}


int main(){
   int a[] = {30, 10, 20};
    char b[] = {'C', 'A', 'B'};
    int n = sizeof(a) / sizeof(a[0]);

    sortArray(a, b, n);

    // Printing sorted arrays
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << "\n";
    }

    return 0;
}