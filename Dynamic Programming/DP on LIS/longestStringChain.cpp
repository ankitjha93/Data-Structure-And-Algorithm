#include<bits/stdc++.h>
using namespace std;

bool checkPossible(string &s1, string &s2){
     if(s1.size() != s2.size() + 1) return false;
     int first = 0;
     int second = 0;

     while(first < s1.size()){
         if(s1[first] == s2[second]){
             first++;
             second++;
         }else{
             first++;
         }
     }

     if(first == s1.size() && second == s2.size()) return true;
     return false;
}


 bool comp(string &s1, string &s2){  //static required while wrapping within the class  or make it lambda function
     return s1.size() < s2.size();
}

int longestStrChain(vector<string> &heights){
    // Write your code here.

    int n = heights.size();
    vector<int> dp (n, 1);

    int maxi = 1;


    sort(heights.begin(), heights.end(), comp);

   
    

    for(int i = 0; i < n; i++){
      
        
         for(int prev = 0; prev < i; prev++){
             if(checkPossible(heights[i], heights[prev]) && 1 + dp[prev] > dp[i]){


                 dp[i] = 1 + dp[prev];
                
                 
             }
         }
     
         if(dp[i] > maxi){
             maxi = dp[i];
            
             
         }
    }

    return maxi;

    
}

int main(){
      
       vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    cout << "Longest String Chain Length: "
         << longestStrChain(words) << endl;

    return 0;
}

// TC - O(n^2 * lenght of string) + O(nlogn)
// SC - O(n)