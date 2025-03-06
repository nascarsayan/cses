# Message Route

[Problem Link](https://cses.fi/problemset/task/1667) | [Solution Link](../../solutions/04_Graph_Algorithms/04_1667_Message_Route.cpp)

## TL;DR

The problem is solved using **Breadth-First Search (BFS)** to find the shortest path in an unweighted graph. BFS ensures the shortest path in terms of the number of edges. The solution constructs the graph using adjacency lists, performs BFS to find the shortest path from node 1 to node $n$, and reconstructs the path using a `prev` array. If no path exists, it outputs "IMPOSSIBLE".

---

## Problem Overview

The task is to determine if there exists a path between two nodes (node 1 and node $n$) in an undirected graph with $n$ nodes and $m$ edges. If such a path exists, the goal is to find the shortest path in terms of the number of nodes and print one valid path. If no path exists, the output should be "IMPOSSIBLE".

### Key Constraints:
- $2 \leq n \leq 10^5$ (number of nodes)
- $1 \leq m \leq 2 \cdot 10^5$ (number of edges)

---

## Solution Approach

### 1. Graph Representation
The graph is represented using an **adjacency list**. This is efficient in terms of both memory and traversal time for sparse graphs, which is critical given the constraints.

```cpp
vector graph(c_node+1, vector<lli>());
for (lli i = 0; i < c_edge; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}
```

### 2. BFS for Shortest Path
The shortest path in an unweighted graph can be found using BFS. BFS explores all nodes at the current distance before moving to nodes at the next distance, ensuring the shortest path is found.

- A `deque` is used to implement the BFS queue.
- A `prev` array is used to track the parent of each node in the BFS tree, enabling path reconstruction.

```cpp
deque<pair<lli, lli>> frontier;
frontier.emplace_back(1, 0); // Start BFS from node 1
prev[1] = -1; // Mark the starting node
```

### 3. Path Reconstruction
If BFS reaches node $n$, the path is reconstructed by backtracking from node $n$ to node 1 using the `prev` array. The path is then reversed to get the correct order.

```cpp
vector<lli> path;
for (lli curr = c_node; curr != -1; curr = prev[curr])
    path.push_back(curr);
ranges::reverse(path);
```

### 4. Handling "IMPOSSIBLE"
If BFS completes without visiting node $n$, it means no path exists, and the output is "IMPOSSIBLE".

---

## Key Learning Points

1. **BFS for Shortest Path in Unweighted Graphs**:
   BFS is optimal for finding the shortest path in terms of edges in an unweighted graph.

2. **Path Reconstruction**:
   Using a `prev` array to backtrack and reconstruct the path is a common technique in graph traversal problems.

3. **Adjacency List Representation**:
   Adjacency lists are memory-efficient and fast for sparse graphs, which is critical for large inputs.

4. **Edge Cases**:
   Consider edge cases like disconnected graphs or when $n=2$ and $m=1$.

---

## Common Pitfalls

1. **Incorrect Graph Representation**:
   Forgetting to add edges in both directions for an undirected graph.

2. **Infinite Loops in BFS**:
   Not marking nodes as visited can lead to revisiting nodes and infinite loops.

3. **Path Reconstruction Errors**:
   Mismanaging the `prev` array or forgetting to reverse the reconstructed path.

4. **Edge Cases**:
   Missing edge cases like no edges ($m=0$) or graphs where node $n$ is isolated.

---

## Complexity

### Time Complexity
1. **Graph Construction**: $O(m)$, where $m$ is the number of edges.
2. **BFS Traversal**: $O(n + m)$, as each node and edge is visited once.

Overall: $O(n + m)$.

### Space Complexity
1. **Graph Storage**: $O(n + m)$ for the adjacency list.
2. **BFS Queue and `prev` Array**: $O(n)$.

Overall: $O(n + m)$.

---

## Alternative Approaches

1. **Bidirectional BFS**:
   Instead of a single BFS, perform BFS from both node 1 and node $n$ simultaneously. This can reduce the search space but adds implementation complexity.

2. **DFS**:
   DFS can find a path but is not guaranteed to find the shortest path in terms of edges, so it is unsuitable for this problem.

3. **Dijkstra's Algorithm**:
   While Dijkstra's algorithm works for shortest paths, it is overkill for unweighted graphs where BFS is simpler and faster.

---

## Extended Learning

1. **Shortest Path Algorithms**:
   - BFS for unweighted graphs.
   - Dijkstra's algorithm for weighted graphs.
   - Bellman-Ford for graphs with negative weights.

2. **Graph Representation**:
   Learn about adjacency lists, adjacency matrices, and edge lists, and when to use each.

3. **Path Reconstruction Techniques**:
   Explore other methods like storing the path directly during traversal.

---

## Tips for Similar Problems

1. **Recognize Unweighted Graphs**:
   If the problem involves finding the shortest path in an unweighted graph, BFS is likely the optimal approach.

2. **Use BFS for Connectivity**:
   BFS is also useful for determining if two nodes are connected in a graph.

3. **Track Parents for Path Reconstruction**:
   Always maintain a way to reconstruct the path (e.g., `prev` array).

4. **Handle Edge Cases**:
   Think about disconnected graphs, isolated nodes, and minimal inputs during implementation.

5. **Optimize for Constraints**:
   Use adjacency lists for large graphs and avoid unnecessary data structures.