#include<iostream>
#include<map>

using namespace std;

int main(){
    // map<int,int> m;
    // m.insert({10,20});
    // m.insert({5, 300});
    // m.insert({20, 400});

    // for(auto it = m.begin(); it != m.end(); i++){
    //       cout<<(*it).first<<" "
    //       <<(*it).second<<endl;
    // }

    // m.clear();

    // cout<<m.size();


    // cout<<m.size()<<" ";
    // m[10] = 300;
    // // m.at(10) = 300
    // cout<<m[20]<<" ";
    // cout<<m.size()<<" ";





    // m[5] = 100;

    //  m.insert({3, 300});

    //  for(auto &x : m){
    //      cout<<x.first<<" "<<x.second<<" ";




    //  }



    map<int, string, greater<int>> m;
    m.insert({5, "gfg"});
    m.insert({2, "ide"});
    m.insert({1, "practice"});

    cout<<m.size()<<" ";

    m.erase(5);
    m.erase(m.find(5))
    m.erase(m.find(5), m.end());



    cout<<m.size()<<" ";



    auto it = m.upper_bound(2);

    if(it != m.end())
       cout<<(*it).first;

       else 
       cout<<"No Greater Value";


    // if(m.find(5) == m.end())

    //    cout<<"Not Found";

    //    else 

    //      cout<<"Found";

     return 0;
}


/*
insert()
operator[]
size()
empty()
clear()
begin()
end()



** map stored in key and value pair , according to key and in increasing order
   



Internal working and Time complexities


begin()
end()
rbegin()    --------> O(1)
rend()
size()
empty()



count()
find()
erase(key)     --------> O(log n)
insert()
[]
at


erase(it) --- on average takes O(1) time...

*/