#include <ctype.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

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

  reverseOnlyVowels("hello");
  reverseOnlyVowels("LeetCode");

  return 0;
}