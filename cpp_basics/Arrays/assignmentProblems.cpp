#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
#include <cmath>
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
  while(num[0] != num[num[0]]) {
    swap(num[0], num[num[0]]);
  }

  cout << "The duplicate number is: " << num[0] << endl;

  // approach 4 solve with binary search without modifying array

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
  findDuplicateNumberInPlace();
  return 0;
}