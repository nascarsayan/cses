# Investigation

[Problem Link](https://cses.fi/problemset/task/1202) | [Solution Link](../../solutions/04_Graph_Algorithms/18_1202_Investigation.cpp)

## TL;DR

The problem involves finding the shortest path in a weighted directed graph while also calculating the number of such shortest paths, the minimum number of edges, and the maximum number of edges in these paths. The solution uses Dijkstra's algorithm with additional bookkeeping to track the required metrics efficiently.

---

## Problem Overview

You are tasked with traveling from city 1 (Syrjälä) to city $n$ (Lehmälä) in a directed graph where edges represent flights with associated costs. The goal is to determine:

1. The minimum cost of traveling from city 1 to city $n$.
2. The number of distinct minimum-cost paths (modulo $10^9+7$).
3. The minimum number of edges (flights) in any minimum-cost path.
4. The maximum number of edges (flights) in any minimum-cost path.

The graph has up to $10^5$ nodes and $2 \times 10^5$ edges, so the solution must be efficient.

---

## Solution Approach

### Key Idea

The problem is primarily about finding the shortest path in a weighted graph, which can be solved using **Dijkstra's algorithm**. However, additional metrics (number of paths, minimum/maximum edges) require extra bookkeeping during the algorithm's execution.

### Steps

1. **Graph Representation**:
   - The graph is represented as an adjacency list where each node has a list of pairs $(v, w)$, representing an edge to node $v$ with weight $w$.

2. **Initialization**:
   - Use a priority queue (min-heap) to implement Dijkstra's algorithm.
   - Maintain arrays:
     - `minCosts[i]`: Minimum cost to reach node $i$.
     - `nWays[i]`: Number of ways to reach node $i$ with the minimum cost.
     - `minHops[i]`: Minimum number of edges in a minimum-cost path to node $i$.
     - `maxHops[i]`: Maximum number of edges in a minimum-cost path to node $i$.

3. **Dijkstra's Algorithm**:
   - Start from the source node (city 1) with cost 0.
   - For each node, explore its neighbors and update the arrays based on the following conditions:
     - **Relaxation**: If a shorter path to a neighbor is found, update the cost, number of ways, and edge counts.
     - **Equal Cost**: If a path with the same minimum cost is found, update the number of ways and adjust the minimum and maximum edge counts.

4. **Output Results**:
   - After processing all nodes, the results for city $n$ (destination) are:
     - `minCosts[n]`: Minimum cost.
     - `nWays[n]`: Number of minimum-cost paths.
     - `minHops[n] - 1`: Minimum number of edges (subtract 1 to exclude the starting node).
     - `maxHops[n] - 1`: Maximum number of edges (subtract 1 to exclude the starting node).

### Key Observations

- The modulo operation ($10^9+7$) is applied to the count of paths to prevent overflow.
- The algorithm avoids revisiting nodes unnecessarily by skipping nodes with outdated costs in the priority queue.

---

## Key Learning Points

1. **Dijkstra's Algorithm**:
   - A powerful tool for finding shortest paths in weighted graphs.
   - Can be extended to track additional metrics with careful bookkeeping.

2. **Path Counting**:
   - Counting paths with specific properties (e.g., shortest paths) often requires dynamic programming or additional state tracking.

3. **Edge Relaxation**:
   - The relaxation step in Dijkstra's algorithm can be adapted to handle multiple criteria (e.g., path count, edge counts).

4. **Efficient Modulo Arithmetic**:
   - Use modulo operations judiciously to handle large numbers in competitive programming.

---

## Common Pitfalls

1. **Incorrect Relaxation Logic**:
   - Failing to update the number of paths or edge counts correctly when a new shortest path is found.

2. **Modulo Arithmetic Errors**:
   - Forgetting to apply modulo $10^9+7$ consistently when updating path counts.

3. **Priority Queue Mismanagement**:
   - Not skipping outdated nodes in the priority queue can lead to incorrect results or inefficiency.

4. **Edge Cases**:
   - Ensure the algorithm handles graphs with single nodes, multiple shortest paths, or varying edge weights correctly.

---

## Complexity

### Time Complexity

- **Graph Construction**: $O(m)$, where $m$ is the number of edges.
- **Dijkstra's Algorithm**: $O((n + m) \log n)$, where $n$ is the number of nodes.
  - Each node and edge is processed once, and priority queue operations take $O(\log n)$.

**Total**: $O((n + m) \log n)$.

### Space Complexity

- **Graph Storage**: $O(m)$.
- **Auxiliary Arrays**: $O(n)$ for `minCosts`, `nWays`, `minHops`, and `maxHops`.
- **Priority Queue**: $O(n)$.

**Total**: $O(n + m)$.

---

## Alternative Approaches

1. **Bellman-Ford Algorithm**:
   - Can also compute shortest paths but is less efficient ($O(n \cdot m)$).
   - Useful for graphs with negative weights (not applicable here).

2. **Dynamic Programming**:
   - Use a DP table to track costs and paths, but this is less efficient for large graphs.

3. **Modified BFS**:
   - For unweighted graphs, BFS can be adapted to find shortest paths and count them.

---

## Extended Learning

1. **Shortest Path Variants**:
   - Learn about other shortest path algorithms like Floyd-Warshall (all-pairs shortest paths).

2. **Path Counting in Graphs**:
   - Explore problems involving counting paths with specific constraints.

3. **Graph Theory**:
   - Study concepts like topological sorting, strongly connected components, and minimum spanning trees.

4. **Modular Arithmetic**:
   - Understand modular arithmetic techniques and their applications in competitive programming.

---

## Tips for Similar Problems

1. **Recognize Graph Problems**:
   - If the problem involves nodes, edges, and paths, it's likely a graph problem.

2. **Understand the Metrics**:
   - Carefully read the problem to identify what metrics (e.g., cost, path count, edge count) need to be tracked.

3. **Choose the Right Algorithm**:
   - Use Dijkstra's for weighted graphs, BFS for unweighted graphs, and Bellman-Ford for graphs with negative weights.

4. **Optimize for Constraints**:
   - Ensure your solution is efficient enough for the given input size.

5. **Test Edge Cases**:
   - Test on small graphs, disconnected graphs, and graphs with multiple shortest paths.