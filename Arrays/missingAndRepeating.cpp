#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int hash[n+1] = {0};
        
        for(int i = 0; i < n; i++){
             hash[arr[i]]++;
        }
        
        int repeating = -1, missing = -1;
        
        for(int i = 1; i <= n; i++){
             if(hash[i] == 2){
                  repeating = i;
             }else if(hash[i] == 0){
                  missing = i;
             }
             
             if(repeating != -1 && missing  != -1){
                  break;
                  
                  
             }
        }
        
        return {repeating, missing};
    }
};


int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> result = sol.findTwoElement(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}


// TC - O(2*n)
// SC - O(n)