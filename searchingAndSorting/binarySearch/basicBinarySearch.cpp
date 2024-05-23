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

int main() {
  basicBinarySearch();
  return 0;
}