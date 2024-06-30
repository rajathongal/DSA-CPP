#include <climits>
#include <iostream>
#include <limits.h> // for INT_MAX
#include <vector>   // for vector
using namespace std;

void printVector(vector< int > v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << endl;
  }
  cout << endl;
}

// Leetcode 70 Climbing stairs
int climbStairs(int n) {
  if (n == 0) {
    return 1;
  }

  if (n == 1) {
    return 1;
  }

  int ans = climbStairs(n - 1) + climbStairs(n - 2);
  return ans;
}

void printArray(int arr[], int size, int index) {
  if (index >= size) {
    return;
  }

  cout << arr[index++] << " ";
  // index++;
  printArray(arr, size, index);
}

// search in array
bool searchArray(int arr[], int size, int target, int index) {
  if (index >= size) {
    return false;
  }

  if (arr[index] == target) {
    return true;
  }
  bool ans = searchArray(arr, size, target, index + 1);
  return ans;
}

// minimum number in an array
void minNumInArr(int arr[], int size, int index,
                 int &minNum) { // v impo &minNum
  // base case
  if (index >= size) {
    return;
  }

  // processing
  minNum = min(minNum, arr[index]);
  // recursive call
  minNumInArr(arr, size, index + 1, minNum);
}

// max number in an array
void maxNumInArr(int arr[], int size, int index,
                 int &maxNum) { // v impo &minNum
  // base case
  if (index >= size) {
    return;
  }

  // processing
  maxNum = max(maxNum, arr[index]);
  // recursive call
  maxNumInArr(arr, size, index + 1, maxNum);
}

// even nums in array
void evenNumsInArray(int arr[], int size, vector< int > &ans, int index) {
  if (index >= size) {
    return;
  }

  if (arr[index] % 2 == 0) {
    ans.push_back(arr[index]);
  }

  evenNumsInArray(arr, size, ans, index + 1);
}

void doubleTheNumInArray(int arr[], int size, int index) {
  if (index >= size) {
    return;
  }

  arr[index] += arr[index];

  doubleTheNumInArray(arr, size, index + 1);
}

int searchArrayIndex(int arr[], int size, int target, int index) {
  if (index >= size) {
    return -1;
  }

  if (arr[index] == target) {
    return index;
  }

  return searchArrayIndex(arr, size, target, index + 1);
}

void printAllOccurancesOfTargetInArrray(int arr[], int size, int target,
                                        int index) {
  if (index >= size) {
    return;
  }

  if (arr[index] == target) {
    cout << index << " ";
  }

  printAllOccurancesOfTargetInArrray(arr, size, target, index + 1);
}

void findAllOccurancesOfTargetInArrray(int arr[], int size, int target,
                                       int index, vector< int > &ans) {

  if (index >= size) {
    return;
  }

  if (arr[index] == target) {
    ans.push_back(index);
  }

  findAllOccurancesOfTargetInArrray(arr, size, target, index + 1, ans);

  return;
}

void getDigitsFromNum(int num, vector< int > &digits) {
  if (num <= 0) {
    return;
  }
  int digit = num % 10;
  num = num / 10;

  getDigitsFromNum(num, digits);
  digits.push_back(digit);
  // cout << digit << " ";
}

void digitToNumber(vector< int > &digits, int size, int index, int &ans) {
  if (index >= size) {
    return;
  }

  ans = ans * 10 + digits[index];
  digitToNumber(digits, size, index + 1, ans);
}

void printTargetCharIndex(string s, int index, char target,
                          vector< int > &ans) {
  if (s[index] == '\0') {
    return;
  }

  if (s[index] == target) {
    // cout << index << endl;
    ans.push_back(index);
  }

  printTargetCharIndex(s, index + 1, target, ans);
}

int main() {
  // cout << climbStairs(4) << endl;

  // for print array and search array, minNum in array, even num in array
  int arr[] = {11, 60, 23, 30, 60, 47, 93, 60, 70};
  int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
  int target = 60;

  // printArray(arr, sizeOfArr, 0);

  // cout << searchArray(arr, sizeOfArr, target, 0) << endl;

  // int minNum = INT_MAX;
  // minNumInArr(arr, sizeOfArr, 0, minNum);
  // cout << minNum << endl;

  // vector<int> ans; // (sizeOfArr, 0)
  // evenNumsInArray(arr, sizeOfArr, ans, 0);
  // printVector(ans);

  // doubleTheNumInArray(arr, sizeOfArr, 0);
  // printArray(arr, sizeOfArr, 0);

  // int maxNum = INT_MIN;
  // maxNumInArr(arr, sizeOfArr, 0, maxNum);
  // cout << maxNum << endl;

  // cout << searchArrayIndex(arr, sizeOfArr, target, 0) << endl;

  // printAllOccurancesOfTargetInArrray(arr, sizeOfArr, target, 0);

  // vector<int> anss;
  // findAllOccurancesOfTargetInArrray(arr, sizeOfArr, target, 0, anss);
  // printVector(anss);

  // vector<int> digits;
  // getDigitsFromNum(559090, digits);
  // printVector(digits);

  // int num = 0;
  // digitToNumber(digits, digits.size(), 0, num);
  // cout << "Digit to num " << num << endl;

  vector< int > targetPosOfString;
  printTargetCharIndex("Rajatadsdsaa", 0, 'a', targetPosOfString);
  printVector(targetPosOfString);

  return 0;
}