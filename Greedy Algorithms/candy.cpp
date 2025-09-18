/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int candy(vector<int>& ratings) {
        int n = ratings.size();
       vector<int> left(n, 1);
        vector<int> right(n, 1);

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                left[i] = left[i-1] + 1;
            }else{
                left[i] = 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1;

            }else{
                right[i] = 1;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum + max(left[i], right[i]);
        }
        return sum;
    }
};


int main() {
  
    Solution sol;
    vector<int> ratings = {1,0,2};
    int ans = sol.candy(ratings);
    cout<<ans;
    return 0;
}


// TC - O(3N)
// SC - O(2N)*/

// Better Solution

/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int candy(vector<int>& ratings) {
        int n = ratings.size();
       vector<int> left(n, 1);
       
       

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                left[i] = left[i-1] + 1;
            }else{
                left[i] = 1;
            }
        }
        
         int right = 1;
         int sum = left[n-1];
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
              
            right = right + 1;
                

            }else{
               right = 1;
               
               
            }
            sum = sum + max(left[i],right);
        }
        return sum;
    }
    
};


int main() {
  
    Solution sol;
    vector<int> ratings = {1,0,2};
    int ans = sol.candy(ratings);
    cout<<ans;
    return 0;
}


// TC - O(2N)
// SC - O(N)*/

// Optimal Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n){
               if(ratings[i] == ratings[i-1]){
                sum = sum + 1; i++; continue;
               }
               int peak = 1;
               while(i < n && ratings[i] > ratings[i-1]){
                peak = peak + 1;
                sum = sum + peak;
                i++;
               }

               int down = 1;
               while(i < n && ratings[i] < ratings[i-1]){
                sum = sum + down;
                i++;
                down++;
               }
               if(down > peak){
                sum += down - peak;
               }
        }
        return sum;
        
    }
    
};


int main() {
  
    Solution sol;
    vector<int> ratings = {1,0,2};
    int ans = sol.candy(ratings);
    cout<<ans;
    return 0;
}

// TC - O(N)
// SC - O(1)


