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
}

int main() {
  reverseSinglyLL();
  return 0;
}