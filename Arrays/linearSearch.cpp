#include<bits/stdc++.h>
using namespace std;


int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for(int i = 0; i < n; i++){
         if(arr[i] == num){
              return i;
         }
    }
    return -1;
}

int main(){
      // Declare and initialize the array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Number to search for
    int num = 4;

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the search function and store the result
    int val = linearSearch(n, num, arr);

    // Print the index of the found number or -1 if not found
    printf("%d", val);

    return 0;
}

// TC - O(n)
// SC - O(1)