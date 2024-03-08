#include <iostream>
using namespace std;

int main() {
  std::cout << "Hello world!" << std::endl;
  cout << "hello world from std namespace!" << endl;

  // size of an int in 4 bytes
  int num = 100;

  cout << num << endl;         // print number
  cout << &num << endl;        // print pointer
  cout << sizeof(num) << endl; // print size of

  // char is 1 byte
  char ch = 'a';
  cout << ch << endl << &ch << endl << sizeof(ch) << endl;

  // float is 4 bytes
  float fl = 0.009;
  cout << fl << endl << &fl << endl << sizeof(fl) << endl;

  // boolean is 1 byte
  bool t = true;
  bool f = false;

  cout << t << endl << f << endl << sizeof(t) << endl;

  int a = 10;
  int b = 20;

  cout << a + b << endl;
  cout << a - b << endl;
  cout << a * b << endl;
  cout << a % b << endl;
  cout << a / b << endl;

  cout << ( a > b) << endl;
  cout << ( a < b) << endl;
  cout << ( a >= b ) << endl;
  cout << ( a <= b) << endl;
  cout << ( a != b ) << endl;
  cout << ( a == b ) << endl;

  int marks;

  cout << "Enter some input number." << endl;
  cin >> marks;

  cout << "Here is your input" << endl << marks << endl;

  return 0;
}