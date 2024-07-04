#include <cstring> // for strrchr
#include <iostream>
#include <string>
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

  return checkPalindrome(str, start + 1, end - 1);
}

// Print all sub array using RE

// TC -> O(N^2)
// start run for N times
// end runs for N, N-1, N-2 ... 1 worst case N
// so N * N

// SC -> O(N)
// subarray runs -> N + 2 calls

void subArray_util(vector< int > &nums, int start, int end) {
  // base case
  if (end >= nums.size()) {
    return;
  }

  // processing
  for (int i = start; i <= end; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  // RE Call
  subArray_util(nums, start, end + 1);
}

void subArray(vector< int > &nums) {
  for (int start = 0; start < nums.size(); start++) {
    int end = start;
    subArray_util(nums, start, end);
  }
}

// Remove all occurances of a subarray
// N -> str.size
// M -> part.size
// left part -> O(N)
// right part -> O(M)
// O(N)
// O(NM) + O(N) -> O(NM) for one case
// total RE calls = O(N/M)

// TC -> O(N/M * NM) = O(N^2)
// SC -> O(N/M)

void removeOccurances(string &str, string &part) {

  // processing
  // 1. find part string position in s
  // 2. erase that part
  // 3. RE call for remaining string

  // 1.
  int found = str.find(part);

  // 2.
  if (found != string::npos) {
    // part string is located
    // we can take left string of found and concatinate it with right +
    // len(part) of found

    // pluck left str
    string leftStr = str.substr(0, found);
    string rightStr = str.substr(found + part.size(), str.size());
    str = leftStr + rightStr;

    removeOccurances(str, part);
  } else {
    // all the occurances have been removed
    // base case
    return;
  }
}

// BUY And SELL Stocks
// LeetCode 121 Best Time to buy and sell stock
// TC -> O(N)
// SC -> O(N)
void maxProfitS(vector< int > &prices, int index, int &minPrice,
                int &maxProfit) {
  // base case N + 1 Times
  if (index >= prices.size()) {
    return;
  }

  // processing k time
  if (prices[index] < minPrice) {
    minPrice = prices[index];
  }

  int todaySProfit = prices[index] - minPrice;
  if (todaySProfit > maxProfit) {
    maxProfit = todaySProfit;
  }

  // RE
  maxProfitS(prices, index + 1, minPrice, maxProfit);
}

// Leetcode 198. House Robber
int rob(vector< int > &nums, int size, int index) {
  if (index >= size) {
    return 0;
  }

  // rob -> ith index
  int option1 = nums[index] + rob(nums, size, index + 2);
  // do not rob -> ith index
  int option2 = 0 + rob(nums, size, index + 1);

  int finalAns = max(option1, option2);
  return finalAns;
}

// Leetcode 273. Integer to words
// computation is proportional to number of words generated
// words generated is proportional to the digits in num
// 1 digit can be represented by 2 words max
// N -> no of digits -> ceil(logN)base10
// TC -> proportional to no of digits
// TC -> O(log10 N) base 10
// N -> no of digits, constant which represents no of time it will loop in
// reference map untill no is found ex num 23 -> 23 times loop in reference map
// SC -> O(log10 N) base 10

string numberToWords(int num, vector< pair< int, string > > &referenceMap) {
  if (num == 0) {
    return "Zero";
  }

  // try to find the closest reference of num
  for (auto it : referenceMap) {
    // breaking condition
    if (num >= it.first) {
      string placeValueInWords = ""; // only if num >= 100
      string placeReferenceInString =
          it.second; // thousand hundred or one, two or tweleve
      string trailingValueInWords = ""; // ex 12,345 -> 345 is trail

      if (num >= 100) { // to get 100, thousands
        placeValueInWords = numberToWords(num / it.first, referenceMap) + " ";
      }

      if (num % it.first != 0) {
        trailingValueInWords =
            " " + numberToWords(num % it.first, referenceMap);
      }

      return placeValueInWords + placeReferenceInString + trailingValueInWords;
    }
  }
  return "";
}

// Leetcode 44, WildCard Matching Hard level
// O(2^N)
// O(N + 1)
bool isMatch(string s, string p, int si = 0, int pi = 0) {

  // base case
  if (si == s.size() && pi == p.size()) {
    return true;
  }

  // processing
  if (si == s.size() && pi < p.size()) {
    // in case p still has **fg -> fg are still there in p but s is already out
    // of bound return false
    while (pi < p.size()) {
      if (p[pi] != '*')
        return false;
      pi++;
    }

    // return true only when there are all astrix in p

    return true;
  }

  // single char matching
  if (s[si] == p[pi] || p[pi] == '?') {
    return isMatch(s, p, si + 1, pi + 1);
  }

  // handling *
  if (p[pi] == '*') {
    // RE Call
    bool isCaseAstrixConsideredAsNull = isMatch(s, p, si, pi + 1);
    bool isCaseLetAstrixConsumeOneChar =
        isMatch(s, p, si + 1, pi); // pi will point at astrix still
    return isCaseAstrixConsideredAsNull || isCaseLetAstrixConsumeOneChar;
  }

  // char does not match
  return false;
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

  // string str1 = "racecar";
  // cout << checkPalindrome(str1, 0, str1.size() - 1) << endl;

  // string str2 = "racetar";
  // cout << checkPalindrome(str2, 0, str2.size() - 1) << endl;

  // vector< int > nums = {1, 2, 3, 4, 5};
  // subArray(nums);

  // string s1 = "daabcbaabcbc";
  // string p1 = "abc";
  // removeOccurances(s1, p1);
  // cout << s1 << endl;

  // string s2 = "axxxxyyyyb";
  // string p2 = "xy";
  // removeOccurances(s2, p2);
  // cout << s2 << endl;

  // vector< int > prices1 = {7, 1, 5, 3, 6, 4};
  // int minPrice = INT_MAX;
  // int maxProfit = INT_MIN;
  // maxProfitS(prices1, 0, minPrice, maxProfit);
  // cout << maxProfit << endl;

  // vector<int> robOne = {1,2,3,1};
  // vector<int> robTwo = {2,7,9,3, 1};

  // cout << rob(robOne, robOne.size(), 0) << endl;
  // cout << rob(robTwo, robTwo.size(), 0) << endl;

  // For int to words problem
  // vector< pair< int, string > > referenceMap = {{1000000000, "Billion"},
  //                                               {1000000, "Million"},
  //                                               {1000, "Thousand"},
  //                                               {100, "Hundred"},
  //                                               {90, "Ninety"},
  //                                               {80, "Eighty"},
  //                                               {70, "Seventy"},
  //                                               {60, "Sixty"},
  //                                               {50, "Fifty"},
  //                                               {40, "Forty"},
  //                                               {30, "Thirty"},
  //                                               {20, "Twenty"},
  //                                               {19, "Nineteen"},
  //                                               {18, "Eighteen"},
  //                                               {17, "Seventeen"},
  //                                               {16, "Sixteen"},
  //                                               {15, "Fifteen"},
  //                                               {14, "Fourteen"},
  //                                               {13, "Thirteen"},
  //                                               {12, "Twelve"},
  //                                               {11, "Eleven"},
  //                                               {10, "Ten"},
  //                                               {9, "Nine"},
  //                                               {8, "Eight"},
  //                                               {7, "Seven"},
  //                                               {6, "Six"},
  //                                               {5, "Five"},
  //                                               {4, "Four"},
  //                                               {3, "Three"},
  //                                               {2, "Two"},
  //                                               {1, "One"}};

  // int num1 = 10102;
  // int num2 = 123;
  // int num3 = 1234567;

  // string ans1, ans2, ans3;
  // ans1 = numberToWords(num1, referenceMap);
  // ans2 = numberToWords(num2, referenceMap);
  // ans3 = numberToWords(num3, referenceMap);

  // cout << ans1 << endl;
  // cout << ans2 << endl;
  // cout << ans3 << endl;

  cout << isMatch("aa", "a") << endl;
  cout << isMatch("aa", "*") << endl;
  cout << isMatch("cb", "?a") << endl;
  cout << isMatch("ca", "?a") << endl;
  cout << isMatch("aa", "aa*") << endl;  // * acts as empty string
  cout << isMatch("**ab", "ab") << endl; // * acts as empty string
  cout << isMatch("abcdefg", "ab*fg")
       << endl; // will return true as * will match with cde
       cout << isMatch("abc", "abc***")
       << endl;

  return 0;
}