# Game Routes

[Problem Link](https://cses.fi/problemset/task/1681) | [Solution Link](../../solutions/04_Graph_Algorithms/17_1681_Game_Routes.cpp)

## TL;DR

The problem is solved using **topological sorting** and **dynamic programming** on a Directed Acyclic Graph (DAG). First, a topological order of the levels is computed using Depth First Search (DFS). Then, the number of ways to reach each level is calculated iteratively in topological order, using the recurrence relation: 

$$
\text{ways}[v] = \sum_{u \in \text{in-neighbors of } v} \text{ways}[u] \mod (10^9 + 7).
$$

The solution is efficient with a time complexity of $O(n + m)$.

---

## Problem Overview

The problem involves finding the number of distinct paths from level $1$ to level $n$ in a game with $n$ levels and $m$ directed teleporters. The graph formed by the levels and teleporters is a Directed Acyclic Graph (DAG). The result must be computed modulo $10^9 + 7$ due to potential large numbers.

### Key Constraints:
- $1 \leq n \leq 10^5$ (number of levels)
- $1 \leq m \leq 2 \cdot 10^5$ (number of teleporters)
- The graph is guaranteed to be a DAG.

---

## Solution Approach

### 1. **Graph Representation**
The graph is represented as an adjacency list. Each node corresponds to a level, and directed edges represent teleporters.

### 2. **Topological Sorting**
Since the graph is a DAG, the levels can be arranged in a **topological order**. This ensures that for any edge $(u, v)$, $u$ appears before $v$ in the order. A DFS-based approach is used to compute the topological order:
- Start DFS from unvisited nodes.
- After visiting all neighbors of a node, add it to the topological order.
- Reverse the order at the end to get the correct topological sequence.

### 3. **Dynamic Programming on the DAG**
Using the topological order, the number of ways to reach each level is calculated:
- Initialize `ways[1] = 1` (1 way to start at level 1).
- For each level $u$ in topological order, update the ways to reach its neighbors $v$:
  $$
  \text{ways}[v] = (\text{ways}[v] + \text{ways}[u]) \mod (10^9 + 7).
  $$
- The result is stored in `ways[n]`, which gives the total number of ways to reach level $n$.

### 4. **Modulo Arithmetic**
Since the number of ways can grow large, all calculations are performed modulo $10^9 + 7$ to prevent overflow and adhere to the problem constraints.

---

## Key Learning Points

1. **Topological Sorting**:
   - Essential for processing nodes in a DAG in a dependency-respecting order.
   - Can be computed using DFS or Kahn's algorithm.

2. **Dynamic Programming on DAGs**:
   - Problems involving paths or counts in DAGs often use DP with topological sorting.
   - The recurrence relation leverages the acyclic property of the graph.

3. **Modulo Arithmetic**:
   - Common in competitive programming to handle large numbers.
   - Ensure all intermediate results are reduced modulo $10^9 + 7$.

4. **Graph Representation**:
   - Adjacency lists are efficient for sparse graphs, especially when $m \approx O(n)$.

---

## Common Pitfalls

1. **Incorrect Topological Order**:
   - Failing to compute the correct order can lead to incorrect DP updates.
   - Ensure the graph is a DAG before applying topological sorting.

2. **Uninitialized DP Array**:
   - Forgetting to initialize `ways[1] = 1` can result in all-zero outputs.

3. **Modulo Errors**:
   - Forgetting to apply modulo at each step can cause overflow or incorrect results.

4. **Graph Input Handling**:
   - Ensure the graph is correctly constructed from the input, especially for 1-based indexing.

---

## Complexity

### Time Complexity
1. **Graph Construction**: $O(m)$ (reading edges and building adjacency list).
2. **Topological Sorting**: $O(n + m)$ (DFS visits each node and edge once).
3. **Dynamic Programming**: $O(n + m)$ (each edge is processed once).

**Total**: $O(n + m)$.

### Space Complexity
1. **Graph Storage**: $O(n + m)$ (adjacency list).
2. **Visited Array**: $O(n)$.
3. **DP Array**: $O(n)$.
4. **Topological Order**: $O(n)$.

**Total**: $O(n + m)$.

---

## Alternative Approaches

1. **Kahn's Algorithm for Topological Sorting**:
   - Use an in-degree array and a queue to compute the topological order iteratively.
   - This approach avoids recursion and is equally efficient.

2. **Matrix Exponentiation**:
   - For small graphs, adjacency matrix exponentiation can compute the number of paths of all lengths. However, this is infeasible for large $n$ due to $O(n^3)$ complexity.

3. **Breadth-First Search (BFS)**:
   - Instead of DFS, BFS can be used to compute the topological order and DP updates simultaneously.

---

## Extended Learning

1. **Applications of Topological Sorting**:
   - Task scheduling, dependency resolution, and pathfinding in DAGs.

2. **Counting Paths in Graphs**:
   - Variants include finding the number of paths of exactly $k$ edges or paths with specific constraints.

3. **Modulo Arithmetic**:
   - Modular inverses and properties of modulo operations are crucial in competitive programming.

4. **Shortest and Longest Paths in DAGs**:
   - Similar DP techniques can be used to compute shortest or longest paths in a DAG.

---

## Tips for Similar Problems

1. **Recognize DAGs**:
   - Look for problems involving directed graphs with no cycles or explicit acyclic constraints.

2. **Topological Order**:
   - If the problem involves dependencies or sequential processing, consider topological sorting.

3. **Dynamic Programming on Graphs**:
   - Use DP when the problem involves counting paths, minimizing/maximizing costs, or aggregating values.

4. **Modulo Constraints**:
   - Always handle modulo constraints carefully to avoid overflow and adhere to problem requirements.

5. **Efficient Graph Traversal**:
   - Use adjacency lists for sparse graphs and avoid unnecessary recomputation by leveraging topological order.