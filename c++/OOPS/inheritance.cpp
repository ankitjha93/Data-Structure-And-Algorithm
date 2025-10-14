/*

1. What is inheritance ?


*/

#include<bits/stdc++.h>
using namespace std;

/*
// parent or super class
class School{
       protected : string name;

       public:

       School(){
         name = "DPS";

       }

       void printSchoolName(){
          cout<<"School name"<<name<<endl;
       }
};


// subclass or child class
class Student : public School{
   private : string name;

   public:

   Student(string name){
     this->name = name;
   }

   void printStudentName(){
         cout<<"Student name"<<name<<endl;
   }
};

class Parent : public Student{
     private : string name;

     public:
      
     Parent(string name, string studentName)
       : Student(studentName){
         this->name = name;
       }

     void printParentName(){
         cout<<"Parent Name"<<name<<endl;
     }
};


class Teacher : public School{
   private : string name;
   private : string subjectName;

   public :
   Teacher(string name, string subjectName){
     this->name = name;
     this->subjectName = subjectName;
   }

   void printTeacherInfo(){
      cout<<"Name"<<name<<endl;
      cout<<"Subject Name"<<subjectName<<endl;
   }
};


int main(){
     
    // Parent parent("dad", "raj");

    //       parent.printParentName();
    //       parent.printStudentName();
    //       parent.printSchoolName(); 



    // Hierarichal Inheritance

    Student student("raj");
    Teacher teacher("ram", "maths");
    student.printStudentName();
    teacher.printSchoolName();
    teacher.printTeacherInfo();
          return 0;
}
        */
#include <bits/stdc++.h>
using namespace std;

// Base class
class Product {
protected:
    string name;
    string category;
    double price;

public:
    Product(string name, string category, double price) {
        this->name = name;
        this->category = category;
        this->price = price;
    }

    virtual void displayDetails() { // virtual -> allows overriding
        cout << "Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class 1
class Electronics : public Product {
private:
    int warrantyPeriodInYear;
    string brand;

public:
    Electronics(int warrantyPeriodInYear, string brand, string name, double price)
        : Product(name, "Electronics", price) {
        this->warrantyPeriodInYear = warrantyPeriodInYear;
        this->brand = brand;
    }

    void displayDetails() override {
        Product::displayDetails(); // call base class method
        cout << "Brand: " << brand << endl;
        cout << "Warranty: " << warrantyPeriodInYear << " years" << endl;
    }
};

// Derived class 2
class Tshirt : public Product {
private:
    string size;
    string color;

public:
    Tshirt(string size, string color, double price, string name)
        : Product(name, "Clothing", price) {
        this->size = size;
        this->color = color;
    }

    void displayDetails() override {
        Product::displayDetails();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
    }
};

// Main function
int main() {
    Electronics electronics(2, "LG", "Smart TV", 45000);
    Tshirt tshirt("L", "Black", 999, "Polo Tee");

    cout << "\n--- Electronics Details ---" << endl;
    electronics.displayDetails();

    cout << "\n--- T-Shirt Details ---" << endl;
    tshirt.displayDetails();

    return 0;
}





