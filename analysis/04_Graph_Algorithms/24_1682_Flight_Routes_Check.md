# Flight Routes Check

[Problem Link](https://cses.fi/problemset/task/1682) | [Solution Link](../../solutions/04_Graph_Algorithms/24_1682_Flight_Routes_Check.cpp)

## TL;DR

The problem requires checking if a directed graph is strongly connected, meaning there is a path between any two nodes in both directions. The solution involves performing two Depth First Searches (DFS): one on the original graph and one on the reversed graph. If all nodes are reachable in both cases, the graph is strongly connected; otherwise, it is not, and we identify a pair of nodes that demonstrate this.

---

## Problem Overview

The task is to determine if a directed graph with $n$ nodes and $m$ edges is **strongly connected**. A graph is strongly connected if, for every pair of nodes $a$ and $b$, there exists a directed path from $a$ to $b$ and from $b$ to $a$. If the graph is not strongly connected, we must output "NO" and provide an example of two cities $a$ and $b$ such that there is no path from $a$ to $b$ or from $b$ to $a$.

### Input:
- $n$ (number of nodes) and $m$ (number of edges).
- $m$ directed edges $(a, b)$.

### Output:
- "YES" if the graph is strongly connected.
- Otherwise, "NO" and two cities $a$ and $b$ such that one is not reachable from the other.

---

## Solution Approach

### Key Idea:
To check if the graph is strongly connected:
1. Perform a DFS from an arbitrary node (e.g., node 1) on the original graph to check if all nodes are reachable.
2. Reverse the graph (reverse all edges) and perform another DFS from the same node. This checks if all nodes can reach the starting node.

If both DFS traversals visit all nodes, the graph is strongly connected. Otherwise, it is not, and we can identify a pair of nodes that demonstrate the lack of connectivity.

### Steps:
1. **Graph Representation**:
   - Represent the graph using adjacency lists for both the original graph and its reverse.

2. **First DFS (Original Graph)**:
   - Start a DFS from node 1 and mark all reachable nodes. If some nodes are not visited, the graph is not strongly connected.

3. **Second DFS (Reversed Graph)**:
   - Reverse the graph by reversing all edges.
   - Perform a DFS from node 1 on the reversed graph. If some nodes are not visited, the graph is not strongly connected.

4. **Output**:
   - If both DFS traversals visit all nodes, print "YES".
   - Otherwise, print "NO" and output a pair of nodes $(a, b)$ where one is not reachable from the other. For example:
     - If node $x$ is not visited in the first DFS, there is no path from node 1 to $x$.
     - If node $y$ is not visited in the second DFS, there is no path from $y$ to node 1.

---

## Key Learning Points

1. **Strong Connectivity**:
   - A graph is strongly connected if every node can reach every other node and vice versa.
   - This property can be efficiently checked using two DFS traversals.

2. **Graph Reversal**:
   - Reversing a graph involves reversing the direction of all edges. This is useful for checking reachability in the opposite direction.

3. **DFS for Reachability**:
   - DFS is a powerful tool for exploring connectivity in graphs. By marking visited nodes, we can determine which nodes are reachable from a given starting point.

4. **Adjacency List Representation**:
   - For large graphs, adjacency lists are more memory-efficient than adjacency matrices.

---

## Common Pitfalls

1. **Forgetting to Reverse the Graph**:
   - Only checking reachability in one direction (original graph) is insufficient. Both directions must be checked.

2. **Disconnected Graph**:
   - If the graph is disconnected (e.g., no edges), ensure the algorithm correctly identifies that it is not strongly connected.

3. **Incorrect Node Pair**:
   - When outputting a pair of nodes $(a, b)$, ensure that $a$ cannot reach $b$ or vice versa, depending on the DFS results.

4. **Handling Large Inputs**:
   - With constraints up to $n = 10^5$ and $m = 2 \cdot 10^5$, ensure the implementation is efficient and avoids unnecessary operations.

---

## Complexity

### Time Complexity:
1. **Graph Construction**:
   - Building adjacency lists for the original and reversed graphs takes $O(m)$.

2. **DFS Traversals**:
   - Each DFS traversal visits all nodes and edges, taking $O(n + m)$.

Overall time complexity: $O(n + m)$.

### Space Complexity:
1. **Graph Storage**:
   - Storing adjacency lists for the original and reversed graphs requires $O(n + m)$.

2. **Visited Arrays**:
   - Two arrays of size $n$ are used for marking visited nodes during DFS.

Overall space complexity: $O(n + m)$.

---

## Alternative Approaches

1. **Kosaraju's Algorithm**:
   - This algorithm also checks strong connectivity using two DFS traversals but involves finding strongly connected components (SCCs) explicitly.

2. **Tarjan's Algorithm**:
   - Tarjan's algorithm can find SCCs in a single DFS traversal. If the graph has only one SCC, it is strongly connected.

3. **Union-Find**:
   - Use a union-find data structure to track connected components. However, this approach is less efficient for directed graphs.

---

## Extended Learning

1. **Strongly Connected Components (SCCs)**:
   - Learn about algorithms like Kosaraju's and Tarjan's for finding SCCs, which are closely related to this problem.

2. **Graph Reversal**:
   - Understanding graph reversal is crucial for problems involving reachability in directed graphs.

3. **Applications of Strong Connectivity**:
   - Strong connectivity is used in network design, transportation systems, and circuit analysis.

---

## Tips for Similar Problems

1. **Recognizing Strong Connectivity Problems**:
   - Look for keywords like "reachability," "strongly connected," or "path between all nodes."

2. **Efficient Graph Traversals**:
   - Use DFS or BFS for exploring connectivity. Ensure you understand how to implement these algorithms efficiently.

3. **Handling Large Graphs**:
   - Use adjacency lists and avoid redundant computations to handle large inputs within time limits.

4. **Graph Reversal**:
   - Be prepared to reverse a graph when checking bidirectional properties or reachability in the opposite direction.