#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

// Implement a min stack
// get min pop push should happen in O(1) not O(N)
// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.
class MinStack {
public:
  vector< pair< int, int > > st;

  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      // while inserting first element itself will be min
      pair< int, int > p;
      p.first = val;
      p.second = val;
      st.push_back(p);
    } else {
      // now verify if the last element's min is valid with new insertion value
      pair< int, int > p;
      p.first = val;
      int oldMin = st.back().second;
      p.second = min(oldMin, val);
      st.push_back(p);
    }
  }

  void pop() {
    // check underflow
    st.pop_back();
  }

  int top() { return st.back().first; }

  int getMin() { return st.back().second; }
};

void printVector(vector< int > v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    cout << v[i] << " "; // method 1
    // cout << v.at(i) << endl;
  }
  cout << endl;
}

// Next smaller element
vector< int > findNextSmallerElement(int *arr, int size) {
  vector< int > answer(size, 0);
  stack< int > st;
  // because the amswer for right most element will be -1 since
  // there is not element to compare
  st.push(-1);

  // Traverse from right most element to left most element
  for (int i = size - 1; i >= 0; i--) {
    int curr = arr[i];

    while (st.top() >= curr) {
      st.pop();
    }

    answer[i] = st.top();
    st.push(curr);
  }

  return answer;
} // TC O(N) = N + N = 2N = O(N)

// Previous Smaller Element
vector< int > findPreviousSmallerElement(int *arr, int size) {
  vector< int > answer(size, 0);
  stack< int > st;
  // because the amswer for right most element will be -1 since
  // there is not element to compare
  st.push(-1);

  // Traverse from right most element to left most element
  for (int i = 0; i < size; i++) {
    int curr = arr[i];

    while (st.top() >= curr) {
      st.pop();
    }

    answer[i] = st.top();
    st.push(curr);
  }

  return answer;
}

// Largest Rectangle in a Histogram leetcode 84
int largestRectangleArea(vector< int > &heights) {}

int main() {
  MinStack *st = new MinStack();
  st->push(1);
  st->push(-1);
  cout << "Min: " << st->getMin() << endl;
  st->push(101);
  cout << "Top: " << st->top() << endl;

  // Next smaller element
  int arr[5] = {8, 4, 6, 2, 3};
  int size = 5;
  vector< int > answer = findNextSmallerElement(arr, size);
  printVector(answer);

  // Previous smaller element
  int arr2[5] = {8, 4, 6, 2, 3};
  int size2 = 5;
  vector< int > answer2 = findPreviousSmallerElement(arr2, size2);
  printVector(answer2);

  // largest rectangle area in a histogram
  vector<int> h1 = {2,1,5,6,2,3};
  vector<int> h2 = {2,4};

  cout << largestRectangleArea(h1) << endl;
  cout << largestRectangleArea(h2) << endl;
  return 0;
}