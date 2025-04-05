#include <deque>
#include <iostream>
#include <queue>
using namespace std;

class CustomQueueUsingArray {
public:
  int *arr; // dynamic arr
  int size;
  int front;
  int rear;

  CustomQueueUsingArray(int size) {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  void push(int val) {
    // check full
    if (rear == size - 1) {
      cout << "Queue Overflow" << endl;
      return;
    } else if (front == -1 && rear == -1) {
      // empty case
      front++;
      rear++;
      arr[rear] = val;
      return;
    } else {
      // base case
      rear++;
      arr[rear] = val;
    }
  }

  void pop() {
    // underflow
    if (front == -1 && rear == -1) {
      cout << "Queue Underflow" << endl;
      return;
    } else if (front == rear) {
      // empty case or removing single element case
      arr[front] = -1;
      rear = -1;
      front = -1;
    } else {
      arr[front] = -1;
      front++;
    }
  }

  bool isEmpty() {
    if (front == -1 && rear == -1) {
      return true;

    } else {
      return false;
    }
  }

  int getSize() {
    if (front == -1 && rear == -1)
      return 0;
    return rear - front + 1;
  }

  int getFront() {
    if (front == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[front];
    }
  }

  int getRear() {
    if (rear == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[rear];
    }
  }

  void printQueue() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

class CustomCircularQueueUsingArray {
public:
  int *arr;
  int size;
  int front;
  int rear;

  CustomCircularQueueUsingArray(int size) {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  void printQueue() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int getFront() {
    if (front == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[front];
    }
  }

  int getRear() {
    if (rear == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[rear];
    }
  }

  bool isEmpty() {
    if (front == -1 && rear == -1) {
      return true;

    } else {
      return false;
    }
  }

  int getSize() {
    if (front == -1 && rear == -1)
      return 0;
    return rear - front + 1;
  }

  void push(int val) {
    // overflow
    // Modulus can be used here to check oerflow condition
    if (front == 0 && rear == size - 1) {
      cout << "Overflow " << endl;
      return;

    } else if (rear == front - 1) {
      cout << "Overflow " << endl;
      return;
    }
    // first element / empty case push
    else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[rear] = val;
    }
    // circular
    else if (rear == size - 1 && front != 0) {
      rear = 0;
      arr[rear] = val;
    }
    // normal push
    else {
      rear++;
      arr[rear] = val;
    }
  }

  void pop() {
    // Underflow
    if (front == -1 && rear == -1) {
      cout << "Underflow " << endl;
      return;
    }
    // Single Element/empty case
    else if (front == rear) {
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    // Circular Case
    else if (front == size - 1) {
      arr[front] = -1;
      front = 0;
    }
    // Normal Case
    else {
      arr[front] = -1;
      front++;
    }
  }
};

class Deque {
  // Normal Deque
  // Implement Circular Deque
public:
  int *arr;
  int size;
  int front;
  int rear;

  Deque(int size) {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  // push front
  void push_front(int val) {
    // overflow check
    if (front == 0) {
      cout << "Overflow" << endl;
    }
    // empty element
    else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[front] = val;
    }
    // normal case
    else {
      front--;
      arr[front] = val;
    }
  }

  // push back
  void push_back(int val) {
    // overflow check
    if (rear == size - 1) {
      cout << "Overflow " << endl;
    }
    // empty element
    else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[rear] = val;
    }
    // normal case
    else {
      rear++;
      arr[rear] = val;
    }
  }

  // pop front
  void pop_front() {
    // Underflow
    if (front == -1 && rear == -1) {
      cout << "Underflow " << endl;
      return;
    }
    // Single Element/empty case
    else if (front == rear) {
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    // Circular Case
    else if (front == size - 1) {
      arr[front] = -1;
      front = 0;
    }
    // Normal Case
    else {
      arr[front] = -1;
      front++;
    }
  }

  // pop back
  void pop_back() {
    // underflow
    if (front == -1 && rear == -1) {
      cout << "Underflow" << endl;
    }
    // single element
    else if (front == rear) {
      arr[rear] = -1;
      front = -1;
      rear = -1;
    }
    // normal flow
    else {
      arr[rear] = -1;
      rear--;
    }
  }

  // Aux
  void printQueue() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int getFront() {
    if (front == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[front];
    }
  }

  int getRear() {
    if (rear == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[rear];
    }
  }

  bool isEmpty() {
    if (front == -1 && rear == -1) {
      return true;

    } else {
      return false;
    }
  }

  int getSize() {
    if (front == -1 && rear == -1)
      return 0;
    return rear - front + 1;
  }
};

// Circular Deque
class CircularDeque {
  // Normal Deque
  // Implement Circular Deque
public:
  int *arr;
  int size;
  int front;
  int rear;

  CircularDeque(int size) {
    arr = new int[size];
    this->size = size;
    front = -1;
    rear = -1;
  }

  // push front
  void push_front(int val) {
    // overflow check
    if (front == 0 && rear == size - 1 || (rear == front - 1)) {
      cout << "Overflow " << endl;
      return;
    }
    // empty element
    else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[front] = val;
    }
    // circular case
    else if (front == 0 && rear != size - 1) {
      front = size - 1;
      arr[front] = val;
    }
    // normal case
    else {
      front--;
      arr[front] = val;
    }
  }

  // push back
  void push_back(int val) {
    // overflow
    // Modulus can be used here to check oerflow condition
    if (front == 0 && rear == size - 1 || (rear == front - 1)) {
      cout << "Overflow " << endl;
      return;
    }
    // first element / empty case push
    else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[rear] = val;
    }
    // circular
    else if (rear == size - 1 && front != 0) {
      rear = 0;
      arr[rear] = val;
    }
    // normal push
    else {
      rear++;
      arr[rear] = val;
    }
  }

  // pop front
  void pop_front() {
    // Underflow
    if (front == -1 && rear == -1) {
      cout << "Underflow " << endl;
      return;
    }
    // Single Element/empty case
    else if (front == rear) {
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    // Circular Case
    else if (front == size - 1) {
      arr[front] = -1;
      front = 0;
    }
    // Normal Case
    else {
      arr[front] = -1;
      front++;
    }
  }

  // pop back
  void pop_back() {
    // underflow
    if (front == -1 && rear == -1) {
      cout << "Underflow" << endl;
    }
    // single element
    else if (front == rear) {
      arr[rear] = -1;
      front = -1;
      rear = -1;
    }
    // Circular Case
    else if (rear == 0) {
      arr[rear] = -1;
      rear = size - 1;
    }
    // normal flow
    else {
      arr[rear] = -1;
      rear--;
    }
  }

  // Aux
  void printQueue() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  int getFront() {
    if (front == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[front];
    }
  }

  int getRear() {
    if (rear == -1) {
      cout << "No element in Queue ";
      return -1;
    } else {
      return arr[rear];
    }
  }

  bool isEmpty() {
    if (front == -1 && rear == -1) {
      return true;

    } else {
      return false;
    }
  }

  int getSize() {
    if (front == -1 && rear == -1)
      return 0;
    return rear - front + 1;
  }
};

int main() {
  queue< int > q;

  q.push(1);
  q.push(2);

  cout << "Size of Queue: " << q.size() << endl;
  cout << "Is Queue Empty ? " << q.empty() << endl;

  q.pop();
  q.pop();
  cout << "Is Queue Empty ? " << q.empty() << endl;

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  cout << "Queue front: " << q.front() << " back: " << q.back() << endl;

  cout << endl << "Custom Queue" << endl;

  CustomQueueUsingArray que(10);
  que.printQueue();
  cout << "Size: " << que.getSize() << endl;

  cout << "Front: " << que.getFront() << " Back: " << que.getRear() << endl
       << endl;

  que.push(11);
  cout << "Front: " << que.getFront() << " Back: " << que.getRear() << endl;
  cout << "Size: " << que.getSize() << endl;

  que.push(12);
  que.push(13);
  que.push(14);
  que.push(15);
  que.push(16);
  que.push(17);
  que.push(18);
  que.push(19);
  que.push(20);

  // overflow
  que.push(21);
  que.push(22);
  que.push(23);

  que.printQueue();
  cout << "Size: " << que.getSize() << endl;

  que.pop();

  que.printQueue();
  cout << "Size: " << que.getSize() << endl;

  cout << "Front: " << que.getFront() << " Back: " << que.getRear() << endl
       << endl;

  que.pop();
  que.pop();
  que.pop();
  que.pop();
  que.pop();
  que.pop();
  que.pop();
  que.pop();
  que.pop();
  que.pop();
  cout << "Front: " << que.getFront() << " Back: " << que.getRear() << endl;
  cout << "Size: " << que.getSize() << endl;

  cout << endl << endl;

  CustomQueueUsingArray queTwo(3);
  // rear push method results in overflow after pop, push
  queTwo.push(12);
  queTwo.push(13);
  queTwo.push(14);
  queTwo.printQueue();
  cout << "After input Size: " << queTwo.getSize() << endl;

  queTwo.pop();
  cout << "After pop Size: " << queTwo.getSize() << endl;

  queTwo.printQueue();
  queTwo.push(12);
  cout << "After input Size: " << queTwo.getSize() << endl;

  queTwo.printQueue();
  queTwo.pop();
  queTwo.printQueue();

  cout << "Front:  " << que.getFront() << " Back:  " << que.getRear() << endl;
  queTwo.pop();
  queTwo.printQueue();
  cout << "After input Size: " << queTwo.getSize() << endl;

  cout << endl << endl;

  CustomCircularQueueUsingArray queCirc(5);
  queCirc.printQueue();
  cout << "Size: " << queCirc.getSize() << endl;

  queCirc.push(10);
  queCirc.printQueue();

  queCirc.push(20);
  queCirc.printQueue();

  queCirc.push(30);
  queCirc.printQueue();

  queCirc.push(40);
  queCirc.printQueue();

  queCirc.push(50);
  queCirc.printQueue();

  queCirc.push(60);
  queCirc.printQueue();

  queCirc.pop();
  queCirc.pop();
  queCirc.pop();
  queCirc.printQueue();

  queCirc.push(60); // circular nature
  queCirc.printQueue();

  queCirc.push(70);
  queCirc.printQueue();

  queCirc.push(80);
  queCirc.printQueue();

  queCirc.push(90); // Overflow case circluar nature
  queCirc.printQueue();

  queCirc.pop();
  queCirc.pop();
  queCirc.pop();
  queCirc.pop();
  queCirc.printQueue();

  queCirc.pop();
  queCirc.pop();
  queCirc.printQueue();

  cout << endl << "Deque" << endl << endl;

  // Deque or Doubly Ended Queue
  deque< int > dq;

  dq.push_back(10);
  cout << dq.front() << endl << dq.back() << endl << dq.size() << endl << endl;

  dq.push_front(20);
  cout << dq.front() << endl << dq.back() << endl << dq.size() << endl << endl;

  dq.push_back(30);
  cout << dq.front() << endl << dq.back() << endl << dq.size() << endl;
}