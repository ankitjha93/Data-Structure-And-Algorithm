#include<bits/stdc++.h>
using namespace std;


bool isSum(int arr[], int n){
    for(int i = 0; i < n; i++){
        int curr_sum = 0;
        for(int j = i; j < n; j++){
            curr_sum += arr[j];
            if(curr_sum == 0)
                return true;
        }
    }
    return false; // ✅ only after checking all subarrays
}


bool isSum(int arr[], int n){
    unordered_set<int> s;
    int pre_sum = 0;

    for(int i = 0; i < n; i++){
        pre_sum = pre_sum + arr[i];

        if(s.find(pre_sum) != s.end())   // prefix sum repeats → zero-sum subarray
            return true;

        if(pre_sum == 0)                 // prefix sum itself is 0 → zero-sum subarray
            return true;

        s.insert(pre_sum);               // store prefix sum
    }

    return false;
}


int main(){
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(isSum(arr, n))
        cout << "Subarray with sum 0 exists\n";
    else
        cout << "No subarray with sum 0\n";

    return 0;
}