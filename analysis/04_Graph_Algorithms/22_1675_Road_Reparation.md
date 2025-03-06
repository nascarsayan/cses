# Road Reparation

[Problem Link](https://cses.fi/problemset/task/1675) | [Solution Link](../../solutions/04_Graph_Algorithms/22_1675_Road_Reparation.cpp)

## TL;DR

The problem is a classic **minimum spanning tree (MST)** problem. The goal is to connect all cities with the minimum total cost of repairing roads. The solution uses **Kruskal's algorithm**, which sorts the edges by cost and uses a **union-find (disjoint-set)** structure to efficiently determine whether adding an edge creates a cycle. If the graph is not connected, the output is "IMPOSSIBLE."

---

## Problem Overview

The task is to repair roads between cities such that all cities are connected with the minimum total cost. The graph is undirected, and each edge has a weight representing the repair cost. If it's not possible to connect all cities (i.e., the graph is disconnected), the program should output "IMPOSSIBLE."

### Key Constraints:
- Up to $10^5$ cities and $2 \cdot 10^5$ roads.
- Costs can be as large as $10^9$.
- The graph may not initially be connected.

### Output:
- The minimum total cost to connect all cities, or "IMPOSSIBLE" if it's not feasible.

---

## Solution Approach

The problem can be solved using **Kruskal's algorithm** for finding the **minimum spanning tree (MST)**. Here's a step-by-step breakdown:

### 1. **Graph Representation**
The graph is represented as a list of edges. Each edge is a tuple $(a, b, c)$, where $a$ and $b$ are the cities connected by the edge, and $c$ is the cost of repairing the road.

### 2. **Sort Edges by Cost**
To build the MST, sort all edges in ascending order of their costs. This ensures that we always consider the cheapest edge first.

### 3. **Union-Find (Disjoint-Set) Data Structure**
Use a union-find structure to efficiently check whether adding an edge creates a cycle:
- **Find:** Determine the root of the set containing a node.
- **Union:** Merge two sets if they are not already connected.
- Use **path compression** and **union by rank** to optimize these operations.

### 4. **Kruskal's Algorithm**
- Initialize the total cost to 0 and the number of edges in the MST to 0.
- Iterate through the sorted edges:
  - If the two cities connected by the edge belong to different sets, add the edge to the MST, update the total cost, and merge the sets.
  - If the edge forms a cycle, skip it.
- Stop when the MST contains exactly $n-1$ edges (where $n$ is the number of cities).

### 5. **Check Connectivity**
If the MST contains fewer than $n-1$ edges after processing all edges, the graph is disconnected, and it's impossible to connect all cities. In this case, output "IMPOSSIBLE."

---

## Key Learning Points

1. **Minimum Spanning Tree (MST):**
   - An MST connects all nodes in a graph with the minimum total edge weight.
   - Kruskal's and Prim's algorithms are the two most common methods for finding an MST.

2. **Union-Find Data Structure:**
   - Essential for efficiently handling connectivity queries in Kruskal's algorithm.
   - Path compression and union by rank are critical optimizations.

3. **Graph Connectivity:**
   - If the graph is not connected, it's impossible to construct an MST.

4. **Edge Sorting:**
   - Sorting edges by weight is a key step in Kruskal's algorithm and ensures we always consider the cheapest edges first.

---

## Common Pitfalls

1. **Disconnected Graphs:**
   - Forgetting to check whether the graph is connected can lead to incorrect results. Always verify that the MST contains exactly $n-1$ edges.

2. **Union-Find Implementation:**
   - Incorrect implementation of path compression or union by rank can lead to inefficiencies or incorrect results.

3. **Integer Overflow:**
   - Be cautious with large edge weights (up to $10^9$). Use appropriate data types (e.g., `long long` in C++).

4. **Edge Cases:**
   - Single city ($n=1$): The cost is 0.
   - No roads ($m=0$): Output "IMPOSSIBLE."
   - Already connected graph: Ensure the algorithm doesn't add unnecessary edges.

---

## Complexity

### Time Complexity:
1. **Sorting Edges:** $O(m \log m)$, where $m$ is the number of edges.
2. **Union-Find Operations:** Nearly $O(1)$ per operation due to path compression and union by rank. For $m$ edges, this is $O(m \cdot \alpha(n))$, where $\alpha(n)$ is the inverse Ackermann function (very small, effectively constant).

Overall: **$O(m \log m)$**

### Space Complexity:
- **Union-Find:** $O(n)$ for parent and rank arrays.
- **Edge List:** $O(m)$.
- Total: **$O(n + m)$**

---

## Alternative Approaches

1. **Prim's Algorithm:**
   - Another method for finding an MST. It uses a priority queue to repeatedly add the smallest edge connecting a visited node to an unvisited node.
   - Time complexity: $O(m \log n)$ using a binary heap.

2. **DFS/BFS for Connectivity Check:**
   - Before running Kruskal's algorithm, a simple DFS or BFS can check if the graph is connected. However, this adds $O(n + m)$ to the runtime and is usually unnecessary.

---

## Extended Learning

1. **Other MST Algorithms:**
   - Borůvka's algorithm is another approach to finding an MST, particularly useful for parallel computing.

2. **Applications of MST:**
   - Network design (e.g., laying cables, designing road networks).
   - Cluster analysis in machine learning.

3. **Graph Theory Concepts:**
   - Spanning trees, connected components, and graph cycles.

4. **Advanced Union-Find:**
   - Learn about other applications of union-find, such as dynamic connectivity and Kruskal's algorithm for maximum spanning trees.

---

## Tips for Similar Problems

1. **Recognize MST Problems:**
   - Look for problems asking to "connect all nodes with minimum cost" or "minimize total edge weight."

2. **Choose the Right Algorithm:**
   - Use Kruskal's algorithm for edge-centric problems.
   - Use Prim's algorithm for node-centric problems.

3. **Optimize Union-Find:**
   - Always implement path compression and union by rank for efficiency.

4. **Handle Edge Cases:**
   - Consider disconnected graphs, single-node graphs, and graphs with no edges.

5. **Practice Common Patterns:**
   - Solve other MST problems to solidify your understanding of Kruskal's and Prim's algorithms. Examples include "Minimum Cost to Connect All Points" (LeetCode) and "Network Connections" (CSES).