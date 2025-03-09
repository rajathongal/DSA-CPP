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
  stack< char > st;

  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    st.push(ch);
  }

  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }
  cout << endl << endl;
}

void solveForFindMidElement(stack< int > &st, int &position, int &answer) {
  if (position == 1) {
    answer = st.top();
    // for deleting a middle element in a stack add pop here
    // st.pop();
    return;
  }

  position--;
  int temp = st.top();
  st.pop();

  solveForFindMidElement(st, position, answer);

  st.push(temp);
}

int findMidElement(stack< int > st) {
  int size = st.size();

  if (st.empty()) {
    return -1;
  } else {
    // stack not empty
    // mid formula odd even case
    int position = 0;
    if (size & 1) {
      position = size / 2 + 1;
    } else {
      position = size / 2;
    }

    int answer;
    solveForFindMidElement(st, position, answer);
    return answer;
  }
}

// Insert at bottom of stack
void insertAtBottom(stack< int > &st, int &element) {
  if (st.empty()) {
    st.push(element);
    return;
  }

  int temp = st.top();
  st.pop();

  insertAtBottom(st, element);

  st.push(temp);
}

void printStack(stack< int > &st) {

  if (st.empty()) {
    cout << endl;
    return;
  }

  int temp = st.top();
  cout << temp << ", ";
  st.pop();

  printStack(st);

  st.push(temp);
}

void reverseAStack(stack< int > &st) {
  // base case
  if (st.empty()) {
    return;
  }

  // case solve
  int temp = st.top();
  st.pop();

  // recursion
  reverseAStack(st);

  // backtrack
  insertAtBottom(st, temp);
} // TC O(n^2)

// insert in a sorted stack
void insertInASortedStack(stack<int> &st, int &insertElement) {
  // base case
  // when accessing top of stack 
  // remember this to check if stack is empty or not v impo
  if(st.empty() || insertElement > st.top()) {
    st.push(insertElement);
    return;
  }

  // case 
  int temp = st.top();
  st.pop();

  // recursion
  insertInASortedStack(st, insertElement);

  // backtracking
  st.push(temp);
}

// Sort a stack
void sortStack(stack<int> &st) {
  // base case
  if(st.empty()) {
    return;
  }

  int temp = st.top();
  st.pop();

  // recursion
  sortStack(st);

  // back tracking
  insertInASortedStack(st, temp);

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

  // 3. Find mid using stack and backtracking
  // evenLength
  stack< int > evenSt;
  // oddLenght
  stack< int > oddSt;

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

  int answer = findMidElement(evenSt);
  cout << answer << endl;
  answer = findMidElement(oddSt);
  cout << answer << endl << endl;

  // 4. Insert at bottom of stack
  stack< int > bottomInsertStack;
  bottomInsertStack.push(10);
  bottomInsertStack.push(20);
  bottomInsertStack.push(30);
  bottomInsertStack.push(40);
  bottomInsertStack.push(50);
  bottomInsertStack.push(60);

  int insertElement = 902;
  printStack(bottomInsertStack);
  insertAtBottom(bottomInsertStack, insertElement);
  printStack(bottomInsertStack);

  cout << endl;

  // 5. Reverse a stack
  reverseAStack(bottomInsertStack);
  printStack(bottomInsertStack);

  cout << endl;

  // 6. Insert in a sorted stack
  stack< int > sortedStack;
  sortedStack.push(10);
  sortedStack.push(20);
  sortedStack.push(30);
  sortedStack.push(40);
  sortedStack.push(50);

  int insertElement_2 = 45;
  printStack(sortedStack);
  insertInASortedStack(sortedStack, insertElement_2);
  printStack(sortedStack);

  cout << endl;

  // 7. Sort a stack
  stack<int> unsortedStack;
  unsortedStack.push(50);
  unsortedStack.push(10);
  unsortedStack.push(60);
  unsortedStack.push(30);
  unsortedStack.push(20);
  unsortedStack.push(40);
  printStack(unsortedStack);
  sortStack(unsortedStack); // TC O(n^2)
  printStack(unsortedStack);

  return 0;
}