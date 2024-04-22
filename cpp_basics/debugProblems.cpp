#include <cmath>
#include <iostream>

using namespace std;

void AreaOfRectangle() {
  double width, length;
  cout << "Enter width and length of the rectangle" << endl;
  cin >> width >> length;
  double area = width * length;
  cout << area << endl;
}

void binaryToDecimal() {
  int binary;
  int decimal = 0, i = 0, remainder;
  cout << "Enter Binary Number" << endl;

  cin >> binary;

  while (binary > 0) {
    remainder = binary % 10;
    binary /= 10;
    decimal += remainder * pow(2, i);
    ++i;
  }
  cout << decimal << endl;
  return;
}

void PrintNPrimeNumbers() {
  int n, flag = 1;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    flag = 1;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        flag = 0;
      }
    }
    if (flag == 1) {
      cout << i << endl;
    }
  }
}

void ReverseNumber() {
  int n, a = 0;
  cin >> n;
  int z = n, digits = 0;
  while (z != 0) {
    z = z / 10;
    digits++;
  }
  while (n != 0) {
    int k = n % 10, z = digits - 1;
    while (z--) {
      k = k * 10;
    }
    a = a + k;
    digits--;
    n = n / 10;
  }
  cout << a;
}

bool checkMember(int n) {
  int f1 = 1, f2 = 1;
  if (n == 0 && n == 1) {
    return true;
  } else {
    while (1) {
      int temp = f1 + f2;
      f1 = f2;
      f2 = temp;
      if (temp == n) {
        return true;
      } else if (temp > n) {
        return false;
      }
    }
  }
}

int main() {
  // AreaOfRectangle();
  // binaryToDecimal();
  // PrintNPrimeNumbers();
  // ReverseNumber();
  // cout << checkMember(7) << endl << checkMember(593) << endl << checkMember(21) << endl;
  return 0;
}