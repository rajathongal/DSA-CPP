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

Node *startingPointOfCycle(Node *head) {

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

  if (fast == NULL) {
    cout << "No cycle exists" << endl;
    Node *temp = NULL;
    return temp;
  }
  cout << slow->data << " " << fast->data << endl; // answer
  // position where fast & slow meet each other is
  // the answer or starting point of cycle
  return slow;
}

// Remove a loop
void removeCycleInLL(Node *head) {
  Node *start = startingPointOfCycle(head);

  Node *temp = start;

  while (temp->nextNode != start) {
    temp = temp->nextNode;
  }
  temp->nextNode = NULL;
  return;
}

// add one to num in LL
void addOneToLL(Node *&head) {
  // steps
  // 1. Reverse LL
  // 2. add 1 and add carry
  // 3. reverse again

  // 1.
  reverse(head);
  // 2.
  int carry = 1;
  Node *temp = head;
  while (temp->nextNode != NULL) {
    int totalSum = temp->data + carry;
    int digit = totalSum % 10;
    carry = totalSum / 10;
    temp->data = digit;
    temp = temp->nextNode;

    if (carry == 0) {
      break;
    }
  }

  // process last node and addition of Node
  if (carry != 0) {
    int totalSum = temp->data + carry;
    int digit = totalSum % 10;
    carry = totalSum / 10;
    temp->data = digit;
    if (carry != 0) {
      // new node
      Node *newNode = new Node(carry);
      temp->nextNode = newNode;
    }
  }

  // 3.
  reverse(head);
}

Node *reverseLLInKGroups(Node *head, int k) {
  // base case
  if (head == NULL) {
    return head;
  }

  if (head->nextNode == NULL) {
    return head;
  }

  int len = lenOfLL(head);
  if (len < k) {
    return head;
  }

  // case 1
  Node *prev = NULL;
  Node *curr = head;
  Node *next = curr->nextNode;
  int position = 0;

  while (position < k) {
    // reverse
    position++;
    next = curr->nextNode;
    curr->nextNode = prev;
    prev = curr;
    curr = next;
  }
  Node *nexthead = NULL;
  if (next != NULL) {
    nexthead = reverseLLInKGroups(next, k); // tricky
    head->nextNode = nexthead;              // tricky
  }
  return prev; // tricky
}

Node *removeDuplicatesInSortedLL(Node *&head) {
  if (head == NULL) {
    return head;
  }

  if (head->nextNode == NULL) {
    return head;
  }

  Node *temp = head;

  while (temp != NULL) {
    if (temp->nextNode != NULL && temp->data == temp->nextNode->data) {
      // remove
      Node *duplicateNode = temp->nextNode;
      temp->nextNode = temp->nextNode->nextNode;
      duplicateNode->nextNode = NULL;
      delete duplicateNode;
    } else {
      temp = temp->nextNode;
    }
  }

  return head;
}

int main() {
  // uncomment for remove cycle && startingPointOfCycle
  // Node *head = NULL;
  // Node *tail = NULL;

  // // uncomment for cycle
  // tailInsertionInLL(head, tail, 10);
  // tailInsertionInLL(head, tail, 20);
  // tailInsertionInLL(head, tail, 30);
  // Node *tailCopy = tail;
  // tailInsertionInLL(head, tail, 40);
  // tailInsertionInLL(head, tail, 50);
  // tailInsertionInLL(head, tail, 60);
  // tail->nextNode = tailCopy;

  // printLinkedList(head); goes into infinite loop since a cycle exists

  // hasCycle();

  // startingPointOfCycle(head);

  // removeCycleInLL(head);
  // printLinkedList(head); // prints fine since cycle is removed

  // uncomment for addOne
  // Node *head = NULL;
  // Node *tail = NULL;
  // tailInsertionInLL(head, tail, 9);
  // tailInsertionInLL(head, tail, 9);
  // tailInsertionInLL(head, tail, 9);

  // printLinkedList(head);
  // addOneToLL(head);
  // printLinkedList(head);
  // addOneToLL(head);
  // printLinkedList(head);

  // uncomment for reverse k groups
  // Node *head = NULL;
  // Node *tail = NULL;
  // tailInsertionInLL(head, tail, 10);
  // tailInsertionInLL(head, tail, 20);
  // tailInsertionInLL(head, tail, 30);
  // tailInsertionInLL(head, tail, 40);
  // tailInsertionInLL(head, tail, 50);
  // tailInsertionInLL(head, tail, 60);
  // tailInsertionInLL(head, tail, 70);
  // printLinkedList(head);

  // Node *newHead = reverseLLInKGroups(head, 2);
  // printLinkedList(newHead);

  // uncomment for remove duplicates
  Node *head = NULL;
  Node *tail = NULL;
  tailInsertionInLL(head, tail, 10);
  tailInsertionInLL(head, tail, 20);
  tailInsertionInLL(head, tail, 20);
  tailInsertionInLL(head, tail, 20);
  tailInsertionInLL(head, tail, 30);
  tailInsertionInLL(head, tail, 30);
  tailInsertionInLL(head, tail, 40);
  tailInsertionInLL(head, tail, 50);
  tailInsertionInLL(head, tail, 50);
  tailInsertionInLL(head, tail, 60);
  tailInsertionInLL(head, tail, 70);
  tailInsertionInLL(head, tail, 70);

  printLinkedList(head);
  removeDuplicatesInSortedLL(head);
  printLinkedList(head);

  return 0;
}