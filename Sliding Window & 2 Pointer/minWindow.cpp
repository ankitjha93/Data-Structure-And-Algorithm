/*#include<bits/stdc++.h>
using namespace std;

string minWindow(string &s, string &t){
   
    int minLen = INT_MAX;
    int sIndex = -1;
    int m = t.size();
    int n = s.size();

    for(int i = 0; i < n-m; i++){
        int hash[256] = {0};
        int cnt = 0;
        for(int j = 0; j < m; j++){
            hash[t[j]]++;
        }
        for(int j = 0; j < n; j++){
            if(hash[s[j]] > 0) cnt = cnt + 1;
            hash[s[j]]--;
            if(cnt == m){
                if(j-i+1 < minLen)
                 minLen = j-i+1;
                 sIndex = i;
                 break;
            }
        }
    }
     
    
    return s.substr(sIndex, minLen);

  
      
}
     
int main(){
 
    string s = "ADOBECODEBANC";
    string t = "ABC";
  
   
string ans = minWindow(s,t);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(N^2)
// SC = O(256)*/


// Optimal Solution


#include<bits/stdc++.h>
using namespace std;

string minWindow(string &s, string &t){
   int n = s.size();
   int m = t.size();
   int minLen = INT_MAX;
   int sIndex = -1;
   int l = 0, r = 0,cnt = 0;
   int hash[256] = {0};

   for(int i = 0; i < m; i++){
     hash[t[i]]++;
   }

   while(r < n){
    if(hash[s[r]] > 0) cnt = cnt + 1;
     hash[s[r]]--;
     while(cnt == m){
        if(r -l + 1 < minLen){
            minLen = r - l + 1;
            sIndex = l;
        }
        hash[s[l]]++;
    
        if(hash[s[l]] > 0) cnt = cnt - 1;
        l++;
     }
     r = r + 1;
   }
   return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}
     
int main(){
 
    string s = "ADOBECODEBANC";
    string t = "ABC";
  
   
string ans = minWindow(s,t);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(2N) + O(m)
// SC = O(256)