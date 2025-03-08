# Stacks

Stack is a datastructure which follow primarily LIFO (Last in first out) ordering. Some terminolgies to remember -

1. Underflow - when stack is empty and trying to pop.
2. Overflow - when stack is full and trying to insert.

Stack can also be accessed using STL Lib of C++ using header `#include <stack>`.

```c++

// Stack Creation
#include <stack>

Stack<int> st;
Stack<char> stc;
Stack<Node*> stLL;

st.push(10); // Push 
st.pop(); // Pop
st.size(); // Size of Stack 
st.empty(); // Is stack empty  
st.top(); // return top element of stack
```

## Read more about stack from below

[Stack Documentation](https://en.cppreference.com/w/cpp/container/stack)

## Take note

1. Always add condition for overflow and underflow while implimenting with Stack.
2. Stack implementation is a must to know using different datastructures.
3. Any operation which requires reverse of its input try to use stack.
4. Stack and Recursion are kind of similar pattern but not the same.
5. Finding mid method can vary for even and odd size.
6. Using backtracking can help.
