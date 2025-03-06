# Round Trip

[Problem Link](https://cses.fi/problemset/task/1669) | [Solution Link](../../solutions/04_Graph_Algorithms/06_1669_Round_Trip.cpp)

## TL;DR

The problem involves finding a cycle in an undirected graph where no intermediate city is repeated. The solution uses Depth First Search (DFS) to detect cycles by tracking visited nodes and parent-child relationships. If a cycle is found, the path is reconstructed and printed; otherwise, "IMPOSSIBLE" is returned. The approach is efficient, with a time complexity of $O(n + m)$.

---

## Problem Overview

The task is to find a "round trip" in a graph, which is essentially a cycle that starts and ends at the same city. The graph is undirected, and the cycle must pass through at least three cities. If no such cycle exists, the output should be "IMPOSSIBLE."

### Input:
- $n$ cities (nodes) and $m$ roads (edges).
- Each road connects two distinct cities.

### Output:
- If a cycle exists, output the number of cities in the cycle and the sequence of cities in the cycle.
- Otherwise, output "IMPOSSIBLE."

### Constraints:
- $1 \leq n \leq 10^5$
- $1 \leq m \leq 2 \cdot 10^5$

---

## Solution Approach

### Key Idea:
The problem boils down to detecting a cycle in an undirected graph. DFS is used to traverse the graph while keeping track of visited nodes and parent-child relationships to detect back edges, which indicate a cycle.

### Steps:

1. **Graph Representation**:
   - Use an adjacency list to represent the graph. This is efficient in terms of both time and space for sparse graphs.

2. **DFS for Cycle Detection**:
   - Traverse the graph using DFS.
   - Maintain a `dist` array to track visited nodes. If a node is revisited during DFS and it is not the direct parent of the current node, a cycle is detected.
   - Use a `prev` array to store the parent of each node, which helps reconstruct the cycle.

3. **Cycle Reconstruction**:
   - Once a cycle is detected, backtrack using the `prev` array to collect the nodes in the cycle.
   - Ensure the cycle starts and ends at the same node.

4. **Output**:
   - If a cycle is found, print its length and the sequence of nodes.
   - If no cycle exists, print "IMPOSSIBLE."

### Key Implementation Details:
- **Cycle Detection**:
  - A back edge in DFS (an edge connecting a node to an ancestor in the DFS tree) indicates a cycle.
  - To avoid false positives, ensure the back edge does not point to the immediate parent of the current node.

- **Cycle Reconstruction**:
  - Start from the node where the cycle was detected and trace back using the `prev` array until the starting node of the cycle is reached.

---

## Key Learning Points

1. **Cycle Detection in Undirected Graphs**:
   - Back edges in DFS are a reliable way to detect cycles in undirected graphs.
   - Use parent-child relationships to differentiate between valid back edges and edges pointing to the immediate parent.

2. **Graph Representation**:
   - Adjacency lists are efficient for representing sparse graphs, especially when $m \ll n^2$.

3. **DFS Traversal**:
   - DFS is a powerful tool for exploring connected components and detecting cycles in graphs.

4. **Path Reconstruction**:
   - Using a parent array during DFS allows efficient reconstruction of paths or cycles.

---

## Common Pitfalls

1. **False Positives in Cycle Detection**:
   - Not checking if the back edge points to the immediate parent can lead to incorrect cycle detection.

2. **Disconnected Graphs**:
   - Ensure all connected components are explored. Start a new DFS from every unvisited node.

3. **Cycle Length**:
   - Ensure the cycle contains at least three nodes. A cycle involving only two nodes (e.g., $a \leftrightarrow b$) is invalid for this problem.

4. **Edge Cases**:
   - Handle cases with no edges, multiple disconnected components, or graphs with no cycles.

---

## Complexity

### Time Complexity:
- **Graph Construction**: $O(m)$ (to build the adjacency list).
- **DFS Traversal**: $O(n + m)$ (each node and edge is visited once).

Overall: $O(n + m)$.

### Space Complexity:
- **Graph Storage**: $O(n + m)$ (adjacency list).
- **Auxiliary Arrays**: $O(n)$ for `dist` and `prev`.

Overall: $O(n + m)$.

---

## Alternative Approaches

1. **Breadth First Search (BFS)**:
   - BFS can also detect cycles in undirected graphs by checking for back edges. However, reconstructing the cycle may be less intuitive compared to DFS.

2. **Union-Find (Disjoint Set Union)**:
   - Use Union-Find to detect cycles during edge insertion. This approach is efficient for offline queries but does not easily allow cycle reconstruction.

3. **Floyd-Warshall for Small Graphs**:
   - For small graphs, an all-pairs shortest path algorithm like Floyd-Warshall can identify cycles. However, it is computationally expensive ($O(n^3)$) and impractical for large graphs.

---

## Extended Learning

1. **Cycle Detection in Directed Graphs**:
   - In directed graphs, cycles are detected using DFS with an additional "recursion stack" or by checking for strongly connected components.

2. **Graph Traversal Techniques**:
   - Explore other traversal techniques like BFS and their applications in cycle detection, shortest paths, and connected components.

3. **Union-Find**:
   - Learn how Union-Find can be used for cycle detection and other graph problems like Kruskal's algorithm for Minimum Spanning Tree.

---

## Tips for Similar Problems

1. **Recognizing Cycle Detection Problems**:
   - Look for keywords like "round trip," "cycle," or "loop" in the problem description.

2. **Graph Representation**:
   - Use adjacency lists for sparse graphs and adjacency matrices for dense graphs.

3. **DFS/BFS for Traversal**:
   - Understand when to use DFS (e.g., for path reconstruction) and BFS (e.g., for shortest paths).

4. **Parent Tracking**:
   - Always track parent-child relationships in DFS to reconstruct paths or detect cycles.

5. **Edge Cases**:
   - Test solutions on edge cases like disconnected graphs, single-node graphs, and graphs with no edges.