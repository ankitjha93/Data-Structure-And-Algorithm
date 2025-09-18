#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string &s){
    
    int n = s.size();
    int cnt = 0;
    int lastSeen[3] = {-1,-1,-1};

    for(int i = 0; i < n; i++){
        lastSeen[s[i] - 'a'] = i;
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
            cnt = cnt + (1 + min({lastSeen[0],lastSeen[1],lastSeen[2]}));
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

// TC = O(N)
// SC = O(1)