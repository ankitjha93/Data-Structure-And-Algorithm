#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for(int i = 0; i < n; i++){
             if(freq[nums[i]] == 0){
                 freq[nums[i]] += 1;
             }else{
                 return nums[i];
             }
        }
        return 0;
    }
};


int main() {
 // declare and initialize array
  vector<int> arr = {1, 3, 4, 2, 3};
  // print result
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
  // exit
  return 0;
}


// TC - O(n)
// SC - O(n)