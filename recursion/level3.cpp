
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// check if array is sorted or not
bool isSorted(int arr[], int size, int index) {
  if (index >= size) {
    return true;
  }

  if (arr[index] > arr[index - 1]) {
    bool ans = isSorted(arr, size, index + 1);
    return ans;
  }
  return false;
}

int binarySearchUsingRecursion(int arr[], int s, int e, int target) {

  // base case
  if (s > e) {
    return -1;
  }

  // processing
  int mid = s + (e - s) / 2;
  if (arr[mid] == target) {
    return mid;
  }

  // Recursive call
  if (arr[mid] < target) {

    return binarySearchUsingRecursion(arr, mid + 1, e, target);
  } else {

    return binarySearchUsingRecursion(arr, s, mid - 1, target);
  }
}

// Include Exclude Pattern ! ! ! ! ! ! ! !
void findSubSeq(string str, string output, int index) {
  if (index >= str.length()) {
    cout << "-> " << output << endl;
    return;
  }

  char ch = str[index];

  // first exclude then include code below
  // exclude
  // findSubSeq(str, output, index + 1);

  // // include
  // output.push_back(ch);
  // findSubSeq(str, output, index + 1);

  // first include then exclude code below
  // include
  output.push_back(ch);
  findSubSeq(str, output, index + 1);

  // include
  output.pop_back();
  findSubSeq(str, output, index + 1);
}

// GFG -> Maximize the cut segments
// Given an integer N denoting the Length of a line segment.
// You need to cut the line segment in such a way that
// the cut length of a line segment each time is either x, y or z.
// Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments
// must be maximum. Note: if no segment can be cut then return 0. Example 1:
// Input:
// N = 4
// x = 2, y = 1, z = 1
// Output: 4
// Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.
// We can make maximum 4 segments each of length 1.

// Exploring all possible ways pattern ! ! ! ! !
int maximizeTheCuts(int n, int x, int y, int z) {

  if (n == 0) {
    return 0;
  }

  // when n-x, n-z, n-y goes negative then return INT_MIN so that it negates
  // while picking max
  if (n < 0) {
    return INT_MIN;
  }

  // Return Max of 3 options
  // cut 1 segment of size option
  int optionX = 1 + maximizeTheCuts(n - x, x, y, z);
  int optionY = 1 + maximizeTheCuts(n - y, x, y, z);
  int optionZ = 1 + maximizeTheCuts(n - z, x, y, z);

  int finalAns = max(optionX, max(optionY, optionZ));
  return finalAns;
}

// Leetcode 322 Coin Change
// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount.
// !!!!!!!

// If that amount of money cannot be made up by any combination of the coins,
// return -1. You may assume that you have an infinite number of each kind of
// coin.

// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

int solveCoinChange(vector< int > &coins, int amount) {

  if (amount == 0) {
    return 0;
  }
  int minCoins = INT_MAX;

  int ans = INT_MAX;
  for (int i = 0; i < coins.size(); i++) {

    // use coin only when coin <= amount
    int coin = coins[i];

    if (coin <= amount) {
      int recAns = solveCoinChange(coins, amount - coin);
      if (recAns != INT_MAX) {
        ans = 1 + recAns;
      }
    }
    minCoins = min(minCoins, ans);
  }

  return ans;
}
int coinchange(vector< int > &coins, int amount) {
  int ans = solveCoinChange(coins, amount);

  if (ans == INT_MAX) {
    return -1;
  }
  return ans;
}

int main() {
  int arr[] = {11, 60, 23, 30, 60, 47, 93, 60, 70};
  int arr2[] = {10, 20, 30, 40, 50};

  int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
  int sizeOfArr2 = sizeof(arr2) / sizeof(arr2[0]);

  // cout << isSorted(arr, sizeOfArr, 1) << endl;
  // cout << isSorted(arr2, sizeOfArr2, 1) << endl;

  // cout << binarySearchUsingRecursion(arr, 0, sizeOfArr - 1, 93) << endl;

  // string output = "";
  // findSubSeq("abc", output, 0);

  // cout << maximizeTheCuts(4,2,1,1) << endl;
  // cout << maximizeTheCuts(20,2,1,1) << endl;
  // cout << maximizeTheCuts(20,2,10,10) << endl;
  // cout << maximizeTheCuts(20,5,10,10) << endl;
  // cout << maximizeTheCuts(20,5,10,5) << endl;

  vector< int > coinChangeCaseOne;
  int amountOne = 11;
  vector< int > coinChangeCaseTwo;
  int amountTwo = 3;

  coinChangeCaseOne.push_back(1);
  coinChangeCaseOne.push_back(2);
  coinChangeCaseOne.push_back(5);

  coinChangeCaseTwo.push_back(2);

  cout << coinchange(coinChangeCaseOne, amountOne) << endl;
  cout << coinchange(coinChangeCaseTwo, amountTwo) << endl;

  return 0;
}