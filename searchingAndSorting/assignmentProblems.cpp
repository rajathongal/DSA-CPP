#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Leetcode 532 K diff pairs

// using two pointer
void kDiffPairsUsingTwoPointer() {
  vector<int> nums;
  // int k = 2;
  // nums.push_back(3);
  // nums.push_back(1);
  // nums.push_back(4);
  // nums.push_back(1);
  // nums.push_back(5);

  // int k = 0;
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);

  int k = 1;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);

  // sort the vector
  sort(nums.begin(), nums.end());

  int i = 0;
  int j = 1;
  int size = nums.size();
  set<pair<int, int> > answer;

  while (j < size) {
    int difference = nums[j] - nums[i];

    if (difference == k) {
      answer.insert(make_pair(nums[i], nums[j]));
      i++;
      j++;
    } else if (difference > k) {
      i++;
    } else
      j++;

    if (i == j)
      j++;
  }

  cout << "Unique K-Diff pair count by two pointer method is: " << answer.size()
       << endl;
}

// using binary search
int binarySearch() { return 0; }

void kDiffPairsUsingBinarySearch() {}

int main() {
  kDiffPairsUsingTwoPointer();
  return 0;
}