#include <cmath>
#include <iostream>
using namespace std;

// find max of 3 numbers
void MaxOfThreeNumbers(int a, int b, int c) {
  if (a > b && a > c) {
    cout << " Maximum is: " << a << endl;
  } else if (b > a && b > c) {
    cout << " Maximum is: " << b << endl;
  } else {
    cout << " Maximum is: " << c << endl;
  }

  // using inbuilt
  int ans = max(a, b); // max only takes 2 inputs
  int finalAns = max(ans, c);
  cout << " Maximum using inbuit function is: " << finalAns << endl;
}

// Counting from 1 to N
void CountingFrom1ToN(int N) {
  for (int i = 1; i <= N; i++) {
    cout << i << " ";
  }
  cout << endl;
}

// check prime or not
bool CheckPrime(int num, bool printFlag) {
  // divisible by one or self only.
  // not perfectly divisible by other numbers

  // method to solve
  // we will not check divisibility with self and 1
  // we will check with all the other numbers that in the range of
  // 2 to N-1,
  // where N is the number you are checking prime for,
  // 2 is to skip 1 and N-1 is to skip the number you are checking

  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      if (printFlag) {
        cout << num << " is not a prime number" << endl;
      }
      return false;
    }
  }

  if (printFlag) {
    cout << num << " is a prime number" << endl;
  }
  return true;
}

// check even or odd
void CheckEvenOdd(int num) {
  if (num % 2 == 0) {
    cout << num << " Is Even Number" << endl;
  } else {
    cout << num << " Is Odd Number" << endl;
  }

  // using bitwise
  if ((num & 1) == 0) {
    cout << num << " Is Even Number using Bitwise" << endl;
  } else {
    cout << num << " Is Odd Number using Bitwise" << endl;
  }
}

// sum of all number from 1 to N
void SumOfOneToN(int N) {
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += i;
  }

  cout << "Sum from 1 to " << N << " is: " << sum << endl;
  ;
}

// sum of all even and odd numbers from 1 to N
void SumOfOneToNEvenAndOdd(int N) {
  int even = 0;
  int odd = 0;

  for (int i = 1; i <= N; i++) {
    if ((i & 1) == 0) {
      even += i;
    } else {
      odd += i;
    }
  }

  cout << "Sum of all even numbers from 1 to " << N << " is:" << even << endl;
  cout << "Sum of all odd numbers from 1 to " << N << " is:" << odd << endl;
}

// Area of a circle
void AreaOfACircle(double radius) {
  double area = M_PI * radius * radius;
  cout << "Area of circle with radius " << radius << " is: " << area << endl;
}

// find the factorial
unsigned int factorial(unsigned int num) {
  if (num == 0 || num == 1) {
    return 1;
  }
  return num * factorial(num - 1);
}

void factorialMain(unsigned int num) {
  unsigned int factorialOfNum = factorial(num);

  cout << "Factorial of " << num << " is: " << factorialOfNum << endl;
}
// print all prime from 1 to N
void PrintPrimeFromOneToN(int N) {
  cout << "Prime Number from 1 to " << N << " are ";

  for (int i = 1; i <= N; i++) {
    bool isPrime = CheckPrime(i, false);
    if (isPrime) {
      cout << i << " ";
    }
  }
  cout << endl;
}
// reverse an integer
void ReverseIntger(int x) {
  int ans = 0, rem = 0;
  bool isNeg = false;
  if (x < 0) {
    isNeg = true;
    x = -x;
  }
  while (x > 0) {
    int digit = x % 10;
    ans = ans * 10 + digit;
    x = x / 10;
  }
  cout << (isNeg ? -ans : ans) << endl;
}
// set k- th bit
// convert temperature
// count all set bits
// create number using digits
// print all digits of an Integer
// KM to miles
// debug problems

int main() {
  MaxOfThreeNumbers(200, 5, 9);
  CountingFrom1ToN(5);
  CheckEvenOdd(31);
  CheckEvenOdd(7);
  CheckEvenOdd(8);
  CheckEvenOdd(10);
  SumOfOneToN(100);
  SumOfOneToNEvenAndOdd(100);
  CheckPrime(7, true);
  CheckPrime(15, true);
  CheckPrime(11, true);
  AreaOfACircle(90);
  AreaOfACircle(3.1256);
  factorialMain(6);
  PrintPrimeFromOneToN(100);
  ReverseIntger(567);
  ReverseIntger(-789);
  return 0;
}