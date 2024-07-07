#include <iostream>

using namespace std;

// Backtracking
// explore all possible soln
// once explored soln will not be explored again

// Permutation of a string
// Print all perma of a string
// abc -> abc, acb, bac, bca, cab, cba
// ab -> ab, ba
// n! soln available
void printSTRPerma(string &str, int index) {
  if (index >= str.length()) {
    cout << str << " ";
    
    return;
  }

  for (int j = index; j < str.length(); j++) {
    swap(str[index], str[j]);
    // RE
    printSTRPerma(str, index + 1);
    // backtracking -> do something after recursion ex bring back original state of str
    swap(str[index], str[j]);

  }
}

int main() {
  string str1 = "abc";
  printSTRPerma(str1, 0);
  return 0;
}