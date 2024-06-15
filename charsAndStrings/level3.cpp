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

int main() {
  decodeTheMessage("the quick brown fox jumps over the lazy dog",
                   "vkbs bs t suepuv");
  decodeTheMessage("eljuxhpwnyrdgtqkviszcfmabo",
                   "zwx hnfx lqantp mnoeius ycgk vcnjrdb");
  return 0;
}