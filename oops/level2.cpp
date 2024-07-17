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

// multiple inheritence demo
class Teacher {
public:
  void teach() { cout << "Teaching" << endl; }
};

class Researcher {
public:
  void research() { cout << "Researching" << endl; }
};

class Professor : public Teacher, public Researcher {
public:
  void bore() { cout << "Boring" << endl; }
};

// Diamond problem demo
class Person {
public:
  void walk() { cout << "Walking" << endl; }
};

class Teacher_ : virtual public Person {
public:
  void teach() { cout << "Teaching" << endl; }
};

class Researcher_ : virtual public Person {
public:
  void research() { cout << "Researching" << endl; }
};

class Professor_ : public Teacher_, public Researcher_ {
public:
  void bore() { cout << "Boring" << endl; }
};

// 1. compile time polymorphism demo
// a. function overloading demo
int add(int a, int b) { return a + b; }

int add(int a, int b, int c) { return a + b + c; }

double add(double a, double b) { return a + b; }

// b. operator overloading demo
class VectorX {
  int x, y;

  public:
  VectorX(int x, int y): x(x), y(y) {}

  // Operator Overloading
  // whenever + is called on class VectorX below function will be called
  void operator+(const VectorX &src) {
    // src is v2 
    this->x += src.x;
    this->y += src.y;

  }

  // void operator-(const VectorX &src) {
  //   // src is v2 
  //   this->x -= src.x;
  //   this->y -= src.y;

  // }

  // void operator++() {
  //   this->x++;
  //   this->y++;
  // }

  void display() {
    cout << "X -> " << x << endl;
    cout << "Y -> " << y << endl;

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
  // {
  //   StudentWithDetor s1("Hallu", 23);
  //   s1.getStudent();
  // }
  // StudentWithDetor s2;

  // Sparrow sp(2, 22, "Mixed brown", 2);
  // Peigon p(5, 20, "White", 2);

  // sp.getInfo();
  // sp.grassing();
  // sp.eat();
  // sp.fly();

  // p.getInfo();
  // p.guttering();
  // p.eat();
  // p.fly();

  // Professor p;
  // p.bore();
  // p.research();
  // p.teach();

  Professor_ ps;
  ps.bore();
  ps.research();
  ps.teach();
  // This wont be possible as walk mthod comes from 2 base classes teacher and
  // researcher both which inturn inherit walk method from person class
  // so the compiler is confused which version of walk to use
  // ps.walk();

  // so you can mention specifically from which class the duplicate method to be
  // used Method One Scope resolution remove virtual to run this code

  // ps.Teacher_::walk();
  // ps.Researcher_::walk();

  // add virtual in child class
  // virtual inheritence
  // same copy of walk will be executed in runtime
  // there is no specific walk for child classes
  ps.walk();

  // 1. compile time polymorphism example
  // a. method overloading or function overloading
  cout << add(2, 4) << endl;
  cout << add(2, 4, 6) << endl;
  cout << add(2.345, 4.9921) << endl;

  // b. operator overloading
  // syntax -> ++, --, ==,
  VectorX v1(1,2);
  VectorX v2(3,4);
  // suppose we want to add v1 + v2 and store it in v1
  v1 + v2;
  v1.display();

  // v1 - v2;
  // v1.display();

  // ++v1;
  // v1.display();
  return 0;
}