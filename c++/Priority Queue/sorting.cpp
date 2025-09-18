#include<bits/stdc++.h>
using namespace std;

void mySort(int arr[], int n){
    // priority_queue<int> pq(arr, arr + n);

    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    // for(int i = n-1; i >= 0; i--){
    for(int i = 0; i < n; i++){
        arr[i] = pq.top();
        pq.pop();
    }
}

int main(){
  int arr[] = {12,5,8};
  mySort(arr, 3);
  return 0;
}

// TC - O(nlogn)


/*
Max Heap = O(k + klogn)
Min Heap = O(k + (n-k) logk)

*/