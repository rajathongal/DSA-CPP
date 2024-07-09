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
  if (size == 1) {
    return nums[0];
  }
  int option1 = rob(nums, size - 2, 0);
  int option2 = rob(nums, size - 1, 1);
  int finalAns = max(option1, option2);
  return finalAns;
}

// Count DeArrangement
// https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
int countDeArrangement(int n) {
  // base case
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  // Processing
  int n1 = countDeArrangement(n - 1);
  int n2 = countDeArrangement(n - 2);
  int ans = (n - 1) *  (n1+ n2);
  cout << n1 << " " << n2 << " " << n << " "<< ans << endl;

  return ans;
}

// painting fence algo
// https://www.geeksforgeeks.org/painting-fence-algorithm/
// Returns count of ways to color k posts
long countWays(int n, int k) {

  // base case
  if(n == 1) {
    return k;
  }

  if(n == 2) {
    return k + k * (k-1);
  }

  int ans = (k-1) * (countWays(n-1, k) + countWays(n-2, k));
  return ans;
}

int main() {
  // vector< int > nums1 = {2, 3, 2};
  // vector< int > nums2 = {1, 2, 3, 1};
  // vector< int > nums3 = {1, 2, 3, 4};
  // vector< int > nums4 = {10};

  // cout << robRobber2(nums1, nums1.size(), 0) << endl;
  // cout << robRobber2(nums2, nums2.size(), 0) << endl;
  // cout << robRobber2(nums3, nums3.size(), 0) << endl;
  // cout << robRobber2(nums4, nums4.size(), 0) << endl;

  // cout << countDeArrangement(5) << endl;
  // cout << countDeArrangement(4) << endl;
  // cout << countDeArrangement(3) << endl;
  // cout << countDeArrangement(1) << endl;

  cout << countWays(2, 4) << endl;
  cout << countWays(3, 2) << endl;
  cout << countWays(3, 3) << endl;


  return 0;
}

// catlan series must read