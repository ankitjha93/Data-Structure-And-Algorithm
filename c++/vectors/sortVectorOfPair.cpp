#include<bits/stdc++.h>
using namespace std;


vector<pair<int, int>> sortBySecond(vector<pair<int, int>> v) {
    // Your code here
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int,int> &b){
        if(a.second != b.second)
            return a.second > b.second;
            
        
        return a.first > b.first;
    });
    return v;
}


int main(){
  vector<pair<int, int>> v = {{1,4}, {2,4}};

 v = sortBySecond(v);
for (auto &p : v) {
    cout << p.first << " " << p.second << endl;
   
}
}