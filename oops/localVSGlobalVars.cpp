// Global Variable -
// written out side a function or a class
// accessible to all functions with same copy or same memory address

// Local Variable -
// written inside a function
// accessible inside the function scope only
// scoped

#include <iostream>
using namespace std;

int x = 2; // Global Variable 

int main() {
  cout << x << endl;
  x = 20;
  cout << x << endl;

  return 0;

}