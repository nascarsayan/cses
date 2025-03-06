# High Score

[Problem Link](https://cses.fi/problemset/task/1673) | [Solution Link](../../solutions/04_Graph_Algorithms/10_1673_High_Score.cpp)

## TL;DR

The problem is solved using the **Bellman-Ford algorithm** to compute the shortest path while detecting negative weight cycles. The solution ensures that the maximum score is calculated from room 1 to room n, and checks if an arbitrarily large score is possible by verifying reachable nodes in negative cycles.

---

## Problem Overview

The problem involves finding the maximum score achievable when traveling from room 1 to room $n$ in a directed graph with weighted edges. Scores can increase or decrease depending on the edge weights, and the goal is to determine the maximum score or detect if an infinite score is possible due to a negative weight cycle that is reachable.

### Key Points:
- **Graph Representation**: Directed graph with $n$ nodes and $m$ edges.
- **Edge Weights**: Can be positive or negative.
- **Output**: Maximum score or $-1$ if infinite score is possible.

---

## Solution Approach

### 1. **Graph Representation**
The graph is represented using adjacency lists. Two graphs are maintained:
- `graph`: Original graph with weights negated (to transform the problem into a shortest path problem).
- `revGraph`: Reverse of the original graph, used for reachability checks.

### 2. **Bellman-Ford Algorithm**
The **Bellman-Ford algorithm** is used to compute the shortest path from room 1 to all other rooms. The algorithm works as follows:
- Initialize the distance to all nodes as infinity, except the source node (room 1) which is set to 0.
- Relax all edges $n-1$ times to compute the shortest paths.

### 3. **Negative Cycle Detection**
After $n-1$ iterations, a further relaxation is performed:
- If any distance can still be reduced, it indicates the presence of a negative weight cycle.

### 4. **Reachability Check**
To determine if a negative cycle affects the path from room 1 to room $n$:
- Perform a Depth-First Search (DFS) from room 1 to find all reachable nodes (`fromSrc`).
- Perform a DFS from room $n$ in the reversed graph to find all nodes that can reach room $n` (`fromDst`).
- A node is part of a relevant negative cycle if it is in both `fromSrc` and `fromDst`.

### 5. **Final Decision**
- If a negative cycle is reachable from room 1 and can reach room $n$, output $-1$ (infinite score possible).
- Otherwise, output the negated shortest path distance to room $n$ (to convert back to the maximum score).

---

## Key Learning Points

1. **Bellman-Ford Algorithm**:
   - Useful for finding shortest paths in graphs with negative weights.
   - Can detect negative weight cycles.

2. **Negative Cycle Detection**:
   - A negative cycle does not always imply an infinite score unless it is reachable and affects the path from source to destination.

3. **Reachability Analysis**:
   - Combining forward and reverse reachability checks ensures that only relevant negative cycles are considered.

4. **Graph Transformations**:
   - Negating edge weights transforms a maximum score problem into a shortest path problem.

---

## Common Pitfalls

1. **Incorrect Negative Cycle Handling**:
   - Not all negative cycles lead to infinite scores. Ensure to check reachability from the source and to the destination.

2. **Graph Representation**:
   - Forgetting to reverse the graph for the reachability check can lead to incorrect results.

3. **Edge Cases**:
   - Single node or single edge graphs.
   - Graphs with no negative weights or all negative weights.

4. **Integer Overflow**:
   - Edge weights can be as large as $10^9$ or as small as $-10^9$, so use a sufficiently large value for infinity (e.g., $10^{17}$).

---

## Complexity

### Time Complexity
1. **Bellman-Ford Algorithm**:
   - Relaxing all edges $n-1$ times: $O(n \cdot m)$.
   - Additional iteration for negative cycle detection: $O(m)$.
2. **DFS for Reachability**:
   - Forward and reverse DFS: $O(n + m)$.

**Total**: $O(n \cdot m)$.

### Space Complexity
- Graph storage: $O(n + m)$.
- Distance array and visited sets: $O(n)$.

**Total**: $O(n + m)$.

---

## Alternative Approaches

1. **SPFA (Shortest Path Faster Algorithm)**:
   - An optimization of Bellman-Ford that uses a queue to process nodes more efficiently.
   - May reduce runtime for sparse graphs but still has the same worst-case complexity.

2. **Floyd-Warshall Algorithm**:
   - Computes shortest paths between all pairs of nodes.
   - Not suitable here due to higher complexity ($O(n^3)$).

3. **Dijkstra's Algorithm**:
   - Cannot handle negative weights, so not applicable here.

---

## Extended Learning

1. **Graph Algorithms**:
   - Study other shortest path algorithms like Dijkstra, Floyd-Warshall, and SPFA.

2. **Negative Weight Cycles**:
   - Explore applications of negative cycles in arbitrage detection and game theory.

3. **Reachability in Graphs**:
   - Learn about strongly connected components (SCCs) and their applications.

---

## Tips for Similar Problems

1. **Recognize Negative Weight Cycles**:
   - If the problem involves maximizing or minimizing scores with cycles, consider negative weight cycle detection.

2. **Transformations**:
   - Convert maximization problems into minimization problems (or vice versa) by negating edge weights.

3. **Reachability Analysis**:
   - Always check if cycles are relevant to the source-destination path.

4. **Graph Constraints**:
   - Pay attention to the size of the graph and edge weights to choose the right algorithm.

5. **Test Edge Cases**:
   - Small graphs, disconnected components, and extreme weights should be tested thoroughly.