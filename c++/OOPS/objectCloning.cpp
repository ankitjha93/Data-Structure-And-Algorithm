#include<bits/stdc++.h>
using namespace std;

class Passport{
 
    
    string passportNumber;

    public:
    Passport(string passportNumber){
         this->passportNumber = passportNumber;
    }

    string getPassportNumber() const {
        return passportNumber;
    }

};

class Student{
   string name;
   Passport passport;

   public:
   Student(string name, Passport passport) : passport(passport){
    this->name = name;
   };

     Student clone() const {
        return Student(name, passport);
    }
};

int main(){
      Passport passport("123");
      Student std("raj", passport);

      Student clonedStudent = std.clone();

      cout<<std.name();
      cout<<clonedStudent.name();
      cout<<std.passport.getPassportNumber();
      cout<<clonedStudent.passport.getPassportNumber();

      clonedStudent.name = "rahul";
      clonedStudent.passport.getPassportNumber("90");

        cout<<std.name();
      cout<<clonedStudent.name();
      cout<<std.passport.getPassportNumber();
      cout<<clonedStudent.passport.getPassportNumber();



}