#include <iostream>
#include <stack>
using namespace std;

class StackManual {
public:
  int *arr; // dynamic array
  int size;
  int top;

  StackManual(int _size) {
    arr = new int[_size];
    this->size = _size;
    this->top = -1;
  }

  void push(int data) {
    if (top == size - 1) {
      cout << "Stack Overflow" << endl;
      return;
    }
    top++;
    arr[top] = data;
  }

  void pop() {
    if (top == -1) {
      // underflow
      cout << "Stack underflow" << endl;
      return;
    } else {
      top--;
    }
  }

  bool isEmpty() {
    if (top == -1) {
      return true;
    } else {
      return false;
    }
  }

  int getTop() {
    if (top == -1) {
      cout << "Stack is empty" << endl; // empty check
      return -1;
    }
    return arr[top];
  }

  int getSize() { return top + 1; }

  // Below function does not exists and is for learning only
  void print() {
    cout << "Top: " << top << endl;
    cout << "Top Element: " << getTop() << endl;
    cout << "Stack ";
    for (int i = 0; i < getSize(); i++) {
      cout << arr[i] << " ";
    }
    cout << endl << endl;
  }
};

void stringReverse() {
  string str = "somestring";
  stack<char> st;

  for(int i=0; i < str.length(); i++) {
    char ch = str[i];
    st.push(ch);
  }

  while(!st.empty()) {
    cout << st.top();
    st.pop();
  }
  cout << endl << endl;
}

void findMidElement(stack<int> st) {

}

int main() {
  // 1. Manual Stack
  StackManual st(8); // static

  st.push(10);
  st.print();

  st.push(20);
  st.print();

  st.push(30);
  st.print();

  st.push(40);
  st.print();

  st.push(10);
  st.print();

  st.push(20);
  st.print();

  st.push(30);
  st.print();

  st.push(40);
  st.print();
  st.push(40);
  st.print();

  st.pop();
  st.print();
  st.pop();
  st.print();
  st.pop();
  st.print();
  st.pop();
  st.print();

  cout << endl;

  // 2. String reverse using inbuilt stack 
  stringReverse();

  cout << endl;

  // 3. Find mid using stack and backtracking

  // evenLength
  stack<int> evenSt;
  // oddLenght
  stack<int> oddSt;

  evenSt.push(13);
  evenSt.push(29);
  evenSt.push(13);
  evenSt.push(90);
  evenSt.push(111);
  evenSt.push(295);

  oddSt.push(1);
  oddSt.push(2);
  oddSt.push(3);
  oddSt.push(4);
  oddSt.push(5);

  findMidElement(evenSt);
  cout << endl;
  findMidElement(oddSt);
  cout << endl;

  return 0;
}