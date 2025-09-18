#include<bits/stdc++.h>

using namespace std;

void iter(vector<int> :: iterator it1, vector<int> :: iterator it2){
    for(auto it = it1; it != it2; it++){
        cout<<*it<<" ";
    }cout<<endl;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    iter(v.begin(), v.end()); 

}