#include <iostream>
using namespace std;

class Base {
public:
  Base() { // cannot be virtual
    cout << "Base ctor" << endl;
  }
  virtual ~Base() { // necessary
    cout << "Base dtor" << endl;
  }
};

class Derived : public Base {
  int *a;

public:
  Derived() {
    a = new int[12];
    cout << "Derived ctor" << endl;
  }
  ~Derived() {
    delete[] a;
    cout << "Derived dtor" << endl;
  }
};

int main() {
  Base *b = new Derived();
  delete b;
  return 0;
}