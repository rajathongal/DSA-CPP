# Queues

- Queue follows FIFO (first in first out) Ordering.
- Queue can be accessed via STL as well.
- Some in built functions are `.front()`, `.back()`, `.size()`, `.empty`.

## Custom Queue notes

- We require two pointers front and back.
- Consider overflow and underflow.
- Push operation -> increment rear and insert at rear position.
- Handle first element cases for push and pop.
- First element case in push increment both front and rear.
- Overflow push case when `rear = size - 1`.
- Underflow pop case when `front == -1 && rear == -1`
- Pop Operation `arr[front] = -1; front++;`
- When `front == rear` single element is present in the Queue.
- When single element is popped `front = -1; rear = -1`.
- Size of Queue `int size = rear - front + 1`;
- Empty Check `rear == -1; front == -1`.
- Queue full check `size - rear == 0 ? true : false`.
- Get front and back with valid index check.

## Notes

- Push will happen at rear/back.
- Pop will happen at front.
- Types of Queue Normal, Circular, Doubly Ended (Deque).
- In Normal Queue Push happens at rear and pop happens at front.
- In **Deque** Push and POP can happen at both ends Rear and Front.
