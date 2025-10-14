#include<bits/stdc++.h>
using namespace std;


void merge(int a[], int b[], int m, int n){

     make_heap(b, b + n, greater<int>());


     for(int i = 0; i < m; i++){
         if(a[i] > b[0]){
             pop_heap(b , b + n, greater<int>());
             swap(a[i], b[n-1]);
             push_heap(b, b + n, greater<int>());
         }
     }
     sort(b, b + n);
}

int main(){
    //  vector<int> v = {15,6,7,12,30};
    //  make_heap(v.begin(), v.end(), greater<int>());
    //  cout<<v.front()<<endl;

    // pop_heap();
    // push_heap();

    // sort_heap();

    
     return 0;
}

// TC - O((m + n) * log n)
