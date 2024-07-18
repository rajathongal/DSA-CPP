#include <iostream>
using namespace std;

class Demo {
public:
  int x;
  int *y;

  // ctor with init list
  Demo(int _x, int _y) : x(_x), y(new int(_y)) {}

  // Shallow copy
  // pointer y's location is stilled not changed but remains the same
  // Demo(const Demo &other) {
  //   x = other.x;
  //   y = other.y;
  // }

  // copy constructor
  // comment below line to see shallow copy problem
  // since y is pointer and is getting memory from heap memory
  // when done Demo d2 = d;
  // same heap memory is copied to d2
  // which can cause problems
  // so we implemented a copy constructor to manually copy the
  // member variables
  // below line is an example for deep copy
  Demo(const Demo &other) : x(other.x), y(new int(*other.y)) {}

  // detor
  ~Demo() { delete y; }

  void print() const {
    printf("X: %d\nPTR Y: %p\nContent of y or *y: %d\n\n", x, y, *y);
  }
};

int main() {
  Demo d(1, 2);
  d.print();

  Demo d2 = d;
  d2.print();

  // as you can see the value of y in object d is not changed and only y in d2
  // takes changes
  d.print();

  Demo *a = new Demo(22,4);
  Demo b = *a;

  delete a;
  b.print();
  return 0;
}