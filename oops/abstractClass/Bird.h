#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

// Interface
class Bird {
public:
  // pure virtual function
  virtual void eat() = 0;
  virtual void fly() = 0;

  // child classes which inherits the bird class
  // has to implement pure virtual functions mandatorily
};

// Implementation
class Sparrow : public Bird {
private:
  void eat() {
    std::cout << "Sparrow is eating" << std::endl;
  }
  void fly() {
    std::cout << "Sparrow is flying" << std::endl;
  }
};

// Implementation
class Eagle : public Bird {
private:
  void eat() {
    std::cout << "Eagle is eating" << std::endl;
  }
  void fly() {
    std::cout << "Eagle is flying" << std::endl;
  }
};
#endif