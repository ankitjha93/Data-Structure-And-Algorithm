#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end){
    while(start < end){
         swap(arr[start], arr[end]);
         start++;
         end--;
    }
}

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int n = arr.size();
    if(n == 0 || k == 0) return arr;

    // left 

    reverseArray(arr, 0, k-1);
    reverseArray(arr, k, n-1);
    reverseArray(arr, 0, n-1);

return arr;
    
}

int main() {
   
    

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
   
    

    vector<int> result = rotateArray(nums, k);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

// TC - O(n)
// SC - O(1)