#include<bits/stdc++.h>

using namespace std;


void arrayOfPairs(int arr[], int n, pair<int, int> res[], int m) {
    // code here
    int i = 0;
    int j = n-1;
    int k = 0;

    while(i <= j && k < m){
        res[k] = {arr[i], arr[j]};
        i++;
        j--;
        k++;
    }
}


int main(){
   int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = (n + 1) / 2; // number of pairs

    pair<int, int> res[m];
    
    arrayOfPairs(arr, n, res, m);

    // Print result
    for (int i = 0; i < m; i++) {
        cout << "(" << res[i].first << ", " << res[i].second << ") ";
    }

    return 0;
}