#include <cmath>
#include <iostream>
#include <limits.h>
using namespace std;

// sizeof returns size of in bytes
// to get the exact size of the array divide the value received from sizeof with
// sizeof array's datatype
int Loops() {
  int num = 700;

  if (num % 2 == 0) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }

  if (num > 0) {
    cout << "Positive" << endl;
  } else if (num < 0) {
    cout << "Negative" << endl;
  } else {
    cout << "ZERO" << endl;
  }

  num = -20;

  if (num > 0) {
    cout << "Positive" << endl;
  } else if (num < 0) {
    cout << "Negative" << endl;
  } else {
    cout << "ZERO" << endl;
  }

  // infinite loop and break
  int i = 1;
  for (;;) {
    cout << "Value of i is " << i << endl;
    if (i < 30) {
      cout << "Henlo Practice " << i << endl;
      i++;
    } else {
      break;
    }
  }

  // general loops
  for (int i = 0; i < 10; i = i + 1) {
    cout << i << endl;
  }

  for (int j = 20; j >= 0; j = j - 2) {
    cout << j << endl;
  }

  return 0;
}

int Basic() {
  std::cout << "Hello world!" << std::endl;
  cout << "hello world from std namespace!" << endl;

  // size of an int in 4 bytes
  int num = 100;

  cout << num << endl;         // print number
  cout << &num << endl;        // print pointer
  cout << sizeof(num) << endl; // print size of

  // char is 1 byte
  char ch = 'a';
  cout << ch << endl << &ch << endl << sizeof(ch) << endl;

  // float is 4 bytes
  float fl = 0.009;
  cout << fl << endl << &fl << endl << sizeof(fl) << endl;

  // boolean is 1 byte
  bool t = true;
  bool f = false;

  cout << t << endl << f << endl << sizeof(t) << endl;

  int a = 10;
  int b = 20;

  cout << a + b << endl;
  cout << a - b << endl;
  cout << a * b << endl;
  cout << a % b << endl;
  cout << a / b << endl;

  cout << (a > b) << endl;
  cout << (a < b) << endl;
  cout << (a >= b) << endl;
  cout << (a <= b) << endl;
  cout << (a != b) << endl;
  cout << (a == b) << endl;

  int marks;

  cout << "Enter some input number." << endl;
  cin >> marks;

  cout << "Here is your input" << endl << marks << endl;
  return 0;
}

int ArraysL1() {
  int a[7] = {0, 1, 2, 3, 4, 5, 6}; // static array
  int arr[101];
  int ch[101];
  bool flags[90];
  long nums[909];
  short sh[1001];

  int n = 10;
  char cha[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter char for index: " << i << endl;
    cin >> cha[i];
    cout << endl;
  }

  for (int i = 0; i < n; i++) {
    cout << "Char entered at index " << i << " is: " << cha[i] << endl;
  }

  cout << "Size of array is " << sizeof(cha) / sizeof(cha[0]) << endl;

  // explicit array init with empty values
  int some[5] = {1, 2, 3};

  // taking input in specified array index
  cout << "enter value for array" << endl;
  cin >> some[3];
  some[4] = 2;
  for (int i = 0; i < (sizeof(some) / sizeof(some[0])); i++) {
    cout << some[i] << endl;
  }

  // linear search
  bool flag = false;
  int ar[5] = {1, 3, 5, 7, 8};

  for (int i = 0; i < (sizeof(ar) / sizeof(ar[0])); i++) {
    if (ar[i] == 7) {
      flag = true;
      break;
    }
  }

  if (flag == 1) {
    cout << "target found" << endl;
  } else {
    cout << "target not found" << endl;
  }

  return 0;
}

int ArrayPracticeL1() {
  // minimum number in an array
  int numArr[4] = {10, 1100, 2, 100};
  int size = sizeof(numArr) / sizeof(numArr[0]);
  int minValue = INT_MAX;

  for (int i = 0; i < size; i++) {
    if (numArr[i] < minValue) {
      minValue = numArr[i];
    }
  }

  cout << "Min Value is " << minValue << endl;

  // maximum number in an array 
  int max_value = INT_MIN;

  for(int i=0; i < size; i++) {
    if(numArr[i] > max_value) {
      max_value = numArr[i];
    }
  }

  cout << "Max Value is " << max_value << endl;


  return 0;
}

int main() {
  // Basic();
  // Loops();
  // ArraysL1();
  ArrayPracticeL1();
  return 0;
}