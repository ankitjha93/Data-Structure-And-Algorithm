#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string &s, int k){
    int n = s.size();
    int l = 0, r = 0, maxLen = 0,maxFreq = 0;
    int hash[26] = {0};

    while(r < n){
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r]-'A']);
        if((r-l+1)- maxFreq > k){
            hash[s[l] -'A']--;
            l++;
        }
            if((r-l+1) - maxFreq <= k){
                maxLen = max(maxLen, r-l+1);
                
            }
        
        r++;
      
    }
    return maxLen;
}
     
int main(){
 
    string s = "AABABBA";
    int k = 2;
  
   
   int ans = characterReplacement(s, k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(N)
// SC = O(26)