#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *nextNode; // Pointer to Next Node

  // default ctor
  Node() { this->nextNode = NULL; }

  // para ctor
  Node(int data) {
    this->data = data;
    this->nextNode = NULL;
  }
  // ~Node() { cout << "destructor called " << data << " deleted" << endl; }
};

void printLinkedList(Node *head) {
  Node *temp = head; // must make a copy always while tracing
  int len = 0;
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->nextNode;
    ++len;
  }
  cout << endl << "Length of LL: " << len << endl;
}

void printVector(vector< int > v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    cout << v[i] << " "; // method 1
    // cout << v.at(i) << endl;
  }
  cout << endl;
}

void printVectorOfTypeDouble(vector< double > v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    cout << v[i] << " "; // method 1
    // cout << v.at(i) << endl;
  }
  cout << endl;
}

// Gets Length of LL
int lenOfLL(Node *&head) {
  int len = 0;
  Node *temp = head;
  while (temp != NULL) {
    len++;
    temp = temp->nextNode;
  }

  return len;
}

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

// Leetcode 1019 Next greater element in LL
vector< int > nextLargerNodes(Node *head) {
  // Convert the LL into an array
  vector< int > ll;
  while (head) {
    ll.push_back(head->data);
    head = head->nextNode;
  }

  stack< int > st;
  vector< int > ans(ll.size(), 0);

  for (int i = 0; i < ll.size(); ++i) {
    while (!st.empty() && ll[i] > ll[st.top()]) {
      // means ith element is the next greater of the element index present in
      // stack

      int kids = st.top();
      st.pop();
      ans[kids] = ll[i];
    }
    st.push(i);
  }
  return ans;
} // TC O(N) SC O(2N)

vector< int > nextLargerNodesMethod2(Node *head) {
  // Convert the LL into an array
  vector< int > ll;
  while (head) {
    ll.push_back(head->data);
    head = head->nextNode;
  }

  stack< int > st;
  // vector< int > ans(ll.size(), 0);

  for (int i = 0; i < ll.size(); ++i) {
    while (!st.empty() && ll[i] > ll[st.top()]) {
      // means ith element is the next greater of the element index present in
      // stack

      int kids = st.top();
      st.pop();
      ll[kids] = ll[i];
    }
    st.push(i);
  }
  while (!st.empty()) {
    ll[st.top()] = 0;
    st.pop();
  }
  ll[ll.size() - 1] = 0;
  return ll;
} // O(N) SC O(N)

// Nstack in an array
class NStack {
  int *a, *top, *next;
  int n;        // no of stacks.
  int size;     // size of main array
  int freespot; // tells free space in main array

public:
  NStack(int _n, int _s) : n(_n), size(_s) {
    freespot = 0;
    a = new int[size];
    top = new int[n];
    next = new int[size];

    for (int i = 0; i < n; i++) {
      top[i] = -1;
    }

    for (int i = 0; i < size; i++) {
      next[i] = i + 1;
    }

    next[size - 1] = -1;
  }

  // Push X into m-th stack
  bool push(int x, int m) {
    if (freespot == -1) {
      return false; // stack overflow
    }

    // 1. find index of insertion
    int index = freespot;

    // 2. Update freespot after use
    freespot = next[index];

    // 3. insert
    a[index] = x;

    // 4. update next
    next[index] =
        top[m -
            1]; // mth array is not empty so next will store element after top

    // 5. update top
    top[m - 1] = index;

    return true; // push success
  }

  // Pop from m th stack
  int pop(int m) {
    if (top[m - 1] == -1) {
      return -1; // stack underflow
    }

    int index = top[m - 1];
    top[m - 1] = next[index];
    int popedElement = a[index];
    next[index] = freespot;
    freespot = index;
    return popedElement;
  }

  // Detor
  ~NStack() {
    delete[] a;
    delete[] top;
    delete[] next;
  }
};

// Monotonic Stack type problems
// Leetcode 901
// Online Stock Span
// O(N^2) by iterative approach
// O(N) soln
// segmented trees approach can be used as well
class StockSpanner {
  stack< pair< int, int > > st;

public:
  StockSpanner() {}

  int next(int price) {
    int span = 1;
    while (!st.empty() && st.top().first <= price) {
      span += st.top().second;
      st.pop();
    }
    st.push({price, span});
    return span;
  }
};

// Leetcode 1003 Check If Word Is Valid After Substitutions
// Recursive O(N^2)
bool isValidRecursiveSoln(string s) {
  if (s.size() == 0) {
    return true;
  }

  int fnd = s.find("abc"); // O(N)
  if (fnd != string::npos) {
    // found abc in string
    string tLeft = s.substr(0, fnd);             // O(N)
    string tRight = s.substr(fnd + 3, s.size()); // O(N)
    return isValidRecursiveSoln(tLeft +
                                tRight); // Recursive call. N/3 recursive call
  }

  return false;
}

// approach O(N) sc O(N)
// Enter the chars of string in the below order and pop
// push a as it is
// push b only if a exists in the top
// if you got c check if b is the top element
// pop both a and b // ignore pushing c
// if you get a after pushing a,b into the stack push the a into the stack in
// the above order as when you get c a,b will be popped out
// and for invalid case if you get c after a or a after b
// basically mismatch in the ordering return invalid or
// after fininshing the length of string if the stack is not empty return
// invalid
bool isValid(string s) {
  if (s[0] != 'a')
    return false;
  stack< char > st;

  for (char ch : s) {
    if (ch == 'a') {
      st.push(ch);
    } else if (ch == 'b') {
      if (!st.empty() && st.top() == 'a') {
        st.push(ch);
      } else {
        return false;
      }
    } else {
      // ch == 'c'
      if (!st.empty() && st.top() == 'b') {
        st.pop();
        if (!st.empty() && st.top() == 'a') {
          st.pop();
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }

  return st.empty();
}

// Leetcode 394. Decode String
string decodeString(string s) {
  stack< string > st;
  for (auto ch : s) {
    if (ch == ']') {
      string stringToRepeat = "";
      while (!st.empty() && !isdigit(st.top()[0])) {
        string top = st.top();
        stringToRepeat += top == "[" ? "" : top;
        st.pop();
      }

      // Numeric string
      string numericTimes = "";
      while (!st.empty() && isdigit(st.top()[0])) {
        numericTimes += st.top();
        st.pop();
      }

      // reverse
      reverse(numericTimes.begin(), numericTimes.end());

      int n = stoi(numericTimes);

      // final decoding
      string currentDecode = "";
      while (n--) {
        currentDecode += stringToRepeat;
      }
      st.push(currentDecode);
    } else {
      string temp(1, ch); // convert ch to str
      st.push(temp);
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

// Leetcide 71 simplify path
void buildAns(stack< string > &st, string &ans) {
  if (st.empty())
    return;

  string minPath = st.top();
  st.pop();
  buildAns(st, ans);
  ans += minPath;
}

string simplifyPath(string path) {
  stack< string > st;
  int i = 0;
  while (i < path.size()) {
    int start = i;
    int end = i + 1;
    while (end < path.size() && path[end] != '/') {
      ++end;
    }

    string minPath = path.substr(start, end - start);

    i = end;
    if (minPath == "/" || minPath == "/.") {
      continue;
    }

    if (minPath != "/..") {
      st.push(minPath);
    } else if (!st.empty()) {
      st.pop();
    }
  }

  string ans = st.empty() ? "/" : "";
  buildAns(st, ans);
  return ans;
}

// Required For Leetcode 85
// Largest Rectangle in a Histogram leetcode 84
// finding width is the key and multiply it with height
// w = next - prev - 1;

// Next smaller element
vector< int > findNextSmallerElementByIndex(vector< int > arr) {
  vector< int > answer(arr.size(), 0);
  stack< int > st;
  // because the amswer for right most element will be -1 since
  // there is not element to compare
  st.push(-1);

  // Traverse from right most element to left most element
  for (int i = arr.size() - 1; i >= 0; i--) {
    int curr = arr[i];

    while (st.top() != -1 && arr[st.top()] >= curr) {
      st.pop();
    }

    answer[i] = st.top();
    st.push(i);
  }

  return answer;
} // TC O(N) = N + N = 2N = O(N)

// Previous Smaller Element
vector< int > findPreviousSmallerElementByIndex(vector< int > arr) {
  vector< int > answer(arr.size(), 0);
  stack< int > st;
  // because the amswer for right most element will be -1 since
  // there is not element to compare
  st.push(-1);

  // Traverse from right most element to left most element
  for (int i = 0; i < arr.size(); i++) {
    int curr = arr[i];

    while (st.top() != -1 && arr[st.top()] >= curr) {
      st.pop();
    }

    answer[i] = st.top();
    st.push(i);
  }

  return answer;
}

int largestRectangleArea(vector< int > &heights) {
  vector< int > next = findNextSmallerElementByIndex(heights);
  // make sure on the right side of array there are no negative values
  for (int i = 0; i < heights.size(); i++) {
    if (next[i] == -1) {
      next[i] = heights.size();
    }
  }
  vector< int > prev = findPreviousSmallerElementByIndex(heights);

  int maxArea = INT_MIN;

  for (int i = 0; i < next.size(); i++) {
    int width = next[i] - prev[i] - 1;
    int length = heights[i];
    int currentArea = width * length;
    maxArea = max(maxArea, currentArea);
  }
  return maxArea;
}

// Uncomment for Leetcode 85 Maximal Rectangle
int maximalRectangle(vector< vector< char > > &matrix) {
  vector< vector< int > > v;
  int n = matrix.size();
  int m = matrix[0].size();

  // convert the char matrix to int
  for (int i = 0; i < n; i++) {
    vector< int > tempV;
    for (int j = 0; j < m; j++) {
      tempV.push_back(matrix[i][j] - '0');
    }
    v.push_back(tempV);
  }

  // add the matrix row by row from top to bottom
  int area = largestRectangleArea(v[0]); // Find out for 1 row;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // update current row with previous row values
      if (v[i][j]) {
        // v[i][j] == 1
        v[i][j] += v[i - 1][j];
      } else {
        // v[i][j] == 0
        v[i][j] = 0;
      }
    }
    area = max(area, largestRectangleArea(v[i]));
  }
  return area;
}

// Leetcode 735 Asteroid Collision
vector< int > asteroidCollision(vector< int > &asteroids) {
  stack< int > st; // stores asteroids after collision
  for (auto ast : asteroids) {
    bool destroy = false; // initially nothing is destroyed
    if (ast > 0) {
      // push
      st.push(ast);
    } else {
      // -ve case
      if (st.empty() || st.top() < 0) {
        st.push(ast);
      } else {
        // collision
        while (!st.empty() && st.top() > 0) {
          if (abs(ast) == st.top()) {
            // same weight destroy
            destroy = true;
            st.pop();
            break;
          } else if (abs(ast) > st.top()) {
            st.pop();
            //  incoming ast is bigger than existing ast in stack
          } else {
            // exisiting ast is bigger than incoming ast
            // do nothing as bigger destroys weaker ast
            destroy = true;
            break;
          }
        }
        if (!destroy) {
          st.push(ast);
        }
      }
    }
  }

  vector< int > ans(st.size());
  for (int i = st.size() - 1; i >= 0; i--) {
    ans[i] = st.top();
    st.pop();
  }
  return ans;
}

// Leetcode 853 Car Fleet
class Car {
public:
  int pos, speed;
  Car(int p, int s) : pos(p), speed(s) {};
};

static bool carComparator(Car &a, Car &b) { return a.pos < b.pos; }

int carFleet(int target, vector< int > &position, vector< int > &speed) {
  vector< Car > cars;
  for (int i = 0; i < position.size(); ++i) {
    Car car(position[i], speed[i]);
    cars.push_back(car);
  }

  sort(cars.begin(), cars.end(), carComparator);

  stack< float > st;
  for (auto car : cars) {
    float time = (target - car.pos) / ((float)car.speed);
    while (!st.empty() && time >= st.top()) {
      st.pop();
    }
    st.push(time);
  }

  return st.size();
}

// Leetcode 1776 Car fleet 2
vector< double > getCollisionTimes(vector< vector< int > > &cars) {
  vector< double > answer(cars.size(),
                          -1); // collision time of i-th car with the next car
  stack< int > st;

  for (int i = cars.size() - 1; i >= 0; --i) {
    // check if car ahead of the current car is faster
    while (!st.empty() && cars[st.top()][1] >= cars[i][1]) {
      st.pop(); // these cars wont collide
    }
    // we keep cars which can collide
    while (!st.empty()) {
      // check if collion happens or not
      double colTime = (double)(cars[st.top()][0] - cars[i][0]) /
                       (cars[i][1] - cars[st.top()][1]);

      if (answer[st.top()] == -1 || colTime <= answer[st.top()]) {
        answer[i] = colTime;
        break;
      }
      // there exists a next cars where collision time is less than the next car
      st.pop();
    }
    st.push(i);
  }

  return answer;
}

// Leetcode 32 Longest Valid Paratheses
int longestValidParenthesesM1(string s) {
  stack< int > st;
  st.push(-1);
  int maxLen = 0;
  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
    if (ch == '(') {
      st.push(i);
    } else {
      st.pop();
      if (st.empty()) {
        st.push(i);
      } else {
        int len = i - st.top();
        maxLen = max(len, maxLen);
      }
    }
  }
  return maxLen;
}

// Leetcode 739. Daily Temperatures
vector< int > dailyTemperatures(vector< int > &temperatures) {
  vector< int > ans(temperatures.size(), 0);
  stack< int > st;
  for (int i = 0; i < temperatures.size(); i++) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      ans[st.top()] = i - st.top();
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

// Leetcode 402. Remove K Digits
string removeKdigits(string num, int k) {
  string ans;
  stack< char > st;
  for (auto digit : num) {
    if (k > 0) {
      while (!st.empty() && st.top() > digit) {
        st.pop();
        k--;
        if (k == 0) {
          break;
        }
      }
    }
    st.push(digit);
  }

  if (k > 0) {
    while (!st.empty() && k) {
      st.pop();
      k--;
    }
  }

  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }

  // remove leading zeros
  while (ans.size() > 0 && ans.back() == '0') {
    ans.pop_back();
  }

  // reverse ans
  reverse(ans.begin(), ans.end());

  return ans == "" ? "0" : ans;
}

// Leetcode 921. Minimum Add to Make Parentheses Valid TCSC-> O(N)
int minAddToMakeValid(string s) {
  int ans = 0;
  stack< char > st;

  for (auto ch : s) {
    if (ch == '(') {
      ++ans;
      st.push(ch);
    } else {
      if (!st.empty()) {
        // pair found
        st.pop();
        ans--;
      } else {
        // No opening pair found for ')'
        ans++;
      }
    }
  }

  return ans;
}

// Leetcode 1472. Design Browser History
class BrowserHistory {
  stack< string > browserStack;
  stack< string > forwardStack;

public:
  BrowserHistory(string homepage) {
    browserStack.push(homepage);
    cout << homepage << endl;
  }

  void visit(string url) {
    browserStack.push(url);
    cout << url << endl;

    // clear all forward history
    while (!forwardStack.empty()) {
      forwardStack.pop();
    }
  }

  string back(int steps) {
    while (steps--) {
      // move back once every step
      // BS size should be greater than one
      if (browserStack.size() > 1) {
        forwardStack.push(browserStack.top());
        browserStack.pop();
      } else {
        // only homepage is present so ignore steps and back
        break;
      }
    }
    cout << browserStack.top() << endl;

    return browserStack.top();
  }

  string forward(int steps) {
    while (steps--) {
      if (!forwardStack.empty()) {
        browserStack.push(forwardStack.top());
        forwardStack.pop();
      } else {
        break;
      }
    }
    cout << browserStack.top() << endl;

    return browserStack.top();
  }
};

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
  // vector< vector< int > > matOne = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
  // vector< vector< int > > matTwo = {{1, 1}, {1, 1}};
  // vector< vector< int > > matThree = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
  // vector< vector< int > > matFour = {{0, 0, 1}, {1, 0, 1}, {0, 0, 0}};

  // cout << "The Celebrity is (matOne): " << celebrity(matOne) << endl;
  // cout << "The Celebrity is (matTwo): " << celebrity(matTwo) << endl;
  // cout << "The Celebrity is (matThree): " << celebrity(matThree) << endl;
  // cout << "The Celebrity is (matFour): " << celebrity(matFour) << endl;

  // Uncomment for Leetcode 1019 next greater element
  // Node *one = new Node(2);
  // Node *two = new Node(1);
  // Node *three = new Node(5);

  // one->nextNode = two;
  // two->nextNode = three;

  // Node *headOne = one;
  // printLinkedList(headOne);

  // cout << endl;

  // Node *four = new Node(2);
  // Node *five = new Node(7);
  // Node *six = new Node(4);
  // Node *seven = new Node(3);
  // Node *eight = new Node(5);

  // four->nextNode = five;
  // five->nextNode = six;
  // six->nextNode = seven;
  // seven->nextNode = eight;

  // Node *headTwo = four;
  // printLinkedList(headTwo);

  // cout << endl;

  // vector< int > ansHeadOne = nextLargerNodes(headOne);
  // vector< int > ansHeadTwo = nextLargerNodes(headTwo);

  // cout << "Answer array of LL one: ";
  // printVector(ansHeadOne);

  // cout << "Answer array of LL two: ";
  // printVector(ansHeadTwo);

  // Uncomment for NStacks in an array
  // NStack st(3, 6);
  // cout << st.push(1, 1) << endl;
  // cout << st.push(2, 1) << endl;
  // cout << st.push(3, 1) << endl;
  // cout << st.push(4, 1) << endl;
  // cout << st.push(5, 1) << endl;
  // cout << st.push(6, 1) << endl;
  // cout << st.push(7, 1) << endl; // will not go through because of overflow
  // cout << st.pop(1) << endl;
  // cout << st.pop(1) << endl;
  // cout << st.pop(1) << endl;
  // cout << st.push(10, 2) << endl;
  // cout << st.push(20, 2) << endl;
  // cout << st.push(30, 2) << endl;
  // cout << st.pop(2) << endl;

  // Uncomment for Leetcode 901 Online stock span
  // StockSpanner *obj = new StockSpanner();
  // cout << obj->next(100) << endl;
  // cout << obj->next(80) << endl;
  // cout << obj->next(60) << endl;
  // cout << obj->next(70) << endl;
  // cout << obj->next(60) << endl;
  // cout << obj->next(75) << endl;
  // cout << obj->next(85) << endl;

  // Uncomment for leetcode 1003
  // cout << isValidRecursiveSoln("aabcbc") << endl;
  // cout << isValidRecursiveSoln("abcabcababcc") << endl;
  // cout << isValidRecursiveSoln("abccba") << endl;
  // cout << endl;
  // cout << isValid("aabcbc") << endl;
  // cout << isValid("abcabcababcc") << endl;
  // cout << isValid("abccba") << endl;

  // Uncomment for decode string LC 394
  // cout << decodeString("3[a]2[bc]") << endl;
  // cout << decodeString("3[a2[c]]") << endl;
  // cout << decodeString("2[abc]3[cd]ef") << endl;
  // cout << decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl;

  // Uncomment for Simplify Path LC 71
  // cout << simplifyPath("/home/") << endl;
  // cout << simplifyPath("/home//foo/") << endl;
  // cout << simplifyPath("/home/user/Documents/../Pictures") << endl;
  // cout << simplifyPath("/../") << endl;
  // cout << simplifyPath("/.../a/../b/c/../d/./") << endl;

  // Uncomment for leetcode 85. Maximal Rectangle
  // vector< vector< char > > matrixOne = {{'1', '0', '1', '0', '0'},
  //                                       {'1', '0', '1', '1', '1'},
  //                                       {'1', '1', '1', '1', '1'},
  //                                       {'1', '0', '0', '1', '0'}};
  // vector< vector< char > > matrixTwo = {{'0'}};
  // vector< vector< char > > matrixThree = {{'1'}};

  // cout << maximalRectangle(matrixOne) << endl;
  // cout << maximalRectangle(matrixTwo) << endl;
  // cout << maximalRectangle(matrixThree) << endl;

  // Uncomment for leetcode 735. Asteroid Collision
  // vector< int > vOne = {5, 10, -5};
  // vector< int > ansOne = asteroidCollision(vOne);
  // printVector(ansOne);

  // vector< int > vTwo = {10, 2, -5};
  // vector< int > ansTwo = asteroidCollision(vTwo);
  // printVector(ansTwo);

  // vector< int > vThree = {8, -8};
  // vector< int > ansThree = asteroidCollision(vThree);
  // printVector(ansThree);

  // Uncomment for Leetcode 853 Car Fleet
  // int targetOne = 12;
  // vector< int > positionsOne = {10, 8, 0, 5, 3};
  // vector< int > speedOne = {2, 4, 1, 1, 3};

  // cout << carFleet(targetOne, positionsOne, speedOne) << endl;

  // int targetTwo = 10;
  // vector< int > positionsTwo = {3};
  // vector< int > speedTwo = {3};

  // cout << carFleet(targetTwo, positionsTwo, speedTwo) << endl;

  // int targetThree = 100;
  // vector< int > positionsThree = {0, 2, 4};
  // vector< int > speedThree = {4, 2, 1};

  // cout << carFleet(targetThree, positionsThree, speedThree) << endl;

  // Uncomment for Leetcode 1776 Car fleet 2
  // vector< vector< int > > carsOne = {{1, 2}, {2, 1}, {4, 3}, {7, 2}};
  // vector< vector< int > > carsTwo = {{3, 4}, {5, 4}, {6, 3}, {9, 1}};

  // vector< double > ansOne = getCollisionTimes((carsOne));
  // vector< double > ansTwo = getCollisionTimes((carsTwo));

  // printVectorOfTypeDouble(ansOne);
  // printVectorOfTypeDouble(ansTwo);

  // Uncomment for leetcode 32 Longest valid Parentheses
  // cout << longestValidParenthesesM1("(()") << endl;
  // cout << longestValidParenthesesM1(")()())") << endl;

  // Uncomment for leetcode 739. Daily Temperatures
  // vector< int > tempOne = {73, 74, 75, 71, 69, 72, 76, 73};
  // vector< int > tempTwo = {30, 40, 50, 60};
  // vector< int > tempThree = {30, 60, 90};

  // vector< int > ansOne = dailyTemperatures(tempOne);
  // vector< int > ansTwo = dailyTemperatures(tempTwo);
  // vector< int > ansThree = dailyTemperatures(tempThree);

  // printVector(ansOne);
  // printVector(ansTwo);
  // printVector(ansThree);

  // Uncomment for Leetcode 402. Remove K Digits
  // string numOne = "1432219";
  // int kOne = 3;

  // string numTwo = "10200";
  // int kTwo = 1;

  // string numThree = "10";
  // int kThree = 2;

  // string numFour = "2561305";
  // int kFour = 4;

  // cout << removeKdigits(numOne, kOne) << endl;
  // cout << removeKdigits(numTwo, kTwo) << endl;
  // cout << removeKdigits(numThree, kThree) << endl;
  // cout << removeKdigits(numFour, kFour) << endl;

  // Uncomment for 921. Minimum Add to Make Parentheses Valid
  // string sOne = "())";
  // string sTwo = "(((";
  // string sThree = "))())(";

  // cout << minAddToMakeValid(sOne) << endl;
  // cout << minAddToMakeValid(sTwo) << endl;
  // cout << minAddToMakeValid(sThree) << endl;

  // Uncomment for Leetcode 1472. Design Browser History
  string homepage = "leetcode.com";
  BrowserHistory *browserHistory = new BrowserHistory(homepage);
  browserHistory->visit("google.com");
  browserHistory->visit("facebook.com");
  browserHistory->visit("youtube.com");
  browserHistory->back(1);
  browserHistory->back(1);
  browserHistory->forward(1);
  browserHistory->visit("linkedin.com");
  browserHistory->forward(2);
  browserHistory->back(2);
  browserHistory->back(7);

  return 0;
}