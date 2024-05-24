#include <iostream>
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
  int arr[8] = {10, 20, 20, 30, 30, 30, 40, 50};
  int target = 30;
  int start = 0;
  int end = 7;
  // int mid = (start + end) / 2;
  int mid = start + (end - start) / 2; // Best Practice
}

int main() {
  // basicBinarySearch();
  // findFirstOccurance();
  // findLastOccurance();
  findTotalOccurance();
  return 0;
}