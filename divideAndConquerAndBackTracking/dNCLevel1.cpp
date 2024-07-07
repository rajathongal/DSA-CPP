#include <iostream>

using namespace std;

void printArray(int arr[], int size) {
  cout << "Array elements are: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// merge sort
// TC -> O(nlogn)
// base case constant time -> k1
// RE call of left half T(n/2)
// RE call of right half T(n/2)
// merge -> O(n) or k*n
// SC ->

void merge(int arr[], int start, int end) {
  // TC for creation is constant here
  int mid = start + (end - start) / 2;
  int lengthOfLeftArray = mid - start + 1;
  int lengthOfRightArray = end - mid;

  // create left and right array
  // TC is n/2 here
  int *left = new int[lengthOfLeftArray];
  int *right = new int[lengthOfRightArray];

  // copy values from original array to left array
  // TC is n/2 here
  int k = start;
  // K denotes -> starting index of left array from original array
  for (int i = 0; i < lengthOfLeftArray; i++) {
    left[i] = arr[k];
    k++;
  }

  // copy values from original array to right array
  k = mid + 1;
  // K denotes -> starting index of right array from original array
  for (int i = 0; i < lengthOfRightArray; i++) {
    right[i] = arr[k];
    k++;
  }

  // sorting/merge logic for 2 arrays
  // left and right array is sorted already
  int leftIndex = 0;
  int rightIndex = 0;
  // important
  int mainArrayIndex = start;

  // TC is n here
  while (leftIndex < lengthOfLeftArray && rightIndex < lengthOfRightArray) {
    if (left[leftIndex] < right[rightIndex]) {
      arr[mainArrayIndex] = left[leftIndex];
      mainArrayIndex++;
      leftIndex++;
    } else {
      arr[mainArrayIndex] = right[rightIndex];
      mainArrayIndex++;
      rightIndex++;
    }
  }

  // for ex left elements have been traced but right element might have 2 or
  // more elements and vice versa
  // TC is n/2 here
  while (rightIndex < lengthOfRightArray) {
    arr[mainArrayIndex] = right[rightIndex];
    mainArrayIndex++;
    rightIndex++;
  }

  // TC is n/2 here
  while (leftIndex < lengthOfLeftArray) {
    arr[mainArrayIndex] = left[leftIndex];
    mainArrayIndex++;
    leftIndex++;
  }

  // delete the dynamic memory taken for arrays
  // TC is constant here
  delete[] left;
  delete[] right;
}

void mergeSort(int arr[], int start, int end) {
  // base case
  if (start >= end) {
    // > invalid and == single element array
    return;
  }

  // break
  int mid = start + (end - start) / 2;
  // RE
  mergeSort(arr, start, mid);   // left
  mergeSort(arr, mid + 1, end); // right

  // merge 2 sorted arrays
  merge(arr, start, end);
}

// quick sort
// consider end as pivot always
// sort in asc order such that
// left of pivot is less than pivot
// right of pivot is greater than pivot
// TC -> O(n^2)
void quickSort(int a[], int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = end;
  int i = start - 1;
  int j = start;

  while (j < pivot) {
    if (a[j] < a[pivot]) {
      ++i;
      swap(a[i], a[j]);
    }
    ++j;
  }
  ++i;
  // i is the right position for pivot the pivot element
  swap(a[i], a[pivot]);
  quickSort(a, start, i - 1);
  quickSort(a, i + 1, end);
}

int main() {
  int arr[] = {2, 1, 6, 9, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int start = 0;
  int end = size - 1;

  cout << "Before merge Sort" << endl;
  printArray(arr, size);
  mergeSort(arr, start, end);
  cout << "After merge Sort" << endl;
  printArray(arr, size);

  int arr2[] = {7, 2, 1, 8, 6, 3, 5, 4};
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  int start2 = 0;
  int end2 = size2 - 1;
  cout << "Before quick Sort" << endl;
  printArray(arr2, size2);
  quickSort(arr2, start2, end2);
  cout << "After quick Sort" << endl;
  printArray(arr2, size2);

  return 0;
}