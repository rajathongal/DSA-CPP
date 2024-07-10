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
  int ans = (n - 1) * (n1 + n2);
  cout << n1 << " " << n2 << " " << n << " " << ans << endl;

  return ans;
}

// painting fence algo
// https://www.geeksforgeeks.org/painting-fence-algorithm/
// Returns count of ways to color k posts
long countWays(int n, int k) {

  // base case
  if (n == 1) {
    return k;
  }

  if (n == 2) {
    return k + k * (k - 1);
  }

  int ans = (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k));
  return ans;
}

// Leetcode 72. Edit distance
int minDistance(string word1, string word2, int i = 0, int j = 0) {
  // base case
  if (i >= word1.length()) {
    // this means there maybe some chars still left in word 2 and word1 may have
    // less chars than word2
    // so we return the remaining chaars from word 2
    return word2.length() - j;
  }

  if (j >= word2.length()) {
    // this means there maybe some chars still left in word 1 and word2 may have
    // less chars than word1
    // so we return the remaining chars from word 1
    return word1.length() - i;
  }

  int ans = 0;

  // match / no match
  if (word1[i] == word2[j]) {
    // match
    ans = 0 + minDistance(word1, word2, i + 1, j + 1);
  } else {
    // not match
    // insert
    int optionInsert = 1 + minDistance(word1, word2, i, j + 1);
    // remove
    int optionRemove = 1 + minDistance(word1, word2, i + 1, j);
    // replace
    int optionReplace = 1 + minDistance(word1, word2, i + 1, j + 1);

    ans = min(optionInsert, min(optionRemove, optionReplace));
  }
  return ans;
}

// Leetcode 221 Maximal Square
int maximalSquare(vector< vector< char > > &matrix, int row, int col, int &maxi,
                  int i = 0, int j = 0) {
  if (i >= row || j >= col) {
    return 0;
  }

  // explore all 3 directions
  int right = maximalSquare(matrix, row, col, maxi, i, j + 1);
  int diagonal = maximalSquare(matrix, row, col, maxi, i + 1, j + 1);
  int down = maximalSquare(matrix, row, col, maxi, i + 1, j);

  // check can we build square from current position
  if (matrix[i][j] == '1') {
    int ans = 1 + min(right, min(down, diagonal));
    maxi = max(maxi, ans);
    return ans;
  } else {
    // ans also 0
    return 0;
  }
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

  // cout << countWays(2, 4) << endl;
  // cout << countWays(3, 2) << endl;
  // cout << countWays(3, 3) << endl;

  // cout << minDistance("horse", "ros") << endl;
  // cout << minDistance("intention", "execution") << endl;

  // for Maximal Square
  vector< vector< char > > matrixOne = {{'1', '0', '1', '0', '0'},
                                        {'1', '0', '1', '1', '1'},
                                        {'1', '1', '1', '1', '1'},
                                        {'1', '0', '0', '1', '0'}};
  vector< vector< char > > matrixTwo = {
      {'1', '0', '1', '1', '1'}, 
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'}, 
      {'1', '1', '1', '1', '0'},
      {'1', '1', '1', '1', '0'}, 
      {'1', '1', '1', '1', '0'},
  };
  int maxOne = INT_MIN;
  int maxTwo = INT_MIN;

  maximalSquare(matrixOne, matrixOne.size(), matrixOne[0].size(), maxOne);
  if(maxOne != INT_MIN) {
    maxOne  = maxOne * maxOne;
  }
  cout << maxOne << endl;

  maximalSquare(matrixTwo, matrixTwo.size(), matrixTwo[0].size(), maxTwo);
  if(maxTwo != INT_MIN) {
    maxTwo  = maxTwo * maxTwo;
  }
  cout << maxTwo  << endl;

  return 0;
}

// catlan series must read