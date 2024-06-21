#include <iostream>
#include <vector>
using namespace std;

// LCM * HCF = A * B
// LCM(A,B) * gcd(a,b) = a*b
// LCM(A,B) = a* b / gcd(A,B)

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

int LCM(int A, int B) {
  int gcdValue = gcd(A,B);
  int LCM = (A * B )/ gcdValue;
  return LCM;
}

int main() {
  cout << "LCM of 243 and 72: " << gcd(243, 72) << endl;
  cout << "LCM of 3 and 6: " << gcd(3, 6) << endl;


  return 0;
}
