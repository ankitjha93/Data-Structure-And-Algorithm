#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &values, int n, int fee)
{
	// Write your code here.
     int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
     
     aheadNotBuy = aheadBuy = 0;

     for(int ind = n-1; ind >= 0;ind--){

        
        

        curNotBuy = max(values[ind] - fee + aheadBuy, 
                    0 + aheadNotBuy);
              

    
        curBuy = max(-values[ind] + aheadNotBuy,   // -fee here either
                     0 + aheadBuy);
    
     
     

             aheadBuy = curBuy;
             aheadNotBuy = curNotBuy;
         
     }

     return aheadBuy;
}


int main(){
  
    int n, fee;
    cin >> n >> fee;

    vector<int> values(n);
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }

    cout << maximumProfit(values, n, fee);
}
