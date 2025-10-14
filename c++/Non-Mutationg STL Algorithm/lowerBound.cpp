#include<bits/stdc++.h>
using namespace std;

int main(){
     vector<int> v = {10,20,20,20, 30, 40};
     auto it = lower_bound(v.begin(), v.end(), 20);
      cout<<(*it)<<endl;

      it = lower_bound(v.begin(), v.end(), 25);
       cout<<(*it)<<endl;
         return 0;
}


/*

lower_bound  :- Returns an iterator having address of element greater than equal to given value in a given sorted range.
*/