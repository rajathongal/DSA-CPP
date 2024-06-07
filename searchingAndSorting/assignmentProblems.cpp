#include <iostream>
#include <set>
#include <utility>
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
int binarySearch(vector<int> &nums, int start, int target) {

  int size = nums.size();
  int end = size - 1;
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
    if (binarySearch(nums, i + 1, abs(nums[i] + k)) != -1) {
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

  while(high - low >= k) {
    if(x - nums[low] > nums[high] - x) {
      low++;
    } else {
      high--;
    }
  }

  for(int i=low; i<=high; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
}

int main() {
  // kDiffPairsUsingTwoPointer();
  // kDiffPairsUsingBinarySearch();
  findKClosestElementsUsingTwoPointers();
  return 0;
}