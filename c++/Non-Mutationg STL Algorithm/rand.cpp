#include<bits/stdc++.h>
using namespace std;


// srand(unsigned int);

// time_t time = (time_t*t);



int main(){
    
  srand(time(NULL));
    for(int i = 0; i < 5; i++){
         cout<<rand() % 100 <<" "; //  % 100 for range
    }

    return 0;
}

/*
 0 to RAND_MAX

    32767


    linear congreential generator

    x^n+1 = (ax^n + b) % m
*/