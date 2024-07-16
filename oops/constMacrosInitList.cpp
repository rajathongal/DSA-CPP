#include <iostream>
using namespace std;

// <--- Macros --->
#define PI 3.14259465
#define MaxOf(x, y) (x > y ? x : y)

class Demo {
  // Const functions Demo
  // const functions cannot change value of member variables

  // Member variables
  int x;
  int *y;
  int z;
  mutable int zz; // use mutable only for debugging
  // const int d; //  this wont be possible with normal ctor

public:
  // z id default arg
  // ctor : old style
  Demo(int _x, int _y, int _z = 0) {
    x = _x;
    *y = _y;
    z = _z;
    // d = 99; //this wont be possible with normal ctor
  }
  Demo() {
    x = 0;
    y = new int(0);
    // d = 009; // this wont be possible with normal ctor
  }

  int getX() const {
    zz = 10101;
    // x = 100; // // This function wont be able to modify variable in it
    return x;
  }

  void setX(int val) { x = val; }

  int getY() const {
    // if const is not mentioned member variables are modifiable
    // int f = 20;
    // y = &f;
    return *y;
  }

  void setY(int val) { *y = val; }

  int getZ() const { // if const not mentioned error
    return z;
  }

  int getZZ() const { return zz; }
};

void printDemo(const Demo &a) {
  // since arg has const
  // you can only call const member functions
  // wont be able to modify
  // it is possible to modify by mentioning mutable in member variables
  cout << a.getX() << endl;
  cout << a.getY() << endl;
  cout << a.getZ() << endl;
  cout << a.getZZ() << endl;
}

// <--- Initialization List --->

class InitializationListDemo {
  // This class demostrates initialisation list
  // which is new way to write ctor or constructor

  int x;
  int y;
  int *z;
  const int d;

public:
  InitializationListDemo(int _x, int _y, int _z = 99, int _d = 12)
      : x(_x), y(_y), z(new int(_z)), d(_d) {
    cout << "init" << endl;
    cout << d * d << endl;
    // d = 100; // wont be able to reassign here
  }
  void setX(int val) { x = val; }
  void setY(int val) { y = val; }

  int getX() const { return x; }

  int getY() const { return y; }
};

// <--- Macros --->
float circleArea(float r) { return PI * r * r; }

float circlePerimeter(float r) { return 2 * PI * r; }

void maaxx() {
  int x = 9;
  int y = 90;
  int c = MaxOf(x, y);
  cout << c << endl;
}

int main() {
  // initialisation can be done
  // but cannot be reassigned
  const int x = 1000; // is a const
  cout << x << endl;
  // x = 10; // expression must be a modifiable lvalue

  // This wont work in newer compilers
  // but works fine in older c++ compilers
  // int *p = &x;
  // *p = 10;
  // cout << x << endl;

  // Const with pointers

  int *a = new int;
  *a = 2;
  cout << *a << endl;
  delete a; // memory leak will be done if not deleted here

  int b = 5;
  a = &b;
  cout << *a << endl;
  // if delete done here
  // delete a; // memory leak -> allocated memory is lost when reassigned

  const int *c = new int(2);
  cout << *c << endl;
  delete c; // to avoid memory leak
  // *c = 2; // not possible

  // 1. const data, non const pointer

  // underlying value of c cannot be changed
  // but the address of the pointer can be changed
  // here will pass another variable'sa address to pointer c
  // the address of new int(2) will be lost
  int d = 201;
  c = &d;
  cout << *c << endl;

  // 2. Now we will see constant pointer and non const data
  int *const ab = new int(2);
  cout << *ab << endl;
  // data can be modifed
  *ab = 401;
  cout << *ab << endl;

  int e = 90;
  // This wont be possible since pointer is constant
  // ab = &e; // expression must be a modifiable lvalue

  cout << endl;

  Demo demo(201, 21, 99);
  printDemo(demo);

  // <--- Initialization List --->
  InitializationListDemo initDemo(22, 33);
  initDemo.getX();
  initDemo.getY();

  cout << endl;

  // <--- Macros --->
  cout << circleArea(10) << endl;
  cout << circlePerimeter(10) << endl;
  maaxx();
  return 0;
}