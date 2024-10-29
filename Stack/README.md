# Stack Implementation Using Array and Linked List in C++

## Description
This repository provides an implementation of the Stack data structure using two approaches:

1. **Array-based implementation**
2. **Linked List-based implementation**

A stack is a linear data structure that follows the Last In, First Out (LIFO) principle, where elements are added and removed from only one end, called the "top" of the stack.

## Features
- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes the top element from the stack.
- **Top**: Retrieves the top element without removing it.
- **isEmpty**: Checks if the stack is empty.
- **Size**: Returns the current number of elements in the stack.

## Implementations

### 1. Stack Using Array
- A fixed-size array is used to store stack elements.
- The top index is updated during push and pop operations.
- This implementation is simple but limited by the predefined size of the array.

### 2. Stack Using Linked List
- A dynamic linked list is used to store stack elements.
- Each node contains data and a reference to the next node.
- This approach allows for a stack of dynamic size without a predefined limit.

## Conclusion
This project demonstrates two different ways to implement a stack, showcasing both fixed-size and dynamic approaches. The array-based stack is efficient and straightforward, while the linked list-based stack offers flexibility with dynamic resizing. This implementation serves as a practical reference for understanding stacks and their operations.
