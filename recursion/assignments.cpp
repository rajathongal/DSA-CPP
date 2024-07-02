#include <cstring> // for strrchr
#include <iostream>
#include <vector>
using namespace std;

// Last occurance of a char
void findLastOccuranceOfChar(string str, int index, int &ans, char target) {
  if (str[index] == '\0') {
    return;
  }

  if (str[index] == target) {
    ans = index;
  }

  findLastOccuranceOfChar(str, index + 1, ans, target);
}

// Reverse a string
// Tc -> O(n/2) -> O(n)
// SC -> O(n/2 + 1 ) -> O(n)
void reverseString(string &str, int start, int end) {
  if (start >= end) {
    return;
  }

  swap(str[start++], str[end--]);
  reverseString(str, start, end);
}

// Leetcode 415. Add Strings
// N = max(num1, num2)
// m = constant
// TC O(N + 1) -> O(N)
// SC O(m(N+1)) -> O(N)
// by ref params reduce space complexity
void addStrings(string &num1, int ptr1, string &num2, int ptr2, string &ans,
                int carry = 0) {
  // string ans = "";
  if (ptr1 && ptr2 < 0) {
    // extra carry might be remaining
    if (carry != 0) {
      // return string(1, carry + '0');
      ans.push_back(carry + '0');
    }
    // return "";
    return;
  }

  // ex sum 1 456 and sum2 56 -> ptr will be at diff positions

  int digitOfNum1 = (ptr1 >= 0 ? num1[ptr1] : '0') - '0';
  int digitOfNum2 = (ptr2 >= 0 ? num2[ptr2] : '0') - '0';
  int csum = digitOfNum1 + digitOfNum2 + carry;

  int remainingDigit = csum % 10;
  carry = csum / 10;
  ans.push_back(remainingDigit + '0');

  // ans += addStrings(num1, ptr1 - 1, num2, ptr2 - 1, ans, carry);
  addStrings(num1, ptr1 - 1, num2, ptr2 - 1, ans, carry);

  // return ans;
}

// Check palindrome
// 1 is for base condition below
// Tc -> O(n/2) -> O(n)
// SC -> O(n/2 + 1 ) -> O(n)

bool checkPalindrome(string &str, int start, int end) {
  if (start >= end) {
    return true;
  }

  if (str[start] != str[end]) {
    return false;
  }

  return checkPalindrome(str, start+1, end-1);
}

// Print all sub array using RE
void subArray(vector<int> &nums, int start, int end) {
  // base case
  if(end >= nums.size()) {
    return;
  }

  // processing 
  for(int i=start; i<= end; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  // RE Call
  subArray(nums, start, end + 1);
}

int main() {
  // // for last occurance of char
  // int ans = -1;
  // findLastOccuranceOfChar("Lababdarbab", 0, ans, 'b');
  // cout << ans << endl;

  // // last occr using inbuilt fn
  // const char* last_occurrence = strrchr("Lababdarbab", 'b');
  // cout << last_occurrence << endl;

  // Reverse a string
  // string str = "lababdar";
  // int start = 0;
  // int end = str.length() - 1;
  // reverseString(str, start, end);
  // cout << str << endl;

  // // for string add
  // string num1 = "456", num2 = "77";
  // string ans1 = "";
  // addStrings(num1, num1.size() - 1, num2, num2.size() - 1, ans1);
  // reverse(ans1.begin(), ans1.end());
  // cout << ans1 << endl;

  // string num3 = "11", num4 = "77";
  // string ans2 = "";
  // addStrings(num3, num3.size() - 1, num4, num4.size() - 1, ans2);
  // reverse(ans2.begin(), ans2.end());
  // cout << ans2 << endl;

  string str1 = "racecar";
  cout << checkPalindrome(str1, 0, str1.size() - 1) << endl;

  string str2 = "racetar";
  cout << checkPalindrome(str2, 0, str2.size() - 1) << endl;

  vector<int> nums = {1,2,3,4};
  // nums.push_back()
  // subArray()

  return 0;
}