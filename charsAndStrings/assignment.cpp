#include <climits>
#include <ctype.h>
#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

void print2DStringVector(vector< vector< string > > arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

void print1DCharVector(vector< char > arr) {
  cout << "Print Char Vector" << endl;
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << "  ";
  }
  cout << endl;
}

// Leetcode 242 Valid Anagram

void createMappingAlphabetically(string &str, string &testString) {
  // find mapping
  char start = 'a';
  char mappingStr[300] = {0};
  char mappingTestString[300] = {0};

  for (auto ch : str) {
    if (mappingStr[ch] == 0) {
      mappingStr[ch] = start;
      start++;
    }
  }

  for (auto ch : testString) {
    if (mappingTestString[ch] == 0) {
      mappingTestString[ch] = start;
      start++;
    }
  }

  // update string according to mapping
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    str[i] = mappingStr[ch];
  }

  for (int i = 0; i < testString.length(); i++) {
    char ch = testString[i];
    if (mappingStr[ch] != 0) {
      testString[i] = mappingStr[ch];
    } else {
      testString[i] = mappingTestString[ch];
    }
  }
}

void isAnagram(string str, string testString) {
  // method 1 sort and compare
  sort(str.begin(), str.end());
  sort(testString.begin(), testString.end());

  // method 2 sort and convert it to alphabetical mapping and compare
  // uncomment below line and do not comment sort lines
  // createMappingAlphabetically(str, testString); // can also be done by
  // creating a alphabetical mapping

  cout << (str == testString) << endl; // do not change
}

void isAnagramByFrequencyMethod(string str, string testString) {
  int freqTable[256] = {0}; // ASCI range for all chars are 2^8 or 256 max

  for (int i = 0; i < str.size(); i++) {
    freqTable[str[i]]++;
  }

  for (int i = 0; i < testString.size(); i++) {
    freqTable[testString[i]]--;
  }

  for (int i = 0; i < 256; i++) {
    if (freqTable[i] != 0) {
      cout << "Not Anagram" << endl;
      return;
    }
  }

  cout << "Anagram" << endl;
  return;
} // TC = O(m) + O(n) + O(256) = O(m+n)

// Leetcode 917 reverse only letters
void reverseOnlyLetters(string str) {
  int low = 0, high = str.size() - 1;
  while (low < high) {
    if (isalpha(str[low]) && isalpha(str[high])) {
      swap(str[low], str[high]);
      low++;
      high--;
    } else if (!isalpha(str[low])) {
      low++;
    } else {
      high--;
    }
  }

  cout << "String after reverse: " << str << endl;
  return;
}

// Leetcode 14 find Longest Common prefix
void findLongestCommonPrefix(vector< string > &strs) {
  string answer = "";
  int i = 0;
  while (true) {
    char currentChar = 0;
    for (auto str : strs) {
      if (i >= str[i]) {
        // out of bound
        currentChar = 0;
        break;
      }

      if (currentChar == 0) {
        currentChar = str[i];
      } else if (str[i] != currentChar) {
        currentChar = 0;
        break;
      }
    }

    if (currentChar == 0) {
      break;
    }
    answer.push_back(currentChar);
    i++;
  }
  if (answer == "") {
    cout << "No Prefix found" << endl;

  } else {
    cout << answer << endl;
  }
  return;
}

// Leetcode 345 reverse only vowels

bool isVowel(char ch) {
  ch = tolower(ch);
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
void reverseOnlyVowels(string str) {
  int low = 0, high = str.size() - 1;
  string vowel = "aeiou";
  while (low < high) {
    if (isVowel(str[low]) && isVowel(str[high])) {
      swap(str[low], str[high]);
      low++;
      high--;
    } else if (!isVowel(str[low])) {
      low++;
    } else {
      high--;
    }
  }

  cout << "String after reverse: " << str << endl;
  return;
}

// leetcode 205 isomorphic strings

void createMappingAlphabetically(string &str) {
  // find mapping
  char start = 'a';
  char mapping[300] = {0};
  for (auto ch : str) {
    if (mapping[ch] == 0) {
      mapping[ch] = start;
      start++;
    }
  }

  // update string according to mapping
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    str[i] = mapping[ch];
  }
}

void isIsomorphic(string s, string t) {
  createMappingAlphabetically(s);
  createMappingAlphabetically(t);
  cout << (s == t) << " " << s << " " << t << " " << endl;
}

// Leetcode 49 Group Anagrams
// TC
// N -> strs.length
// K -> max length of largest string
// O(N KlogK) -> KlogK is TC of map datastructure insert
// SC
// O(NK)
void groupAnagrams(vector< string > &strs) {
  // map string -> vector answer
  map< string, vector< string > > mp;
  for (auto str : strs) {
    string s = str;
    sort(s.begin(), s.end());
    mp[s].push_back(str);
  }

  vector< vector< string > > answer;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    answer.push_back(it->second); // key -> first, vector<string>
  }

  print2DStringVector(answer);
}

// group anagrams Method 2

// avoiding sort
// hash[256] ={0} // 0-256 -> all charecters

// TC
// N -> strs.length
// K -> max length of largest string
// O(NK)
// SC
// O(NK)

array< int, 256 > hashStr(string s) {
  array< int, 256 > hashArray = {0};
  for (int i = 0; i < s.size(); i++) {
    hashArray[s[i]]++;
  }
  return hashArray;
}

void groupAnagram2(vector< string > &strs) {
  map< array< int, 256 >, vector< string > > mp;
  for (auto str : strs) {
    mp[hashStr(str)].push_back(str);
  }
  vector< vector< string > > answer;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    answer.push_back(it->second); // key -> first, vector<string>
  }
  print2DStringVector(answer);
}

// Leetcode 5 Longest Palindromic substring
// substrings of a string
// extract palidromic ones
// max length string from palindromic ones

bool checkPalindrome(string str, int start, int end) {
  while (start <= end) {
    if (str[start] == str[end]) {
      start++;
      end--;
    } else {
      return false;
    }
  }

  return true;
}
void longestPalindrome(string s) {
  string answer = "";
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      if (checkPalindrome(s, i, j)) {
        string t = s.substr(i, j - i + 1);
        answer = t.size() > answer.size() ? t : answer;
      }
    }
  }
  cout << answer << endl;
}

// Leetcode 8. String to Integer (atoi)
void myAtoi(string s) {

  // int integer = atoi(s.c_str());
  // cout << "Answer using In built Library " << integer << endl;

  int num = 0, i = 0, sign = 1; // +1 and  -1

  // iterate through leading whitespaces
  while (s[i] == ' ') {
    i++;
  }

  if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
    sign = s[i] == '+' ? 1 : -1;
    ++i;
  }

  while (i < s.size() && isdigit(s[i])) {
    if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
      cout << "Answer: " << (sign == -1 ? INT_MIN : INT_MAX) << endl;
      return;
    }
    num = num * 10 + (s[i] - '0');
    i++;
  }

  cout << "Answer: " << num * sign << endl;
  return;
}

// Leetcode 443. String Compression
// this algo is also called run length algo
int compress(vector< char > &s) {
  int index = 0;
  int count = 1;
  char prev = s[0];

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == prev) {
      count++;
    } else {
      s[index++] = prev;
      if (count > 1) {
        int start = index;
        while (count) {
          s[index++] = (count % 10) + '0';
          count /= 10;
        }
        reverse(s.begin() + start, s.begin() + index);
      }
      prev = s[i];
      count = 1;
    }
  }

  s[index++] = prev;
  if (count > 1) {
    int start = index;

    while (count) {
      s[index++] = (count % 10) + '0';
      count /= 10;
    }
    reverse(s.begin() + start, s.begin() + index);
  }

  return index;
}

// Leetcode 12: Integer to Roman
void intToRoman(int num) {
  string romanSymbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                           "XL", "X",  "IX", "V",  "IV", "I"};
  int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  string answer = "";
  for (int i = 0; i < 13; i++) {
    while (num >= values[i]) {
      answer += romanSymbols[i];
      num -= values[i];
    }
  }

  cout << "Answer " << answer << endl;
}

// Leetcode 6. Zigzag Conversion
void convert(string s, int numRows) {
  if (numRows == 1) {
    cout << "Answer: " << s << endl;
    return;
  }

  int i = 0;
  int row = 0;
  bool direction = 1; // 1 -> Top to bottom 0 -> vice versa
  vector< string > zigzag(numRows);

  while (true) {
    if (direction) {
      // T -> B
      while (
          row < numRows &&
          i < s.size()) { // out of range check and iterate thru all rows given
        zigzag[row++].push_back(s[i++]);
      }

      // once the T->B conversion is done we need to be at a B->T row
      row = numRows - 2;
    } else {
      // starting from zigzagrow to zero B->T
      while (row >= 0 && i < s.size()) {
        zigzag[row--].push_back(s[i++]);
      }
      row = 1; // we neednot to be at zero to T->B
    }

    if (i >= s.size())
      break;                // break if all chars in string are iterated
    direction = !direction; // update direction after operation is completed
  }
  cout << "Answer: ";
  for (int k = 0; k < zigzag.size(); k++) {
    cout << zigzag[k];
  }
  cout << endl;
}

// Leetcode 179. Largest Number

static bool comparator(string a, string b) {
  string t1 = a + b;
  string t2 = b + a;

  return t1 > t2;
}

void largestNumber(vector< int > &nums) {
  vector< string > snums;
  for (auto n : nums) {
    snums.push_back(to_string(n));
  }

  sort(snums.begin(), snums.end(), comparator);

  string answer = "";
  if (snums[0] == "0") {
    cout << "0" << endl;
    return;
  }
  for (auto str : snums) {
    answer += str;
  }

  cout << answer << endl;
}

// Leetcode 767. Reorganize String
void reorganizeString(string s) {
  int hash[26] = {0};

  for (int i = 0; i < s.size(); i++) {
    hash[s[i] - 'a']++;
  }

  // find most freq char
  char maxFreqChar;
  int maxFreq = INT_MIN;
  for (int i = 0; i < 26; i++) {
    if (hash[i] > maxFreq) {
      maxFreq = hash[i];
      maxFreqChar = i + 'a';
    }
  }

  // try to place max freq char adjacently
  int index = 0;
  while (maxFreq > 0 && index < s.size()) {
    s[index] = maxFreqChar;
    maxFreq--;
    index += 2;
  }

  // one or more max freq char was not able to place adacently
  if (maxFreq != 0) {
    cout << "Answer: "
         << "" << endl;
    return;
  }

  hash[maxFreqChar - 'a'] = 0;
  // try to place the rest of char
  for (int i = 0; i < 26; i++) {
    while (hash[i] > 0) {
      // since after placing most freq char index will be at s.size()
      // check if its true bring to 1st index so that you can start placing rest
      // chars else move how index is as it is
      index = index >= s.size() ? 1 : index;
      s[index] = i + 'a';
      index += 2;
      hash[i]--; // reduce frequency of char after placing
    }
  }

  cout << "Answer: " << s << endl;
}

// leetcode 28. Find the Index of the First Occurrence in a String O(mn)
int strStr(string haystack, string needle) {
  int sizeOfHaystack = haystack.size();
  int sizeOfNeedle = needle.size();

  for (int i = 0; i <= sizeOfHaystack - sizeOfNeedle; i++) {
    for (int j = 0; j < sizeOfNeedle; j++) {
      if (needle[j] != haystack[i + j]) {
        break;
      }

      if (j == sizeOfNeedle - 1) {
        return i;
      }
    }
  }

  return -1;
}

// Leetcode 1209. Remove All Adjacent Duplicates in String II

// Method 1 TC - O(NK)
bool areLastK_1CharsSame(string &ans, char &newch, int K_1) {
  int it = ans.size() - 1;
  for (int k = 0; k < K_1; k++) {
    if (newch != ans[it]) {
      return false;
    }
    it--;
  }
  return true;
}
string removeDuplicatesMethodOne(string s, int k) {
  string ans;
  for (int i = 0; i < s.size(); ++i) {
    char &newchar = s[i];
    if (ans.size() < k - 1) {
      ans.push_back(newchar);
    } else {
      if (areLastK_1CharsSame(ans, newchar, k - 1)) {
        for (int j = 0; j < k - 1; j++) {
          ans.pop_back();
        }
      } else {
        ans.push_back(newchar);
      }
    }
  }
  return ans;
}

// Method 2
// 2 pointer approach TC - O(n) SC - O(n)
string removeDuplicatesMethodTwo(string s, int k) {
  int i = 0, j = 0;
  vector< int > count(s.size(), 0);

  while (j < s.size()) {
    s[i] = s[j];
    count[i] = 1;
    if (i > 0 && s[i] == s[i - 1]) {
      count[i] += count[i - 1];
    }
    if (count[i] == k) {
      i -= k;
    }
    ++i;
    ++j;
  }

  return s.substr(0, i);
}

// Leetcode 539. Minimum Time Difference
// Given a list of 24-hour clock time points in "HH:MM" format, return the
// minimum minutes difference between any two time-points in the list.
// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

int convertToMins(string time) {
  int hour = stoi(time.substr(0, 2));
  int mins = stoi(time.substr(3, 2));
  return 60 * hour + mins;
}
int findMinimumTimeDifference(vector< string > &timePoints) {
  // substr() -> fetch hrs and min strings
  // stoi() -> string to integer conversion
  // total minutes
  // sort
  // EDGE CASE ->

  // min = 60 * HH + MM

  vector< int > mins;
  for (auto time : timePoints) {
    mins.push_back(convertToMins(time));
  }
  sort(mins.begin(), mins.end());
  int answer = INT_MAX; // stores minimum differnce
  for (int i = 0; i < mins.size() - 1; ++i) {
    answer = min(answer, mins[i + 1] - mins[i]);
  }

  // last hour difference
  int lastDiff = mins[0] + 1440 - mins[mins.size() - 1];
  answer = min(answer, lastDiff);

  return answer;
}

int main() {
  // isAnagram("anagram", "nagaram");
  // isAnagram("rat", "car");

  // isAnagramByFrequencyMethod("anagram", "nagaram");
  // isAnagramByFrequencyMethod("rat", "car");

  // reverseOnlyLetters("ab-cd");
  // reverseOnlyLetters("Test1ng-Leet=code-Q!");
  // reverseOnlyLetters("a-bC-dEf-ghIj");

  // for longest prefix problem
  // vector< string > strsTestCaseOne;
  // vector< string > strsTestCaseTwo;

  // strsTestCaseOne.push_back("flower");
  // strsTestCaseOne.push_back("flow");
  // strsTestCaseOne.push_back("flight");

  // strsTestCaseTwo.push_back("dog");
  // strsTestCaseTwo.push_back("racecar");
  // strsTestCaseTwo.push_back("car");

  // findLongestCommonPrefix(strsTestCaseOne);
  // findLongestCommonPrefix(strsTestCaseTwo);

  // reverseOnlyVowels("hello");
  // reverseOnlyVowels("LeetCode");

  // isIsomorphic("egg", "add");
  // isIsomorphic("paper", "title");
  // isIsomorphic("foo", "bar");

  // for group anagrams
  // vector< string > strs;
  // strs.push_back("eat");
  // strs.push_back("tea");
  // strs.push_back("tan");
  // strs.push_back("ate");
  // strs.push_back("nat");
  // strs.push_back("bat");

  // groupAnagrams(strs);
  // groupAnagram2(strs);

  // longestPalindrome("babad");

  // myAtoi("42");
  // myAtoi(" -042");
  // myAtoi("1337c0d3");
  // myAtoi("0-1");
  // myAtoi("words and 987");

  // for string compression
  // vector< char > testCaseOne;
  // vector< char > testCaseTwo;
  // vector< char > testCaseThree;

  // testCaseOne.push_back('a');
  // testCaseOne.push_back('a');
  // testCaseOne.push_back('b');
  // testCaseOne.push_back('b');
  // testCaseOne.push_back('c');
  // testCaseOne.push_back('c');
  // testCaseOne.push_back('c');

  // testCaseTwo.push_back('a');

  // testCaseThree.push_back('a');
  // testCaseThree.push_back('a');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');
  // testCaseThree.push_back('b');

  // int res1 = compress(testCaseOne);
  // print1DCharVector(testCaseOne);
  // cout << "Result: " << res1 << endl;

  // int res2 = compress(testCaseTwo);
  // print1DCharVector(testCaseTwo);
  // cout << "Result: " << res2 << endl;

  // int res3 = compress(testCaseThree);
  // print1DCharVector(testCaseThree);
  // cout << "Result: " << res3 << endl;

  // intToRoman(3749);
  // intToRoman(58);
  // intToRoman(1994);
  // intToRoman(1999);

  // convert("PAYPALISHIRING", 3);
  // convert("PAYPALISHIRING", 4);
  // convert("A", 1);

  // for largest number
  // vector< int > numsTestCaseOne;
  // vector< int > numsTestCaseTwo;
  // vector< int > numsTestCaseThree;

  // numsTestCaseOne.push_back(10);
  // numsTestCaseOne.push_back(2);

  // numsTestCaseTwo.push_back(3);
  // numsTestCaseTwo.push_back(30);
  // numsTestCaseTwo.push_back(34);
  // numsTestCaseTwo.push_back(5);
  // numsTestCaseTwo.push_back(9);

  // numsTestCaseThree.push_back(0);
  // numsTestCaseThree.push_back(0);
  // numsTestCaseThree.push_back(0);
  // numsTestCaseThree.push_back(0);
  // numsTestCaseThree.push_back(0);
  // numsTestCaseThree.push_back(0);

  // largestNumber(numsTestCaseOne);
  // largestNumber(numsTestCaseTwo);
  // largestNumber(numsTestCaseThree);

  // reorganizeString("aab");
  // reorganizeString("aaab");
  // reorganizeString("aaabc");

  // cout << strStr("sadbutsad", "sad") << endl;
  // cout << strStr("sadbutsad", "but") << endl;
  // cout << strStr("sadbutsada", "da") << endl;
  // cout << strStr("leetcode", "leeto") << endl;

  // cout << removeDuplicatesMethodOne("deeedbbcccbdaa", 3) << endl;
  // cout << removeDuplicatesMethodOne("abcd", 2) << endl;
  // cout << removeDuplicatesMethodOne("pbbcggttciiippooaais", 2) << endl;

  // cout << removeDuplicatesMethodTwo("deeedbbcccbdaa", 3) << endl;
  // cout << removeDuplicatesMethodTwo("abcd", 2) << endl;
  // cout << removeDuplicatesMethodTwo("pbbcggttciiippooaais", 2) << endl;

  // For find minimm time difference
  vector< string > timePointsTestCaseOne;
  vector< string > timePointsTestCaseTwo;
  vector< string > timePointsTestCaseThree;

  timePointsTestCaseOne.push_back("23:59");
  timePointsTestCaseOne.push_back("00:00");

  timePointsTestCaseTwo.push_back("00:00");
  timePointsTestCaseTwo.push_back("23:59");
  timePointsTestCaseTwo.push_back("00:00");

  timePointsTestCaseThree.push_back("12:50");
  timePointsTestCaseThree.push_back("23:59");
  timePointsTestCaseThree.push_back("01:39");

  cout << findMinimumTimeDifference(timePointsTestCaseOne) << endl;

  cout << findMinimumTimeDifference(timePointsTestCaseTwo) << endl;

  cout << findMinimumTimeDifference(timePointsTestCaseThree) << endl;

  return 0;
}