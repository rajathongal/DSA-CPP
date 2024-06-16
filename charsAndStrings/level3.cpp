#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void printStringVectorNativeMethod(vector<string> v) {
  // for each loop
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;

}

// leetcode 2325 Decode the message
void decodeTheMessage(string key, string message) {
  // create mapping between a-z and the key // 0 -> char is NULL
  char start = 'a';
  char mapping[280] = {0};

  // for each loop
  for (auto ch : key) {
    if (ch != ' ' && mapping[ch] == 0) {
      mapping[ch] = start;
      start++;
    }
  }

  // use mapping to decode
  string answer;
  for (auto msgCh : message) {
    if (msgCh != ' ') {
      char decodedChar = mapping[msgCh];
      answer.push_back(decodedChar);
    } else {
      answer.push_back(' ');
    }
  }

  cout << "The Decoded Message is: " << answer << endl;
}

// leetcode 2391 Minimum Amount of Time to Collect Garbage

void garbageCollection(vector< string > &garbage, vector< int > &travel) {
  int pickTimeP = 0;
  int pickTimeM = 0;
  int pickTimeG = 0;

  int travelTImeP = 0;
  int travelTImeM = 0;
  int travelTImeG = 0;

  int lastPositionP = 0;
  int lastPositionM = 0;
  int lastPositionG = 0;

  // calculate pick time and travel time
  for (int i = 0; i < garbage.size(); i++) {
    string curr = garbage[i];
    for (int j = 0; j < curr.length(); j++) {
      char ch = curr[j];
      if (ch == 'P') {
        pickTimeP++;
        lastPositionP = i;
      } else if (ch == 'G') {
        pickTimeG++;
        lastPositionG = i;

      } else if (ch == 'M') {
        pickTimeM++;
        lastPositionM = i;
      }
    }
  }

  // calculate travel time
  for (int k = 0; k < lastPositionP; k++) {
    travelTImeP += travel[k];
  }
  for (int k = 0; k < lastPositionG; k++) {
    travelTImeG += travel[k];
  }
  for (int k = 0; k < lastPositionM; k++) {
    travelTImeM += travel[k];
  }

  int answer = (pickTimeP + travelTImeP) + (pickTimeG + travelTImeG) +
               (pickTimeM + travelTImeM);
  cout << "Answer: " << answer << endl;
}

// leetcode 791 Custom sort string

// custom comparator
static string strp;
static bool compare(char char1, char char2) {
  // this will return true if pos f char1 in strp string is less than pos of
  // char 2 in strp string
  // when true is returned it means char 1 will be placed before char2 in output
  // string
  return (strp.find(char1) < strp.find(char2));
}

void customSortString(string order, string s) {
  strp = order;
  sort(s.begin(), s.end(), compare);

  cout << s << endl;
}

// Leetcode 890

void createMappingAlphabetically(string& str) {
  // find mapping
  char start = 'a';
  char mapping[300] = {0};
  for(auto ch: str) {
    if(mapping[ch] == 0) {
      mapping[ch] = start;
      start++;
    }
  }

  // update string according to mapping
  for(int i=0; i<str.length(); i++) {
    char ch = str[i];
    str[i] = mapping[ch];
  }

}
void findAndReplacePattern(vector< string > &words, string pattern) {
  // create a mapping of pattern in terms of abc
  // create a mapping for each of word in word with abc 
  // compare both and return words which are same
  vector< string > answer;


  // create mapping of pattern
  createMappingAlphabetically(pattern);

  // create mapping for each word in words 
  for(string s: words) {
    string tempString = s;
    // create mapping for s
    createMappingAlphabetically(tempString);

    if(tempString == pattern) {
      // it means s is a valid answer 
      answer.push_back(s);
    }
  }

  printStringVectorNativeMethod(answer);

}

int main() {
  // decodeTheMessage("the quick brown fox jumps over the lazy dog",
  //                  "vkbs bs t suepuv");
  // decodeTheMessage("eljuxhpwnyrdgtqkviszcfmabo",
  //                  "zwx hnfx lqantp mnoeius ycgk vcnjrdb");

  // for garbage collection problem,
  // vector< string > garbageTestCaseOne;
  // vector< int > travelTestCaseOne;
  // vector< string > garbageTestCaseTwo;
  // vector< int > travelTestCaseTwo;

  // garbageTestCaseOne.push_back("G");
  // garbageTestCaseOne.push_back("P");
  // garbageTestCaseOne.push_back("GP");
  // garbageTestCaseOne.push_back("GG");

  // travelTestCaseOne.push_back(2);
  // travelTestCaseOne.push_back(3);
  // travelTestCaseOne.push_back(4);

  // garbageTestCaseTwo.push_back("MMM");
  // garbageTestCaseTwo.push_back("PGM");
  // garbageTestCaseTwo.push_back("GP");

  // travelTestCaseTwo.push_back(3);
  // travelTestCaseTwo.push_back(10);

  // garbageCollection(garbageTestCaseOne, travelTestCaseOne);
  // garbageCollection(garbageTestCaseTwo, travelTestCaseTwo);

  // customSortString("cba", "abcd");
  // customSortString("bcafg", "abcd");

  // for find and replace pattern
  vector< string > wordsTestCaseOne;
  string patternTestCaseOne = "abb";

  wordsTestCaseOne.push_back("abc");
  wordsTestCaseOne.push_back("deq");
  wordsTestCaseOne.push_back("mee");
  wordsTestCaseOne.push_back("aqq");
  wordsTestCaseOne.push_back("dkd");
  wordsTestCaseOne.push_back("ccc");

  vector< string > wordsTestCaseTwo;
  string patternTestCaseTwo = "a";

  wordsTestCaseTwo.push_back("a");
  wordsTestCaseTwo.push_back("b");
  wordsTestCaseTwo.push_back("c");

  findAndReplacePattern(wordsTestCaseOne, patternTestCaseOne);
  findAndReplacePattern(wordsTestCaseTwo, patternTestCaseTwo);

  return 0;
}