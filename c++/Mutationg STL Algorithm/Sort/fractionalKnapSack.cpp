#include<bits/stdc++.h>
using namespace std;


bool myCmp(pair<int, int> a, pair<int, int> b){
      double r1 = (double)a.first/(double)a.second;

      double r2 = (double)b.first/ (double)b.second;

      return r1 > r2;
}

double fKnapS(int w, pair<int, int> arr[], int n){
      sort(arr, arr + n, myCmp);

      double res = 0.0;

      for(int i = 0; i < n; i++){
         if(arr[i].second <= w){
             res += arr[i].first;
             w = w - arr[i].second;
         }else{
             res += arr[i].first * ((double) w/ arr[i].second);
             break;
         }
      }
}

int main(){
   
    
   return 0;
}

// TC - O(nlogn) + O(n) --- O(nlogn)