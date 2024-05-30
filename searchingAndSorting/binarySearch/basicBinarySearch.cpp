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

// same as above with returns
int binarySearch(vector<int> &arr, int start, int end, int target) {
  int size = arr.size();
  int mid = (start + end) / 2;

  while (start <= end) {
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else if (arr[mid] < target) {
      start = mid + 1;
    }

    mid = (start + end) / 2;
  }

  return -1;
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

int findPivotIndex(vector<int> &arr) {
  int size = arr.size();
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    // corner case
    if (start == end) {
      return start;
    }

    // check if mid greater than next element
    // make sure mid does not go out the range and is inside the size of the
    // array since we are checking next element then we will make sure the next
    // element is equal to end or less than end
    if (mid + 1 <= end && arr[mid] > arr[mid + 1]) {
      return mid; // example 16 > 2 then 16 is pivot
    } else if (mid - 1 >= start && arr[mid] < arr[mid - 1]) {
      // check if mid is less than the previous element
      // make sure mid is not out of range and is inside the size of array
      // since we are checking previous element then we need to make sure mid -
      // 1 is greater than or equal to start
      return mid - 1; // example 2 < 16 then pivot would be 16
    } else if (arr[start] > arr[mid]) {
      // lets move if the pivot is not yet found towards left
      // if the increasing order 12, 14, 16 is on the left part and mid lies in
      // 2,4,6,8,10 then we definetely should move towards left
      end = mid - 1;
    } else {
      // move right
      start = mid + 1;
    }

    // do not forget to update mid
    mid = start + (end - start) / 2;
  }

  // when nothing found
  return -1;
}

int search(vector<int> &nums, int target) {
  int pivotIndex = findPivotIndex(nums);
  int size = nums.size();
  int ans = -1;

  if (target >= nums[0] && target <= nums[pivotIndex]) {
    ans = binarySearch(nums, 0, pivotIndex, target);
  } else {
    ans = binarySearch(nums, pivotIndex, size - 1, target);
  }

  return ans;
}

void findNearestSQRT() {
  int num = 51;
  int start = 0;
  int end = num;
  long long mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    if (mid * mid == num) {
      cout << "SQRT is: " << mid << endl;
      return;
    } else if (mid * mid <= num) {
      // move right side
      start = mid + 1;
      ans = mid;
    } else {
      end = mid - 1;
      ans = mid;
    }

    mid = start + (end - start) / 2;
  }

  cout << "SQRT is: " << ans << endl;
}

int findSQRTWithPrecesion(int num) {

  int start = 0;
  int end = num;
  long long mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    if (mid * mid <= num) {
      ans = mid;
      start = mid + 1; // move left
    } else {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  return ans;
}

double precesionSQRT(int n) {
  double sqrt = findSQRTWithPrecesion(51);
  double step = 0.1;
  int precesion = 10;
  for(int i=0; i< precesion; i++)
  {
    double j = sqrt;
    while (j * j <= n) {
      sqrt = j;
      j += step;
    }
    step /= 10;
  }
  return sqrt;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; // for missing elem
  int size = 9;                         // for missing elem

  int arrA[] = {0, 2, 1, 0}; // for peak index
  int sizeA = 4;             // for peak index

  // for pivot index
  vector<int> v;

  v.push_back(12);
  v.push_back(14);
  v.push_back(16);
  v.push_back(2);
  v.push_back(4);
  v.push_back(6);
  v.push_back(8);
  v.push_back(10);

  // // func calls
  // basicBinarySearch();
  // findFirstOccurance();
  // findLastOccurance();
  // findTotalOccurance();
  // findMissingElement(arr, size);
  // findPeakIndexInAMountainArray(arrA, sizeA);

  // // pivot index
  // int pivotIndex = findPivotIndex(v);
  // cout << "Pivot Index is: " << pivotIndex << endl;
  // search in rotated and sorted array
  // int ans = search(v, 8);
  // cout << "Target is at: " << ans << " Index" << endl;

  // findNearestSQRT();
  // findSQRTWithPrecesion(51);
  double sqrt = precesionSQRT(51);
  // cout << "Precesion SQRT is: " << sqrt << endl; // wont show all precesion use printf
  printf("%0.10f", sqrt);
  cout << endl;

  return 0;
}