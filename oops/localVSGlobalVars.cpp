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

void func() {
  x = 44;
  int x = 60;
  cout << x << " " << ::x << endl;
}

int main() {

  cout << x << endl;

  x = 20;
  cout << x << endl;

  int x = 40;        // Local to main function
  cout << x << endl; // Prints local variable

  // to access global variable
  cout << ::x << endl;

  // scope
  {
    int x = 22;          // local
    cout << x << endl;   // most local var is printed
    cout << ::x << endl; // global accessible
    {
      int x = 99;
      cout << x << endl;
    }
  }

  func();
  cout << ::x << endl; // global changed accessible

  return 0;
}