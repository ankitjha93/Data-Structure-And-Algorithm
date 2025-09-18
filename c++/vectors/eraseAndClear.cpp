#include<bits/stdc++.h>

using namespace std;

void eraseAt(vector<int> &arr, int pos) {
    // your code here
    arr.erase(arr.begin() + pos);
    
}

void eraseInRange(vector<int> &arr, int start, int end) {
    
    // your code here
    arr.erase(arr.begin() + start, arr.begin() + end);
}

    
void clearAll(vector<int> &arr) {
    // your code here
    arr.clear();
}
int main(){

    vector<int> arr = {2, 3, 4, 5, 6};
   
    eraseAt(arr, 2);
    eraseInRange(arr,1,3);
    clearAll(arr);


}