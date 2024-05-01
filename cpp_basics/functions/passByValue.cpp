#include <iostream>
using namespace std;

void sumOfNumbers(int a, int b, int c) {
  // here int a,b,c has diferent memory locations and are dependant on the
  // function call creates a copy of the variable passed
  int answer = a + b + c;
  cout << "Answer is " << answer << endl;
  return; // do not send any data with return.
}

int sumByreturn(int a, int b, int c) {
  int answer = a + b + c;
  return answer;
}

int solve(int m);

int incrementBy1(int num) {
  num++;
  return num;
}

void basicCallByValue() {
  int n;
  cout << "Enter Value of n" << endl;
  cin >> n;

  n = incrementBy1(n);

  cout << "Value of n after increment " << n << endl;
}

int main() {

  // cout << "enter 3 numbers " << endl;
  sumOfNumbers(3, 5, 7);

  int sum = sumByreturn(2, 6, 9);
  cout << "Sum " << sum << endl;

  int marks = 90;
  marks++;
  solve(marks);
  basicCallByValue();
  return 1;
}

int solve(int m) {
  m--;
  m = m * 10;
  cout << m << endl;
  return m;
}