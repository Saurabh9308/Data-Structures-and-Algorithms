# Doubly Linked List Implementation in C++

This repository contains an implementation of a Doubly Linked List in C++, providing a variety of operations such as insertion, deletion, traversal, reversal, and search. This class also includes functions to check for the presence of an element and determine the current size of the list.

## Features

### 1. Insertion
- **Insert at Head**: Adds an element at the beginning of the list.
- **Insert at Tail**: Adds an element at the end of the list.
- **Insert at Index**: Inserts an element at a specified index.

### 2. Deletion
- **Delete at Head**: Removes the element at the head.
- **Delete at Tail**: Removes the element at the tail.
- **Delete at Index**: Removes the element at a specified index.
- **Delete by Value**: Removes the first occurrence of a specified value.

### 3. Traversal
- **Forward Traversal**: Displays the list elements from head to tail.

### 4. Reversal
- **Reverse the List**: Reverses the entire list, allowing traversal from tail to head.

### 5. Search
- **Element Presence Check**: Verifies if a specific element exists in the list.

### 6. Size Management
- **List Length**: Returns the current number of nodes in the list.

## Class Structure

### `ListNode` Class
Represents a node in the Doubly Linked List, with the following members:
- **int val**: Holds the value of the node.
- **ListNode* prev**: Pointer to the previous node.
- **ListNode* next**: Pointer to the next node.

**Constructor**: `ListNode(int val)` initializes the node with the given value and sets `prev` and `next` pointers to `NULL`.

## Conclusion

This C++ implementation of a Doubly Linked List offers efficient methods for dynamic data management, supporting both forward and backward traversal. The structure's ability to reverse the list enhances flexibility and control, making it ideal for a variety of applications.

