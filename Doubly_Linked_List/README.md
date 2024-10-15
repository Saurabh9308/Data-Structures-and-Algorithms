Doubly Linked List Implementation in C++

Description:
This repository contains an implementation of a Doubly Linked List in C++ that supports various operations such as insertion, deletion, traversal, reversal, and search. The class also includes functions to check the presence of an element and return the current size of the list.

Features:
1. Insertion:
  a) Insert an element at the head.
  b) Insert an element at the tail.
  c) Insert an element at any given index.

2. Deletion:
  a) Delete an element from the head.
  b) Delete an element from the tail.
  c) Delete an element at any given index.
  d) Delete an element by its value.

3. Traversal: Display the list elements from head to tail.

4. Reversal: Reverse the entire list.

5. Search: Check if a specific element is present in the list.

6. Size Management: Get the length of the list at any time.

Class Structure
ListNode Class: This class represents a node in the Doubly Linked List.

Members:
  a) int val: Value stored in the node.
  b) ListNode* prev: Pointer to the previous node.
  c) ListNode* next: Pointer to the next node.
  
Constructor:
ListNode(int val) initializes the node with a given value and sets prev and next pointers to NULL.

Conclusion:
This implementation of a Doubly Linked List in C++ provides efficient methods for insertion, deletion, traversal, and manipulation of data, making it versatile for various applications. Its flexibility in both forward and backward traversal, along with the ability to reverse the list, offers enhanced control over dynamic data structures.
