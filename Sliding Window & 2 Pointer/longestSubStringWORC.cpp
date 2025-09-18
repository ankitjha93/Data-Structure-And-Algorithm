#include<bits/stdc++.h>
using namespace std;

int longestSubString(string &s){
    int n = s.length();
    int maxLen = 0;
    for(int i = 0; i < n; i++){
       int hash[255] = {0};
        for(int j = i; j < n; j++){
            if(hash[s[j]] == 1) break;
            int len = j - i + 1;
            maxLen = max(len, maxLen);
            hash[s[j]] = 1;
        }
    }
    return maxLen;

    
}
     
int main(){
   string s = "cadbzabcd";
   int ans = longestSubString(s);
   cout<<"length of  the longest subArray is :"<<ans<<endl;

}