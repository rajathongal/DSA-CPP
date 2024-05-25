#include <iostream>
#include <vector>
using namespace std;

void basicBinarySearch() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 90, 100, 210, 510};
  int size = 10;
  int start = 0;
  int end = size - 1;
  int mid = (start + end) / 2;
  // int target = 900;
  int target = 90;

  while (start <= end) {
    if (arr[mid] == target) {
      cout << "Target Found at index: " << mid << endl;
      return;
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else if (arr[mid] < target) {
      start = mid + 1;
    }

    mid = (start + end) / 2;
  }

  cout << "Target Not Found" << endl;
}

int findFirstOccurance() {
  int arr[8] = {10, 20, 20, 30, 30, 30, 40, 50};
  int target = 30;
  int start = 0;
  int end = 7;
  // int mid = (start + end) / 2;
  int mid = start + (end - start) / 2; // Best Practice
  int answer = -1;

  while (start <= end) {
    if (arr[mid] == target) {
      answer = mid;
      // move towards left
      end = mid - 1;
    } else if (target > arr[mid]) {
      start = mid + 1;
    } else if (target < arr[mid]) {
      end = mid - 1;
    }

    mid = (start + end) / 2;
  }

  cout << "First Occurance of target " << target << " is at: " << answer
       << endl;
  return answer;
}

int findLastOccurance() {
  int arr[8] = {10, 20, 20, 30, 30, 30, 40, 50};
  int target = 30;
  int start = 0;
  int end = 7;
  // int mid = (start + end) / 2;
  int mid = start + (end - start) / 2; // Best Practice
  int answer = -1;

  while (start <= end) {
    if (arr[mid] == target) {
      answer = mid;
      // move towards left
      start = mid + 1;
    } else if (target > arr[mid]) {
      start = mid + 1;
    } else if (target < arr[mid]) {
      end = mid - 1;
    }

    mid = (start + end) / 2;
  }

  cout << "Last Occurance of target " << target << " is at: " << answer << endl;
  return answer;
}

void findTotalOccurance() {
  int firstOccurance = findFirstOccurance();
  int lastOcurance = findLastOccurance();
  int totalOccurance = lastOcurance - firstOccurance + 1;

  cout << "Totol Occurance is: " << totalOccurance << endl;
}

void findMissingElement(int arr[], int size) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    int difference = arr[mid] - mid;
    if (difference == 1) {
      start = mid + 1;
    } else {
      ans = mid;
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  // try to exclude below statement and solve it in above logic HW
  if (ans + 1 == 0) {
    cout << "Missing Element is: " << size + 1 << endl;
    return;
  }

  cout << "Missing Element is: " << ans + 1 << endl;
  return;
}

// Leetcode 852
// find peak indes in a mountain array
// input [0,1,0]
// output 1
// solve in TC of O(logn)
void findPeakIndexInAMountainArray(int arr[], int size) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start < end) {
    if (arr[mid] < arr[mid + 1]) {
      // in A section of graph
      // peak exists right side
      // so move right
      start = mid + 1;
    } else {
      // you might be in B section of graph
      // and you might be on peak element
      // move left without losing peak element so end = mid
      end = mid;
    }

    // update mid
    mid = start + (end - start) / 2;
  }

  cout << "Peak element is: " << start << endl;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; // for missing elem
  int size = 9;                         // for missing elem

  int arrA[] = {0, 2, 1, 0}; // for peak index
  int sizeA = 4;             // for peak index

  // basicBinarySearch();
  // findFirstOccurance();
  // findLastOccurance();
  // findTotalOccurance();
  // findMissingElement(arr, size);
  findPeakIndexInAMountainArray(arrA, sizeA);
  return 0;
}