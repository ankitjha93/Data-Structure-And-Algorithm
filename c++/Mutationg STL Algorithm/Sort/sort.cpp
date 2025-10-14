#include<bits/stdc++.h>
using namespace std;

int main(){
   int arr[] = {10,20,5,7};
    int n = arr.size();
   sort(arr, arr + n);

   for(int x : arr){
      cout<<x<<" ";
   }

   sort(arr, arr + n, greater<int>);

   cout<<endl;

   for(int x : arr){
     cout<<x<<" ";
   }
}


/*
 worst case and Average case - O(nlogn)

 --> uses introSort --- hybrid of quickSort, insertionSort and heapSort

*/