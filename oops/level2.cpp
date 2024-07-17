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

// Inheritence Demo
// Parent class
class Bird {
public:
  string name;
  int age, weight;
  int nol;
  string color;

  void eat() { cout << name << " is Eating" << endl; }

  void fly() { cout << name << " is Flying" << endl; }

  void getInfo() {
    cout << age << " " << weight << " " << nol << " " << color << endl;
  }
};

// child class
// Public here is mode of abstraction
// or it will bring all public member variables and methods
class Sparrow : public Bird {
public:
  Sparrow() { this->name = "Sparrow"; }
  Sparrow(int age, int weight, string color, int nol) {
    this->age = age;
    this->nol = weight;
    this->color = color;
    this->weight = nol;
    this->name = "Sparrow";
  }
  void grassing() { cout << "Sparrow is Grassing" << endl; }
};

class Peigon : public Bird {
public:
  Peigon() { this->name = "Peigon"; }
  Peigon(int age, int weight, string color, int nol) {
    this->age = age;
    this->nol = weight;
    this->color = color;
    this->weight = nol;
    this->name = "Peigon";
  }
  void guttering() { cout << "Peigon is guttering" << endl; }
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
  // {
  //   StudentWithDetor s1("Hallu", 23);
  //   s1.getStudent();
  // }
  // StudentWithDetor s2;

  Sparrow sp(2, 22, "Mixed brown", 2);
  Peigon p(5, 20, "White", 2);

  sp.getInfo();
  sp.grassing();
  sp.eat();
  sp.fly();

  p.getInfo();
  p.guttering();
  p.eat();
  p.fly();

  return 0;
}