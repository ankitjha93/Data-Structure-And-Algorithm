#include<bits/stdc++.h>
using namespace std;


// method overloading
class Calculator{
    public:

      int add(int a, int b){
          return a + b;
      }

      double add(double a, double b){
           return a + b;
      }

      int add(int a, int b, int c){
         return a + b + c;
      }
};


// method override

class Parent{
    public :

    static void print(){
         cout<<"Static Method";
    }

      virtual void display(){
         cout<<"Parent class";
      }

};

class Child : public Parent{
    public :

    

       void display() override{
        Parent(print());
         cout<<"Parent class";
      }

};



int main(){
    Calculator obj = Calculator();
    // compile time polymorphism
    cout<<obj.add(1,2);


    // dynamic binding 
    // runtime
    Child child = Child();
    child.display();
     return 0;
}