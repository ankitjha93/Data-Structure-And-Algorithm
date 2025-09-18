#include<bits/stdc++.h>
using namespace std;

vector<string> generate(int n) {
    // Your code here
    
    vector<string> result;
    
    queue<string> q;
    
    
    q.push("1");
    
    for(int i = 0; i < n; i++){
        string curr = q.front();
        q.pop();
        
        result.push_back(curr);
        
        q.push(curr + "0");
        q.push(curr + "1");
    }
    
    return result;
    
}

int main(){
     int n = 2;

    vector<string> ans =  generate(n);

    for(auto &nums : ans){
        cout<<nums<<" ";
    }cout<<endl;

    return 0;
     
}