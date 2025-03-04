#include <iostream>
#include <map>
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

class Node2D {
public:
  int data;
  Node2D *next;
  Node2D *bottom;

  Node2D(int newData) {
    data = newData;
    next = bottom = nullptr;
  }
};

class NodeV2 {
public:
  int val = 0;
  NodeV2 *next;
  NodeV2 *random;

  NodeV2(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
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
void printLinkedListFromBottom(Node2D *head) {
  Node2D *temp = head; // must make a copy always while tracing
  int len = 0;
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->bottom;
    ++len;
  }
  cout << endl << "Length of LL: " << len << endl;
}

void printLinkedListWithRandomPTR(NodeV2 *head) {
  // First, create a map of node pointers to their indices
  map< NodeV2 *, int > nodeToIndex;
  NodeV2 *temp = head;
  int index = 0;

  // Build the map
  while (temp != NULL) {
    nodeToIndex[temp] = index;
    temp = temp->next;
    index++;
  }

  // Now print the list with random pointers showing indices
  temp = head;
  int len = 0;
  while (temp != NULL) {
    cout << "[" << temp->val << " , ";
    // Check if random pointer is null before accessing its index
    if (temp->random != nullptr) {
      cout << nodeToIndex[temp->random];
    } else {
      cout << "nullptr";
    }
    cout << "], ";
    temp = temp->next;
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

// 2. leetcode 21 merge two sorted Lists
Node *mergeTwoLists(Node *list1, Node *list2) {
  Node *answer = NULL;
  Node *head = NULL;

  Node *ListOneIt = list1;
  Node *ListTwoIt = list2;

  while (ListOneIt != NULL && ListTwoIt != NULL) {

    if (ListOneIt->data > ListTwoIt->data) {
      if (answer == NULL) {
        Node *newNode = new Node(ListTwoIt->data);
        answer = newNode;
        head = answer;
      } else {
        Node *newNode = new Node(ListTwoIt->data);
        answer->nextNode = newNode;
        answer = answer->nextNode;
      }
      // move the listTwoIt
      ListTwoIt = ListTwoIt->nextNode;
    } else {
      if (answer == NULL) {
        Node *newNode = new Node(ListOneIt->data);
        answer = newNode;
        head = answer;
      } else {
        Node *newNode = new Node(ListOneIt->data);
        answer->nextNode = newNode;
        answer = answer->nextNode;
      }
      // move the ListOneIt
      ListOneIt = ListOneIt->nextNode;
    }
  }

  // check if extra elements are still left in either of the LL

  // ListOne
  if (ListOneIt != NULL) {
    while (ListOneIt != NULL) {
      Node *newNode = new Node(ListOneIt->data);
      answer->nextNode = newNode;
      answer = answer->nextNode;
      ListOneIt = ListOneIt->nextNode;
    }
  }

  // ListTwo
  if (ListTwoIt != NULL) {
    while (ListTwoIt != NULL) {
      Node *newNode = new Node(ListTwoIt->data);
      answer->nextNode = newNode;
      answer = answer->nextNode;
      ListTwoIt = ListTwoIt->nextNode;
    }
  }

  return head;
}

Node *mergeV2(Node *left, Node *right) {
  if (left == 0)
    return right;
  if (right == 0)
    return left;

  Node *answer = new Node(-1);
  Node *mptr = answer;

  while (left && right) {
    if (left->data <= right->data) {
      mptr->nextNode = left;
      mptr = left;
      left = left->nextNode;
    } else {
      mptr->nextNode = right;
      mptr = right;
      right = right->nextNode;
    }
  }

  if (left) {
    mptr->nextNode = left;
  }
  if (right) {
    mptr->nextNode = right;
  }

  return answer->nextNode;
}

// 3. GetNode
// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem

void getNodeHelper(Node *head, int &positionFromTail, int &ans) {
  if (head == NULL)
    return;

  getNodeHelper(head->nextNode, positionFromTail, ans);
  if (positionFromTail == 0) {
    ans = head->data;
  }
  positionFromTail--;
}
int getNode(Node *head, int positionFromTail) {
  int ans = -1;
  getNodeHelper(head, positionFromTail, ans);
  return ans;
}

// Intersection of 2 linkedlist leetcode 160
Node *IntersetionOfLL(Node *headA, Node *headB) {

  // make copies of LL recieved
  Node *a = headA;
  Node *b = headB;

  // iterate till one of the ll reaches null or end of any one ll
  while (a->nextNode && b->nextNode) {
    if (a == b) {
      return a;
    }

    a = a->nextNode;
    b = b->nextNode;
  }

  // here we will reach with 2 cases
  // 1. both the LL have reached their end and we need to return null because
  // there is no intersection
  // 2. one of LL has not reached its end so there may exists an intersection

  // 1. both LL have reached end
  // another check needs to be added so that the ending nodes are not same
  if (a->nextNode == 0 && b->nextNode == 0 && a != b)
    return new Node(0);

  // 2. lets check for case where any one LL is bigger
  if (a->nextNode == 0) {
    // if a has reached end then definately b is bigger so
    // we calculate the len of b from where the b is currently right now and
    // skip it

    int skipB = 0;
    while (b->nextNode) { // calculate the length till b has next node
      skipB++;
      b = b->nextNode; // iterate b
    }

    // once we recieve the length lets skip in the head itself
    // note head is also being copied so that the original LL stays intact
    while (skipB--) {
      headB = headB->nextNode;
    }

  } else {
    // a might be the bigger LL
    int skipA = 0;
    while (a->nextNode) {
      skipA++;
      a = a->nextNode;
    }

    while (skipA--) {
      headA = headA->nextNode;
    }
  }

  // now we check till we get a match
  // make sure there is a next node before iterating
  while (headA != headB && headA->nextNode && headB->nextNode) {
    headA = headA->nextNode;
    headB = headB->nextNode;
  }

  // we also need to handle a case where no intersection is present and LL is of
  // variable length
  if (headA->nextNode == 0 && headB->nextNode == 0) {
    return new Node(0);
  }

  return headA;
}

void IntersectionOfLLMain() {

  // case 1 intersection present at variable length
  Node *headOne = NULL;
  Node *headTwo = NULL;
  Node *tailOne = NULL;
  Node *tailTwo = NULL;

  tailInsertionInLL(headOne, tailOne, 1);
  tailInsertionInLL(headOne, tailOne, 2);
  tailInsertionInLL(headOne, tailOne, 3);
  tailInsertionInLL(headOne, tailOne, 4);

  tailInsertionInLL(headTwo, tailTwo, 4);
  tailInsertionInLL(headTwo, tailTwo, 3);

  tailTwo->nextNode = tailOne;

  tailInsertionInLL(headOne, tailOne, 5);
  tailInsertionInLL(headOne, tailOne, 6);
  tailInsertionInLL(headOne, tailOne, 7);

  printLinkedList(headOne);
  printLinkedList(headTwo);

  Node *answer = IntersetionOfLL(headOne, headTwo);
  cout << "Answer for case 1 -> " << answer->data << endl << endl;

  // case 2 intersection not present with variable length
  Node *headThree = NULL;
  Node *headFour = NULL;
  Node *tailThree = NULL;
  Node *tailFour = NULL;

  tailInsertionInLL(headThree, tailThree, 1);
  tailInsertionInLL(headFour, tailFour, 1);
  tailInsertionInLL(headThree, tailThree, 2);
  tailInsertionInLL(headFour, tailFour, 2);
  tailInsertionInLL(headThree, tailThree, 3);
  tailInsertionInLL(headFour, tailFour, 3);
  tailInsertionInLL(headThree, tailThree, 4);
  tailInsertionInLL(headFour, tailFour, 4);
  tailInsertionInLL(headThree, tailThree, 5);
  tailInsertionInLL(headFour, tailFour, 5);
  tailInsertionInLL(headFour, tailFour, 6);

  printLinkedList(headThree);
  printLinkedList(headFour);

  Node *answerTwo = IntersetionOfLL(headThree, headFour);
  cout << "Answer for case 2 -> " << answerTwo->data << endl;
}

Node *findMidUsingFastSlowPointers(Node *head) {
  Node *slow = head;
  Node *fast = head;
  int position = 1;
  while (fast->nextNode != NULL) {
    // move fast once
    fast = fast->nextNode;
    // check if fast is not null
    if (fast->nextNode != NULL) {
      // move fast for 2 nd time
      fast = fast->nextNode;
      // since fast is able to move 2 times
      // move slow once
      slow = slow->nextNode;
      position++;
    }
  }
  cout << "Mid: " << slow->data << " Found at Position: " << position << endl;
  return slow;
}

// Sort list Leetcode 168 or sort list using merge sort
Node *sortList(Node *head) {
  // check if LL is null or has one element
  if (head == 0 || head->nextNode == 0) {
    return head;
  }

  // merge sorting

  // 1. Break into left and right using mid

  // get mid using fast slow ptrs
  Node *mid = findMidUsingFastSlowPointers(head);
  Node *left = head;
  Node *right = mid->nextNode;
  mid->nextNode = 0;

  // 2. sort
  left = sortList(left);
  right = sortList(right);

  Node *mergedLL = mergeTwoLists(left, right);
  return mergedLL;
}

Node2D *mergeRecursively(Node2D *a, Node2D *b) {
  if (!a)
    return b;
  if (!b)
    return a;

  Node2D *answer = 0;
  if (a->data < b->data) {
    answer = a;
    a->bottom = mergeRecursively(a->bottom, b);
  } else {
    answer = b;
    b->bottom = mergeRecursively(a, b->bottom);
  }

  return answer;
}

Node2D *flattenLL(Node2D *root) {
  if (!root)
    return 0;
  Node2D *mergedLL = mergeRecursively(root, flattenLL(root->next));
  return mergedLL;
}

// LC 138 Copy list with random pointer
NodeV2 *nodeMapHelper(NodeV2 *head,
                      unordered_map< NodeV2 *, NodeV2 * > &nodeMap) {
  if (head == 0)
    return 0;
  NodeV2 *newHead = new NodeV2(head->val);
  nodeMap[head] = newHead;
  newHead->next = nodeMapHelper(head->next, nodeMap);

  // map random pointers
  if (head->random) {
    newHead->random = nodeMap[head->random];
  }
  return newHead;
} // this function will create a new LL and a map for old->new node

// method 1
// create a map and return a new LL
NodeV2 *copyRandomList(NodeV2 *head) {
  unordered_map< NodeV2 *, NodeV2 * > nodeMap; // oldNode -> newNode map
  NodeV2 *newHead = nodeMapHelper(head, nodeMap);
  return newHead;
} // TC O(N) SC O(N)

// method 2 merge new and old LL and attach random and delink old LL
// space complexity O(1) tc O(n)
NodeV2 *copyRandomListMethod2(NodeV2 *head) {
  if (head == 0)
    return 0;

  // step 1 clone A -> A'
  NodeV2 *it = head;
  while (it) {
    NodeV2 *clonedNode = new NodeV2(it->val);
    clonedNode->next = it->next;
    it->next = clonedNode;
    it = it->next->next;
  }

  // step 2 assign random pointer links A' with help of old node A
  it = head;
  while (it) {
    NodeV2 *clonedNode = it->next;
    clonedNode->random = it->random ? it->random->next : nullptr;
    it = it->next->next;
  }

  // step 3 detach A' from A for detach old LL from new LL
  it = head;
  NodeV2 *clonedHead = it->next;

  while (it) {
    NodeV2 *clonedNode = it->next;
    it->next = it->next->next;
    if (clonedNode->next) {
      clonedNode->next = clonedNode->next->next;
    }
    it = it->next;
  }
  return clonedHead;
}

// Leet code 61 rotate list
Node *rotateRight(Node *head, int k) {

  if (head == nullptr)
    return nullptr;

  int len = lenOfLL(head);
  int actualKRotations = k % len; // rotation of k=1 is similar to k=6 so modulo
                                  // will give actual rotations required
  if (actualKRotations == 0)
    return head; // the answer will be same as given LL if k=0

  int newLastNodePosition = len - actualKRotations - 1;

  // Move to new last node
  Node *newLastNode = head;
  for (int i = 0; i < newLastNodePosition; i++) {
    newLastNode = newLastNode->nextNode;
  }
  // Store new head
  // store new head and remove next of newlastnode
  Node *newHead = newLastNode->nextNode;

  newLastNode->nextNode = nullptr;
  // lets find the end of new head
  Node *it = newHead;
  while (it->nextNode != nullptr) {
    it = it->nextNode;
  }

  // now by assigning the end of new head to old head the rotated LL is ready
  it->nextNode = head;

  return newHead;
}

int main() {
  // uncomment for 1. GFG Delete n nodes after m nodes
  // Node *headOne = NULL;
  // Node *tailOne = NULL;

  // tailInsertionInLL(headOne, tailOne, 1);
  // tailInsertionInLL(headOne, tailOne, 2);
  // tailInsertionInLL(headOne, tailOne, 3);
  // tailInsertionInLL(headOne, tailOne, 4);
  // tailInsertionInLL(headOne, tailOne, 5);
  // tailInsertionInLL(headOne, tailOne, 6);

  // printLinkedList(headOne);
  // linkDelete(headOne, 5, 2);
  // printLinkedList(headOne);

  // Uncomment for lc 21 merge 2 sorted lists
  // Node *headTwo = NULL;
  // Node *tailTwo = NULL;

  // Node *headThree = NULL;
  // Node *tailThree = NULL;

  // tailInsertionInLL(headTwo, tailTwo, 1);
  // tailInsertionInLL(headTwo, tailTwo, 3);
  // tailInsertionInLL(headTwo, tailTwo, 5);

  // tailInsertionInLL(headThree, tailThree, 2);
  // tailInsertionInLL(headThree, tailThree, 4);
  // tailInsertionInLL(headThree, tailThree, 6);
  // tailInsertionInLL(headThree, tailThree, 7);
  // tailInsertionInLL(headThree, tailThree, 8);

  // Node *headOfMergedList = mergeTwoLists(headTwo, headThree);
  // printLinkedList(headOfMergedList);

  // Node *headFour = NULL;
  // Node *tailFour = NULL;
  // tailInsertionInLL(headFour, tailFour, 1);
  // tailInsertionInLL(headFour, tailFour, 2);
  // tailInsertionInLL(headFour, tailFour, 3);
  // tailInsertionInLL(headFour, tailFour, 4);
  // tailInsertionInLL(headFour, tailFour, 5);
  // tailInsertionInLL(headFour, tailFour, 6);
  // cout << getNode(headFour, 2) << endl;

  // uncomment for leet code 160 intersection of LL
  // IntersectionOfLLMain();

  // Uncomment for mergesort LL
  // Node *head = NULL;
  // Node *tail = NULL;

  // tailInsertionInLL(head, tail, 6);
  // tailInsertionInLL(head, tail, 4);
  // tailInsertionInLL(head, tail, 3);
  // tailInsertionInLL(head, tail, 2);
  // tailInsertionInLL(head, tail, 5);
  // tailInsertionInLL(head, tail, 1);
  // printLinkedList(head);
  // Node *answerHead = sortList(head);
  // printLinkedList(answerHead);

  // Uncomment for flatten LinkedList
  // https://www.geeksforgeeks.org/flattening-a-linked-list/
  // Create a hard-coded linked list:
  //   5 -> 10 -> 19 -> 28
  //   |    |     |
  //   V    V     V
  //   7    20    22
  //   |          |
  //   V          V
  //   8          50
  //   |
  //   V
  //   30

  // Node2D *head = new Node2D(5);
  // head->bottom = new Node2D(7);
  // head->bottom->bottom = new Node2D(8);
  // head->bottom->bottom->bottom = new Node2D(30);

  // head->next = new Node2D(10);
  // head->next->bottom = new Node2D(20);

  // head->next->next = new Node2D(19);
  // head->next->next->bottom = new Node2D(22);
  // head->next->next->bottom->bottom = new Node2D(50);

  // head->next->next->next = new Node2D(28);

  // Node2D *answer = flattenLL(head);
  // printLinkedListFromBottom(answer);

  // Uncomment for copy using random pointer leetcode 138
  // NodeV2 *head = new NodeV2(7);
  // head->random = nullptr;

  // head->next = new NodeV2(13);
  // head->next->random = head;

  // head->next->next = new NodeV2(11);
  // head->next->next->next = new NodeV2(10);
  // head->next->next->next->random = head->next->next;

  // head->next->next->next->next = new NodeV2(1);
  // head->next->next->next->next->random = head;

  // head->next->next->random = head->next->next->next->next;
  // cout << endl << "Method 1" << endl;
  // printLinkedListWithRandomPTR(head); // before copy
  // NodeV2 *answerHead = copyRandomList(head);
  // printLinkedListWithRandomPTR(answerHead); // after copy

  // cout << endl << "Method 2" << endl;
  // answerHead = copyRandomListMethod2(head);
  // printLinkedListWithRandomPTR(answerHead); // after copy

  // uncomment for leet code 61 rotateRight list
  Node *headOne = NULL;
  Node *tailOne = NULL;
  int k = 4;
  tailInsertionInLL(headOne, tailOne, 1);
  tailInsertionInLL(headOne, tailOne, 2);
  tailInsertionInLL(headOne, tailOne, 3);
  tailInsertionInLL(headOne, tailOne, 4);
  tailInsertionInLL(headOne, tailOne, 5);
  tailInsertionInLL(headOne, tailOne, 6);
  printLinkedList(headOne);
  Node *answerHead = rotateRight(headOne, k);
  printLinkedList(answerHead);

  return 0;
}