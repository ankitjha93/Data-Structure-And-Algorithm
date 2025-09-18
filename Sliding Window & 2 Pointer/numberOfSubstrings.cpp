#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string &s){
      int n = s.size();
      int cnt = 0;
      for(int i = 0; i < n; i++){
        int hash[3] = {0};
         for(int j = i; j < n; j++){
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
                cnt = cnt + (n-j);
                break;
            }
         }
      }
      return cnt;
    
}
     
int main(){
 
    string s = "abcabc";
    int k = 2;
  
   
   int ans = numberOfSubstrings(s);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(N^2)
// SC = O(3)