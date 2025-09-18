#include<bits/stdc++.h>
using namespace std;

 struct Item{
      int value;
      int weight;
    };

class Solution {
public:
 
   double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
       
        int n = val.size();
        vector<pair<double, int>> arr;
         for(int i = 0; i < n; i++){
            double r = (double)val[i]/(double)wt[i];
            arr.push_back({r,i});
         }

         
         sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first;
         });

         double totalVal = 0.0;
         int curWeight = 0;

        
         
           
             for(auto &p : arr){
               int ind = p.second;
               if(curWeight + wt[ind] <= capacity){
                  curWeight += wt[ind];
                  totalVal += val[ind];
               }else{
                  int rem = capacity - curWeight;
                  totalVal += (double)val[ind]/(double)wt[ind] * rem;
                  break;
               }
             }
              
         return totalVal;
    }
 

};

int main(){
    Solution sol;
    
   vector<int> val = {60,100,120};
   vector<int> wt = {10,20,30};
   int capacity = 50;

   double ans = sol.fractionalKnapsack(val, wt, capacity);
     cout << fixed << setprecision(6) << ans;

   return 0;


}

// TC - O(N)
// SC - O(1)
