#include<bits/stdc++.h>
using namespace std;

// int main(){
//      string str = "geeksforgeeks";
//      cout<<str;
//      return 0;
// }

int main(){
     string str = "gfg";
     cout<<str.length()<<endl;
     str = str + "xyz";
     cout<<str<<endl;
     cout<<str.substr(1,3)<<endl;
     cout<<str.find("fg");

     getline(cin, str, '$');

     
     return 0;
}