## Depth First Search (DFS) and Breadth First Search (BFS) Implementation

### Overview
This repository contains C++ implementations of graph traversal algorithms using **Depth First Search (DFS)** and **Breadth First Search (BFS)**. The graph is represented as an adjacency list using a `vector<list<int>>` structure. These algorithms provide efficient ways to traverse and explore graphs.

### Features
- **Graph Construction**: The graph is constructed using an adjacency list representation for efficient storage and traversal.
- **DFS Traversal**:
  - Explores nodes deeply along each branch before backtracking.
  - Recursively visits all nodes in the connected component starting from a given node.
- **BFS Traversal**:
  - Traverses nodes level by level starting from a given node.
  - Uses a queue to manage the traversal process.

### Applications
- **DFS**:
  - Pathfinding in mazes or puzzles.
  - Detecting cycles in a graph.
  - Solving connectivity problems.
- **BFS**:
  - Shortest path finding in unweighted graphs.
  - Level-order traversal in trees.
  - Network broadcast algorithms.

### Acknowledgments
This project demonstrates fundamental graph traversal algorithms, serving as a foundation for solving various graph-based problems.
