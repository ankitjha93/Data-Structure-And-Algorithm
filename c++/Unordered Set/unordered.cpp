#include<bits/stdc++.h>
using namespace std;

int main(){

   unordered_set<int> s;

   s.insert(10);
   s.insert(5);
   s.insert(15);
   s.insert(20);

   cout<<s.size()<<" ";
   s.erase(15);

   cout<<s.size()<<" ";

   auto it = s.find(10);

   s.erase(it);

   cout<<s.size()<<" ";
   

   s.erase(s.begin(), s.end());


//    for(int x : s){
//     cout<<x<<" ";
//    }

// for(auto it = s.begin(); it != s.end()l it++){
//     cout<<(*it)<<" ";
//     cout<<endl;
//     cout<<s.size()<<" ";
//     s.clear();
// }

// if(s.find(15) == s.end()){
//     cout<<"Not Found";
// }else{
//     cout<<"Found"<<*(s.find(15));
// }

// if(s.count(15)){
//     cout<<"Found";
// } else{
//     cout<<"Not Found";
// }

   return 0;
}


/*

insert()
begin()
end()
size()
clear()
find()



** Internal Working and Time complexity

 begin(), end(),     --------> O(1)
 rbegin(), rend(),
size(), empty() 


 insert()
 erase()       -------- O(n)
 count()
 erase(val)
 find()

*/