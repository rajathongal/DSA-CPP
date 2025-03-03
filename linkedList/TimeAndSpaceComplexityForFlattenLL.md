# Space and Time Complexity Analysis

## Node2D Class

- **Space Complexity**: O(1) per node
  - Each node stores:
    - One integer (`data`)
    - Two pointers (`next` and `bottom`)
  - Fixed memory per node regardless of input size

## printLinkedListFromBottom Function

- **Time Complexity**: O(n)
  - Where n is the number of nodes in the bottom linked list
  - The function traverses each node in the bottom linked list once with this loop:

    ```cpp
    while (temp != NULL) {
        // O(1) operations inside loop
        temp = temp->bottom;
    }
    ```

  - Each iteration performs constant time (O(1)) operations

- **Space Complexity**: O(1)
  - Only uses a single temporary pointer variable `temp`
  - A single integer variable `len`
  - No recursive calls or dynamic data structures

## mergeRecursively Function

- **Time Complexity**: O(n + m)
  - Where n and m are the lengths of lists a and b respectively
  - Each recursive call processes exactly one node
  - Each node from both lists is visited exactly once
  - The base case checks are O(1)
  - The comparison and pointer assignments are O(1)

- **Space Complexity**: O(n + m) for the recursion stack
  - In worst case (when lists don't have many common elements), the recursion depth will be proportional to the combined length of both lists
  - Each recursive call adds one frame to the call stack
  - Maximum stack depth is O(n + m)

## flattenLL Function

- **Time Complexity**: O(N *M* log(K))
  - Where:
    - N is the total number of nodes in the entire structure
    - M is the average length of each vertical linked list
    - K is the number of horizontal nodes (number of linked lists)
  
  - Detailed calculation:
    1. The function recursively calls itself for each horizontal node (K times)
    2. For each recursion level, we merge two lists of average length M
    3. The recursive merge operation takes O(M) time
    4. When we have K lists, merging them takes O(M * log(K)) time using the divide-and-conquer approach pattern seen in the recursive flattening
    5. Overall complexity: O(N *M* log(K))

- **Space Complexity**: O(K) for the recursion stack
  - The maximum depth of recursion is proportional to K (number of horizontal nodes)
  - Each recursive call adds one frame to the call stack
  - This does not include the space for the nodes themselves (which is O(N))

## main Function

- **Time Complexity**: O(1) for creation + O(N *M* log(K)) for flattenLL
  - Creating the hard-coded linked list: O(1) as it's a fixed structure
  - Calling flattenLL: O(N *M* log(K)) as analyzed above
  - Calling printLinkedListFromBottom: O(N)
  - Overall dominated by flattenLL: O(N *M* log(K))

- **Space Complexity**: O(N) + O(K)
  - O(N) for all nodes in the data structure
  - O(K) for the recursion stack in flattenLL
  - Overall: O(N + K), which is effectively O(N) since K ≤ N

## Overall Program Analysis

- **Time Complexity**: O(N *M* log(K))
  - Dominated by the flattening operation
  - In the context of the example, it may not look very complex, but for larger inputs, this complexity would be significant

- **Space Complexity**: O(N + K)
  - O(N) for storing all the nodes
  - O(K) for the recursion stack
  - In practice, this is O(N) since K is typically much smaller than N

The most important factor affecting performance is the flattenLL function with its recursive merging approach, which has a non-trivial time complexity of O(N *M* log(K)).
