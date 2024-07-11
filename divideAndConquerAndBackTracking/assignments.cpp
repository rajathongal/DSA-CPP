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

// In Place Merge Sort
// TC -> O(nlogn)
// SC -> O(1)
// sort array LC 912
void mergeInPlace(vector< int > &nums, int start, int end, int mid) {
  int totalLength = end - start + 1;
  int gap = (totalLength / 2) + (totalLength % 2);

  while (gap > 0) {
    int i = start, j = start + gap;
    while (j <= end) {
      if (nums[i] > nums[j]) {
        swap(nums[i], nums[j]);
      }
      ++i, ++j;
    }

    gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
  }
}
void mergeSortInPlace(vector< int > &nums, int start, int end) {
  // base case
  if (start >= end) {
    // > invalid and == single element array
    return;
  }

  // break
  int mid = start + (end - start) / 2;
  // RE
  mergeSortInPlace(nums, start, mid);   // left
  mergeSortInPlace(nums, mid + 1, end); // right
  mergeInPlace(nums, start, end, mid);
}

void sortArray(vector< int > &nums) {
  mergeSortInPlace(nums, 0, nums.size() - 1);
  return;
}

// Merge 2 sorted Arrays
void merge2SortedArrays(vector< int > &a, vector< int > &b) {
  int n = a.size();
  int m = b.size();
  int total_len = n + m;
  int gap = (total_len / 2) + total_len % 2;
  while (gap > 0) {
    int i = 0, j = gap;
    while (j < total_len) {
      // comparing elements in first array - if b[f]<a(i] swap their values
      if (j < n && a[i] > a[j]) {
        swap(a[i], a[j]);
      } else if (j >= n && i < n && a[i] > b[j - n]) {
        /* comparing elements
      in both
      arrays */
        swap(a[i], b[j - n]);
      }

      /* comparing elements
        in the second array */
      else if (j >= n && i >= n && b[i - n] > b[j - n]) {
        swap(b[i - n], b[j - n]);
      }

      j++;
      i++;
    }
    gap = gap <= 1 ? 0 : (gap / 2) + (gap & 2);
  }
}

// Leetcode 53 Maximum SubArray
// TC -> O(nlogn)
// SC -> O(logn) 
int maxSubArray(vector< int > &nums, int start, int end) {
  // m1 brute force find all sub arrays then find max of them O(n3) or O(n2)


  if(start == end) {
    return nums[start];
  }

  int maxOfLeftBorderSum = INT_MIN;
  int maxOfRightBorderSum = INT_MIN;
  int leftBorderSum = 0;
  int rightBorderSum = 0;

  int mid = start + ((end-start) >> 1);

  int maxLeftSum = maxSubArray(nums, start, mid);
  int maxRightSum = maxSubArray(nums, mid + 1, end);

  // max cross border sum
  for(int i= mid; i >= start;i-- ) {
    leftBorderSum += nums[i];
    if(leftBorderSum > maxOfLeftBorderSum) {
      maxOfLeftBorderSum = leftBorderSum;
    }
  }

   for(int i= mid + 1; i <= end;i++ ) {
    rightBorderSum += nums[i];
    if(rightBorderSum > maxOfRightBorderSum) {
      maxOfRightBorderSum = rightBorderSum;
    }
  }

  int crossBorderSum = maxOfLeftBorderSum + maxOfRightBorderSum;

  return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

int main() {
  // vector< int > arrOne = {8,4,2,1};
  // cout << countInversion(arrOne) << endl;

  // vector< int > nums = {5, 2, 3, 1, 4, 7, 8, 9, 100};
  // sortArray(nums);
  // printVector(nums);

  vector< int > maxSubOne = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector< int > maxSubTwo = {5, 4, -1, 7, 8};
  vector< int > maxSubThree = {1000};

  cout << maxSubArray(maxSubOne, 0, maxSubOne.size() - 1) << endl;
  cout << maxSubArray(maxSubTwo, 0, maxSubTwo.size() - 1) << endl;
  cout << maxSubArray(maxSubThree, 0, maxSubThree.size() - 1) << endl;

  return 0;
}