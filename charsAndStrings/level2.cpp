#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// You are given a string s consisting of lowercase English letters. A duplicate
// removal consists of choosing two adjacent and equal letters and removing
// them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It
// can be proven that the answer is unique.

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent
// and equal, and this is the only possible move.  The result of this move is
// that the string is "aaca", of which only "aa" is possible, so the final
// string is "ca". Example 2:

// Input: s = "azxxzy"
// Output: "ay"

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

void removeAdjacentDuplicateStrings(string str) {
  string answer = "";

  int index = 0;
  while (index < str.length()) {

    // same check
    // answer right most char and string's current char [index]
    // pop
    if (answer.length() > 0 && answer[answer.length() - 1] == str[index]) {
      answer.pop_back();
    } else {
      answer.push_back(str[index]);
    }
    index++;
  }

  cout << "Answer: " << answer << endl;
}

// Leetcode 1910. Remove All Occurrences of a Substring
// Given two strings s and part, perform the following operation on s until all
// occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

void removeAllOccurancesOfSubstring(string str, string subString) {
  while (str.find(subString) != string::npos) {
    int startOfSubString = str.find(subString);
    int subStringLength = subString.length();
    str.erase(startOfSubString, subStringLength);
  }

  cout << "After removing duplicate substring: " << str << endl;
}

// Leetcode 680. Valid Palindrome II
// Given a string s, return true if the s can be palindrome after deleting at
// most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true
// Example 2:

// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.
// Example 3:

// Input: s = "abc"
// Output: false

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

// Total TC O(n)
void validPalindrome(string str) { 
  int size = str.length();
  int start = 0;
  int end = size - 1;

  while (start <= end) {
    if (str[start] == str[end]) {
      start++;
      end--;
    } else {
      // 1 removal allowed
      // check palindrome for remaining chars in strings

      // start th char removal
      bool possibleAnswerOne = checkPalindrome(str, start + 1, end);
      // end th char removal
      bool possibleAnswerTwo = checkPalindrome(str, start, end - 1);

      if (possibleAnswerOne || possibleAnswerTwo) {
        cout << "Palindrome" << endl;
      } else {
        cout << "Not Palindrome" << endl;
      }
      return;
    }
  }
  cout << "Palindrome" << endl;
}

int main() {
  // removeAdjacentDuplicateStrings("abbaca");
  // removeAdjacentDuplicateStrings("azxxzy");
  // removeAllOccurancesOfSubstring("daabcbaabcbc", "abc");
  // removeAllOccurancesOfSubstring("axxxxyyyyb", "xy");
  validPalindrome("aba");
  validPalindrome("abca");
  validPalindrome("abc");
  validPalindrome("MADMAM");
  validPalindrome("ABCRRRCA");
  validPalindrome("GRACABRG");

  return 0;
}