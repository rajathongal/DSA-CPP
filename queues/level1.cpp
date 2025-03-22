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

  int getSize() { return rear - front + 1; }

  int getFront() {
    if (front == -1) {
      cout << "No element in Queue" << endl;
      return -1;
    } else {
      return arr[front];
    }
  }

  int getRear() {
    if (rear == -1) {
      cout << "No element in Queue" << endl;
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
}