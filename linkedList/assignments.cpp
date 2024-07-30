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

// 1. GFG Delete n nodes after m nodes of a LL
// https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/

void linkDelete(Node *head, int m, int n) {
  if (head == NULL)
    return;

  if (head->nextNode == NULL) {
    return;
  }

  if (m > lenOfLL((head))) {
    return;
  }

  Node *it = head;
  while (m > 1) {
    if (it == NULL)
      return;
    m--;
    it = it->nextNode;
  }
  if (it == NULL)
    return;
  while (n > 0) {
    Node *deletionNode = it->nextNode;
    it->nextNode = deletionNode->nextNode;
    if (deletionNode->nextNode == NULL) {
      deletionNode->nextNode = NULL;
      delete deletionNode;
      return;
    }
    deletionNode->nextNode = NULL;
    delete deletionNode;
    n--;
  }
}

int main() {
  Node *headOne = NULL;
  Node *tailOne = NULL;

  tailInsertionInLL(headOne, tailOne, 1);
  tailInsertionInLL(headOne, tailOne, 2);
  tailInsertionInLL(headOne, tailOne, 3);
  tailInsertionInLL(headOne, tailOne, 4);
  tailInsertionInLL(headOne, tailOne, 5);
  tailInsertionInLL(headOne, tailOne, 6);
  printLinkedList(headOne);
  linkDelete(headOne, 5, 2);
  printLinkedList(headOne);

  return 0;
}