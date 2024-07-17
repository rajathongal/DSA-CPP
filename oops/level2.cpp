#include <iostream>
using namespace std;

// Copy ctor Demo
class Student {
public:
  string name;
  int age;

  Student (): name("No Name"), age(0) {}

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

int main() {

  Student s1;
  s1.getStudent();

  return 0;
}