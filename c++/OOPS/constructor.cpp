/*

1. key Features
2. Purpose of a constructor
3. Types of constructor
4. Can a constructor call another constructors?
5. Can a constructor be overloaded ?

*/

// parameterized constructor


#include<bits/stdc++.h>
using namespace std;


class Account{
    private :

     string name;
     double balance;

     public:
       Account(string name, double balance){
          this->name = name;
          this->balance = balance;
       }

       double getBalance(){
          return balance;
       }

       string getName(){
           return name;
       }

    //    constructor overloading


    Account(string name){
         this->name = name;
    }

    Account(double balance){
         this->balance = balance;
    }

    // copy constructor

    Account(Account account){
          Account(account.getBalance(), account.getName());
    }

};

int main(){
  
    
    Account obj1 = new Account("raj", 1000);

    cout<<obj1.getName()<<obj1.getBalance()<<endl;

    //copy constructor

    Account obj2 = new Account(obj1);
}
     
