#include <cmath>
#include <iostream>
#include <limits.h>
using namespace std;

int age = 20; // global variable

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

  for (int i = 0; i < size; i++) {
    if (numArr[i] > max_value) {
      max_value = numArr[i];
    }
  }

  cout << "Max Value is " << max_value << endl;

  // reverse array
  // algo
  // use 2 pointers left as 0th index index and right as n-1 index
  // while left is less than right swap left and right, increment left and
  // decrement right if left < right exit
  int left = 0;
  int right = size - 1;

  while (left < right) {
    int temp = numArr[left];
    numArr[left] = numArr[right];
    numArr[right] = temp;
    left++;
    right--;
  }

  for (int i = 0; i < size; i++) {
    cout << numArr[i] << " ";
  }
  cout << endl;

  return 0;
}

void changeValue(int arr[]) { arr[2] = 101; }

void printArray(int arr[], int size) {
  cout << size << endl;
  cout << "Array elements are: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int getUniqueElementFromArray(int arr[], int size) {
  int ans = 0;
  for (int i = 0; i < size; i++) {
    ans = ans ^ arr[i];
  }
  return ans;
}

void printDoublePairs(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << arr[i] << ", " << arr[j] << endl;
    }
  }
}
void printTripletPairs(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        cout << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
      }
    }
  }
}

void sortZerosAndOnes(int arr[], int size) {
  int zeroCount = 0;
  int onesCount = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) {
      zeroCount++;
    }

    if (arr[i] == 1) {
      onesCount++;
    }
  }

  int i = 0;
  for (i = 0; i < zeroCount; i++) {
    arr[i] = 0;
  }
  for (int j = i; j < onesCount; j++) {
    arr[j] = 1;
  }
}

void RightShiftArray(int arr[], int size) {
  int temp = arr[size - 1];
  // right shift
  for (int i = size - 1; i >= 1; i--) {
    arr[i] = arr[i - 1];
  }
  arr[0] = temp;
}

void LeftShiftArray(int arr[], int size) {
  int temp = arr[0];
  for (int i = 0; i <= size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[size - 1] = temp;
}

int ArrayL2() {
  int a[4] = {0, 1, 2, 3};
  int size = sizeof(a) / sizeof(a[0]);
  changeValue(a);
  printArray(a, size);

  // unique elem
  int b[] = {1, 1, 3, 4, 3, 4, 10, 8, 10};
  int sizeb = sizeof(b) / sizeof(b[0]);
  int ans = getUniqueElementFromArray(b, sizeb);
  cout << "Unique element is: " << ans << endl;

  // triplets pair print
  int c[] = {10, 20, 30};
  int sizec = sizeof(c) / sizeof(c[0]);
  printDoublePairs(c, sizec);
  printTripletPairs(c, sizec);

  // separate out 0's and 1's in asc order
  int arr[] = {0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0};
  int arrSize = sizeof(arr) / sizeof(arr[0]);
  sortZerosAndOnes(arr, arrSize);
  printArray(arr, arrSize);

  // right Shift Array
  int arrb[] = {10, 20, 30, 40, 50, 60};
  int arrbSize = sizeof(arrb) / sizeof(arrb[0]);
  RightShiftArray(arrb, arrbSize);
  printArray(arrb, arrbSize);

  // left shift array
  LeftShiftArray(arrb, arrbSize);
  printArray(arrb, arrbSize);

  return 0;
}

int decimalToBinaryByDivisionMethod(int decimalNumber) {
  int i = 0;
  int binaryNumber = 0;
  while (decimalNumber > 0) {
    cout << "i before " << i << endl;
    cout << "binaryNumber before " << binaryNumber << endl;

    int remainderOrBit = decimalNumber % 2;
    binaryNumber = remainderOrBit * pow(10, i++) + binaryNumber;
    cout << "i after " << i << endl;
    cout << "binaryNumber after " << binaryNumber << endl;

    decimalNumber = decimalNumber / 2;
  }
  return binaryNumber;
}

int decimalToBinaryUsingBitwise(int decimalNumber) {
  int binaryNumber = 0;
  int i = 0;
  while (decimalNumber > 0) {
    int remainderBit = (decimalNumber & 1);
    binaryNumber = remainderBit * pow(10, i++) + binaryNumber;
    decimalNumber = decimalNumber >> 1;
  }
  return binaryNumber;
}

// not working needs fix
int decimalToBinaryUsingBitwisePlaceValue(int decimalNumber) {
  int binaryNumber = 0;
  int placeValue = 1;

  while (decimalNumber > 0) {
    int remainderBit = decimalNumber % 2;
    binaryNumber += remainderBit * placeValue;
    decimalNumber = decimalNumber / 2;
    placeValue = placeValue
                 << 1; // every Left shift is equivalent to multiplying by 2
  }
  return binaryNumber;
}

int NumberSystem() {
  // we will be using cmath lib to get pow(powertothe) functionality
  int n;
  int binaryNumber;

  cout << "Enter a Decimal Number" << endl;
  cin >> n;

  // decimal to binary conversion by division method
  binaryNumber = decimalToBinaryByDivisionMethod(n);

  cout << "Decimal to Binary Conversion of " << n << " by division method is "
       << binaryNumber << endl
       << endl;

  binaryNumber = decimalToBinaryUsingBitwise(n);

  cout << "Decimal to Binary Conversion of " << n
       << " by bitwise division method is " << binaryNumber << endl
       << endl;

  binaryNumber = decimalToBinaryUsingBitwisePlaceValue(n);

  cout << "Decimal to Binary Converion of " << n
       << " by bitwise place value method is " << binaryNumber << endl;

  return 0;
}

int Operators() {

  // Bitwise ops
  int a = 1;
  int b = 12;

  bool bof = false;
  bool bot = true;

  // bitwise and op
  cout << (a & b) << endl;

  // bitwise OR op
  cout << (a | b) << endl;

  // bitwise NOT op
  cout << ~a << endl;
  cout << ~bof << endl;
  cout << ~bot << endl;

  // bitwise XOR op
  cout << (a ^ b) << endl;

  // left shift
  cout << (a << b) << endl;

  // right shift
  cout << (a >> b) << endl;

  unsigned int num = -1;
  cout << (num >> 1) << endl;

  // break and continue
  for (int i = 0; i < 5; i++) {
    cout << i << endl;
    if (i == 3) {
      break;
    }
  }

  for (int i = 0; i < 7; i++) {
    if (i == 4) {
      continue;
    }

    cout << i << endl;
  }

  // pre post operators
  cout << "initial value of a " << a << endl;
  cout << "pre increment " << ++a << endl;
  cout << "post increment " << a++ << endl;
  cout << "after post incr " << a << endl;

  cout << "pre decrement " << --a << endl;
  cout << "post decr" << a-- << endl;
  cout << "after post decr " << a << endl;

  // Variable Scoping

  // Local varaibles

  // i is not accessble here
  for (int i = 0; i < 6; i++) {
    // i is a local variable for this for loop
    cout << i << endl;
  }
  // i is not accessble here
  if (true) {
    int ab = 25; // ab is global scope for the inner if
    if (true) {
      cout << ab << endl; // ab is accessible here
      // we can also redfine variable here

      int ab = 100;

      cout << ab << endl; // ab is now 100 only is second if loop level

      // the nearest definition of variable ab is printed
    }
  }

  a = 5; // updation

  // redfinition of variable cannot be done
  // int a = 100;

  for (int i = 0; i < a + 1; i++) {
    cout << i << a << endl; // a is accesible here as well
  }

  cout << a << endl; // a is accesible here as well
  return 0;
}

// Functions
void printGreetings();

int Hello(string userName) {
  cout << userName << endl;
  return 0;
}

void sumOfNumbers(int a, int b, int c) {
  int answer = a + b + c;
  cout << "Answer is " << answer << endl;
  return;
}

int sumByReturn(int a, int b, int c) {
  // abc have different memory location than the passed values during function call
  // this is an example for pass by value 
  int answer = a + b + c;
  return answer;
}

// example for pass by reference
void solve(int& a) {
  a++;
  cout << "Print inside solve Fn " << a << endl;
}

void solve2(int& a) {
  a--;
  a= a * 2;
  cout << "Print inside solve2 fn " << a << endl;
}

int Functions() {
  printGreetings();
  Hello("Rajath");
  sumOfNumbers(3, 5, 7);
  int sum = sumByReturn(2, 7, 3);
  cout << "Sum " << sum << endl;

  solve(sum);
  cout << "Print outside solve Fn " << sum << endl;

  sum++;
  solve2(sum);
  cout << "Print outside solve2 fn " << sum << endl;


  return 0;
}

void printGreetings() { cout << "Greetings" << endl; }

int main() {
  // Basic();
  // Loops();
  // ArraysL1();
  // ArrayPracticeL1();
  // ArrayL2();
  // NumberSystem();
  // Operators();
  Functions();
  return 0;
}