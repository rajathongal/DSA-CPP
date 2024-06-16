#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

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

  int answer = (pickTimeP + travelTImeP) + (pickTimeG + travelTImeG) + (pickTimeM + travelTImeM);
  cout << "Answer: " << answer << endl;
}

int main() {
  // decodeTheMessage("the quick brown fox jumps over the lazy dog",
  //                  "vkbs bs t suepuv");
  // decodeTheMessage("eljuxhpwnyrdgtqkviszcfmabo",
  //                  "zwx hnfx lqantp mnoeius ycgk vcnjrdb");

  // for garbage collection problem,
  vector< string > garbageTestCaseOne;
  vector< int > travelTestCaseOne;
  vector< string > garbageTestCaseTwo;
  vector< int > travelTestCaseTwo;

  garbageTestCaseOne.push_back("G");
  garbageTestCaseOne.push_back("P");
  garbageTestCaseOne.push_back("GP");
  garbageTestCaseOne.push_back("GG");

  travelTestCaseOne.push_back(2);
  travelTestCaseOne.push_back(3);
  travelTestCaseOne.push_back(4);

  garbageTestCaseTwo.push_back("MMM");
  garbageTestCaseTwo.push_back("PGM");
  garbageTestCaseTwo.push_back("GP");

  travelTestCaseTwo.push_back(3);
  travelTestCaseTwo.push_back(10);

  garbageCollection(garbageTestCaseOne, travelTestCaseOne);
  garbageCollection(garbageTestCaseTwo, travelTestCaseTwo);

  return 0;
}