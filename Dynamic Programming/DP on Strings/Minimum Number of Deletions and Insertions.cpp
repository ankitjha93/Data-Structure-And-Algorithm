#include<bits/stdc++.h>
using namespace std;

int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  
  int n = str1.size();
  int m = str2.size();

 
  vector<int> prev(m+1, 0), cur(m+1, 0);

  for(int j = 0; j <= m; j++) prev[j] = 0;

  for(int i = 1; i <= n; i++){
     for(int j = 1; j <= m; j++){
         if(str1[i-1] == str2[j-1]) cur[j] = 1 + prev[j-1];

         else cur[j] = max(prev[j], cur[j-1]);
     }
     prev = cur;
  }
     
  return prev[m];
  
  
}

int canYouMake(string &s1, string &s2){
    // Write your code here.
    return s1.size() + s2.size() - 2 *getLengthOfLCS(s1,s2);
}

int main(){
    string s1 = "abcd";
    string s2 = "ancd";
    cout << "Operations to make strings equal = "
         << canYouMake(s1, s2) << endl;

    return 0;
}

// TC -
// SC - 