#include <iostream>
using namespace std;

class Animal {
public:
  // Runtime polymorphism since func sound has many versions

  // compiler ignores which version of sound to excute during compile time
  // In runtime it is decided which sound fn should execute
  virtual void sound() { cout << "Animal is making sound" << endl; }
};

class Dog : public Animal {
public:
  // virtual is inherited
  // Runtime polymorphism since func sound has many versions

  void sound() { cout << "Dog is Barking" << endl; }
};

class Cat : public Animal {
public:
  // virtual is inherited
  // Runtime polymorphism since func sound has many versions
  void sound() { cout << "Cat is meowing" << endl; }
};

void sound(Animal *animal) {
  // Below line is polymorphic
  animal->sound();
}

int main() {
  Animal *animal = new Dog(); // upcasting syntax
  sound(animal);
  delete animal;
  animal = new Cat();
  sound(animal);
  delete animal;

  return 0;
}