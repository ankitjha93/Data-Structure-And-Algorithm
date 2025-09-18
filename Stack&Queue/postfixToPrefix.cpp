#include<bits/stdc++.h>

using namespace std;


// int prec(char c){
//     if(c == '^') return 3;
//     else if(c == '*' || c == '/') return 2;
//     else if(c == '+' || c == '-') return 1;
//     else return -1;
// }

void postfixToPrefix(string s){
    stack<string> st;
    int n = s.length();
    int i = 0;
    // string result;

    while(i < n){
     char c = s[i];
       
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            st.push(string(1,c));
    }else{
        string t1 = st.top();
         st.pop();
         string t2 = st.top();
         st.pop();

         string con = c + t2 + t1 ;
          st.push(con);
    }
    i++;

    }
   
    cout<<st.top()<<endl;
    
}

int main(){
   string exp  = "ab-de+f*/";
   cout<<"Postfix expression "<<exp<<endl;
   postfixToPrefix(exp);
   return 0;
}