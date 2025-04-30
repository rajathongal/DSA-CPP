#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printVector(vector< int > v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    cout << v[i] << " "; // method 1
    // cout << v.at(i) << endl;
  }
  cout << endl;
}

// First Non repeating Character in a stream Left -> right
void firstNonRepeatingCharInStream(string str) {
  queue< char > q;
  int freq[26] = {0};

  for (int i = 0; i < str.length(); i++) {
    // Map char to freq table
    char ch = str[i];
    freq[ch - 'a']++; // convert char to number 0-26 a-z
    q.push(ch);

    // find answer
    while (!q.empty()) {
      char frontChar = q.front();
      if (freq[frontChar - 'a'] > 1) {
        // remove
        q.pop();
      } else {
        // unique char
        // answer
        cout << frontChar << " -> ";
        break;
      }
    }

    if (q.empty()) {
      cout << "# -> ";
    }
  }
}

// vvimp
// gas station / petrol pump problem
// LeetCode 134
int canCompleteCircuit(vector< int > &gas, vector< int > &cost) {
  int deficit = 0;
  int balance = 0;

  int start = 0;
  for (int i = 0; i < gas.size(); i++) {
    balance = balance + gas[i] - cost[i];

    if (balance < 0) {
      deficit += abs(balance);
      start = i + 1;
      balance = 0;
    }
  }

  if (balance - deficit >= 0) {
    return start;
  } else
    return -1;
}

// Sliding window maximum Leetcode 239
vector< int > maxSlidingWindow(vector< int > &nums, int k) {
  vector< int > ans;
  deque< int > dq;

  // process first window
  for (int i = 0; i < k; i++) {
    int element = nums[i];
    // remove less than element in queue
    while (!dq.empty() && element > nums[dq.back()]) {
      dq.pop_back();
    }
    // insert the element
    dq.push_back(i);
  }

  // process remaning window
  // removal and addition
  for (int i = k; i < nums.size(); i++) {
    // store ans
    ans.push_back(nums[dq.front()]);

    // remove out of range elements
    if (!dq.empty() && (i - dq.front() >= k)) {
      dq.pop_front();
    }

    // pop small element
    int element = nums[i];
    while (!dq.empty() && element > nums[dq.back()]) {
      dq.pop_back();
    }

    // addition 
    dq.push_back(i);
  }

  // last window processing
  ans.push_back((nums[dq.front()]));
  return ans;
}

int main() {

  // Uncomment for first non repeating char in stream
  // firstNonRepeatingCharInStream("facfdcad");

  // Uncomment for Leetcode 34
  // vector< int > gasOne = {1, 2, 3, 4, 5};
  // vector< int > costOne = {3, 4, 5, 1, 2};

  // vector< int > gasTwo = {2, 3, 4};
  // vector< int > costTwo = {3, 4, 3};

  // cout << canCompleteCircuit(gasOne, costOne) << endl;
  // cout << canCompleteCircuit(gasTwo, costTwo) << endl;

  // Uncomment for sliding window maximum Leetcode 239

  vector< int > numOne = {1, 3, -1, -3, 5, 3, 6, 7};
  int kOne = 3;

  vector< int > ansOne = maxSlidingWindow(numOne, kOne);
  printVector(ansOne);

  return 0;
}