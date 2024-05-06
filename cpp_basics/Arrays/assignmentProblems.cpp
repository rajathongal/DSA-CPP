#include <climits>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void FindPivotIndex() {
  vector<int> nums;
  // case 1 ans 3
  // nums.push_back(1);
  // nums.push_back(7);
  // nums.push_back(3);
  // nums.push_back(6);
  // nums.push_back(5);
  // nums.push_back(6);

  // case 2 ans -1
  // nums.push_back(1);
  // nums.push_back(2);
  // nums.push_back(3);

  // case 3 ans 0
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(-1);

  vector<int> leftSum(nums.size(), 0);
  vector<int> rightSum(nums.size(), 0);

  // Calculate left Sum
  for (int i = 1; i < nums.size(); ++i) {
    leftSum[i] = leftSum[i - 1] + nums[i - 1];
    // cout << leftSum[i] << leftSum[i - 1] << nums[i - 1] << endl; // debugging
  }

  // Calculate right Sum
  for (int i = nums.size() - 2; i >= 0; --i) {
    rightSum[i] = rightSum[i + 1] + nums[i + 1];
    // cout << rightSum[i] << rightSum[i + 1] << nums[i + 1] << endl; // debugging
  
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

int main() {
  FindPivotIndex();
  // FindPivotIndexBruteForce();
  return 0;
}