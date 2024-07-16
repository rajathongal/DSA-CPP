#include <iostream>
using namespace std;

class StaticDemo {
public:
  int x, y;
  static int a, b;

  // this pointer is used by default when we call or assign to member functions
  // it is the reason why member variables are different for different instances
  // this keyword is a hidden parameter which is passed by default
  static void print() {
    // cout << this->x << " " << this->y << endl; // this is accessible to non
    // No this pointer accessible inside static function
    // static functions
    printf("I am in static function: %s\n", __FUNCTION__);
    cout << a << " " << b << endl;
  }

  void print2() {
    printf("I am in non-static function: %s\n", __FUNCTION__);
    cout << this->x << " " << this->y << endl;
  }
};

// All instances of Static demo will share a, b
// a, b value will be same for all instances of obj1, obj2, obj3 .. n
// static var require initialisation like below mandatory
int StaticDemo::a;
int StaticDemo::b;

int main() {
  StaticDemo obj1 = {1, 2};
  StaticDemo obj2 = {3, 4};
  StaticDemo obj3 = {5, 6};

  obj1.a = 10;
  obj1.b = 11;

  obj2.a = 101;
  obj2.b = 111;

  obj2.a = 1011;
  obj2.b = 1111;

  cout << endl;

  obj1.print2();
  obj2.print2();
  obj3.print2();

  cout << endl;

  // Static function call -> Method 1
  obj1.print();
  obj2.print();
  obj3.print();

  cout << endl;

  // Static function call -> Method 2
  StaticDemo::print();
  StaticDemo::print();
  StaticDemo::print();

  return 0;
}