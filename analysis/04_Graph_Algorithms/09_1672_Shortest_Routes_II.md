# Shortest Routes II

[Problem Link](https://cses.fi/problemset/task/1672) | [Solution Link](../../solutions/04_Graph_Algorithms/09_1672_Shortest_Routes_II.cpp)

## TL;DR

The problem is solved using the **Floyd-Warshall algorithm**, a classic all-pairs shortest path algorithm. The solution precomputes the shortest distances between all pairs of cities in $O(n^3)$ time, allowing each of the $q$ queries to be answered in $O(1)$ time. This approach is efficient given the constraints, where $n \leq 500$ and $q \leq 10^5$.

---

## Problem Overview

The task is to determine the shortest route between pairs of cities in a weighted, undirected graph. The graph has $n$ nodes (cities) and $m$ edges (roads). Each query asks for the shortest distance between two specific cities. If no route exists, the output should be $-1$.

Key constraints:
- $1 \leq n \leq 500$: The graph can have up to 500 nodes.
- $1 \leq m \leq n^2$: The graph can be dense, with up to $n^2$ edges.
- $1 \leq q \leq 10^5$: Up to 100,000 queries need to be answered efficiently.

---

## Solution Approach

### 1. Graph Representation
The graph is represented as an adjacency matrix `graph[u][v]`, where `graph[u][v]` stores the shortest known distance between nodes $u$ and $v$. Initially:
- `graph[u][v] = c` if there is a road of cost $c$ between $u$ and $v$.
- `graph[u][v] = \infty` if no direct road exists.
- `graph[u][u] = 0` for all $u$ (distance to itself is zero).

### 2. Floyd-Warshall Algorithm
The **Floyd-Warshall algorithm** is used to compute the shortest paths between all pairs of nodes. It works by iteratively considering each node as an intermediate point and updating the shortest distances:
$$
\text{graph}[u][v] = \min(\text{graph}[u][v], \text{graph}[u][k] + \text{graph}[k][v])
$$
for all nodes $u$, $v$, and $k$.

This algorithm has a time complexity of $O(n^3)$, which is feasible for $n \leq 500$.

### 3. Query Processing
Once the shortest paths are precomputed using Floyd-Warshall, each query can be answered in $O(1)$ time:
- If `graph[a][b] = \infty`, output $-1$ (no route exists).
- Otherwise, output `graph[a][b]`.

### Key Steps in the Implementation:
- **Input Parsing:** Read the graph structure and initialize the adjacency matrix.
- **Floyd-Warshall Execution:** Update the adjacency matrix to compute all-pairs shortest paths.
- **Query Responses:** For each query, directly retrieve the precomputed shortest distance.

---

## Key Learning Points

1. **Floyd-Warshall Algorithm:** A fundamental algorithm for solving all-pairs shortest path problems in dense graphs.
2. **Adjacency Matrix Representation:** Useful for dense graphs and algorithms like Floyd-Warshall.
3. **Precomputation for Efficiency:** Precomputing results (e.g., shortest paths) can significantly reduce query response time in problems with multiple queries.
4. **Infinity Representation:** Use a sufficiently large value (e.g., $10^{16}$) to represent "infinity" in the adjacency matrix, ensuring no overflow during updates.

---

## Common Pitfalls

1. **Incorrect Initialization:** Forgetting to initialize `graph[u][u] = 0` or incorrectly setting initial edge weights can lead to incorrect results.
2. **Handling No Path Cases:** Failing to check for "infinity" when outputting query results can result in incorrect or undefined behavior.
3. **Integer Overflow:** Using a small value for "infinity" (e.g., $10^9$) can cause overflow when adding edge weights during updates.
4. **Inefficient Query Handling:** Not precomputing shortest paths and attempting to compute them on-the-fly for each query would lead to a time complexity of $O(q \cdot n^3)$, which is infeasible.

---

## Complexity

### Time Complexity
1. **Floyd-Warshall Algorithm:** $O(n^3)$ for precomputing all-pairs shortest paths.
2. **Query Processing:** $O(1)$ per query, for a total of $O(q)$.

Overall: $O(n^3 + q)$.

### Space Complexity
- The adjacency matrix requires $O(n^2)$ space.
- Additional space for temporary variables is negligible.

Overall: $O(n^2)$.

---

## Alternative Approaches

1. **Dijkstra's Algorithm with Priority Queue:**
   - For each query, run Dijkstra's algorithm from the source city.
   - Time complexity: $O(q \cdot (n + m) \log n)$.
   - This approach is better for sparse graphs but inefficient for dense graphs due to repeated computations.

2. **Johnson's Algorithm:**
   - Reweight the graph using Bellman-Ford, then use Dijkstra's algorithm for all-pairs shortest paths.
   - Time complexity: $O(n^2 \log n + nm)$.
   - More complex to implement and not as efficient as Floyd-Warshall for dense graphs.

---

## Extended Learning

1. **All-Pairs Shortest Path Algorithms:**
   - Study other algorithms like Johnson's algorithm and their use cases.
2. **Graph Representations:**
   - Understand when to use adjacency matrices vs. adjacency lists.
3. **Dynamic Programming in Graphs:**
   - Floyd-Warshall is a classic example of dynamic programming applied to graphs.

---

## Tips for Similar Problems

1. **Identify Query Patterns:**
   - If multiple queries are involved, consider precomputing results to reduce query time.
2. **Graph Density:**
   - For dense graphs, prefer algorithms like Floyd-Warshall. For sparse graphs, use Dijkstra's or Bellman-Ford.
3. **Infinity Handling:**
   - Use a large value to represent "infinity" and ensure it doesn't interfere with computations.
4. **Algorithm Selection:**
   - Match the algorithm to the constraints. Floyd-Warshall is ideal for small to medium-sized graphs with $n \leq 500$.