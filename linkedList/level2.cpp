#include <iostream>
using namespace std;

// Doubly Linked List
class Node {
public:
  int data;
  Node *prev; // Pointer to previous Node
  Node *next; // Pointer to next Node

  // default ctor
  Node() {
    this->prev = NULL;
    this->next = NULL;
  }

  // para ctor
  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

void printLinkedList(Node *head) {
  Node *temp = head; // must make a copy always while tracing
  int len = 0;
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
    ++len;
  }
  cout << endl << "Length of LL: " << len << endl << endl;
}

// Gets Length of LL
int lenOfLL(Node *&head) {
  int len = 0;
  Node *temp = head;
  while (temp != NULL) {
    len++;
    temp = temp->next;
  }

  return len;
}

void insertAtHead(Node *&head, Node *&tail, int data) {
  if (head == NULL) {
    // create new node
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    // create new node
    Node *newNode = new Node(data);
    // attach head's prev to newNode
    head->prev = newNode;
    // attach newNode's next to head
    newNode->next = head;
    // update head to newNode
    // head = head->prev; or
    head = newNode; // both works
  }
}

void insertAtTail(Node *&head, Node *&tail, int data) {
  // create new node
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    // create new node
    Node *newNode = new Node(data);
    // point tail's next node to new node
    tail->next = newNode;
    // point newnode prev's to tail
    newNode->prev = tail;
    // update tail
    tail = newNode;
  }
}

void insertionAtPosition(Node *&head, Node *&tail, int data, int position) {
  if (head == NULL) {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  } else {
    int len = lenOfLL(head);
    if (position == 1) {
      // insert head
      insertAtHead(head, tail, data);
    } else if (position >= len + 1) {
      // insert tail
      insertAtTail(head, tail, data);
    } else {
      // create a node
      Node *newNode = new Node(data);
      // traverse for prevNode and currNode
      Node *prevNode = NULL;
      Node *currNode = head;

      while (position != 1) {
        prevNode = currNode;
        currNode = currNode->next;
        position--;
      }
      // attach prevNode's next to newnode
      prevNode->next = newNode;
      // attach prevs of newNode to prevNode
      newNode->prev = prevNode;
      // attach newnode's next to currNode
      newNode->next = currNode;
      // attach prev of currNode to new node
      currNode->prev = newNode;
    }
  }
}

void deletionAtPosition(Node *&head, Node *&tail, int position) {
  // if LL is empty
  if (head == NULL) {
    cout << "Cannot delete from empty LL" << endl;
    return;
  }

  // single element case
  if (head == tail) {
    Node *temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
  }

  int length = lenOfLL(head);

  // delete from head
  if(position == 1) {
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    head->prev = NULL;
    delete temp;
  } else if(position == length) {
    // deletion at tail
    Node *prevNodeToTail = tail->prev;

    prevNodeToTail->next = NULL;
    tail->prev = NULL;
    delete tail;
    tail = prevNodeToTail;
  } else {
    // deletion at position
    Node* prevNode = NULL;
    Node* currNode = head;

    while(position != 1) {
      prevNode = currNode;
      currNode = currNode->next;
      position--;
    }

    Node* currNextNode = currNode->next;
    prevNode->next = currNextNode;
    currNextNode->prev = prevNode;

    currNode->next = NULL;
    currNode->prev = NULL;

    delete currNode;

  }
}

int main() {

  Node *head = NULL;
  Node *tail = NULL;

  insertAtHead(head, tail, 40);
  insertAtHead(head, tail, 30);
  insertAtHead(head, tail, 20);
  insertAtHead(head, tail, 10);

  printLinkedList(head);

  insertAtTail(head, tail, 50);
  insertAtTail(head, tail, 60);
  insertAtTail(head, tail, 70);

  printLinkedList(head);

  // at head
  insertionAtPosition(head, tail, 1, 1);
  printLinkedList(head);

  // at tail
  insertionAtPosition(head, tail, 2, 9);
  printLinkedList(head);

  // at pos
  insertionAtPosition(head, tail, 3, 3);
  printLinkedList(head);

  // deletion at head
  deletionAtPosition(head, tail, 1);
  printLinkedList(head);

  // deletion at tail 
  int len = lenOfLL(head);
  deletionAtPosition(head, tail, len);
  printLinkedList(head);

  // deletion at pos
  deletionAtPosition(head, tail, 2);
  printLinkedList(head);


  return 0;
}