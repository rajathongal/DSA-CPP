#include <iostream>
#include <limits.h> // for INT_MAX
#include <vector> // for vector
using namespace std;

void printVector(vector<int> v) {
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
void minNumInArr(int arr[], int size, int index, int &minNum) { // v impo &minNum
  // base case
  if (index >= size) {
    return;
  }

  // processing
  minNum = min(minNum, arr[index]);
  // recursive call
  minNumInArr(arr, size, index+1, minNum);
}

// even nums in array
void evenNumsInArray(int arr[], int size, vector<int> &ans, int index) {
  if(index >= size) {
    return;
  }

  if(arr[index] % 2 == 0) {
    ans.push_back(arr[index]);
  }

  evenNumsInArray(arr, size, ans, index+1);

}

int main() {
  // cout << climbStairs(4) << endl;

  // for print array and search array, minNum in array, even num in array
  int arr[] = {11, 23, 30, 47, 93, 60, 70};
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

  
  return 0;
}