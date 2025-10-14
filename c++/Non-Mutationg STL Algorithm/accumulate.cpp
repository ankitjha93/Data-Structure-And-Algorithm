#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> v = {10,20,30,40, 50, 60};
    int init_res = 0;

    cout<<accumulate(v.begin(), v.end(), init_res, minus<int>);

    return 0;
}