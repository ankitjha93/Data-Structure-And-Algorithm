#include<bits/stdc++.h>
using namespace std;

int longestSubString(string &s){
    
    int n = s.size();
    int hash[256];
    fill(hash, hash + 256, -1);
    int l = 0, r = 0, maxLen = 0;
    while(r < n){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
        }
        int len = r-l+1;
        maxLen = max(maxLen, len);
        hash[s[r]] = r;
        r++;
    }

    return maxLen;

    
}
     
int main(){
   string s = "cadbzabcd";
   int ans = longestSubString(s);
   cout<<"length of  the longest subArray is :"<<ans<<endl;

}