# Circular Linked List in C++

This repository contains an implementation of a Circular Linked List in C++, offering functionalities to manipulate and interact with the list, including insertion, deletion, searching, and reversal. The code dynamically manages elements while maintaining the circular structure of the list.

## Features

### Insertions
- **Insert at Head**: Add a new node at the beginning of the list.
- **Insert at Tail**: Add a new node at the end of the list.
- **Insert at Index**: Insert a node at a specified index (1-based indexing).

### Deletions
- **Delete at Head**: Remove the node at the head of the list.
- **Delete at Tail**: Remove the node at the tail of the list.
- **Delete at Index**: Delete the node at a specified index.
- **Delete by Value**: Find and remove the first node with a specific value.

### Additional Functionalities
- **Reversing the List**: Reverse the entire list while preserving the circular structure.
- **Searching**: Check if a given value is present in the list.
- **Display**: Output all elements in the list.
- **Size Calculation**: Return the number of nodes in the list.

## Class Structure

- **`ListNode` Class**: Represents an individual node, containing a value and a pointer to the next node.
- **`Circular_Linked_List` Class**: Manages the circular linked list and provides member functions for various operations.

## Conclusion

This implementation of a Circular Linked List in C++ allows for efficient and dynamic element management with support for insertion, deletion, reversal, and searching. The circular structure ensures that the list loops back to the head, making it ideal for applications like round-robin scheduling. This codebase provides a flexible foundation for enhancements or integration into larger projects.

