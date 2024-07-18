#include <iostream>
using namespace std;

class Box {
  int width;

  // ctor can be made private but
  // use only when main function or other libraries
  // should not use this class directly

  Box(int _width) : width(_width) {}

public:
  // public ctor
  // Box(int _width) : width(_width) {}

  int getWidth() const { return width; }

  void setWidth(int _width) { width = _width; }

  // You can allow other classes to use this Box class by specifying
  // classes which can use in box class using friend keyword
  friend class BoxFactory;
};

class BoxFactory {
  int count;

public:
  Box getABox(int _w) {
    ++count;
    return Box(_w);
  }
};
int main() {

  BoxFactory boxFact;
  Box bx = boxFact.getABox(10);
  cout << bx.getWidth() << endl;
  return 0;
}