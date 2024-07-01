#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Last occurance of a char
void findLastOccuranceOfChar(string str, int index, int &ans, char target) {
  if(str[index] == '\0') {
    return;
  }

  if(str[index] == target) {
    ans = index;
  }

  findLastOccuranceOfChar(str, index+1, ans, target);
}

int main() {
  // for last occurance of char
  int ans = -1;
  findLastOccuranceOfChar("Lababdarbab", 0, ans, 'b');

  return 0;
}