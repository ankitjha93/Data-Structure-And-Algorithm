#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string &s, int k){
    int n = s.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++){
         int hash[26] = {0};
          int maxFreq = 0;
         for(int j = i; j < n; j++){
             hash[s[j] - 'A']++;
             maxFreq = max(maxFreq, hash[s[j] - 'A']);
             int len = j -i + 1;
             int chng = len - maxFreq;

             if(chng <= k){
                maxLen = max(maxLen, len);
             }else{
                break;
             }
         }

         return maxLen;
    }
    
    
}
     
int main(){
 
    string s = "AABABBA";
    int k = 2;
  
   
   int ans = characterReplacement(s, k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(N^2)
// SC = O(26)