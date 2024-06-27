#include <iostream>
using namespace std;

int factorial(int n) {
  // base case
  if (n == 0) {
    return 1;
  }

  if (n == 1) {
    return 1;
  }

  // recursive call
  int recursionAnswer = factorial(n - 1);

  // processing
  int finalAnswer = n * recursionAnswer;
  return finalAnswer;
}

void printReverseCount(int n) {
  // base case
  if (n == 0 || n == 1) {
    cout << 1 << endl;
    return;
  }

  // processing
  cout << n << " ";

  // recursive call
  printReverseCount(n - 1);
}

int pow(int n) {
  // base case
  // base case
  if (n == 0 ) {
    return 1;
  }

  int ans = 2 * pow(n-1);
  return ans;
}

int NfibonacciSeriesSum(int n) {
  if(n == 0) {
    return 0;
  } 
  if(n == 1) {
    return 1;
  } 

  int ans = NfibonacciSeriesSum(n-1) + NfibonacciSeriesSum(n-2);
  return ans;
}

int main() {
  // cout << factorial(5) << endl;
  // printReverseCount(20);
  // cout << pow(4) << endl;
  cout << NfibonacciSeriesSum(4) << endl;
  return 0;
}