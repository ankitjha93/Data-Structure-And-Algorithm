#include<bits/stdc++.h>
using namespace std;

int main(){
     vector<int> v = {10,20,20,20, 30, 40};
     auto it = upper_bound(v.begin(), v.end(), 20);
      cout<<(*it)<<endl;

      it = upper_bound(v.begin(), v.end(), 30);
       cout<<(*it)<<endl;
         return 0;
}


/*

upper_bound  :- Returns an iterator to the first greater element in a sorted range.

O(log n ) - when we have random access.
          - n is the total no. of element in the range.
*/