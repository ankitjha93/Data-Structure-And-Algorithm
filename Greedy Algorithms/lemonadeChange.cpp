#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
       int five = 0;
       int ten = 0;
       for(int i = 0; i < n; i++){
          if(bills[i] == 5){
            five = five + 1;
          }
          else if(bills[i] == 10){
             if(five){
                five = five - 1;
                ten = ten + 1;
             }
             else return false;
             
          } else{
            if(ten && five){
                ten = ten - 1;
                five = five - 1;
            }else if(five >= 3){
                five = five - 3;
            }else{
                return false;
            }
          }
       }
       return true;
    }
};

int main(){
    Solution sol;
    vector<int> bills= {5,5,5,10,20};
  
    
    
    int ans = sol.lemonadeChange(bills);
    
    cout<<ans;


}

// TC - O(N)
// SC - O(1)