# Round Trip II

[Problem Link](https://cses.fi/problemset/task/1678) | [Solution Link](../../solutions/04_Graph_Algorithms/14_1678_Round_Trip_II.cpp)

## TL;DR

The problem involves finding a cycle in a directed graph where all intermediate nodes are distinct. The solution uses Depth-First Search (DFS) with a visitation state (`unvisited`, `visiting`, `visited`) to detect cycles. If a cycle is found, the path is reconstructed and printed; otherwise, "IMPOSSIBLE" is returned. The algorithm runs in $O(n + m)$ time, where $n$ is the number of nodes and $m$ is the number of edges.

---

## Problem Overview

The task is to find a round trip in a directed graph, which starts and ends at the same city, with all intermediate cities distinct. If such a cycle exists, the program should output the cycle's length and the cities in the order they are visited. If no cycle exists, the output should be "IMPOSSIBLE".

### Input:
- $n$: Number of cities (nodes).
- $m$: Number of flight connections (edges).
- $m$ pairs of integers $(a, b)$ representing directed edges from city $a$ to city $b$.

### Output:
- If a cycle exists, output the number of cities in the cycle and the sequence of cities.
- If no cycle exists, output "IMPOSSIBLE".

---

## Solution Approach

### Key Idea
The problem is solved using **DFS with cycle detection**. The algorithm maintains a visitation state for each node:
1. **`unvisited`**: Node has not been visited yet.
2. **`visiting`**: Node is currently being explored (part of the current DFS path).
3. **`visited`**: Node has been fully explored (all its neighbors have been processed).

A cycle is detected when a node in the `visiting` state is encountered during DFS traversal.

### Steps
1. **Graph Representation**:
   - The graph is represented as an adjacency list.
   - Input edges are read and stored in this structure.

2. **Cycle Detection**:
   - Perform DFS from each unvisited node.
   - Maintain a `path` vector to keep track of the current DFS path.
   - If a node in the `visiting` state is encountered, a cycle is detected. The cycle is reconstructed by finding the repeated node in the `path` vector.

3. **Output**:
   - If a cycle is found, output its length and the sequence of nodes.
   - If no cycle is found after processing all nodes, output "IMPOSSIBLE".

### Implementation Highlights
- **DFS with State Tracking**:
  - The `visitState` array tracks the state of each node.
  - The `path` vector helps reconstruct the cycle when detected.
- **Cycle Reconstruction**:
  - When a cycle is detected, the repeated node marks the start of the cycle.
  - The cycle is extracted from the `path` vector by identifying the first occurrence of the repeated node.

---

## Key Learning Points

1. **Cycle Detection in Directed Graphs**:
   - Using DFS with a `visiting` state is a standard approach to detect cycles in directed graphs.
   - This method avoids the need for additional data structures like a stack for backtracking.

2. **Graph Representation**:
   - Adjacency lists are efficient for sparse graphs, as they reduce memory usage and improve traversal efficiency.

3. **Path Reconstruction**:
   - Maintaining a `path` vector during DFS allows easy reconstruction of cycles when detected.

4. **State Management**:
   - The use of three states (`unvisited`, `visiting`, `visited`) ensures that nodes are processed efficiently without redundant work.

---

## Common Pitfalls

1. **Incorrect Cycle Reconstruction**:
   - Forgetting to identify the start of the cycle in the `path` vector can lead to incorrect results.
   - Ensure the cycle is extracted correctly by finding the first occurrence of the repeated node.

2. **Handling Disconnected Graphs**:
   - The graph may not be fully connected. Ensure DFS is initiated from all unvisited nodes.

3. **Edge Cases**:
   - Graphs with no edges or a single node should be handled correctly.
   - Self-loops (e.g., an edge from a node to itself) should also be considered as valid cycles.

4. **Memory Limits**:
   - With $n \leq 10^5$ and $m \leq 2 \cdot 10^5$, ensure the adjacency list and other data structures fit within the memory constraints.

---

## Complexity

### Time Complexity
- **Graph Construction**: $O(m)$, where $m$ is the number of edges.
- **DFS Traversal**: $O(n + m)$, as each node and edge is processed once.
- **Cycle Reconstruction**: $O(k)$, where $k$ is the length of the cycle (bounded by $n$).

Overall: **$O(n + m)$**

### Space Complexity
- **Graph Storage**: $O(n + m)$ for the adjacency list.
- **Visit State and Path**: $O(n)$.
- Total: **$O(n + m)$**

---

## Alternative Approaches

1. **Kahn's Algorithm**:
   - Use topological sorting to detect cycles. If the graph cannot be fully sorted, a cycle exists.
   - However, this approach does not directly reconstruct the cycle.

2. **Union-Find**:
   - For undirected graphs, Union-Find can detect cycles efficiently.
   - However, it is less suited for directed graphs, as it does not handle directionality.

3. **Floyd-Warshall Algorithm**:
   - For small graphs, the Floyd-Warshall algorithm can detect cycles by checking for negative-weight cycles in a weighted graph.
   - This is not efficient for large, sparse graphs.

---

## Extended Learning

1. **Tarjan's Algorithm**:
   - Learn about Tarjan's algorithm for finding strongly connected components (SCCs), which can also help in detecting cycles in directed graphs.

2. **Topological Sorting**:
   - Understand how topological sorting can be used to detect cycles in directed acyclic graphs (DAGs).

3. **Graph Traversal Techniques**:
   - Explore BFS-based approaches for cycle detection and path reconstruction.

---

## Tips for Similar Problems

1. **Recognizing Cycle Detection Problems**:
   - Look for keywords like "cycle", "round trip", or "repeated path" in the problem statement.

2. **Directed vs. Undirected Graphs**:
   - Understand the differences in cycle detection techniques for directed and undirected graphs.

3. **Efficient Graph Representation**:
   - Use adjacency lists for sparse graphs and adjacency matrices for dense graphs.

4. **State Tracking**:
   - Use visitation states (`unvisited`, `visiting`, `visited`) to avoid redundant work and detect cycles efficiently.

5. **Path Reconstruction**:
   - Maintain a path or parent array during traversal to reconstruct cycles or paths as needed.