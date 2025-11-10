#include<bits/stdc++.h>
using namespace std;


//  one to one relationship
// class Passport{
//    private:


//      string passportNumber;

//      public:

//      Passport(string passportNumber){
//         this->passportNumber = passportNumber;
//      }

//      public :

//      string getPassportNumber(){
//          return passportNumber;
//      }



// };


// class Student{

//    private: string name;
//    private: Passport passport;


//    public:

//    Student(string name, Passport passport)  :name(name), passport(passport) {};
   
    

//    public: void displayDetails(){
//      cout<<"Student name"<<name<<endl;
//      cout<<"Passport Number"<<passport.getPassportNumber();
//    }
// };

// int main(){
//       Passport pass("1q4434");
//       Student  stu("rah", pass);

//       stu.displayDetails();
// }


//  one to many

// class Student{

//    private: string name;
//    private : string id;
   
//    public:
//    Student(string name, string id){
//      this->name = name;
//      this->id = id;
//    }

//    string getName(){
//      return name;

//    }

//    string getId(){
//     return id;
//    }
   
// };

// class College{
//     private : string name;
//     private : vector<Student> students;

//     public:

//     College(string name) : name(name){

        
        
//     };

//     void addStudent(Student student){
//           students.push_back(student);
//     }

//     void printAllStudents(){
//          for(int i = 0; i < students.size(); i++){
//                Student student = students[i];

//                cout<<"Student"<<student.getName()<<"id"<<student.getId();
//          }
//     }
// };

// int main(){
//      Student student1("raj","1");

//      Student student2("rahul", "2");

//      College college("JKU");
//      college.addStudent(student1);
//      college.addStudent(student2);

//      college.printAllStudents();
// }

//  many to many


// class Student{
//   private : string name;
//   private : vector<Course> courses;

//   public:

//   Student(string name){
//      this->name = name;
//   }
  
//   void addCourse(Course course){
//      courses.push_back(course);
//   }

//   string getName(){
//      return name;
//   }

//     void displayAllCourses(){
//       for(int i = 0; i < courses.size(); i++){
//          cout<<"Students"<<courses[i].getName();
//       }
//    }
// };

// class Course{
//    private: string name;
//    private : vector<Student> students;
   
//    public:


//    Course(string name){
//      this->name = name;

   
     
//    }

//    void addStudent(Student student){
//      students.push_back(student);
//    }

//    void displayAllStudents(){
//       for(int i = 0; i < students.size(); i++){
//          cout<<"Students"<<students[i].getName();
//       }
//    }

//    string getName(){
//      return name;
//    }

// };

// int main(){
//   Course math = Course("math");
//   Course cs = Course("cs");

//   Student raj("raj");
//   Student rahul("rahul");
//   Student karan("karan");

//   raj.addCourse(math);
//   raj.addCourse(cs);
//   cs.addStudent(raj);
//   math.addStudent(raj);

//   rahul.addCourse(math);
//   math.addStudent(rahul);

//   karan.addCourse(cs);
//   cs.addStudent(karan);

//   math.displayAllStudents();
//   cs.displayAllStudents();

//   raj.displayAllCourses();

// }


class Passport{
   private : string name;

   public:

   Passport(string name){ 
    this->name = name;
   }
};

class Student{
    private : string name;
    private : Passport passport;

    public:

    Student(string name, string  passportNumber): name(name), passport(passportNumber){
         
      
        
    }
};


int main(){
    //  Passport passport("123");
     Student std("raj", "123");
}




// Aggregation







