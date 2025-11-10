#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
// static int cnt = 0;
    virtual void makeSound() = 0;
    virtual void eat() = 0;

    virtual void airBags(){
         cout<<"Car has 5 airbags";
    }

     static void wheels() {
        cout << "All cars have 4 wheels." << endl;
    }

    virtual ~Animal(){}
};

class Pet{
    public:

    virtual void sunRoof() = 0;

    virtual ~Pet(){}
};

// Implementing the interface
class Dog : public Animal,Pet {
public:
    void makeSound() override {
        airBags();
        cout << "Dog says: Woof!"<< endl;
    }

    void eat() override {
        cout << "Dog eats bones." << endl;
    }

    void sunRoof() override{
         cout<<" It has a normal sunroof";
    }
};

int main(){
      Dog an;
      an.makeSound();
      an.eat();
      an.airBags();
      an.wheels();
      an.sunRoof();
    //   Animal cn;
    //   cn.cnt();
}