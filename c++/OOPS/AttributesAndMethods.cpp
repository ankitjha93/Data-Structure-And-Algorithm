/*

1. What are attributes and Methods
2. How attributes and Methods works together?
3. Key points for starter(accessing, encapsulation, default values, error handling)
4. Implement a Bank Account class keeping all thing in mind



*/

#include<bits/stdc++.h>
using namespace std;



// getter and setter

class BankAccount{
  
     private:

        string name;
        double balance;

        BankAccount(string name, double balance){
             this->name = name;
             this->balance = balance;
        }

        public:
           void setName(string name){
              this->name = name;
           }

           string getName(){
              return name;
           }

           double getBalance(){
               return balance;
           }


        //    default constructor

           BankAccount(){
             name = "";
             balance = 0.0;
           }

        //    error handling

        void addMoney(double amount){
             if(amount > 0) balance += amount;
             else{
                 cout<<"Amount is in negative";
             }
        }

        bool withdrawMoney(double amount){
              if(amount >= balance){
                 balance -= amount;
                 return true;
              }

              cout<<"Balance Low";
              return false;
        }
};
int main(){

    
     return 0;
}