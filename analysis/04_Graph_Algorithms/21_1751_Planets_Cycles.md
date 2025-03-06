# Planets Cycles

[Problem Link](https://cses.fi/problemset/task/1751) | [Solution Link](../../solutions/04_Graph_Algorithms/21_1751_Planets_Cycles.cpp)

## TL;DR

The problem involves finding the number of teleportations required to reach a cycle for each planet in a graph where each node has exactly one outgoing edge. The solution uses graph traversal techniques (DFS) to identify cycles and compute the required teleportation counts efficiently. The approach ensures $O(n)$ time complexity by carefully marking visited nodes and leveraging properties of cycles in directed graphs.

---

## Problem Overview

The problem is about a graph with $n$ nodes (planets), where each node has exactly one outgoing edge (teleporter). Starting from any node, the traversal will eventually lead to a cycle. The task is to compute, for each node, the number of teleportations required to reach a cycle, including the cycle length if the node is part of the cycle.

### Key Details:
- Each planet teleports to exactly one other planet (or itself).
- The graph is a collection of cycles and paths leading into cycles.
- The output is an array where each element corresponds to the number of teleportations required for the respective planet.

---

## Solution Approach

The problem can be solved using graph traversal techniques, specifically Depth-First Search (DFS). Here's the step-by-step breakdown:

### 1. **Graph Representation**
The graph is represented as an array `t` where $t[i]$ indicates the destination of the teleporter from planet $i$. This is a compact representation of a directed graph.

### 2. **Cycle Detection**
Since each node has exactly one outgoing edge, the graph is composed of cycles and paths leading into cycles. To solve the problem:
- Identify all cycles in the graph.
- Compute the cycle length for each node in the cycle.
- For nodes outside the cycle, calculate the number of steps required to reach the cycle.

### 3. **DFS for Traversal**
DFS is used to traverse the graph and compute the required values:
- **Visited States**: Use an array `visited` to track the state of each node:
  - `0`: Node not yet visited.
  - `1`: Node currently being visited (part of an ongoing DFS).
  - `2`: Node fully processed (cycle length or distance to cycle known).
- **Cycle Detection**: During DFS, if a node currently being visited (`visited[node] == 1`) is encountered, a cycle is detected.
- **Backtracking**: Once a cycle is detected, backtrack to compute the cycle length and propagate the values to nodes leading into the cycle.

### 4. **Propagation of Results**
- For nodes in a cycle, set their values to the cycle length.
- For nodes leading into a cycle, compute their distance to the cycle by incrementing the count during backtracking.

### 5. **Efficiency**
The solution ensures each node is visited exactly once during the DFS, resulting in $O(n)$ time complexity.

---

## Key Learning Points

1. **Graph with Single Outgoing Edge per Node**:
   - Such graphs always lead to cycles, making them easier to analyze.
   - They can be efficiently traversed using DFS or similar techniques.

2. **Cycle Detection in Directed Graphs**:
   - Use a `visited` array with three states to detect cycles during DFS.

3. **Path and Cycle Length Calculation**:
   - Nodes in a cycle share the same cycle length.
   - Nodes outside the cycle can compute their distance to the cycle during backtracking.

4. **Efficient Propagation**:
   - By leveraging DFS and backtracking, results can be propagated efficiently without redundant computations.

---

## Common Pitfalls

1. **Incorrect Cycle Detection**:
   - Failing to distinguish between nodes currently being visited and fully processed nodes can lead to incorrect cycle detection.

2. **Infinite Loops**:
   - Not marking nodes as visited during DFS can result in infinite loops.

3. **Incorrect Propagation**:
   - Forgetting to propagate the cycle length or distance to nodes leading into the cycle can result in incorrect outputs.

4. **Edge Cases**:
   - Self-loops ($t[i] = i$) and graphs with multiple disjoint cycles need to be handled correctly.

---

## Complexity

### Time Complexity
- **DFS Traversal**: Each node is visited exactly once, resulting in $O(n)$ time complexity.

### Space Complexity
- **Visited Array**: $O(n)$ space for the `visited` array.
- **Call Stack**: In the worst case, the DFS call stack can grow to $O(n)$.

Overall, the solution has $O(n)$ time and $O(n)$ space complexity.

---

## Alternative Approaches

1. **Iterative Approach**:
   - Use an iterative method instead of recursive DFS to avoid potential stack overflow for large $n$.

2. **Union-Find**:
   - Use a disjoint-set data structure to group nodes into cycles and paths. However, this might be less efficient than DFS for this specific problem.

3. **BFS**:
   - Perform a Breadth-First Search (BFS) from each node to detect cycles and compute distances. This is less efficient than DFS due to redundant traversals.

---

## Extended Learning

1. **Graph Theory**:
   - Study properties of graphs with exactly one outgoing edge per node.
   - Explore applications of cycle detection in directed graphs.

2. **DFS Applications**:
   - Learn how DFS can be used for tasks like topological sorting, connected components, and detecting strongly connected components.

3. **Cycle Detection Algorithms**:
   - Understand other cycle detection techniques like Floyd's Tortoise and Hare algorithm.

---

## Tips for Similar Problems

1. **Identify Graph Structure**:
   - Recognize if the graph has specific properties (e.g., single outgoing edge per node) that simplify the problem.

2. **Use Visited States**:
   - Use a `visited` array with multiple states to handle cycle detection and propagation efficiently.

3. **Leverage Backtracking**:
   - Use backtracking during DFS to compute and propagate results efficiently.

4. **Optimize for Large Inputs**:
   - Ensure the solution scales well for large $n$ by avoiding redundant computations and using efficient data structures.