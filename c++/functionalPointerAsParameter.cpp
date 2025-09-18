#include <bits/stdc++.h>

using namespace std;

int add(int x, int y) {
    return x + y;
}


int mul(int x, int y) {
    return x * y;
}



int compute( int a, int b, int(*operation)(int, int)) {
    // code here
    return operation(a,b);
    
}


int main()
{
     
    int a = 5, b = 3;

      cout << "Addition: " << compute(a, b, add) << endl;


      
    cout << "Multiplication: " << compute(a, b, mul) << endl;

    return 0;
  
    
}