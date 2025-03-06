# Building Teams

[Problem Link](https://cses.fi/problemset/task/1668) | [Solution Link](../../solutions/04_Graph_Algorithms/05_1668_Building_Teams.cpp)

## TL;DR

The problem is about dividing pupils into two teams such that no two friends are on the same team. This is a classic bipartite graph problem. The solution uses Breadth-First Search (BFS) to attempt to color the graph with two colors. If a conflict is detected during the coloring process, the output is "IMPOSSIBLE". Otherwise, the team assignments are printed.

---

## Problem Overview

The task is to divide $n$ pupils into two teams based on $m$ friendship relations such that no two pupils in the same team are friends. The problem can be represented as a graph where pupils are nodes and friendships are edges. The goal is to determine if the graph is bipartite (can be colored with two colors) and, if so, output a valid coloring.

### Key Constraints:
- $1 \leq n \leq 10^5$ (number of pupils/nodes)
- $1 \leq m \leq 2 \cdot 10^5$ (number of friendships/edges)

---

## Solution Approach

### Graph Representation
The problem is modeled as an **undirected graph**:
- Nodes represent pupils.
- Edges represent friendships.

The graph is stored as an adjacency list for efficient traversal.

### Bipartite Graph Check
The solution uses BFS to check if the graph is bipartite:
1. **Coloring the Graph**: Each node is assigned one of two colors (1 or 2). This corresponds to assigning pupils to one of the two teams.
2. **Conflict Detection**: During BFS, if a neighboring node has the same color as the current node, the graph is not bipartite, and the output is "IMPOSSIBLE".
3. **Disconnected Components**: Since the graph may not be connected, the BFS is initiated from every unvisited node to ensure all components are processed.

### BFS Implementation
- A queue is used to traverse the graph level by level.
- Each node is assigned a color opposite to its parent.
- If a conflict is found (neighbor has the same color), the process terminates early.

### Output
- If the graph is bipartite, the colors (1 or 2) of all nodes are printed.
- If not, "IMPOSSIBLE" is printed.

---

## Key Learning Points

1. **Bipartite Graphs**:
   - A graph is bipartite if it can be colored with two colors such that no two adjacent nodes share the same color.
   - This is equivalent to dividing the graph's nodes into two disjoint sets.

2. **Graph Traversal**:
   - BFS is a natural choice for level-wise traversal and coloring in bipartite graph problems.
   - DFS can also be used, but BFS is often easier to implement for this purpose.

3. **Handling Disconnected Graphs**:
   - Always account for disconnected components in graph problems by iterating through all nodes and starting a new traversal for unvisited nodes.

4. **Conflict Detection**:
   - Checking for conflicts during traversal is key to determining if a graph is bipartite.

---

## Common Pitfalls

1. **Not Handling Disconnected Components**:
   - Forgetting to process all components of the graph can lead to incorrect results.

2. **Incorrect Conflict Check**:
   - Failing to properly check for color conflicts during traversal can result in false positives.

3. **Indexing Errors**:
   - Ensure the graph is 1-indexed or 0-indexed consistently throughout the implementation.

4. **Memory Usage**:
   - Using inefficient data structures for large graphs can lead to memory issues.

---

## Complexity

### Time Complexity
- **Graph Construction**: $O(m)$, where $m$ is the number of edges.
- **BFS Traversal**: $O(n + m)$, where $n$ is the number of nodes and $m$ is the number of edges.
- Total: $O(n + m)$.

### Space Complexity
- **Graph Storage**: $O(n + m)$ for the adjacency list.
- **Auxiliary Storage**: $O(n)$ for the `group` array and BFS queue.
- Total: $O(n + m)$.

---

## Alternative Approaches

1. **DFS-Based Coloring**:
   - Use Depth-First Search (DFS) instead of BFS to color the graph. The logic for conflict detection remains the same.

2. **Union-Find**:
   - Use a union-find (disjoint set) data structure to group nodes and check for conflicts. This approach is less intuitive for bipartite graph problems but can be adapted.

3. **Matrix Representation**:
   - Represent the graph as an adjacency matrix instead of a list. This is less efficient for sparse graphs but can simplify implementation for smaller inputs.

---

## Extended Learning

1. **Graph Coloring**:
   - Learn about graph coloring problems, including $k$-coloring and chromatic numbers.

2. **Bipartite Matching**:
   - Explore advanced applications of bipartite graphs, such as maximum bipartite matching.

3. **Planar Graphs**:
   - Study planar graphs, which are always 2-colorable under certain conditions.

4. **DFS vs BFS**:
   - Understand the trade-offs between DFS and BFS for graph traversal.

---

## Tips for Similar Problems

1. **Recognize Bipartite Graph Problems**:
   - Look for problems involving partitioning nodes into two groups with constraints on edges.

2. **Start with Small Examples**:
   - Test your understanding of the problem by manually solving small cases.

3. **Use BFS for Level-Wise Traversal**:
   - BFS is often easier to implement and debug for bipartite graph problems.

4. **Handle Edge Cases**:
   - Consider disconnected graphs, single-node graphs, and graphs with no edges.

5. **Optimize for Large Inputs**:
   - Use adjacency lists and avoid unnecessary operations to handle constraints efficiently.