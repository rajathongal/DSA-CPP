#include <iostream>
using namespace std;
// Alternative to long if else chaining
int SwitchCase() {
  float a, b, ans;
  cout << "Enter Two Numbers" << endl;
  cin >> a >> b;

  int op;

  cout << "What Operation you want to do ?" << endl;
  cin >> op;

  // op
  // 0 -> add
  // 1 -> sub
  // 2 -> mul
  // 3 -> div
  // invalid op

  // op is an expression which must be of integral value which means it should
  // be an int, char,short, long, long long etc no float / double not allowed
  switch (op) {
  case 0:
    ans = a + b;
    break;
  case 1:
    ans = a - b;
    break;

  case 2:
    ans = a * b;
    break;

  case 3:
    ans = a / b;
    break;

  default:
    cout << "Invalid Operation" << endl;
    return 1;
  }

  cout << "Your answer is: " << ans << endl;
  return 0;
}

int main() {
  SwitchCase();
  return 0;
}