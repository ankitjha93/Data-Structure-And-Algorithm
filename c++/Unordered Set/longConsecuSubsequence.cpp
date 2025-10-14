#include<bits/stdc++.h>
using namespace std;

int findLongest(int arr[], int n){
    sort(arr, arr + n);  // O(n log n)
    int res = 1, curr = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1] + 1){
            curr++;
        } else if(arr[i] != arr[i-1]) {  // handle duplicates
            res = max(res, curr);
            curr = 1;
        }
    }

    res = max(res, curr);
    return res;
}


int main(){
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Longest consecutive subsequence length = " 
         << findLongest(arr, n) << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int getLongest(int arr[], int n){
    int res = 0;
    unordered_set<int> h;

    for(int i = 0; i < n; i++){
        h.insert(arr[i]);
    }
    
    for(int i = 0; i < n; i++){
        // Only check if arr[i] is the start of a sequence
        if(h.find(arr[i] - 1) == h.end()){
            int curr = 1;
            int x = arr[i];

            // Count consecutive numbers
            while(h.find(x + curr) != h.end()){
                curr++;
            }

            res = max(res, curr);
        }
    }
    return res;
}

int main(){
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Longest consecutive subsequence length = " 
         << getLongest(arr, n) << endl;
    return 0;
}


int main(){
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Longest consecutive subsequence length = " 
         << findLongest(arr, n) << endl;
    return 0;
}
