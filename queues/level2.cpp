#include <deque>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printNQueue(queue< int > q) {
  if (q.empty()) {
    cout << endl;
    return;
  };

  int poppedElement = q.front();
  q.pop();
  cout << poppedElement << " ";
  printNQueue(q);

  return;
}

void reverseQueueUsingStack(queue< int > &q) {
  stack< int > st;
  // Store elements into stack from queue
  while (!q.empty()) {
    int frontElement = q.front();
    q.pop();
    st.push(frontElement);
  }

  // push elements back into queue
  while (!st.empty()) {
    int element = st.top();
    st.pop();
    q.push(element);
  }
}

void reverseQueueUsingRecursion(queue< int > &q) {
  if (q.empty())
    return;

  int element = q.front();
  q.pop();
  reverseQueueUsingRecursion(q);
  q.push(element);
  return;
}

// Reverse K elements
void reverseKElements(queue< int > &q, int &k) {

  if(k > q.size() || k == 0) return;

  // Using Stack
  stack< int > st;
  int kCopy = k;
  // Push first k elements from q to stack
  while (k--) {
    st.push(q.front());
    q.pop();
  }

  // Push all K elements from stack to queue
  while (!st.empty()) {
    q.push(st.top());
    st.pop();
  }

  // POP n-k elements push again
  int existingElements = q.size() - kCopy;

  while (existingElements--) {
    int temp = q.front();
    q.pop();
    q.push(temp);
  }
  return;
}

// Interleave first and second half of Queue

int main() {

  // Uncomment for Reverse Queue using stack
  queue< int > q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);
  cout << q.front() << " " << q.back() << endl;
  printNQueue(q);

  reverseQueueUsingStack(q);

  cout << q.front() << " " << q.back() << endl;
  printNQueue(q);

  reverseQueueUsingRecursion(q);
  cout << q.front() << " " << q.back() << endl;
  printNQueue(q);

  int k = 4;
  reverseKElements(q, k);
  printNQueue(q);

  return 0;
}