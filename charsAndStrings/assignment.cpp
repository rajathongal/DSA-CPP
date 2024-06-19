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

  intToRoman(3749);
  intToRoman(58);
  intToRoman(1994);
  intToRoman(1999);

  return 0;
}