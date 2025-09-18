// Brute Force

// #include<bits/stdc++.h>
// using namespace std;

// int stockSpan(vector<int> & arr){
//      int n = arr.size();
    
//      for(int i = 0; i < n; i++){
//         int span = 1;
//         for(int j = i - 1; j >= 0; j--){
//             if(arr[j] <= arr[i]){
//                 span = span + 1;

//             }else{
//                 break;
//             }
//         }
//         cout<<span<<" ";
//      }
//     //  cout<<span<<" ";
// }

// int main(){
//      vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
//     stockSpan(arr);
//     return 0;
// }



// Optimal Solution

#include<bits/stdc++.h>
using namespace std;

int stockSpan(vector<int> & arr){
    int n = arr.size();    
    stack<int> s;

    s.push(arr[0]);

    for(int i =1 ; i < n; i++){
        while(s.empty() == false && arr[s.top()] <= arr[i]) s.pop();

        int span = (s.empty()) ? i + 1 : (i-s.top());
        cout<<span<<" ";
        s.push(i);
    }

}

int main(){
     vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    stockSpan(arr);
    return 0;
}