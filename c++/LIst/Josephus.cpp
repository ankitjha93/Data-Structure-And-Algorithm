#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
      int josephus(int n, int k) {
        // code here
        int res = 0;
        for(int i = 2; i <= n; i++){
            res = (res+k)%i;
        }
        return res + 1;
        
    }
};

int main(){
   Solution sol;
   int n = 3;
   int k = 2;

   int ans = sol.josephus(n,k);
   cout<<ans;
}