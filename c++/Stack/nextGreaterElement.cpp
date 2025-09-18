#include <bits/stdc++.h>
using namespace std;

void nextGreater(int arr[], int n){
    for(int i = 0; i < n; i++){
        int j;
        for(j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                cout << arr[j] << " ";
                break;
            }
        }
        if(j == n)  // if no greater element found
            cout << -1 << " ";
    }
}

int main(){
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreater(arr, n);
    return 0;
}


// Optimal Solution


#include <bits/stdc++.h>
using namespace std;

void nextGreater(int arr[], int n){

    stack<int> s;
    s.push(arr[n-1]);

    for(int i = n-2; i >= 0; i--){
        while(s.empty() == false && s.top() <= arr[i]) s.pop();
        int nextGreater = (s.empty()) ? -1 : (s.top());
        cout<<nextGreater<<" ";
        s.push(arr[i]);
    }
}

int main(){
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreater(arr, n);
    return 0;
}