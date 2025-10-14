#include<bits/stdc++.h>
#include<tuple>
using namespace std;

int main(){
     tuple<string, int, string> t = make_tuple("abc", 10, "xyz");

     cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t), get<0>(t) = "pqr";

     cout<<"\n"<<get<0>(t);

     cout<<tuple_size<<decltype(t)

     tuple_cat(t1,t2);

     return 0;
}