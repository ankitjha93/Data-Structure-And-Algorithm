#include<bits/stdc++.h>

using namespace std;


int prec(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string result;

    for(int i = 0; i < s.length(); i++){
        char c = s[i];

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            result += c;
    }
            else if(c == '(') 
             st.push('(');

             else if( c == ')'){
                while(st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
             }
             else{


                  if(c == '^'){
                    while(!st.empty() && prec(c) <= prec(st.top())){
                        result += st.top();
                        st.pop();
                    }
                  }else{
                while(!st.empty() && prec(c) < prec(st.top())){
                    result += st.top();
                    st.pop();
                }
                st.push(c);
             }
            }
        
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    // cout<<"Prefix expression "<<result<<endl;
    return result;
}



string convertToPrefix(string infix){
    reverse(infix.begin(), infix.end());

    for(int i = 0; i < infix.size(); i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main(){
  string exp = "(a+b)*c-d+f";
    cout << "Infix expression: " << exp << endl;

    string prefix = convertToPrefix(exp);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}