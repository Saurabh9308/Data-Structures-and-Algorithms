Stack Implementation using Array and Linked List

Description
This repository contains the implementation of the Stack data structure using two different methods:

  1. Array-based implementation
  2. Linked List-based implementation

Stacks are linear data structures that follow the Last In, First Out (LIFO) principle, where elements can only be added or removed from one end, referred to as the top of the stack.

Features:
Push: Adds an element to the top of the stack.
Pop: Removes the top element from the stack.
Top: Retrieves the top element without removing it.
isEmpty: Checks if the stack is empty.
Size: Returns the number of elements in the stack.


Implementations:

1. Stack Using Array
  a) A fixed-size array is used to store stack elements.
  b) The top index is updated during push and pop operations.
  c) The array implementation is simple but limited by the predefined size of the array.

2. Stack Using Linked List
  a) A dynamic linked list is used to store stack elements.
  b) Each node contains data and a reference to the next node.
  c) This approach allows for a stack of dynamic size.
