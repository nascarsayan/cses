# Longest Flight Route

[Problem Link](https://cses.fi/problemset/task/1680) | [Solution Link](../../solutions/04_Graph_Algorithms/16_1680_Longest_Flight_Route.cpp)

## TL;DR

The problem involves finding the longest path in a Directed Acyclic Graph (DAG) from a source node to a destination node. The solution uses topological sorting to process nodes in a valid order and dynamic programming to compute the longest path. If no path exists, the output is "IMPOSSIBLE." The approach ensures efficiency with a time complexity of $O(n + m)$, where $n$ is the number of cities (nodes) and $m$ is the number of flights (edges).

---

## Problem Overview

The task is to determine the longest path (in terms of the number of cities visited) from city 1 (Syrjälä) to city $n$ (Lehmälä) in a directed acyclic graph (DAG) representing flight routes. If no such path exists, the output should be "IMPOSSIBLE." Additionally, the solution must output the sequence of cities in the longest path.

### Key Constraints:
- The graph is a DAG (no directed cycles).
- $2 \leq n \leq 10^5$ (number of cities).
- $1 \leq m \leq 2 \cdot 10^5$ (number of flights).

---

## Solution Approach

### 1. **Topological Sorting**
Since the graph is a DAG, we can perform a topological sort to order the nodes such that for every directed edge $u \to v$, $u$ appears before $v$ in the order. This ordering ensures that we can process nodes in a way that respects dependencies.

- **DFS for Topological Sort**: Perform a depth-first search (DFS) to compute the topological order. Nodes are added to the order after all their neighbors are visited.

### 2. **Dynamic Programming for Longest Path**
Using the topological order, compute the longest path from the source (city 1) to all other nodes using dynamic programming:

- **State Definition**:
  - `maxDist[u]`: The maximum number of cities that can be visited starting from city 1 and ending at city $u$.
  - `parent[u]`: The previous city in the longest path to city $u$ (used to reconstruct the path).

- **Initialization**:
  - `maxDist[1] = 0` (starting city has a distance of 0).
  - All other nodes are initialized to a very negative value (e.g., $-\infty$) to indicate they are unreachable.

- **Transition**:
  For each edge $u \to v$, update:
  $$
  \text{if } \text{maxDist}[u] + 1 > \text{maxDist}[v] \text{, then update:}
  $$
  $$
  \text{maxDist}[v] = \text{maxDist}[u] + 1 \quad \text{and} \quad \text{parent}[v] = u.
  $$

### 3. **Path Reconstruction**
If `maxDist[n]` (longest path to city $n$) is still $-\infty$, output "IMPOSSIBLE." Otherwise, backtrack using the `parent` array to reconstruct the path from city $n$ to city 1.

### 4. **Output**
- The length of the longest path (number of cities visited).
- The sequence of cities in the path.

---

## Key Learning Points

1. **Topological Sorting**:
   - Essential for processing nodes in a DAG in a dependency-respecting order.
   - Can be computed using DFS or Kahn's algorithm.

2. **Dynamic Programming on DAGs**:
   - Longest path problems in DAGs can often be solved efficiently using dynamic programming with a topological order.

3. **Path Reconstruction**:
   - Use a `parent` array to trace back the path from the destination to the source.

4. **Handling Unreachable Nodes**:
   - Initialize distances to $-\infty$ to represent unreachable nodes and check for this condition explicitly.

---

## Common Pitfalls

1. **Cycle Detection**:
   - The problem guarantees a DAG, but in general, you must ensure the graph is acyclic before applying topological sorting.

2. **Incorrect Initialization**:
   - Forgetting to initialize `maxDist[1] = 0` or initializing other distances incorrectly can lead to wrong results.

3. **Path Reconstruction Errors**:
   - Ensure the `parent` array is updated correctly and handle edge cases where no path exists.

4. **Reverse Topological Order**:
   - Ensure the topological order is processed in reverse (from sources to sinks) for longest path computation.

---

## Complexity

### Time Complexity:
1. **Topological Sorting**:
   - DFS visits each node and edge once: $O(n + m)$.

2. **Longest Path Computation**:
   - Each edge is processed once: $O(m)$.

Overall: $O(n + m)$.

### Space Complexity:
- Graph representation: $O(n + m)$ (adjacency list).
- Additional arrays (`maxDist`, `parent`, `visited`, `topo`): $O(n)$.

Overall: $O(n + m)$.

---

## Alternative Approaches

1. **Bellman-Ford Algorithm**:
   - Can also compute the longest path in a DAG by negating edge weights and finding the shortest path. However, this is less efficient ($O(n \cdot m)$) compared to the topological sort approach.

2. **Kahn's Algorithm for Topological Sort**:
   - Instead of DFS, use Kahn's algorithm (BFS-based) to compute the topological order.

---

## Extended Learning

1. **Shortest and Longest Paths in DAGs**:
   - Learn how to adapt the approach for shortest paths by changing the transition logic.

2. **Applications of Topological Sorting**:
   - Task scheduling, dependency resolution, and more.

3. **Dynamic Programming on Graphs**:
   - Explore other DP problems on graphs, such as counting paths or finding the number of ways to reach a node.

---

## Tips for Similar Problems

1. **Recognizing DAGs**:
   - Look for constraints like "no cycles" or "dependencies" to identify DAG-related problems.

2. **Topological Sorting**:
   - If the problem involves processing nodes in a dependency-respecting order, consider topological sorting.

3. **Dynamic Programming on Graphs**:
   - Use DP when the problem involves optimizing a path or counting paths.

4. **Unreachable Nodes**:
   - Always handle edge cases where the destination is unreachable. Use $-\infty$ or a similar sentinel value.

5. **Path Reconstruction**:
   - Maintain a `parent` array or similar structure to reconstruct paths when required.