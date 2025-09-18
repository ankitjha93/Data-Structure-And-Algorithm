/*#include<bits/stdc++.h>

using namespace std;



int main(){
  vector<int> v;
  v.push_back(5);
  v.push_back(10);
  v.push_back(20);


  for(int i = 0; i < v.size(); i++){
     cout<<v[i]<< " ";
  }
  return 0;
  

}*/

// way 2


/*#include<bits/stdc++.h>

using namespace std;



int main(){

    vector<int> v = {10,5,20};


    for(int x : v){
        cout<<x<<" ";
    }
  return 0;

}*/


// Way - 2


#include<bits/stdc++.h>
using namespace std;

int main(){

//    int n = 3;
//    int x = 10;
//    vector<int> v(n,x);


   int arr[] = {10,5,20};
   int n = sizeof(arr)/sizeof(arr[0]);

   vector<int> v(arr, arr + n);

   for(auto it = v.rbegin(); it != v.rend(); it++){
         cout<<(*it)<<" ";
   }
    
  return 0;

}


