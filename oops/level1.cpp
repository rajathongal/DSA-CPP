#include <iostream>
using namespace std;

// Alan kay oops founder

// Bundle or Class
// Bundle of properties and behaviour
// Mandatory first letter Capital
// {} scope and ; are necessary as they are syntax req
class Student {
  // These are all properties of class student
  // or also called as state of class
  // or also called as attributes of class
  int id;
  int age;
  string name;
  int noOfSub;

  // These are behaviours of the class Student
  // or also called as methods of class
  // or function of class
  void study() { cout << "Studying" << endl; };
  void bunk() { cout << "Bunking" << endl; };
  void sleep() { cout << "Sleeping" << endl; };
  void writeAssignment() { cout << "Writing Assignments" << endl; };
};

int main() {
  // Student class is a blueprint / or
  // Student Object -> instance of student class
  Student s1; // same as variables 
  Student s2; // both are different instances

  return 0;
}