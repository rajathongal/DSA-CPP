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

void printLinkedList(Node* head) {
  Node *temp = head; // must make a copy always
  int len = 0;
  while(temp != NULL) {
    cout << temp->data << "->";
    temp = temp->nextNode;
    ++len;
  }
  cout << endl << "Length of LL: " << len << endl;
}

int main() {
  // creation of Node
  // static object or static allocation stores in stack memory
  Node a; 
  // Dynamic Object or dynamic allocation gives pointer to
  // allocated heap memory
  Node *b = new Node();

  // Creates Independent Nodes 
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);

  // stitch Linked List
  first->nextNode = second;
  second->nextNode = third;
  third->nextNode = fourth;
  // Linked List created

  Node* head = first;
  printLinkedList(head);

  return 0;
}