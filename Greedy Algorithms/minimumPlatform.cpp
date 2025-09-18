/*#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:

 int findPlatform(vector<int>& arr, vector<int>& dep){
        //your code goes here
        int maxCnt = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
           int cnt = 1;
           for(int j = i + 1; j < n; j++){
             if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i])){
            cnt = cnt + 1;
           }
           }
           maxCnt = max(maxCnt, cnt);
        }
        
        return maxCnt;
    }
};

int main(){
   Solution sol;
   vector<int> Arrival = {900,940, 950, 1100, 1500, 1800};
   vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};
   int ans = sol.findPlatform(Arrival, Departure);
   cout<<ans;
  
}

// TC - O(N^2)
// SC - O(1)*/

// Optimal Solution

#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:

 int findPlatform(vector<int>& arr, vector<int>& dep){
        //your code goes here
       int n = arr.size();
       sort(arr.begin(), arr.end());
       sort(dep.begin(), dep.end());

       int i =0, j = 0, cnt = 0, maxCnt = 0;
       while(i < n){
        if(arr[i] <= dep[j]){
            cnt = cnt + 1;
            i = i + 1;
        }else{
            cnt = cnt - 1;
            j = j + 1;
        }
        maxCnt = max(maxCnt, cnt);
       }
       return maxCnt;
    }
};

int main(){
   Solution sol;
   vector<int> Arrival = {900,940, 950, 1100, 1500, 1800};
   vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};
   int ans = sol.findPlatform(Arrival, Departure);
   cout<<ans;
  
}