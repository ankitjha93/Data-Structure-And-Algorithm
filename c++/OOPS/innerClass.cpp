#include <bits/stdc++.h>
using namespace std;

// class OuterClass
// {

// public:
//     static int val;


//     string name = "OuterClass";

//     public: 
    
//     void execute(){
//          int x = 10;
//            class InnerClass
//     {
//     public:
//         void execute()
//         {
//             cout << "Inner class executed" <<val;
            
//         }
//     };
//  x = x + 10;
//     val = val + 100;

//     InnerClass inn;
//     inn.execute();
//     }

   
    

//     // public:

//     //   void execute(){
//     //      InnerClass innerClass;
//     //      innerClass.execute();
//     //   }
// };

// int OuterClass::val = 10;

//  class Sample{
//    public:

//     virtual void execute();

//     virtual ~Sample(){};
// };


// int main()
// {

//     Sample sm = new Sample(){
  
//       public:

//        void execute(){
//          cout<<"yes i did run";
//        };

//     }
//        sm.execute();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// Custom wrapper class for vector
class MyVector {
    vector<int> data;

public:
    bool add(int val) {
        if (val % 2 == 1) { // Odd number
            cout << "Value not added: " << val << endl;
            return false;
        }
        data.push_back(val); // Even number
        return true;
    }

    void print() {
        cout << "Vector elements: ";
        for (int val : data) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MyVector list;

    list.add(10); // ✅ Added
    list.add(15); // ❌ Not added
    list.add(18); // ✅ Added

    list.print();

    return 0;
}
