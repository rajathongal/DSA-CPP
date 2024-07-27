#include <iostream>
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

// Must do when you are changing in LL to pass by reference
void headInsertionInLL(Node *&head, Node *&tail, int newData) {
  // check for empty LL
  if (head == NULL) {
    // 1. create a new node
    Node *newNode = new Node(newData);
    // update head
    head = newNode;
    // update tail
    tail = newNode;
  } else {
    // create new node
    Node *newNode = new Node(newData);
    // Attach new node to head
    newNode->nextNode = head;
    // update head
    head = newNode;
  }
}

void tailInsertionInLL(Node *&head, Node *&tail, int newData) {
  // check for empty LL
  if (head == NULL) {
    // 1. create a new node
    Node *newNode = new Node(newData);
    // update head
    head = newNode;
    // update tail
    tail = newNode;
  } else {
    // create new node
    Node *newNode = new Node(newData);
    // Attach tail to new Node
    tail->nextNode = newNode;
    // update tail
    tail = newNode;
  }
}

void insertionAtPosition(Node *&head, Node *&tail, int newData,
                         int newPosition) {
  // // check for NULL Nodes or out of bound
  // if (newPosition < 1) {
  //   cout << "Cannot insert, please enter a valid position" << endl;
  //   return;
  // }

  int length = lenOfLL(head);

  if (newPosition <= 1) {
    headInsertionInLL(head, tail, newData);
  } else if (newPosition > length) { // len +1 or > len insert at tail
    // Note length + 1 = tail very important else mistake
    tailInsertionInLL(head, tail, newData);
  } else {
    // insert at position

    // create a new node
    Node *newNode = new Node(newData);

    // traverse to current/previous position of the new position
    Node *prev = NULL;
    Node *curr = head;

    while (newPosition != 1) {
      prev = curr;
      curr = curr->nextNode;
      newPosition--;
    }

    // previous->nextNode = newNode;
    prev->nextNode = newNode;

    // newNode->nextNode = current;
    newNode->nextNode = curr;
  }
}

// Leetcode 141 Linked list cycle using fast slow ptrs
bool hasCycle() {
  Node *head = NULL;
  Node *tail = NULL;

  // uncomment for cycle
  tailInsertionInLL(head, tail, 10);
  tailInsertionInLL(head, tail, 20);
  tailInsertionInLL(head, tail, 30);
  Node *tailCopy = tail;
  tailInsertionInLL(head, tail, 40);
  tailInsertionInLL(head, tail, 50);
  tailInsertionInLL(head, tail, 60);
  tail->nextNode = tailCopy;

  // uncomment for no cycle
  // tailInsertionInLL(head, tail, 10);
  // tailInsertionInLL(head, tail, 20);
  // tailInsertionInLL(head, tail, 30);
  // tailInsertionInLL(head, tail, 40);
  // tailInsertionInLL(head, tail, 50);
  // tailInsertionInLL(head, tail, 60);

  Node *slow = head;
  Node *fast = head;
  // slow == fast then cycle exists

  while (fast != NULL) {
    fast = fast->nextNode;
    if (fast != NULL) {
      fast = fast->nextNode;
      slow = slow->nextNode;
    }

    // check for cycle
    if (fast == slow) {
      cout << "cycle exists" << endl;
      return true;
    }
  }
  cout << "no cycle exists" << endl;
  return false;
}

// Leetcode 141 Linked list cycle using fast slow ptrs
bool hasCycleInputs(Node *&slow, Node *&fast) {

  // slow == fast then cycle exists

  while (fast != NULL) {
    fast = fast->nextNode;
    if (fast != NULL) {
      fast = fast->nextNode;
      slow = slow->nextNode;
    }

    // check for cycle
    if (fast == slow) {
      cout << "cycle exists" << endl;
      return true;
    }
  }
  cout << "no cycle exists" << endl;
  return false;
}

// Starting point of Loop

void startingPointOfLoop() {
  Node *head = NULL;
  Node *tail = NULL;

  // uncomment for cycle
  tailInsertionInLL(head, tail, 10);
  tailInsertionInLL(head, tail, 20);
  tailInsertionInLL(head, tail, 30);
  Node *tailCopy = tail;
  tailInsertionInLL(head, tail, 40);
  tailInsertionInLL(head, tail, 50);
  tailInsertionInLL(head, tail, 60);
  tail->nextNode = tailCopy;

  Node *slow = head;
  Node *fast = head;
  // 1. Find if cycle exists
  bool isCycleExists = hasCycleInputs(slow, fast);
  // 2. update slow to point at head
  slow = head;
  // 3. move slow and fast by 1step untill fast == slow
  while (fast != slow) {
    slow = slow->nextNode;
    fast = fast->nextNode;
  }
  cout << slow->data << " " << fast->data << endl; // answer
  // position where fast & slow meet each other is
  // the answer or starting point of cycle
}

int main() {
  // hasCycle();
  startingPointOfLoop();
  return 0;
}