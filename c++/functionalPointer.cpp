#include <bits/stdc++.h>

using namespace std;

int multiply(int a, int b) {
    return a * b;
}

int multiplyUsingfunPointer(int a, int b) {
    // code here
    int(*funcPtr)(int, int) = multiply;
    return funcPtr(a,b);
}


int main()
{
     int result = multiplyUsingfunPointer(5,5);
     cout<<"Result "<<result<<endl;
     return 0;
}