#include <iostream>
using namespace std;

void referenceVariable() {
  // variable
  int number = 100;

  // reference variable
  int &k = number;

  // reference variable
  int &c = number;

  cout << "number: " << number << endl;
  cout << "k: " << k << endl;
  cout << "c: " << c << endl;

  // if original value of original variable is modified then
  // reference variables value will also be modified
  number += 99;

  cout << "number: " << number << endl;
  cout << "k: " << k << endl;
  cout << "c: " << c << endl;

  // any reference variable modified will also affect original variable
  k++;

  cout << "number: " << number << endl;
  cout << "k: " << k << endl;
  cout << "c: " << c << endl;

  // int &kt = 6; this will throw error as reference variables do not take contants or direct inputs 
  // but take only reference of an existing variable.
}

void solve(int &a) {
  // get actual varibale address and any operation made here
  // can be seen in main function as well
  a++;
  cout << "Print inside solve " << a << endl;
}

void solve2(int &a) {
  a--;
  a = a * 10;
  cout << "Print inside solve " << a << endl;
}

void incrementBy1(int &num) {
    num++;
}

void basicCallByRef() {
    int n;
    cout << "Enter Value of n" << endl;
    cin >> n;

    incrementBy1(n);

    cout << "Value of n after increment " << n << endl;
}

int main() {
  int a = 5;
  solve(a);
  cout << "Print inside main " << a << endl;

  a++;
  solve2(a);
  cout << "Print inside main " << a << endl;

  referenceVariable();
  basicCallByRef();
}
