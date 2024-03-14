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
  int temp = arr[size-1];
  // right shift 
  for(int i=size-1; i >= 1; i--) {
    arr[i] = arr[i-1];
  }
  arr[0] = temp;
}

void LeftShiftArray(int arr[], int size) {
  int temp = arr[0];
  for(int i=0; i<= size-1; i++) {
    arr[i] = arr[i+1];
  }
  arr[size-1] = temp;
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

int main() {
  // Basic();
  // Loops();
  // ArraysL1();
  // ArrayPracticeL1();
  ArrayL2();
  return 0;
}