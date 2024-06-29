#include <iostream>
using namespace std;

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

int main() {
  // cout << climbStairs(4) << endl;

  // for print array and search array
  int arr[] = {10, 20, 30, 40, 50, 60, 70};
  int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
  int target = 60;

  // printArray(arr, sizeOfArr, 0);
  cout << searchArray(arr, sizeOfArr, target, 0) << endl;
  return 0;
}