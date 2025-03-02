# Detailed Loop-by-Loop Complexity Analysis

## 1. `printLinkedList(Node *head)`

### Loop Analysis

```cpp
while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->nextNode;
    ++len;
}
```

**Iterations**: Exactly n iterations (where n is the number of nodes in the list)
**Operations per iteration**:

- Print operation: O(1)
- Pointer assignment: O(1)
- Increment operation: O(1)
- Null check: O(1)

**Total operations inside loop**: 4n operations = O(n)
**Operations outside loop**: Initialization and final print statement = O(1)

**Time Complexity**: O(n)
**Space Complexity**: O(1) - just uses a temporary pointer and counter

## 2. `tailInsertionInLL(Node *&head, Node *&tail, int newData)`

### No Loops Present

This function operates in constant time as it doesn't contain any loops.

**Empty list case**:

- Node creation: O(1)
- Head assignment: O(1)
- Tail assignment: O(1)

**Non-empty list case**:

- Node creation: O(1)
- Pointer assignment (tail->nextNode): O(1)
- Tail update: O(1)

**Time Complexity**: O(1)
**Space Complexity**: O(1) - creates exactly one new node

## 3. `findMidUsingFastSlowPointers(Node *head)`

### Loop Analysis

```cpp
while (fast->nextNode != NULL) {
    fast = fast->nextNode;
    if (fast->nextNode != NULL) {
        fast = fast->nextNode;
        slow = slow->nextNode;
        position++;
    }
}
```

**Iterations**: Approximately n/2 iterations (where n is the number of nodes)

- For each iteration, `fast` moves two steps
- The loop terminates when `fast` reaches the end
- If n is the list length, the loop runs n/2 times (for even n) or (n-1)/2 times (for odd n)

**Operations per iteration**:

- First pointer movement: O(1)
- Null check: O(1)
- Second pointer movement (conditional): O(1)
- Slow pointer movement: O(1)
- Counter increment: O(1)

**Total operations inside loop**: 5 × (n/2) operations = O(n)
**Operations outside loop**: Initialization and print statement = O(1)

**Time Complexity**: O(n)
**Space Complexity**: O(1) - uses two pointers and a position counter

## 4. `mergeV2(Node *left, Node *right)`

### Loop Analysis

```cpp
while(left && right) {
    if(left->data <= right->data) {
        mptr->nextNode = left;
        mptr = left;
        left = left->nextNode;
    } else {
        mptr->nextNode = right;
        mptr = right;
        right = right->nextNode;
    }
}
```

**Iterations**: At most (n + m) iterations (where n is the length of `left` and m is the length of `right`)

- Each iteration consumes exactly one node from either `left` or `right`
- The loop terminates when either `left` or `right` becomes NULL

**Operations per iteration**:

- Condition check: O(1)
- Data comparison: O(1)
- Pointer assignments (3 in each branch): O(1)

**Total operations inside loop**: ≤ 5 × (n + m) operations = O(n + m)
**Operations outside loop**:

- Initial checks: O(1)
- Dummy node creation: O(1)
- Remaining list attachment: O(1)

**Time Complexity**: O(n + m)
**Space Complexity**: O(1) - creates one dummy node and uses a few pointers

## 5. `sortList(Node *head)`

### Recursive Analysis

This function doesn't contain explicit loops but uses recursion.

**Base Case**:

- Empty list or single-node list: O(1)

**Recursive Case**:

- Finding middle: O(n) (calls `findMidUsingFastSlowPointers`)
- Dividing the list: O(1)
- Recursive calls: T(n/2) + T(n/2)
- Merging: O(n) (calls `mergeV2`)

**Recurrence Relation**: T(n) = 2T(n/2) + O(n)
**Solution to the recurrence**: T(n) = O(n log n)

**Time Complexity Breakdown by Recursion Level**:

- Level 0 (original list): 1 list of size n → O(n) work
- Level 1: 2 lists of size n/2 → O(n) work
- Level 2: 4 lists of size n/4 → O(n) work
- ...
- Level log(n): n lists of size 1 → O(n) work
- Total levels: log(n)
- Total work: O(n) × log(n) = O(n log n)

**Space Complexity**: O(log n) for the recursion stack

## Main Function Analysis

### Sequence of Operations

1. **List Creation**: 6 calls to `tailInsertionInLL`
   - Each call: O(1)
   - Total: O(1)

2. **First Print**: 1 call to `printLinkedList`
   - Cost: O(n)

3. **Sort**: 1 call to `sortList`
   - Cost: O(n log n)

4. **Second Print**: 1 call to `printLinkedList`
   - Cost: O(n)

**Overall Time Complexity**: O(n log n)

## Total Analysis

### Time Complexity

| Function | Time Complexity | Dominant Factor |
|----------|----------------|-----------------|
| `printLinkedList` | O(n) | While loop traversal |
| `tailInsertionInLL` | O(1) | Constant operations |
| `findMidUsingFastSlowPointers` | O(n) | While loop with fast/slow pointers |
| `mergeV2` | O(n + m) | While loop merging two lists |
| `sortList` | O(n log n) | Recursive divide-and-conquer |
| `main` | O(n log n) | Dominated by sorting operation |

### Space Complexity

| Function | Space Complexity | Dominant Factor |
|----------|-----------------|-----------------|
| `printLinkedList` | O(1) | Fixed variables |
| `tailInsertionInLL` | O(1) | One new node |
| `findMidUsingFastSlowPointers` | O(1) | Fixed variables |
| `mergeV2` | O(1) | One dummy node |
| `sortList` | O(log n) | Recursion stack |
| `main` | O(n) | Linked list storage |

### Detailed Operation Count

- **Total nodes created**: 6 nodes in main + O(log n) dummy nodes in merging
- **Total pointer operations**: O(n log n)
- **Total comparisons**: O(n log n)
- **Total recursion depth**: O(log n)

The overall algorithm has an optimal time complexity of O(n log n) for sorting a linked list, which matches the theoretical lower bound for comparison-based sorting. The space complexity is efficient at O(log n), which is better than many sorting algorithms that require O(n) extra space.
