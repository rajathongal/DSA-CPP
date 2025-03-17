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
  StockSpanner *obj = new StockSpanner();
  cout << obj->next(100) << endl;
  cout << obj->next(80) << endl;
  cout << obj->next(60) << endl;
  cout << obj->next(70) << endl;
  cout << obj->next(60) << endl;
  cout << obj->next(75) << endl;
  cout << obj->next(85) << endl;

  return 0;
}