#include <iostream>
using namespace std;

class Animal {
public:
  // Runtime polymorphism since func sound has many versions

  // compiler ignores which version of sound to excute during compile time
  // In runtime it is decided which sound fn should execute
  // virtual keyword should be used in parent class 
  virtual void sound() { cout << "Animal is making sound" << endl; }

  virtual ~Animal() {
    // detor
    cout << "Animal Detor Called" << endl;
  }
};

class Dog : public Animal {
public:
  // virtual is inherited
  // Runtime polymorphism since func sound has many versions

  void sound() { cout << "Dog is Barking" << endl; }
  ~Dog() {
    // detor
    cout << "Dog Detor Called" << endl;
  }
};

class Cat : public Animal {
public:
  // virtual is inherited
  // Runtime polymorphism since func sound has many versions
  void sound() { cout << "Cat is meowing" << endl; }
  ~Cat() {
    // detor
    cout << "Cat Detor Called" << endl;
  }
};

class Parrot : public Animal {
public:
  // virtual is inherited
  // Runtime polymorphism since func sound has many versions
  void sound() { cout << "Parrot is mimicing" << endl; }
  ~Parrot() {
    // detor
    cout << "Parrot Detor Called" << endl;
  }
};

void sound(Animal *animal) {
  // Below line is polymorphic
  animal->sound();
}

int main() {
  // if virtual keyword is added to parent class member functions and member variables 
  // then the if there exists a version of member function or of member variables in child class
  // then the implementation in child class is used and happens in runtime
  // else 
  // The parent class's implementation is used
  // In our case sound function has a different version in each of its child class child class 
  // This applies to ctor and dtor
  
  Animal *animal = new Dog(); // upcasting syntax
  sound(animal);
  delete animal;
  cout << endl;

  animal = new Cat();
  sound(animal);
  delete animal;
  cout << endl;

  animal = new Parrot();
  sound(animal);
  delete animal;

  return 0;
}