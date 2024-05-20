#include <climits>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << " ";
  }
  cout << endl;
}

void printArray(int arr[], int size) {
  cout << size << endl;
  cout << "Array elements are: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printSet(set<int> mySet) {
  // Print the elements of the set (elements will be sorted)
  for (auto element : mySet) {
    cout << element << " ";
  }
  cout << endl;
}

void print2DVector(vector<vector<int> > arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

void FindPivotIndex() {
  vector<int> nums;
  // case 1 ans 3
  nums.push_back(1); // 0
  nums.push_back(7); // 1
  nums.push_back(3); // 2
  nums.push_back(6); // 3
  nums.push_back(5); // 4
  nums.push_back(6); // 5

  // case 2 ans -1
  // nums.push_back(1);
  // nums.push_back(2);
  // nums.push_back(3);

  // case 3 ans 0
  // nums.push_back(2);
  // nums.push_back(1);
  // nums.push_back(-1);

  vector<int> leftSum(nums.size(), 0);
  vector<int> rightSum(nums.size(), 0);

  // Calculate left Sum
  for (int i = 1; i < nums.size(); ++i) {
    leftSum[i] = leftSum[i - 1] + nums[i - 1];
    // cout << leftSum[i] << " " << leftSum[i - 1] << " " << nums[i - 1] << " "
    //      << i << endl; // debugging
  }
  cout << endl;
  // Calculate right Sum
  for (int i = nums.size() - 2; i >= 0; --i) {
    rightSum[i] = rightSum[i + 1] + nums[i + 1];
    // cout << rightSum[i] << " " << rightSum[i + 1] << " " << nums[i + 1] << "
    // "
    //      << i << endl; //
    // // debugging
  }

  // check
  for (int i = 0; i < nums.size(); ++i) {
    if (leftSum[i] == rightSum[i]) {
      cout << "Pivot Index is: " << i << endl;
      return;
    }
  }
  cout << "Pivot Index is: " << -1 << endl;
}

void FindPivotIndexBruteForce() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(7);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(5);
  nums.push_back(6);

  for (int i = 0; i < nums.size(); ++i) {
    int lsum = 0;
    int rsum = 0;

    // lsum
    for (int j = 0; j < i; j++)
      lsum += nums[j];

    // rsum
    for (int j = i + 1; j < nums.size(); ++j)
      rsum += nums[j];

    if (lsum == rsum)
      cout << "Pivot Index is " << i << endl;
  }
}

// leetcode 1
void keyPairTwoSum() {
  // sum of 2 number in array should match with the target
  int target = 9;
  int nums[6] = {22, 2, 7, 11, 15, 3};

  sort(nums, nums + 6);
  printArray(nums, 6);
  int low = 0;
  int high = 6 - 1;

  while (low < high) {
    int sum = nums[low] + nums[high];

    if (sum == target) {
      cout << low << high << "Target Exists" << endl;
      return;
    }

    if (sum > target) {
      high--;
    }

    if (sum < target) {
      low++;
    }
  }
}

// leetcode 75 sort colors
void sortColors() {
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(0);
  arr.push_back(2);
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(0);
  arr.push_back(1);
  arr.push_back(0);
  printVector(arr);

  int size = arr.size();
  int left = 0;
  int right = size - 1;
  int index = 0;

  while (index <= right) {
    if (arr[index] == 0) {
      swap(arr[index], arr[left]);
      left++;
      index++;
    } else if (arr[index] == 2) {
      swap(arr[index], arr[right]);
      right--;
    } else {
      index++;
    }
  }

  printVector(arr);
}

// leetcode 268
void missingNumber() {
  // method 1
  int nums[9] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  int size = 9;

  // AP method
  int totalSum = ((size) * (size + 1)) / 2;

  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += nums[i];
  }
  cout << "The missing number is: " << totalSum - sum << endl;
}

void missingNumberBySortMethod() {
  // method 2
  // sorting method complexity o(nlogn) + o(n) = o(nlogn) TC, o(1) SC
  vector<int> nums2;
  nums2.push_back(0);
  nums2.push_back(1);

  sort(nums2.begin(), nums2.end());
  for (int i = 0; i < nums2.size(); i++) {
    if (i == nums2[i]) {
      continue;
    } else {
      cout << "The missing number using Sort Method is: " << i << endl;
      return;
    }
  }

  // if all index match with nums2[index] then size is the missing number or n
  cout << "The missing number using Sort Method is: " << nums2.size() << endl;
}

void missingNumberByXORMethod() {
  // method 3
  // TC - O(n) and SC - O(1)
  vector<int> arr;
  arr.push_back(9);
  arr.push_back(6);
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(5);
  arr.push_back(7);
  arr.push_back(0);
  arr.push_back(1);

  // XOR i^i = 0 else some number
  // method
  // XOR given arr and XOR from 0 - n
  int ans = 0;
  // XOR all values of array
  for (int i = 0; i < arr.size(); i++) {
    ans ^= arr[i];
  }

  // XOR all range items ot 0-n
  for (int i = 0; i <= arr.size(); i++) {
    ans ^= i;
  }

  cout << "The missing element using XOR is: " << ans << endl;
}

// Move all negative number to left side of the array in place
// no order required
void sortNegNumbersToLeft() {
  // aproach 1 sort the arr TC- Onlogn SC- O(n) n-> size of ar
  // aproach 2 Dutch National flag method or 2 pointer

  vector<int> arr;
  arr.push_back(-9);
  arr.push_back(6);
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(-3);
  arr.push_back(5);
  arr.push_back(-7);
  arr.push_back(0);
  arr.push_back(-1);

  // low - manages neg numbers
  // high - manages pos numbers

  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    if (arr[left] < 0) {
      left++;
    } else if (arr[right] > 0) {
      right--;
    } else {
      swap(arr[left], arr[right]);
    }
  }

  printVector(arr);

  // TC - O(n)
  // SC - O(1)
}

// Find Duplicate number mid level 287 only 1 integer will be repeating many
// times arr will be of size n and belong to [1,N]

void findDuplicateNumberInPlace() {
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(2);

  vector<int> nums;
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(2);

  vector<int> num;
  num.push_back(3);
  num.push_back(1);
  num.push_back(3);
  num.push_back(4);
  num.push_back(2);

  // aproach 1 would be to sort and compare i = i+1 then return duplicate number
  // i visit the loop only til N-1 not N because i+1 will be out of bound
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      cout << "Duplicate Number is: " << arr[i] << endl;
      break;
    }
  }

  // aproach 2  Negative marking method
  int ans = -1;

  for (int i = 0; i < nums.size(); i++) {

    int index = abs(nums[i]);

    // already visited check
    if (nums[index] < 0) {
      ans = index;
      break;
    }

    // mark visited
    nums[index] *= -1;
  }

  cout << "The duplicate number is: " << ans << endl;

  // approach 3 positioning method
  while (num[0] != num[num[0]]) {
    swap(num[0], num[num[0]]);
  }

  cout << "The duplicate number is: " << num[0] << endl;

  // approach 4 solve with binary search without modifying array
}

void findMissingElementWithDuplicates() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(4);

  // by visiting method
  for (int i = 0; i < nums.size(); i++) {
    int index = abs(nums[i]);
    if (nums[index - 1] > 0) {
      nums[index - 1] *= -1;
    }
  }

  printVector(nums);

  cout << "The missing numbers are ";
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0)
      cout << i + 1 << " ";
  }

  cout << endl;
}

// first repeating element GFG
// Given an array arrl] of size n, find the first repeating element. The element
// should occur more than once and the index of its first occurrence should be
// the smallest. Note:- The position you return should be according to 1-based
// indexing. Example 1: Input: n = 7 arr] = {1, 5, 3, 4, 3, 5, 6} Output: 2
// Explanation:
// 5 is appearing twice and its first appearence is at index 2 which is less
// than 3 whose first occuring index is 3.

void findFirstRepeatingElement() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(6);

  // // brute force approach compare each element and return first occurance
  // for (int i = 0; i < nums.size(); i++) {

  //   for (int j = i + 1; j < nums.size(); j++) {
  //     if (nums[i] == nums[j]) {

  //       cout << "Repeated Number Index is: " << i + 1 << endl;
  //       return;
  //     }
  //   }
  // }
  // // TC is O(n) + O(n-1) = O(n^2) SC - O(1)
  // cout << "Repeated Number Index is: " << -1 << endl;

  // optimised soln
  // storing the occurance of numbers in hash unordered map
  // Hashing
  unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); i++) {
    hash[nums[i]]++;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (hash[nums[i]] > 1) {
      cout << "Repeated Number index is: " << i + 1 << endl;
      return;
    }
  }
  // TC is O(n) sc is O(1)
  cout << "Repeated Number Index is: " << -1 << endl;
}

// Given three arrays sorted in increasing order. Find the elements that are
// common in all three arrays. Note: can you take care of the duplicates without
// using any additional Data Structure? Example 1: Input: n1 = 6; A = （1,5, 10,
// 20, 40, 80｝ n2 = 5; B = {6, 7, 20, 80, 100} n3 = 8; C = {3, 4, 15, 20, 30,
// 70, 80, 120} Output: 20 80 Explanation: 20 and 80 are the only common
// elements in A, B and C.

// Expected Time Complexity: 0(n1 + n2 + n3)
// Expected Auxiliary Space: 0(n1 + n2 + n3)
// Constraints:
// 1 <= n1, n2, n3 <= 10^5
// The array elements can be both positive or negative integers.
void findCommonElementsIn3SortedArray() {
  int n1 = 6;
  int a[6] = {1, 5, 10, 20, 40, 80};
  int n2 = 5;
  int b[5] = {6, 7, 20, 80, 100};
  int n3 = 8;
  int c[8] = {3, 4, 15, 20, 30, 70, 80, 120};

  set<int> ans;
  int i, j, k;
  i = j = k = 0;

  while (i < n1 && j < n2 && k < n3) {
    if (a[i] == b[j] && b[j] == c[k]) {
      ans.insert(a[i]);
      i++;
      j++;
      k++;
    } else if (a[i] < b[j]) {
      i++;
    } else if (b[j] < c[k]) {
      j++;
    } else {
      k++;
    }
  }

  cout << "Common element are: ";
  printSet(ans);
}

// Wave print a matrix
void WavePrintMatrix() {
  int r1[] = {1, 2, 3, 4};
  int r2[] = {5, 6, 7, 8};
  int r3[] = {9, 10, 11, 12};
  int r4[] = {13, 14, 15, 16};
  int r5[] = {17, 18, 19, 20};

  vector<int> row1(r1, r1 + sizeof(r1) / sizeof(r1[0]));
  vector<int> row2(r2, r2 + sizeof(r2) / sizeof(r2[0]));
  vector<int> row3(r3, r3 + sizeof(r3) / sizeof(r3[0]));
  vector<int> row4(r4, r4 + sizeof(r4) / sizeof(r4[0]));
  vector<int> row5(r5, r5 + sizeof(r5) / sizeof(r5[0]));

  vector<vector<int> > v;
  v.push_back(row1);
  v.push_back(row2);
  v.push_back(row3);
  v.push_back(row4);
  v.push_back(row5);

  int rows = v.size();
  int cols = v[0].size();
  for (int startCol = 0; startCol < cols; startCol++) {
    // even col print top to bottom
    if ((startCol & 1) == 0) {
      for (int row = 0; row < rows; row++) {
        cout << v[row][startCol] << " ";
      }
    } else {
      // odd col print bottom to top
      for (int row = rows - 1; row >= 0; row--) {
        cout << v[row][startCol] << " ";
      }
    }
  }
}

// spiralprint matrix leet code 54
void SpiralPrintMatrix() {
  int r1[] = {1, 2, 3, 4};
  int r2[] = {5, 6, 7, 8};
  int r3[] = {9, 10, 11, 12};
  int r4[] = {13, 14, 15, 16};
  int r5[] = {17, 18, 19, 20};

  vector<int> row1(r1, r1 + sizeof(r1) / sizeof(r1[0]));
  vector<int> row2(r2, r2 + sizeof(r2) / sizeof(r2[0]));
  vector<int> row3(r3, r3 + sizeof(r3) / sizeof(r3[0]));
  vector<int> row4(r4, r4 + sizeof(r4) / sizeof(r4[0]));
  vector<int> row5(r5, r5 + sizeof(r5) / sizeof(r5[0]));

  vector<vector<int> > v;
  v.push_back(row1);
  v.push_back(row2);
  v.push_back(row3);
  v.push_back(row4);
  v.push_back(row5);
  print2DVector(v);

  vector<int> ans;
  int rows = v.size();
  int cols = v[0].size();
  int totalElements = rows * cols;

  int startingRow = 0;
  int endingCol = cols - 1;
  int endingRow = rows - 1;
  int startingCol = 0;

  int count = 0;

  while (count < totalElements) {
    // print starting row
    for (int i = startingCol; i <= endingCol && count < totalElements; i++) {
      ans.push_back(v[startingRow][i]);
      count++;
      // if(count >= totalElements) {
      //   break;
      // }
    }
    startingRow++;

    // print ending col
    for (int i = startingRow; i <= endingRow && count < totalElements; i++) {
      ans.push_back(v[i][endingCol]);
      count++;
    }
    endingCol--;

    // print ending row
    for (int i = endingCol; i >= startingCol && count < totalElements; i--) {
      ans.push_back(v[endingRow][i]);
      count++;
    }
    endingRow--;

    // print starting col
    for (int i = endingRow; i >= startingRow && count < totalElements; i--) {
      ans.push_back(v[i][startingCol]);
      count++;
    }
    startingCol++;
  }

  printVector(ans);
}

// Given two array A[O...N-1] and BIO....M-1] of size N and M respectively,
// representing two numbers such that every element of arrays represent a digit.
// For example, Al] = {1, 2, 3} and BI] = {2, 1,4 } represent 123 and 214
// respectively. The task is to find the sum of both the numbers.

// Input : All = (1, 23, BO] = (2, 1}
// Output : 33
// Explanation:
// N=2, and All=(1,2)
// M=2, and BIl=(2,1}
// Number represented by first array is 12.
// Number represented by second array is 21
// Sum=12+21=33

// Input : A[] = {9, 5, 4, 9}, B[] = {2, 1, 4}
// Output : 9763

void AddTwoNumbersByTwoArrays() {
  int a[] = {0, 9, 5, 4, 9};
  int b[] = {2, 1, 4};

  string ans;
  int i = 4;
  int j = 2;
  int carry = 0;
  // adding both the arrays till the both the index are same
  while (i >= 0 && j >= 0) {
    int x = a[i] + b[j] + carry;
    int digit = x % 10;
    carry = x / 10;
    ans.push_back(digit + '0');
    i--;
    j--;
  }

  // if some left most digits are left to add in array a
  while (i >= 0) {
    int x = a[i] + carry;
    int digit = x % 10;
    carry = x / 10;
    ans.push_back(digit + '0');
    i--;
  }

  // if some left most digits are left to add in array b
  while (j >= 0) {
    int x = b[j] + carry;
    int digit = x % 10;
    carry = x / 10;
    ans.push_back(digit + '0');
    j--;
  }

  if (carry) {
    ans.push_back(carry + '0');
  }

  // to remove extra zeros in the starting
  while (ans[ans.size() - 1] == '0') {
    ans.pop_back();
  }
  // the answer should be reversed to
  reverse(ans.begin(), ans.end());

  cout << ans << endl;
}

void findFactorialOfALargeNumber() {
  int n = 50;
  vector<int> ans;
  ans.push_back(1);
  int carry = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < ans.size(); j++) {
      int x = ans[j] * i + carry;
      ans[j] = x % 10;
      carry = x / 10;
    }
    // if(carry) {
    //   ans.push_back(carry);
    // }

    // if carry is also in double digit
    while (carry) {
      ans.push_back(carry % 10);
      carry = carry / 10;
    }

    carry = 0;
  }
  reverse(ans.begin(), ans.end());
  printVector(ans);
}

// Leetcode 26
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
// • Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums:.
// • Return k.
// Remove Duplicates
// Input: nums = [0,0,1, 1, 1,2,2,3,3,4]
// Output: 5, nums =
// ［0,1,2,3,4._,_,_,_,_］
// Explanation: Your function should return k = 5, with the
// first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
void removeDuplicates() {
  vector<int> arr;
  arr.push_back(0);
  arr.push_back(0);
  arr.push_back(1);
  arr.push_back(1);
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(3);
  arr.push_back(4);

  int i=1, j=0;

  while(i < arr.size()) {
    if(arr[i] == arr[j]) {
      i++;
    } else arr[++j] = arr[i++];
    // else {
    //   j++;
    //   arr[j] = arr[i];
    //   i++;
    // }
  }
  cout << "K is: " << j + 1 << endl;
  printVector(arr);


}


int main() {
  // FindPivotIndex();
  // FindPivotIndexBruteForce();
  // keyPairTwoSum();
  // sortColors();
  // missingNumber();
  // missingNumberBySortMethod();
  // missingNumberByXORMethod();
  // sortNegNumbersToLeft();
  // findDuplicateNumberInPlace();
  // findMissingElementWithDuplicates();
  // findFirstRepeatingElement();
  // findCommonElementsIn3SortedArray();
  // WavePrintMatrix();
  // SpiralPrintMatrix();
  // AddTwoNumbersByTwoArrays();
  // findFactorialOfALargeNumber();
  removeDuplicates();
  return 0;
}