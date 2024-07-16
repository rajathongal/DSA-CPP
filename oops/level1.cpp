#include <iostream>
using namespace std;

// Alan kay oops founder

// Bundle or Class
// Bundle of properties and behaviour
// Mandatory first letter Capital
// {} scope and ; are necessary as they are syntax req
// Classes have 3 levels of data protection or Access modifiers
// 1. Public
// 2. Private
// 3. Protected
// By Default the class variable and functions are private
// Multiple Constructors can also be referred as polymorphism behaviour
// By default int a; or Student s1; the memory allocated is of stack memory
class Student {

  // constructor function is the class in c++ which does not has return type
  // ctor constructs an instance of class
  // constructor syntax init a function with same name as class
  // class once called constructor assigns garbage values to all variables
public: // Access modifier required or by default it is private
  Student() { cout << "Student Ctor called" << endl; }
  // Parameterised contructor
  Student(double _id, double _age, bool _isPresent, string _name) {
    id = _id;
    age = _age;
    isPresent = _isPresent;
    name = _name;
  }
  // You can add as many constructors as you require
  Student(string _name, double _age) {
    name = _name;
    age = _age;
  }

private: // Access modifiers
  // These are all properties of class student
  // or also called as state of class
  // or also called as attributes of class
  int numOfBacklogs;

public: // Access modifiers
  // These are all properties of class student
  // or also called as state of class
  // or also called as attributes of class
  double id;
  double age;
  bool isPresent;
  string name;

  // These are behaviours of the class Student
  // or also called as methods of class
  // or function of class
  void study() { cout << "Studying" << endl; };
  void bunk() { cout << "Bunking" << endl; };
  void sleep() { cout << "Sleeping" << endl; };
  void writeAssignment() { cout << "Writing Assignments" << endl; };

private: // Access modifiers
  void getBacklogs() { cout << "No. of backlogs are: " << endl; }
};

class EmptyC {
  // This is an empty class to demonstrate space occupied by classes
  // When no constructor is defined compiler will add a default constructor
  // which basically does nothing
};

class Person {
public:
  Person(int numberOfGF) {
    // There exists a default pointer in class called "this" which is also
    // private variable which can be used to specifically point to objects,
    // properties of class since constructor param and var decalred in class are
    // same we use this to migigate any confusion this keyword has varioud other
    // usecase but here it is used in a lame way just to demostrate
    this->numberOfGF = numberOfGF;
  }
  int numberOfGF;
  void getNumberOfGF() { cout << "GF: " << numberOfGF << endl; }
};

int main() {
  // Student class is a blueprint / or
  // Student Object -> instance of student class
  Student s1; // same as variables
  Student s2; // both are different instances

  // empty class size demo
  // empty class occupies 1byte minimum
  // for student class the variables/props occupies space
  // functions doesnot have preccoupied space
  // space is allocated when the function is called
  EmptyC emp;
  cout << sizeof(emp) << " " << sizeof(s1) << endl;

  // one way of assigning values manually
  s1.name = "Foo Singh";
  s1.age = 24;
  s1.isPresent = true;
  s1.id = 2433423;

  cout << s1.name << endl;

  s2.name = "Honey Singh";
  s2.age = 42;
  s2.isPresent = false;
  s2.id = 2423;

  cout << s2.name << endl;

  // default or 1st constructor demo
  Student s;

  // 2rd constructor demo
  Student s3(234234324, 32, true, "Chota Singh");
  cout << s3.name << endl;

  // 3rd constructor demo
  Student s4("Love Babbar", 22);
  cout << s4.name << endl;
  cout << s4.age << endl;

  // above are all stack memory allocation example
  // since class is like a datastructure
  // heap memory can also be used
  Person *p1 = new Person(10);
  // p1 is a pointer to heap memory allocated for Person class
  // to access members of Person use ->
  // to access in stack memory you can use s1.name
  // to access heap similar to stack use dereference syntax (*p1)
  p1->getNumberOfGF();
  cout << (*p1).numberOfGF << endl; // Dereference

  // since we allocared P1 using heap memory if
  // we do not delete the instance after use there will be a memory leak
  delete p1; // no leak

  return 0;
}