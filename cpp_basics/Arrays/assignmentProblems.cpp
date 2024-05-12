#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

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

int main() {
  // FindPivotIndex();
  // FindPivotIndexBruteForce();
  keyPairTwoSum();
  return 0;
}