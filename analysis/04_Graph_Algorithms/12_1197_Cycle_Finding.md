# Cycle Finding

[Problem Link](https://cses.fi/problemset/task/1197) | [Solution Link](../../solutions/04_Graph_Algorithms/12_1197_Cycle_Finding.cpp)

## TL;DR

The solution uses the **Bellman-Ford algorithm** to detect negative weight cycles in a directed graph. It iteratively relaxes all edges to compute shortest paths and checks for further relaxations to identify negative cycles. If a negative cycle is found, it reconstructs and outputs the cycle. Otherwise, it outputs "NO".

---

## Problem Overview

The problem asks us to determine if a directed graph contains a **negative weight cycle**. If such a cycle exists, we need to output one example of the cycle. A negative weight cycle is a cycle in the graph where the sum of edge weights is less than zero. If no such cycle exists, the output should be "NO".

### Input:
- $n$: Number of nodes ($1 \leq n \leq 2500$)
- $m$: Number of edges ($1 \leq m \leq 5000$)
- Each edge is represented by three integers $a$, $b$, and $c$, indicating an edge from node $a$ to node $b$ with weight $c$.

### Output:
- "YES" followed by the nodes in the negative cycle (in order) if a negative cycle exists.
- "NO" if no negative cycle exists.

---

## Solution Approach

### Key Idea: Bellman-Ford Algorithm
The Bellman-Ford algorithm is a well-known algorithm for finding shortest paths in graphs with negative weights. It can also detect negative weight cycles by attempting to relax edges one additional time after $n-1$ iterations.

### Steps in the Solution:

1. **Graph Representation**:
   - The graph is represented as an adjacency list where each node has a list of outgoing edges with weights.

2. **Initialization**:
   - A `dist` array is initialized to store the shortest distance from a starting node to all other nodes. Initially, all distances are set to infinity (`inf`), except the starting node which is set to 0.
   - A `parent` array is used to keep track of the predecessor of each node, which helps in reconstructing the cycle.

3. **Relaxation**:
   - For up to $n-1$ iterations, each edge is relaxed. Relaxation means checking if the distance to a node can be minimized by passing through another node. If so, the distance is updated, and the parent of the node is recorded.

4. **Cycle Detection**:
   - After $n-1$ iterations, an additional relaxation is attempted. If any edge can still be relaxed, it indicates the presence of a negative cycle.
   - The node involved in the relaxation is part of the cycle.

5. **Cycle Reconstruction**:
   - To ensure the starting node of the cycle lies within the cycle, the algorithm traces back through the `parent` array for $n$ steps.
   - The cycle is reconstructed by following the `parent` pointers until the starting node is reached again.

6. **Output**:
   - If a cycle is found, output "YES" followed by the nodes in the cycle.
   - If no cycle is found, output "NO".

---

## Key Learning Points

1. **Negative Weight Cycles**:
   - Negative weight cycles can cause shortest path algorithms like Dijkstra's to fail, as they result in infinitely decreasing path costs.

2. **Bellman-Ford Algorithm**:
   - Bellman-Ford is a versatile algorithm that works with negative weights and can detect negative cycles.
   - It relaxes all edges $n-1$ times for $n$ nodes, ensuring the shortest paths are computed.

3. **Cycle Reconstruction**:
   - The parent array is crucial for reconstructing the cycle. Tracing back through the parent pointers ensures the correct cycle is identified.

4. **Optimization**:
   - Early termination during relaxation can save computation time if no further updates are possible.

---

## Common Pitfalls

1. **Incorrect Cycle Reconstruction**:
   - If the starting node of the cycle is not traced back far enough, the reconstructed cycle may include extra nodes outside the actual cycle.

2. **Infinite Loops**:
   - Forgetting to stop the cycle reconstruction when the starting node is reached can lead to infinite loops.

3. **Edge Cases**:
   - Graphs with no edges or graphs with disconnected components need to be handled carefully.

4. **Large Weights**:
   - Using an insufficiently large value for `inf` can lead to incorrect results when edge weights are very large (close to $10^9$).

---

## Complexity

### Time Complexity:
- **Relaxation**: Each iteration relaxes all $m$ edges, taking $O(m)$ time.
- **Total Relaxations**: $n-1$ iterations for shortest paths + 1 extra iteration for cycle detection = $O(n \cdot m)$.
- **Cycle Reconstruction**: Tracing back through the parent array takes $O(n)$.

**Overall Time Complexity**:  
$$ O(n \cdot m) $$

### Space Complexity:
- **Graph Storage**: $O(m)$ for the adjacency list.
- **Distance and Parent Arrays**: $O(n)$ each.

**Overall Space Complexity**:  
$$ O(n + m) $$

---

## Alternative Approaches

1. **Floyd-Warshall Algorithm**:
   - A dynamic programming approach to compute shortest paths between all pairs of nodes. It can detect negative cycles by checking if the diagonal of the distance matrix becomes negative.
   - Time Complexity: $O(n^3)$, which is slower for sparse graphs.

2. **DFS with Backtracking**:
   - For small graphs, a DFS-based approach can be used to detect cycles and compute their weights. However, this is inefficient for large graphs.

---

## Extended Learning

1. **Shortest Path Algorithms**:
   - Study Dijkstra's algorithm and understand why it fails with negative weights.
   - Learn about Johnson's algorithm, which reweights edges to handle negative weights.

2. **Graph Representations**:
   - Explore adjacency matrices and lists, and understand their trade-offs in terms of space and time.

3. **Applications of Negative Cycles**:
   - Negative cycles are used in arbitrage detection in financial markets and in certain game theory problems.

---

## Tips for Similar Problems

1. **Recognizing Negative Cycle Problems**:
   - Look for problems involving shortest paths with negative weights or constraints that can lead to cycles with negative costs.

2. **Algorithm Selection**:
   - Use Bellman-Ford for sparse graphs and Floyd-Warshall for dense graphs.

3. **Cycle Reconstruction**:
   - Always maintain a parent array or similar structure to trace back paths or cycles.

4. **Edge Cases**:
   - Test with disconnected graphs, graphs with no edges, and graphs with all positive weights to ensure robustness.

---