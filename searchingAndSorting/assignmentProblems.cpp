#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
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
int binarySearch(vector<int> &nums, int start, int end, int target) {

  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (nums[mid] == target) {
      return mid;
    } else if (target > nums[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }

  return -1;
}

void kDiffPairsUsingBinarySearch() {
  vector<int> nums;
  int k = 2;
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(1);
  nums.push_back(5);

  sort(nums.begin(), nums.end());
  set<pair<int, int> > answer;
  for (int i = 0; i < nums.size(); i++) {
    if (binarySearch(nums, i + 1, nums.size() - 1, abs(nums[i] + k)) != -1) {
      answer.insert(make_pair(nums[i], nums[i] + k));
    }
  }

  cout << "K-Diff Pairs count using binary search is: " << answer.size()
       << endl;
}

// leetcode 658
void findKClosestElementsUsingTwoPointers() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);

  int k = 4;
  int x = -1;

  int low = 0;
  int high = nums.size() - 1;

  while (high - low >= k) {
    if (x - nums[low] > nums[high] - x) {
      low++;
    } else {
      high--;
    }
  }

  for (int i = low; i <= high; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
}

// k closest element using Binary Search
int lowerBound(vector<int> &nums, int target) {
  int start = 0, end = nums.size() - 1;
  int ans = end; // overflow

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (nums[mid] >= target) {
      ans = mid;
      end = mid - 1;
    } else if (target > nums[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return ans;
}

void findKClosestElementsUsingBinarySearch() {
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(8);
  nums.push_back(10);

  int k = 2;
  int x = 15;

  int high = lowerBound(nums, x);
  int low = high - 1;

  while (k--) {
    if (low < 0) {
      high++;
    } else if (high >= nums.size()) {
      low--;
    } else if (x - nums[low] > nums[high] - x) {
      high++;
    } else {
      low--;
    }
  }

  for (int i = low + 1; i < high; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
}

void exponentialSearch() {
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(11);
  nums.push_back(13);
  nums.push_back(14);
  nums.push_back(15);
  nums.push_back(56);
  nums.push_back(70);

  int target = 13;
  int size = nums.size();
  int ans = -1;

  if(nums[0] == target) {
    ans = 0;
  }

  int i=1;

  while(i < size && nums[i] <= target) {
    i *= 2; // or i = i * 2 or i = i<< 1
  }

  ans = binarySearch(nums, i/2, min(i, size - 1), target);

  cout << "The target is at index: " << ans << endl;
}

int main() {
  // kDiffPairsUsingTwoPointer();
  // kDiffPairsUsingBinarySearch();
  // findKClosestElementsUsingTwoPointers();
  // findKClosestElementsUsingBinarySearch();
  exponentialSearch();
  return 0;
}