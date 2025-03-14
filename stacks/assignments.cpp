#include <iostream>
#include <stack>
using namespace std;

// https://www.geeksforgeeks.org/problems/count-the-reversals0401/1
int countRev(string s) {
  if (s.size() & 1)
    return -1; // odd length case

  int ans = 0;
  stack< char > st;
  for (char ch : s) {
    if (ch == '{') {
      st.push(ch);
    } else {
      if (!st.empty() && st.top() == '{') {
        st.pop();
      } else {
        st.push(ch);
      }
    }
  }

  // if stack is still not empty
  // calculate reversals
  while (!st.empty()) {
    char a = st.top();
    st.pop();
    char b = st.top();
    st.pop();
    if (a == b) {
      ans += 1;
    } else {
      ans += 2;
    }
  }

  return ans;
}

// leetcode 1047 Remove all adjacent duplicates in string
string removeDuplicates(string s) {
  stack< char > st;
  for (auto ch : s) {
    if (!st.empty() && st.top() == ch) {
      st.pop();
    } else {
      st.push(ch);
    }
  }
  string ans;
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  // Uncomment for count reversal problem
  // string s1 = "}{{}}{{{";
  // string s2 = "{{}{{{}{{}}{{";
  // cout << "S1: " << countRev(s1) << endl;
  // cout << "S2: " << countRev(s2) << endl;

  // Uncomment for leetcode 1047 Remove all adjacent duplicates in string
  string s1 = "abbaca";
  string s2 = "azxxzy";

  cout << "S1: " << s1 << " -> " << removeDuplicates(s1) << endl;
  cout << "S2: " << s2 << " -> " << removeDuplicates(s2) << endl;
  return 0;
}