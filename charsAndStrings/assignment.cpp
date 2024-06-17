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
    if(isalpha(str[low]) && isalpha(str[high])) {
      swap(str[low], str[high]);
      low++; high--;
    } else if(!isalpha(str[low])) {
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

  reverseOnlyLetters("ab-cd");
  reverseOnlyLetters("Test1ng-Leet=code-Q!");
  reverseOnlyLetters("a-bC-dEf-ghIj");


  return 0;
}