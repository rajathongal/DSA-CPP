#include <iostream>
#include <stack>
using namespace std;

// 2 stack implimentation using array
// Terminologies
// Stack 1 move from left to right during insertion
// Stack 2 move from right to left during insertion
// top == -1 stack 1 is empty // underflow condition
// top == size stack 2 is empty // underflow condition
// when both top are adjacent top2 - top1 == 1  // overflow condition
// push in stack 1 -> top1++; array[top1]=data
// push in stack 2 -> top2--; array[top2]=data
// pop in stack 1 -> arr[top1] = 0; top1--;
// pop in stack 2 -> arr[top2] = 0; top2++;

class StackArr {
public:
  int *arr; // dynamic array
  int size;
  int top1;
  int top2;

  StackArr(int size) {
    arr = new int[size];
    this->size = size;
    top1 = -1;
    top2 = size;
  }

  void push1(int data) {
    // overflow check
    if (top2 - top1 == 1) {
      cout << "OVERFLOW" << endl;
      return;
    }
    top1++;
    arr[top1] = data;
  }

  void push2(int data) {
    // overflow check
    if (top2 - top1 == 1) {
      cout << "OVERFLOW" << endl;
      return;
    }
    top2--;
    arr[top2] = data;
  }

  void pop1() {
    // underflow check
    if (top1 == -1) {
      cout << "UNDERFLOW" << endl;
      return;
    }
    arr[top1] = 0;
    top1--;
  }

  void pop2() {
    if (top2 == size) {
      cout << "UNDERFLOW" << endl;
      return;
    }
    arr[top2] = 0;
    top2++;
  }

  void printStack() {
    cout << endl;
    cout << "Top1: " << top1 << endl;
    cout << "Top2: " << top2 << endl;
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

// Very important
// Valid Parentheses
// Leetcode 20.
bool isValid(string str) {
  stack< char > strSt;

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (ch == '(' || ch == '[' || ch == '{') {
      strSt.push(ch);
    } else {
      if (!strSt.empty()) {
        if (ch == ')' && strSt.top() == '(') {
          strSt.pop();
        } else if (ch == ']' && strSt.top() == '[') {
          strSt.pop();
        } else if (ch == '}' && strSt.top() == '{') {
          strSt.pop();
        } else {
          // no match
          return false;
        }
      } else {
        return false;
      }
    }
  }
  if (strSt.size() == 0) {
    return true;
  } else {
    return false;
  }
}

// Remove Redundant brackets

int main() {

  StackArr st(6);
  st.printStack();

  // push
  st.push1(10);
  st.printStack();

  st.push1(20);
  st.printStack();

  st.push2(100);
  st.printStack();

  st.push2(200);
  st.printStack();

  st.push2(300);
  st.printStack();

  st.push2(700);
  st.printStack();

  // overflow check
  st.push1(1);
  st.push2(2);
  st.printStack();

  // pop
  st.pop1();
  st.printStack();

  st.pop1();
  st.printStack();

  // Underflow check
  st.pop1();
  st.printStack();

  // valid parantheses
  string s1 = "()";
  string s2 = "()[]{}";
  string s3 = "(]";
  string s4 = "[({})]";
  string s5 = "[(}{)]";

  bool isValidString = isValid(s1); // O(N) TC
  cout << "s1: " << isValidString << endl;

  isValidString = isValid(s2);
  cout << "s2: " << isValidString << endl;

  isValidString = isValid(s3);
  cout << "s3: " << isValidString << endl;

  isValidString = isValid(s4);
  cout << "s4: " << isValidString << endl;

  isValidString = isValid(s5);
  cout << "s5: " << isValidString << endl;

  // Remove Redundant brackets

  return 0;
}