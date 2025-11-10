#include <bits/stdc++.h>
using namespace std;

// Abstract class
class Car {
public:
    // Pure virtual function — makes this class abstract
    virtual void start() = 0;
    Car(){
         cout<<"Car constructor is called";
    }

    // Normal function (concrete)
    void noise() {
        cout << "Noise..." << endl;
    }
};



class Dealer : public Car{

    private : int numberOfCars;
    public:
    Dealer(){
         cout<<"Dealer constructor is called";
    }

    Dealer(int numberOfCars){
         this->numberOfCars = numberOfCars;
    }
  
    

};
// Derived class
class BMW : public Dealer{
public:

BMW(int number) : Dealer(number){
     cout<<"BMW Constructor is called";
}


    void start() override {
     
        cout << "BMW starting..." << endl;
    }
};

int main() {
    // Car c; ❌ Not allowed — abstract class cannot be instantiated

    BMW b(15);
    b.start();   // Calls overridden method
    b.noise();   // Calls base class method

    return 0;
}
