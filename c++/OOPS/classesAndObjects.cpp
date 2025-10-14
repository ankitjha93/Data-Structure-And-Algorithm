#include<bits/stdc++.h>
using namespace std;

class Employee{
     private:

      int salary;

       public :

       string employeeName;

       void setName(string s){
          employeeName = s;
       }

       void setSalary(int val){
           salary = val;
       }

       int getSalary(){
         return salary;
       }
};

int main(){

     Employee obj1;

     obj1.setName("Raj");
     obj1.setSalary(10000);


     Employee obj2;
     obj2.setName("Rahul");
     obj2.setSalary(15000);


     cout<<"Salary of"<<obj1.employeeName<<"is"<<obj1.getSalary()<<endl;
     cout<<"Salary of"<<obj2.employeeName<<"is"<<obj2.getSalary()<<endl;
     return 0;
}