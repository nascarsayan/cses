# Flight Discount

[Problem Link](https://cses.fi/problemset/task/1195) | [Solution Link](../../solutions/04_Graph_Algorithms/11_1195_Flight_Discount.cpp)

## TL;DR

The problem involves finding the cheapest path from city 1 to city $n$ in a directed graph, where you can use a discount coupon to halve the cost of one edge. The solution uses Dijkstra's algorithm twice to compute shortest paths from the start and to the end, and then iterates over all edges to calculate the minimum cost by applying the discount on each edge.

---

## Problem Overview

The task is to compute the minimum cost of traveling from city 1 (Syrjälä) to city $n$ (Metsälä) in a directed graph with weighted edges. You are allowed to use a discount coupon to halve the cost of one edge in the path. The goal is to determine the minimum possible cost of the journey.

### Constraints:
- Up to $10^5$ cities and $2 \cdot 10^5$ flights.
- Edge weights can be as large as $10^9$.
- The graph is guaranteed to have a path from city 1 to city $n$.

---

## Solution Approach

The solution leverages **Dijkstra's algorithm** to compute shortest paths and then evaluates the impact of applying the discount on each edge. Here's a step-by-step breakdown:

### 1. Graph Representation
The graph is represented using adjacency lists:
- `graph[u]` stores all outgoing edges from node $u$.
- `revGraph[v]` stores all incoming edges to node $v$ (used for reverse shortest path computation).

### 2. Shortest Path Computation
Dijkstra's algorithm is run twice:
- **From the start (city 1)**: Compute the shortest distance from city 1 to all other cities (`dist_from_start`).
- **To the end (city $n$)**: Compute the shortest distance to city $n$ from all other cities using the reverse graph (`dist_to_end`).

### 3. Discount Application
For each edge $(u, v, c)$:
- If the shortest path from city 1 to $u$ and from $v$ to city $n$ are both finite, calculate the total cost of the path when the discount is applied to this edge:
  $$
  \text{total\_cost} = \text{dist\_from\_start}[u] + \lfloor c / 2 \rfloor + \text{dist\_to\_end}[v]
  $$
- Track the minimum cost across all edges.

### 4. Output the Result
The minimum cost found in the previous step is printed as the result.

---

## Key Learning Points

1. **Dijkstra's Algorithm**:
   - A fundamental algorithm for finding shortest paths in graphs with non-negative edge weights.
   - Priority queues (min-heaps) are used to efficiently retrieve the next closest node.

2. **Reverse Graphs**:
   - Useful for computing shortest paths to a destination by reversing the direction of all edges.

3. **Edge Relaxation with Discounts**:
   - The problem demonstrates how to modify edge weights dynamically (e.g., applying a discount) and evaluate their impact on the overall path cost.

4. **Graph Traversal Optimization**:
   - By precomputing shortest paths, the solution avoids redundant calculations and ensures efficiency.

---

## Common Pitfalls

1. **Incorrect Discount Application**:
   - Forgetting to round down the halved edge cost using $\lfloor c / 2 \rfloor$ can lead to incorrect results.

2. **Handling Large Edge Weights**:
   - Edge weights up to $10^9$ require using 64-bit integers to avoid overflow.

3. **Disconnected Paths**:
   - Ensure that paths are valid by checking if distances are finite before applying the discount.

4. **Efficiency**:
   - Iterating over all edges after running Dijkstra's algorithm ensures the solution is efficient. Avoid recomputing shortest paths for each edge.

---

## Complexity

### Time Complexity:
1. **Dijkstra's Algorithm**:
   - Runs twice, once for the forward graph and once for the reverse graph.
   - Each run has a complexity of $O((n + m) \log n)$, where $n$ is the number of nodes and $m$ is the number of edges.

2. **Edge Iteration**:
   - Iterating over all $m$ edges to apply the discount takes $O(m)$.

Overall:  
$$
O((n + m) \log n + m) \approx O((n + m) \log n)
$$

### Space Complexity:
- Storing the graph and reverse graph: $O(n + m)$.
- Distance arrays: $O(n)$.
- Priority queue: $O(n)$.

Overall:  
$$
O(n + m)
$$

---

## Alternative Approaches

1. **Bellman-Ford Algorithm**:
   - Can handle negative edge weights but is slower with $O(n \cdot m)$ complexity.
   - Not suitable for this problem due to the large constraints.

2. **Dynamic Programming with State Representation**:
   - Use a DP table where `dp[u][0]` is the shortest path to $u$ without using the discount, and `dp[u][1]` is the shortest path to $u$ with the discount already used.
   - This approach is more complex to implement but avoids iterating over all edges after Dijkstra's algorithm.

---

## Extended Learning

1. **Shortest Path Algorithms**:
   - Study other algorithms like A* and Floyd-Warshall for different use cases.

2. **Graph Representation**:
   - Learn about adjacency matrices and edge lists and their trade-offs compared to adjacency lists.

3. **Path Reconstruction**:
   - Modify Dijkstra's algorithm to reconstruct the actual path, which is useful in many real-world applications.

4. **Discount Optimization Problems**:
   - Explore problems where discounts or modifications are applied to edges or nodes dynamically.

---

## Tips for Similar Problems

1. **Look for Modifications to Standard Algorithms**:
   - Problems like this often require small tweaks to well-known algorithms like Dijkstra or BFS.

2. **Precompute Shortest Paths**:
   - If a problem involves modifying edge weights or applying conditions, precomputing shortest paths can simplify the solution.

3. **Use Reverse Graphs**:
   - When dealing with paths to a specific destination, reverse graphs are often helpful.

4. **Efficient Graph Traversal**:
   - Always consider the constraints and choose algorithms that scale well with the input size.