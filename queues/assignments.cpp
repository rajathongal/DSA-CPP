#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Leetcode 232 Impliment queue using stacks
// Method 1
class MyQueueM1 {
  stack< int > s1;
  stack< int > s2;

public:
  MyQueueM1() {}

  void push(int x) {
    while (!s1.empty()) {
      int elem = s1.top();
      s1.pop();
      s2.push(elem);
    }

    s1.push(x);
    while (!s2.empty()) {
      int elem = s2.top();
      s2.pop();
      s1.push(elem);
    }
  }

  int pop() {
    int poppedElem = s1.top();
    s1.pop();
    return poppedElem;
  }

  int peek() { return s1.top(); }

  bool empty() { return (s1.empty() && s2.empty()); }
};
// Method 2
class MyQueueM2 {
  stack< int > s1;
  stack< int > s2;

public:
  MyQueueM2() {}

  void push(int x) { s1.push(x); }

  int pop() {
    if (!s2.empty()) {
      int poppedElem = s2.top();
      s2.pop();
      return poppedElem;

    } else {
      while (!s1.empty()) {
        int elem = s1.top();
        s1.pop();
        s2.push(elem);
      }
      int poppedElem = s2.top();
      s2.pop();
      return poppedElem;
    }
  }

  int peek() {
    if (!s2.empty()) {
      return s2.top();

    } else {
      while (!s1.empty()) {
        int elem = s1.top();
        s1.pop();
        s2.push(elem);
      }
      return s2.top();
    }
  }

  bool empty() { return (s1.empty() && s2.empty()); }
};

// Leetcode 225: Implement stacks using queues
// Method 1
// Using 2 Queues and push is a heavy op rest are O(1)
class MyStackM1 {
  queue< int > q1;
  queue< int > q2;

public:
  MyStackM1() {}

  void push(int x) {
    q2.push(x);

    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }

    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int pop() {
    int poppedElem = q1.front();
    q1.pop();
    return poppedElem;
  }

  int top() { return q1.front(); }

  bool empty() { return (q1.empty() && q2.empty()); }
};

// Method 2
// Using only one queue
class MyStackM2 {
  queue< int > q;

public:
  MyStackM2() {}

  void push(int x) {
    q.push(x);
    // reverse queue
    for (int i = 0; i < q.size() - 1; i++) { // O(N)
      int popElem = q.front();
      q.pop();
      q.push(popElem);
    }
  }

  int pop() {
    int popElem = q.front();
    q.pop();
    return popElem;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};

int main() {

  // Uncomment for LC 232
  // M1
  // MyQueueM1 *obj = new MyQueueM1();
  // obj->push(1);
  // obj->push(2);
  // obj->push(3);
  // obj->push(4);
  // obj->push(5);
  // int param_2 = obj->pop();
  // cout << param_2 << endl;
  // int param_3 = obj->peek();
  // cout << param_3 << endl;
  // bool param_4 = obj->empty();
  // cout << param_4 << endl << endl;

  // // M2
  // MyQueueM2 *obj2 = new MyQueueM2();
  // obj2->push(1);
  // obj2->push(2);
  // obj2->push(3);
  // obj2->push(4);
  // obj2->push(5);
  // int param_2_2 = obj2->pop();
  // cout << param_2_2 << endl;
  // int param_3_2 = obj2->peek();
  // cout << param_3_2 << endl;
  // bool param_4_2 = obj2->empty();
  // cout << param_4_2 << endl;

  // Uncomment for Leetcode 225 Implement stacks using queues
  // M1
  // MyStackM1 *myStack = new MyStackM1();
  // myStack->push(1);
  // myStack->push(2);
  // cout << myStack->top() << endl;   // return 2
  // cout << myStack->pop() << endl;   // return 2
  // cout << myStack->empty() << endl; // return False

  // M2
  MyStackM2 *myStack = new MyStackM2();
  myStack->push(1);
  myStack->push(2);
  cout << myStack->top() << endl;   // return 2
  cout << myStack->pop() << endl;   // return 2
  cout << myStack->empty() << endl; // return False

  return 0;
}