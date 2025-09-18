/*#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k){
    int maxLen = 0;
    int n = s.size();
    map<char, int> mpp;
    for(int i = 0; i < n; i++){
        mpp.clear();
        for(int j = i; j < n; j++){
            mpp[s[j]]++;
            if(mpp.size() <= k){
                maxLen = max(maxLen, j - i + 1);
            }else{
                break;
            }
        }
    }
    return maxLen;   
}
     
int main(){
 
    string s = "aabacbebebe";
    int k = 3;
  
   
   int ans = longestKSubstr(s,k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

TC = O(N^2)
SC = O(256)*/



// Better approach

/*#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k){
    int maxLen = 0;
    int n = s.size();
    int l = 0, r = 0;
    map<char, int> mpp;

    while(r < n){
        mpp[s[r]]++;
        while(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
             l = l + 1;
        }

            if(mpp.size() <= k){
                maxLen = max(maxLen, r - l + 1);
            }
            r = r + 1;
        }
    
    return maxLen;
  
      
}
     
int main(){
 
    string s = "aabacbebebe";
    int k = 3;
  
   
   int ans = longestKSubstr(s,k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(2N) + O(log(256))
// SC = O(256)*/



// Optima Solution


#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k){
    int maxLen = 0;
    int n = s.size();
    int l = 0, r = 0;
    map<char, int> mpp;

    while(r < n){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
             l = l + 1;
        }

            if(mpp.size() <= k){
                maxLen = max(maxLen, r - l + 1);
            }
            r = r + 1;
        }
    
    return maxLen;
  
      
}
     
int main(){
 
    string s = "aabacbebebe";
    int k = 3;
  
   
   int ans = longestKSubstr(s,k);
   cout<<"longest character Replacement are :"<<ans<<endl;

}

// TC = O(N) + O(log(256))
// SC = O(256)
