#include <iostream>
#include <vector>
using namespace std;

void printVector(vector< int > v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << " ";
  }
  cout << endl;
}

// Hacker Rank: Count Inversion
// Variation of merge sort
// https://www.hackerrank.com/challenges/ctci-merge-sort/problem?%7CsFullScreen=true
// TC -> O(nlogn)
// SC -> O(n)
int merge(vector< int > &arr, vector< int > &temp, int start, int end,
          int mid) {
  int i = start, j = mid + 1, k = start;
  int count = 0;
  while (i <= mid && j <= end) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      // arr[i] > arr[j] inversion count case
      temp[k++] = arr[j++];
      count += mid - i + 1;
    }
  }

  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= end) {
    temp[k++] = arr[j++];
  }

  while (start <= end) {
    arr[start] = temp[start];
    ++start;
  }

  return count;
}
int mergeSort(vector< int > &arr, vector< int > &temp, int start, int end) {
  // base case
  if (start >= end) {
    // > invalid and == single element array
    return 0;
  }

  // break
  int mid = start + (end - start) / 2;
  int count = 0; // inversion count

  // RE
  count += mergeSort(arr, temp, start, mid);   // left
  count += mergeSort(arr, temp, mid + 1, end); // right

  count += merge(arr, temp, start, end, mid);
  return count;
}
int countInversion(vector< int > &arr) {

  // brute force
  // int count = 0;
  // for(int i=0; i< arr.size();i++) {
  //   for(int j=i+1; j< arr.size(); j++) {
  //     count = arr[i] > arr[j] ? count + 1 : count;
  //   }
  // }
  // return count;

  int count = 0; // inversion count
  vector< int > temp(arr.size(), 0);
  count = mergeSort(arr, temp, 0, arr.size() - 1);
  return count;
}

int main() {
  vector< int > arrOne = {8,4,2,1};
  cout << countInversion(arrOne) << endl;

  return 0;
}