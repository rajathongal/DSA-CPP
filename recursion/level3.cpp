
#include <iostream>
using namespace std;

// check if array is sorted or not
bool isSorted(int arr[], int size, int index) {
  if (index >= size) {
    return true;
  }

  if (arr[index] > arr[index - 1]) {
    bool ans = isSorted(arr, size, index + 1);
    return ans;
  }
  return false;
}

int binarySearchUsingRecursion(int arr[], int s, int e, int target) {

  // base case
  if (s > e) {
    return -1;
  }

  // processing
  int mid = s + (e - s) / 2;
  if (arr[mid] == target) {
    return mid;
  } 

  // Recursive call
  if(arr[mid] < target) {

    return binarySearchUsingRecursion(arr, mid + 1, e, target);
  } else {

    return binarySearchUsingRecursion(arr, s, mid - 1, target);
  }
}

int main() {
  int arr[] = {11, 60, 23, 30, 60, 47, 93, 60, 70};
  int arr2[] = {10, 20, 30, 40, 50};

  int sizeOfArr = sizeof(arr) / sizeof(arr[0]); 
  int sizeOfArr2 = sizeof(arr2) / sizeof(arr2[0]);

  cout << isSorted(arr, sizeOfArr, 1) << endl;
  cout << isSorted(arr2, sizeOfArr2, 1) << endl;

  cout << binarySearchUsingRecursion(arr, 0, sizeOfArr - 1, 93) << endl;

  return 0;
}