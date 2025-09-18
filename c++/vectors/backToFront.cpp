#include<bits/stdc++.h>

using namespace std;

void reverseIterator(vector<int> :: reverse_iterator it1, vector<int> :: reverse_iterator it2){
    for(auto it = it1; it != it2; it++){
        cout<<*it<<" ";
    }cout<<endl;
}

int main(){
    vector<int> v = {1,2,3,4,5};
    reverseIterator(v.rbegin(), v.rend()); 

}