#include<bits/stdc++.h>
using namespace std;


void patSearch(string txt, string pat){
     int pos = txt.find(pat);

     while (pos != string :: npos)
     {
        /* code */
        cout<<pos<<" ";
        pos = txt.find(pat, pos + 1);
     }
     
}

int main(){
    
     return 0;
}