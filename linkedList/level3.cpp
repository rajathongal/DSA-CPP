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

// Leetcode 206
void reverse(Node *&head) {
  Node *prev = NULL;
  Node *curr = head;
  while (curr != NULL) {
    Node *next = curr->nextNode;
    curr->nextNode = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
}

void reverseUsingRecursion(Node *&head, Node *curr, Node *prev = NULL,
                           Node *next = NULL) {
  if (curr == NULL) {
    head = prev;
    return;
  }
  next = curr->nextNode;
  curr->nextNode = prev;
  prev = curr;
  curr = next;

  reverseUsingRecursion(head, curr, prev, next);
}

void reverseSinglyLL() {
  Node *head = NULL;
  Node *tail = NULL;

  insertionAtPosition(head, tail, 10, 1);
  insertionAtPosition(head, tail, 20, 2);
  insertionAtPosition(head, tail, 30, 3);
  insertionAtPosition(head, tail, 40, 4);
  insertionAtPosition(head, tail, 50, 5);

  printLinkedList(head);

  reverse(head);
  printLinkedList(head);

  reverseUsingRecursion(head, head);
  printLinkedList(head);
}

// TC O(n + n/2) -> O(n) takes 2 traversal
void findMiddleOfLL(Node *head) {
  int len = lenOfLL(head);
  // mid
  int position = len / 2 + 1;
  int currPos = 1;
  Node *temp = head;
  while (currPos != position) {
    temp = temp->nextNode;
    currPos++;
  }

  cout << "Mid: " << temp->data << " Found at Position: " << position << endl;
}

// using 2 pointers or slow fast pointer or totoise method
// slow ptr moves 1 step // moves only when fast ptr is able to move 2 steps
// fast ptr moves 2 steps
void findMidOfLLUsingFastSlowPtrs(Node *head) {
  Node* slow = head;
  Node* fast = head;
  int position = 1;
  while(fast != NULL) {
    // move fast once
    fast = fast->nextNode;
    // check if fast is not null
    if(fast != NULL) {
      // move fast for 2 nd time
      fast = fast->nextNode;
      // since fast is able to move 2 times
      // move slow once
      slow = slow->nextNode;
      position++;
    }
  }
  cout << "Mid: " << slow->data << " Found at Position: " << position << endl;
}

int main() {
  Node *head = NULL;
  Node *tail = NULL;

  insertionAtPosition(head, tail, 10, 1);
  insertionAtPosition(head, tail, 20, 2);
  insertionAtPosition(head, tail, 30, 3);
  insertionAtPosition(head, tail, 40, 4);
  insertionAtPosition(head, tail, 50, 5);
  insertionAtPosition(head, tail, 60, 6);
  insertionAtPosition(head, tail, 70, 7);
  insertionAtPosition(head, tail, 80, 8);
  insertionAtPosition(head, tail, 90, 9);
  insertionAtPosition(head, tail, 100, 10);
  insertionAtPosition(head, tail, 110, 11);
  insertionAtPosition(head, tail, 120, 12);


  // reverseSinglyLL();
  // findMiddleOfLL(head);
  findMidOfLLUsingFastSlowPtrs(head);
  return 0;
}