# Flight Routes

[Problem Link](https://cses.fi/problemset/task/1196) | [Solution Link](../../solutions/04_Graph_Algorithms/13_1196_Flight_Routes.cpp)

## TL;DR

The problem involves finding the $k$ shortest paths from a source city to a destination city in a weighted directed graph. The solution uses a modified Dijkstra's algorithm with a priority queue to explore paths in ascending order of cost, ensuring that the $k$ shortest paths are found efficiently. The algorithm avoids prematurely pruning paths and carefully tracks the number of paths discovered for each node.

---

## Problem Overview

The task is to compute the $k$ shortest routes from city $1$ (Syrjälä) to city $n$ (Metsälä) in a directed graph with weighted edges. Each route's cost is the sum of the weights of the edges it traverses. The output should list the costs of the $k$ shortest routes in ascending order.

### Key Constraints:
- The graph can have up to $10^5$ nodes and $2 \cdot 10^5$ edges.
- Edge weights can be as large as $10^9$.
- $k \leq 10$, ensuring that the number of routes to track is small.

---

## Solution Approach

The solution is based on a **modified Dijkstra's algorithm** that tracks multiple shortest paths to each node. Here's a step-by-step breakdown:

### 1. **Graph Representation**
The graph is represented as an adjacency list, where each node stores a list of its outgoing edges. Each edge is represented as a pair $(v, w)$, where $v$ is the destination node and $w$ is the weight of the edge.

### 2. **Priority Queue for Exploration**
A priority queue (min-heap) is used to explore nodes in ascending order of cost. Each entry in the queue is a pair $(d, u)$, where $d$ is the current cost to reach node $u$.

### 3. **Tracking Path Counts**
A `distCnt` array is maintained to track how many shortest paths have been found for each node. This ensures that we stop exploring a node once we have found $k$ paths to it.

### 4. **Modified Dijkstra's Logic**
- Start from the source node (city $1$) with a cost of $0$.
- For each node $u$ popped from the priority queue:
  - If $distCnt[u]$ has already reached $k$, skip further exploration of $u$.
  - Otherwise, increment $distCnt[u]$ and explore all outgoing edges $(u, v, w)$.
  - Push $(d + w, v)$ into the priority queue for further exploration.
- If the destination node (city $n$) is reached, record the cost. Stop once $k$ paths to the destination are found.

### 5. **Output**
The costs of the $k$ shortest paths to the destination are printed in ascending order.

---

## Key Learning Points

1. **Modified Dijkstra's Algorithm**:
   - Standard Dijkstra's algorithm finds the single shortest path to each node. By allowing multiple visits to nodes and tracking path counts, it can be adapted to find multiple shortest paths.

2. **Priority Queue for Path Exploration**:
   - The priority queue ensures that paths are explored in ascending order of cost, which is critical for correctness.

3. **Avoiding Premature Pruning**:
   - It's important not to prune paths to a node prematurely (e.g., by checking $distCnt[v]$ before pushing to the queue). This ensures that all potential paths are considered.

4. **Efficient Path Tracking**:
   - Using a counter (`distCnt`) to track the number of paths found for each node avoids unnecessary computations and ensures the algorithm terminates efficiently.

---

## Common Pitfalls

1. **Premature Pruning**:
   - Checking the path count (`distCnt[v]`) before pushing a node into the priority queue can lead to missing valid paths.

2. **Incorrect Priority Queue Usage**:
   - Not using a min-heap or improperly updating the queue can result in incorrect path exploration.

3. **Handling Large Edge Weights**:
   - Edge weights up to $10^9$ require careful handling to avoid integer overflow.

4. **Output Order**:
   - Forgetting to output the $k$ shortest paths in ascending order can lead to incorrect results.

---

## Complexity

### Time Complexity:
- Each edge is processed at most $k$ times (once for each valid path).
- Pushing and popping from the priority queue takes $O(\log(mk))$ time.
- Total complexity: $O(mk \log(mk))$, where $m$ is the number of edges and $k$ is the number of paths.

### Space Complexity:
- The graph requires $O(m)$ space.
- The priority queue can hold up to $O(mk)$ elements.
- Total space complexity: $O(m + mk)$.

---

## Alternative Approaches

1. **A* Algorithm**:
   - If a heuristic is available, A* can be used to guide the search toward the destination more efficiently.

2. **Yen's Algorithm**:
   - A specialized algorithm for finding $k$ shortest paths. It repeatedly finds the next shortest path by modifying the graph and re-running a shortest path algorithm.

3. **Dynamic Programming**:
   - For small graphs, a DP-based approach could be used to compute all paths and select the $k$ shortest.

---

## Extended Learning

1. **K Shortest Paths Problem**:
   - The general problem of finding $k$ shortest paths in a graph has applications in routing, logistics, and network design.

2. **Priority Queue Optimization**:
   - Understanding how to efficiently use and manage priority queues is critical for graph algorithms.

3. **Graph Representation**:
   - Adjacency lists are space-efficient and well-suited for sparse graphs like this one.

4. **Path Enumeration**:
   - Techniques for enumerating paths in a graph are useful for problems involving multiple solutions.

---

## Tips for Similar Problems

1. **Recognize the Problem Type**:
   - If the problem involves finding multiple paths or routes, consider adapting Dijkstra's algorithm or using specialized algorithms like Yen's.

2. **Use Priority Queues**:
   - For problems involving shortest paths or minimum costs, a priority queue is often the right data structure.

3. **Track State Carefully**:
   - When exploring multiple paths, ensure that you track the state (e.g., path counts) correctly to avoid redundant computations.

4. **Start with a Simple Case**:
   - Solve the single shortest path problem first, then extend the solution to handle multiple paths.

5. **Test with Edge Cases**:
   - Ensure the solution works for graphs with cycles, large weights, and multiple paths with the same cost.