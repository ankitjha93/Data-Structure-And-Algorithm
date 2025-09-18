#include<bits/stdc++.h>

using namespace std;


// int prec(char c){
//     if(c == '^') return 3;
//     else if(c == '*' || c == '/') return 2;
//     else if(c == '+' || c == '-') return 1;
//     else return -1;
// }

void prefixToPostfix(string s){
    stack<string> st;
    int n = s.length();
    int i = n-1;
    // string result;

    while(i >= 0){
     char c = s[i];
       
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            st.push(string(1,c));
    }else{
        string t1 = st.top();
         st.pop();
         string t2 = st.top();
         st.pop();

         string con = t1 + t2 + c;
          st.push(con);
    }
    i--;

    }
   
    cout<<st.top()<<endl;
    
}

int main(){
   string exp  = "/-ab*+def";
   cout<<"Infix expression "<<exp<<endl;
   prefixToPostfix(exp);
   return 0;
}