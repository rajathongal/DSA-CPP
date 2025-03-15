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

// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
int celebrity(vector< vector< int > > &mat) {
  int n = mat.size();
  if (n == 0)
    return -1;
  stack< int > st;

  // Push all persons into stack
  for (int i = 0; i < n; ++i) {
    st.push(i);
  }

  // Run Discard Method, to get a mightBeCelebrity
  while (st.size() != 1) {
    // pick top two elements and compare
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();

    // If a know b ?
    if (mat[a][b]) {
      // a is not celebrity, b might be
      st.push(b);
    } else {
      st.push(a);
    }
  }

  // If stack is empty, return -1
  if (st.empty())
    return -1;

  // Check that single person is actually celebrity
  int mightBeCelebrity = st.top();
  st.pop();

  // Celebrity Should not know anyone
  // all rows should be zero
  for (int i = 0; i < n; i++) {
    if (mat[mightBeCelebrity][i] != 0) {
      return -1;
    }
  }
  //  Everybody Should know Celebrity
  for (int i = 0; i < n; i++) {
    if (mat[i][mightBeCelebrity] == 0 && i != mightBeCelebrity) {
      return -1;
    }
  }

  // mightBeCelebrity is the Celebrity
  return mightBeCelebrity;
} // TC O(N)

int main() {
  // Uncomment for count reversal problem
  // string s1 = "}{{}}{{{";
  // string s2 = "{{}{{{}{{}}{{";
  // cout << "S1: " << countRev(s1) << endl;
  // cout << "S2: " << countRev(s2) << endl;

  // Uncomment for leetcode 1047 Remove all adjacent duplicates in string
  // string s1 = "abbaca";
  // string s2 = "azxxzy";

  // cout << "S1: " << s1 << " -> " << removeDuplicates(s1) << endl;
  // cout << "S2: " << s2 << " -> " << removeDuplicates(s2) << endl;

  // Uncomment for The Celebrity Problem
  // https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
  vector< vector< int > > matOne = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
  vector< vector< int > > matTwo = {{1, 1}, {1, 1}};
  vector< vector< int > > matThree = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
  vector< vector< int > > matFour = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};

  cout << "The Celebrity is (matOne): " << celebrity(matOne) << endl;
  cout << "The Celebrity is (matTwo): " << celebrity(matTwo) << endl;
  cout << "The Celebrity is (matThree): " << celebrity(matThree) << endl;
  cout << "The Celebrity is (matFour): " << celebrity(matFour) << endl;

  return 0;
}