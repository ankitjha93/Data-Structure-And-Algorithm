#include<bits/stdc++.h>

using namespace std;

void sortChar(int a[],  char b[], int n){
    pair <int,char> p[n];
    for(int i = 0; i < n; i++){
       p[i] = {a[i], b[i]};

       sort(p, p + n);

       for(int i = 0; i < n; i++){
        cout<<p[i].second<<" ";
       }
       cout<<endl;
    }
}

int main(){
    int a[] = {3, 1, 2};
    char b[] = {'c', 'a', 'b'};
    int n = sizeof(a) / sizeof(a[0]);

    sortChar(a, b, n);

    return 0;
}