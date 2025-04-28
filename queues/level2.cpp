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

  if (k > q.size() || k == 0)
    return;

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
void interLeaveQueue(queue< int > &first) {
  queue< int > second;

  // push first half of queue in second q
  int size = first.size();
  for (int i = 0; i < size / 2; i++) {
    int temp = first.front();
    first.pop();
    second.push(temp);
  }

  // merge both halfves
  // into original q named first
  for (int i = 0; i < size / 2; i++) {
    int temp = second.front();
    second.pop();
    first.push(temp);
    temp = first.front();
    first.pop();
    first.push(temp);
  }
}

// first negative integer in every window of k
// n-k+1 windoes exists
// by brute force approach time complexity will be O(n * k)
// Linear approach
void printFirstNegativeInKWindow(int *arr, int n, int k) {
  deque< int > q;

  // process first window
  for (int i = 0; i < k; i++) {
    int element = arr[i];
    if (element < 0) {
      q.push_back(i);
    }
  }

  // process remaining windows
  // removal and addition of new elements as we move to new window
  for (int i = k; i < n; i++) {
    // previous answer
    if (q.empty()) {
      cout << "0 " << endl;
    } else {
      cout << arr[q.front()] << " ";
    }

    // Removal
    // index - q.front >= k (out of window)
    // (== k front of window)
    // (<k second or other element in window)
    if (i - q.front() >= k) {
      // out of window range element
      q.pop_front();
    }

    // addition
    if (arr[i] < 0) {
      q.push_back(i);
    }
  }

  if (q.empty()) {
    cout << "0 " << endl;
  } else {
    cout << arr[q.front()] << " ";
  }

  cout << endl;
}

int main() {

  // Uncomment for Reverse Queue using stack
  // queue< int > q;
  // q.push(10);
  // q.push(20);
  // q.push(30);
  // q.push(40);
  // q.push(50);
  // q.push(60);
  // cout << q.front() << " " << q.back() << endl;
  // printNQueue(q);

  // reverseQueueUsingStack(q);

  // cout << q.front() << " " << q.back() << endl;
  // printNQueue(q);

  // reverseQueueUsingRecursion(q);
  // cout << q.front() << " " << q.back() << endl;
  // printNQueue(q);

  // int k = 4;
  // reverseKElements(q, k);
  // printNQueue(q);

  // Uncomment for interleave queue
  // queue< int > q;
  // q.push(10);
  // q.push(20);
  // q.push(30);
  // q.push(40);
  // q.push(50);
  // q.push(60);
  // q.push(70);
  // printNQueue(q);
  // interLeaveQueue(q);
  // printNQueue(q);

  // Uncomment for first negative element in k window
  int arr[] = {2, -5, 4, -1, -2, 0, 5};
  printFirstNegativeInKWindow(arr, 7, 3);
  return 0;
}