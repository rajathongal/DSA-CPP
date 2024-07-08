#include <iostream>
#include <vector>
using namespace std;

int rob(vector< int > &nums, int size, int index) {
  if (index > size) {
    return 0;
  }

  // rob -> ith index
  int option1 = nums[index] + rob(nums, size, index + 2);
  // do not rob -> ith index
  int option2 = 0 + rob(nums, size, index + 1);

  int finalAns = max(option1, option2);
  return finalAns;
}

int robRobber2(vector< int > &nums, int size, int index) {
  if(size == 1) {
    return nums[0];
  }
  int option1 = rob(nums, size - 2, 0);
  int option2 = rob(nums, size - 1, 1);
  int finalAns = max(option1, option2);
  return finalAns;
}

int main() {
  vector< int > nums1 = {2, 3, 2};
  vector< int > nums2 = {1, 2, 3, 1};
  vector< int > nums3 = {1, 2, 3, 4};
  vector< int > nums4 = {10};

  cout << robRobber2(nums1, nums1.size(), 0) << endl;
  cout << robRobber2(nums2, nums2.size(), 0) << endl;
  cout << robRobber2(nums3, nums3.size(), 0) << endl;
  cout << robRobber2(nums4, nums4.size(), 0) << endl;


  return 0;
}