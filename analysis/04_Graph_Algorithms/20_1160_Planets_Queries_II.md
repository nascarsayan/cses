# Planets Queries II

[Problem Link](https://cses.fi/problemset/task/1160) | [Solution Link](../../solutions/04_Graph_Algorithms/20_1160_Planets_Queries_II.cpp)

## TL;DR

The problem involves finding the minimum number of teleportations required to travel between two planets in a graph where each node has exactly one outgoing edge. The solution uses **cycle detection** and **preprocessing with binary lifting** to efficiently handle up to $2 \cdot 10^5$ queries. If a destination is unreachable, the query returns $-1$.

---

## Problem Overview

The problem is set on a directed graph with $n$ nodes (planets), where each node has exactly one outgoing edge (teleporter). This structure forms a series of **directed chains** and **cycles**. Given $q$ queries, each asking for the minimum number of teleportations to travel from planet $a$ to planet $b$, the task is to determine the shortest path or determine if $b$ is unreachable from $a$.

Key challenges include:
- Efficiently handling up to $2 \cdot 10^5$ queries.
- Dealing with cycles and unreachable nodes.

---

## Solution Approach

### 1. Graph Structure and Observations
- Each planet has exactly one outgoing edge, meaning the graph is made up of **chains** leading into **cycles**.
- To solve the problem, we need to:
  1. Detect cycles.
  2. Precompute distances for nodes in chains leading to cycles.
  3. Use this precomputed information to answer queries efficiently.

### 2. Cycle Detection
- Use a **visited array** to detect cycles:
  - Perform a DFS or iterative traversal starting from each unvisited node.
  - Mark nodes as visited during traversal. If a node is revisited, a cycle is detected.
  - Assign a unique cycle ID to each node in the cycle for easy identification.

### 3. Precomputing Distances
- For nodes in cycles:
  - The distance from any node in the cycle to itself is $0$.
- For nodes in chains leading to cycles:
  - Traverse backward from the cycle and compute the distance to the cycle for each node.

### 4. Binary Lifting for Efficient Queries
- To efficiently compute the number of teleportations, use **binary lifting**:
  - Precompute a table `up[node][k]` where `up[node][k]` represents the node reached after $2^k$ teleportations from `node`.
  - This allows jumping large distances in $O(\log n)$ time during query processing.

### 5. Query Processing
- For each query $(a, b)$:
  1. Check if $b$ is reachable from $a$:
     - If $a$ and $b$ are in the same cycle, compute the distance directly.
     - If $a$ is in a chain leading to a cycle, check if $b$ is reachable by following the precomputed paths.
  2. If $b$ is unreachable, return $-1$.

---

## Key Learning Points

1. **Cycle Detection in Directed Graphs**:
   - Detecting cycles is crucial for problems involving directed graphs with one outgoing edge per node.
   - Assigning unique IDs to cycles simplifies query processing.

2. **Binary Lifting**:
   - A powerful technique for efficiently jumping through paths in a graph.
   - Commonly used in problems involving trees or graphs with fixed outgoing edges.

3. **Preprocessing for Efficiency**:
   - Precomputing distances and paths reduces query time complexity, making it feasible to handle large inputs.

4. **Graph Representation**:
   - Understanding the structure of the graph (chains + cycles) is key to designing an efficient solution.

---

## Common Pitfalls

1. **Incorrect Cycle Detection**:
   - Failing to correctly identify cycles or nodes leading to cycles can lead to incorrect results.
   - Ensure all nodes are processed, even if they are part of chains.

2. **Handling Unreachable Nodes**:
   - Forgetting to account for nodes that do not lead to a cycle can result in incorrect answers for some queries.

3. **Inefficient Query Handling**:
   - Without binary lifting or precomputed distances, query processing can become too slow for large inputs.

---

## Complexity

### Time Complexity
1. **Preprocessing**:
   - Cycle detection: $O(n)$ (DFS or iterative traversal).
   - Distance computation: $O(n)$.
   - Binary lifting table construction: $O(n \log n)$.
   - Total preprocessing: $O(n \log n)$.

2. **Query Processing**:
   - Each query takes $O(\log n)$ (binary lifting).
   - For $q$ queries: $O(q \log n)$.

**Overall Complexity**: $O(n \log n + q \log n)$.

### Space Complexity
- Binary lifting table: $O(n \log n)$.
- Additional arrays for visited nodes, cycle IDs, and distances: $O(n)$.
- Total: $O(n \log n)$.

---

## Alternative Approaches

1. **Breadth-First Search (BFS)**:
   - For each query, perform a BFS from $a$ to find $b$.
   - Inefficient for large $n$ and $q$ due to $O(n)$ per query.

2. **Dynamic Programming**:
   - Use DP to store the minimum number of teleportations for all pairs.
   - Requires $O(n^2)$ space and preprocessing, which is infeasible for large $n$.

3. **Floyd-Warshall Algorithm**:
   - Compute shortest paths for all pairs.
   - Time complexity: $O(n^3)$, which is impractical for $n \leq 2 \cdot 10^5$.

---

## Extended Learning

1. **Graph Theory**:
   - Understanding cycles, strongly connected components (SCCs), and chain structures.
2. **Binary Lifting**:
   - Widely used in problems involving trees, LCA (Lowest Common Ancestor), and fixed-path graphs.
3. **Efficient Query Handling**:
   - Techniques like preprocessing, sparse tables, and segment trees.

---

## Tips for Similar Problems

1. **Identify Graph Structure**:
   - Look for patterns like cycles, chains, or trees to simplify the problem.

2. **Precompute When Possible**:
   - If queries involve repeated computations, preprocess results to save time.

3. **Use Efficient Path Traversal**:
   - Techniques like binary lifting or sparse tables can drastically reduce query times.

4. **Handle Edge Cases**:
   - Consider unreachable nodes, self-loops, and disconnected components.

5. **Optimize for Constraints**:
   - For large inputs, focus on $O(\log n)$ or $O(1)$ query solutions.