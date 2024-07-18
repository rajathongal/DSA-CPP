#include <iostream>
using namespace std;

class A {
private:
  int x;

public:
  A(int _val) : x(_val) {}

  int getX() const { return x; }

  void setX(int _val) { x = _val; }

  friend class B; // works for class 
  friend void print2(const A &a); // and works for independent functions 
};

class B {
public:
  void print(const A &a) {
    // cout << a.getX() << endl; // This works
    // you cannot modify or access x directly without friend keyword
    cout << a.x << endl;
  }
};

void print2(const A &a) {
  // cout << a.getX() << endl; // This works
  // you cannot modify or access x directly without friend keyword
  cout << a.x << endl;
}

int main() {

  A a(5);
  B b;
  b.print(a);
  return 0;
}