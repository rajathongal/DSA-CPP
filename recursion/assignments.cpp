#include <iostream>
#include <vector>
#include <cstring> // for strrchr
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
  cout << ans << endl;

  // last occr using inbuilt fn
  const char* last_occurrence = strrchr("Lababdarbab", 'b');
  cout << last_occurrence << endl;

  return 0;
}