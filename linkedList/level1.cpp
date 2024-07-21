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
int lenOfLL(Node *head) {
  int len = 0;
  Node *temp = head;
  while (temp != NULL) {
    ++len;
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

int main() {
  // creation of Node
  // static object or static allocation stores in stack memory
  Node a;
  // Dynamic Object or dynamic allocation gives pointer to
  // allocated heap memory
  Node *b = new Node();

  // Creates Independent Nodes
  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);
  Node *fourth = new Node(40);

  // stitch Linked List
  first->nextNode = second;
  second->nextNode = third;
  third->nextNode = fourth;
  // Linked List created

  Node *head = first;
  Node *tail = fourth;
  printLinkedList(head);

  cout << endl;

  headInsertionInLL(head, tail, 500);
  printLinkedList(head);

  cout << endl;

  tailInsertionInLL(head, tail, 200);
  printLinkedList(head);

  cout << endl;
  // insertion in an empty LL
  // create empty LL
  Node *emptyLL = new Node();
  Node *headOfEmptyLL = emptyLL;
  Node *tailOfEmptyLL = emptyLL;

  headInsertionInLL(headOfEmptyLL, tailOfEmptyLL, 20);
  printLinkedList(headOfEmptyLL);

  cout << endl;

  // Creating LL using insertions
  Node *headNewLL = NULL;
  Node *tailNewLL = NULL;

  headInsertionInLL(headNewLL, tailNewLL, 40);
  headInsertionInLL(headNewLL, tailNewLL, 30);
  headInsertionInLL(headNewLL, tailNewLL, 20);
  headInsertionInLL(headNewLL, tailNewLL, 10);
  printLinkedList(headNewLL);

  cout << endl;

  tailInsertionInLL(headNewLL, tailNewLL, 50);
  printLinkedList(headNewLL);

  cout << endl;

  // insert at pos
  insertionAtPosition(headNewLL, tailNewLL, 101, 0);
  cout << endl;

  // head Insertion
  insertionAtPosition(headNewLL, tailNewLL, 11, 1);
  cout << endl;

  // pos > length tail insertion
  insertionAtPosition(headNewLL, tailNewLL, 101, 100);
  cout << endl;

  // insert in between
  insertionAtPosition(headNewLL, tailNewLL, 1, 4);
  cout << endl;

  printLinkedList(headNewLL);
  cout << endl;

  // insertion at tail using insert at pos
  insertionAtPosition(headNewLL, tailNewLL, 1000, 9);
  cout << endl;

  printLinkedList(headNewLL);
  cout << endl;

  return 0;
}