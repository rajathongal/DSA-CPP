#include <iostream>
using namespace std;

// Copy ctor Demo
class Student {
public:
  string name;
  int age;

  Student() : name("No Name"), age(0) {}

  Student(string _name, int _age) {
    name = _name;
    age = _age;
  }

  Student(const Student &newSrc) {
    name = newSrc.name;
    age = newSrc.age;
  }

  void getStudent() const { cout << name << " " << age << endl; }
};

// dtor demo
class StudentWithDetor {
public:
  string name;
  int age;
  int *ptr;

  StudentWithDetor() : name("No Name"), age(0), ptr(new int(10)) {
    cout << "Student default Ctor Called" << endl;
  }

  StudentWithDetor(string _name, int _age) {
    name = _name;
    age = _age;
    ptr = new int(10); // needs to be deleted in detor
    cout << "Student parameterised Ctor Called" << endl;
  }

  StudentWithDetor(const StudentWithDetor &newSrc) {
    name = newSrc.name;
    age = newSrc.age;
    ptr = newSrc.ptr; // needs to be deleted in detor
    cout << "Student parameterised Ctor Called" << endl;
  }

  void getStudent() const { cout << name << " " << age << endl; }

  // tilde char is detor syntax ~
  // detor is public
  ~StudentWithDetor() {
    delete ptr;
    cout << "Student Detor Called" << endl;
  }
};

int main() {

  // // Copy Ctor Demo
  // Student s1("Foo", 22);
  // s1.getStudent();

  // // Copy Ctor called
  // Student s2(s1);
  // Student s3 = s1;

  // s2.getStudent();
  // s3.getStudent();

  // // dtor demo
  {
    StudentWithDetor s1("Hallu", 23);
    s1.getStudent();
  }
  StudentWithDetor s2;
  return 0;
}