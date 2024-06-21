#include <iostream>
#include <vector>
using namespace std;

// gcd (a,b) = gcd (a-b, b) if a > b
// gcd (a,b) = gcd (b-a, a) if a < b
// gcd(a,b) = gcd (a % b,b) a>b

int gcd(int A, int B) {
  if (A == 0) {
    return B;
  }
  if (B == 0) {
    return A;
  }

  while (A > 0 && B > 0) {
    if (A > B) {
      A = A - B;
    } else {
      B = B - A;
    }
  }

  return A == 0 ? B : A;
}

int main() {
  cout << "Euclid Approach HCF: " << gcd(24, 72) << endl;
  cout << "Euclid Approach HCF: " << gcd(3, 6) << endl;


  return 0;
}