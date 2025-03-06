# Shortest Routes I

[Problem Link](https://cses.fi/problemset/task/1671) | [Solution Link](../../solutions/04_Graph_Algorithms/08_1671_Shortest_Routes_I.cpp)

## TL;DR

The problem involves finding the shortest paths from a source city (Syrjälä) to all other cities in a directed weighted graph. The solution uses Dijkstra's algorithm with a priority queue (implemented using a `set`) to efficiently compute the shortest path distances. The algorithm ensures correctness by processing nodes in increasing order of their distances from the source.

---

## Problem Overview

You are given a graph with $n$ nodes (cities) and $m$ directed edges (flights). Each edge has a positive weight (flight cost). The goal is to calculate the shortest distance from a designated source city (city 1, Syrjälä) to all other cities. The graph is guaranteed to be connected, so every city is reachable from the source.

### Input:
- $n$ (number of cities) and $m$ (number of flights).
- $m$ lines, each containing three integers $a$, $b$, and $c$, representing a directed edge from city $a$ to city $b$ with cost $c$.

### Output:
- A single line with $n$ integers, where the $i$-th integer is the shortest distance from city 1 to city $i$.

---

## Solution Approach

The solution uses **Dijkstra's algorithm**, which is well-suited for finding shortest paths in graphs with non-negative edge weights. Here's a step-by-step breakdown:

### 1. **Graph Representation**
- The graph is represented as an adjacency list using a `vector<vector<pair<int, int>>>`. Each node stores a list of its neighbors and the corresponding edge weights.

### 2. **Initialization**
- A `minCost` array is initialized with a size of $n+1$ (1-based indexing). It stores the shortest distance to each node, initially set to `-1` (unvisited).
- A priority queue (implemented using a `set` of pairs) is used to store nodes along with their current shortest distance from the source. The queue is initialized with the source node (city 1) and distance 0.

### 3. **Dijkstra's Algorithm**
- The algorithm processes nodes in increasing order of their distance from the source:
  1. Extract the node with the smallest distance from the priority queue.
  2. If the node has already been visited (i.e., its distance is finalized in `minCost`), skip it.
  3. Otherwise, mark the node as visited and update its shortest distance in `minCost`.
  4. For each neighbor of the current node, calculate the tentative distance through the current node. If the neighbor hasn't been visited, add it to the priority queue with the updated distance.

### 4. **Output**
- After processing all nodes, the `minCost` array contains the shortest distances from the source to all other nodes. These distances are printed as the output.

---

## Key Learning Points

1. **Dijkstra's Algorithm**:
   - A greedy algorithm for finding shortest paths in graphs with non-negative weights.
   - Processes nodes in increasing order of their shortest distance from the source.

2. **Graph Representation**:
   - Adjacency lists are efficient for sparse graphs, as they reduce memory usage compared to adjacency matrices.

3. **Priority Queue**:
   - A `set` is used here to implement the priority queue. While this works, a `priority_queue` (min-heap) is generally more efficient for Dijkstra's algorithm.

4. **Edge Relaxation**:
   - The process of updating the shortest distance to a neighbor if a shorter path is found.

---

## Common Pitfalls

1. **Incorrect Initialization**:
   - Forgetting to initialize the source node's distance to 0 can lead to incorrect results.

2. **Handling Unvisited Nodes**:
   - Ensure that unvisited nodes are not prematurely marked as visited.

3. **Inefficient Priority Queue**:
   - Using a `set` for the priority queue is less efficient than a `priority_queue` due to the logarithmic overhead of insertion and deletion.

4. **Large Edge Weights**:
   - Ensure that the algorithm handles large edge weights (up to $10^9$) without integer overflow.

---

## Complexity

### Time Complexity:
- **Graph Construction**: $O(m)$, where $m$ is the number of edges.
- **Dijkstra's Algorithm**:
  - Each node is processed once: $O(n)$.
  - Each edge is relaxed once: $O(m)$.
  - Priority queue operations (insert and extract) take $O(\log n)$.
  - Total: $O((n + m) \log n)$.

### Space Complexity:
- Adjacency list: $O(m)$.
- Priority queue: $O(n)$.
- Distance array: $O(n)$.
- Total: $O(n + m)$.

---

## Alternative Approaches

1. **Bellman-Ford Algorithm**:
   - Can handle graphs with negative edge weights.
   - Slower ($O(n \cdot m)$) compared to Dijkstra's algorithm for this problem.

2. **Fibonacci Heap**:
   - A more advanced data structure for the priority queue in Dijkstra's algorithm.
   - Reduces the time complexity of priority queue operations, but is rarely used in practice due to implementation complexity.

3. **Bidirectional Dijkstra**:
   - Optimized version of Dijkstra's algorithm for shortest path queries between two specific nodes.

---

## Extended Learning

1. **Shortest Path Algorithms**:
   - Explore other shortest path algorithms like Floyd-Warshall (all-pairs shortest paths) and A* (heuristic-based).

2. **Graph Theory**:
   - Study concepts like connected components, minimum spanning trees, and topological sorting.

3. **Efficient Data Structures**:
   - Learn about heaps, Fibonacci heaps, and other advanced data structures.

---

## Tips for Similar Problems

1. **Recognizing Shortest Path Problems**:
   - Look for keywords like "shortest path," "minimum cost," or "distance."

2. **Choosing the Right Algorithm**:
   - Use Dijkstra's algorithm for non-negative weights.
   - Use Bellman-Ford for graphs with negative weights.
   - Use Floyd-Warshall for all-pairs shortest paths.

3. **Graph Representation**:
   - Use adjacency lists for sparse graphs and adjacency matrices for dense graphs.

4. **Optimization**:
   - Use efficient data structures for priority queues to handle large inputs within time limits.

5. **Edge Cases**:
   - Test with graphs having:
     - Single node or edge.
     - Large weights.
     - Multiple edges between the same nodes.