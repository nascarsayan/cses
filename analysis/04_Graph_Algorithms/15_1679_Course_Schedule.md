# Course Schedule

[Problem Link](https://cses.fi/problemset/task/1679) | [Solution Link](../../solutions/04_Graph_Algorithms/15_1679_Course_Schedule.cpp)

## TL;DR

The problem is solved using **topological sorting** via Depth-First Search (DFS). The solution checks for cycles in the directed graph representing course prerequisites. If a cycle exists, it outputs "IMPOSSIBLE". Otherwise, it outputs a valid order of courses. The algorithm ensures correctness by maintaining a visitation state for each node and carefully handling dependencies.

---

## Problem Overview

The problem involves determining a valid order to complete $n$ courses given $m$ prerequisite relationships. Each prerequisite specifies that one course must be completed before another. The task is to output a valid order of courses or determine that it is impossible due to cyclic dependencies.

### Key Details:
- The problem can be modeled as a **Directed Acyclic Graph (DAG)**.
- Nodes represent courses, and directed edges represent prerequisites.
- The goal is to perform a **topological sort** of the graph.

---

## Solution Approach

### Graph Representation
The courses and their prerequisites are represented as a **directed graph**:
- Nodes: Courses $1, 2, \dots, n$.
- Edges: Directed edges $(a, b)$ where course $a$ must be completed before course $b$.

### Topological Sorting via DFS
The solution uses **DFS-based topological sorting**:
1. **Visitation States**:
   - Each node has one of three states:
     - `unvisited`: The node has not been processed.
     - `visiting`: The node is being processed (part of the current DFS path).
     - `visited`: The node and all its dependencies have been processed.
   - These states help detect cycles and ensure proper ordering.
2. **Cycle Detection**:
   - If a node is encountered in the `visiting` state during DFS, a cycle exists, and the output is "IMPOSSIBLE".
3. **DFS Traversal**:
   - For each unvisited node, perform a DFS.
   - Push nodes to a result stack after all their dependencies have been processed.
4. **Output**:
   - If no cycles are detected, the result stack contains a valid topological order.

### Implementation Highlights
- **Graph Construction**: The prerequisites are stored in an adjacency list.
- **DFS Function**: Recursively processes nodes, detects cycles, and builds the result.
- **Order Reversal**: The result is reversed at the end to obtain the correct topological order.

---

## Key Learning Points

1. **Topological Sorting**:
   - A fundamental algorithm for ordering nodes in a DAG based on dependencies.
   - Two common approaches: DFS-based and Kahn's Algorithm (BFS-based).
   
2. **Cycle Detection in Directed Graphs**:
   - Using visitation states (`unvisited`, `visiting`, `visited`) is an elegant way to detect cycles during DFS.

3. **Graph Representation**:
   - Adjacency lists are efficient for sparse graphs, especially when $n$ and $m$ are large.

4. **Handling Multiple Outputs**:
   - When multiple valid orders exist, any one can be returned, as the problem does not require a unique solution.

---

## Common Pitfalls

1. **Cycle Detection**:
   - Forgetting to check for cycles can lead to incorrect results or infinite recursion.
   
2. **Incorrect Graph Representation**:
   - Misinterpreting the direction of edges (e.g., reversing prerequisites) can lead to invalid outputs.

3. **Initialization Errors**:
   - Not initializing visitation states or result containers properly can cause runtime errors.

4. **Edge Cases**:
   - Single node graphs, disconnected components, or graphs with no edges must be handled correctly.

---

## Complexity

### Time Complexity
- **Graph Construction**: $O(m)$, where $m$ is the number of edges.
- **DFS Traversal**: $O(n + m)$, where $n$ is the number of nodes and $m$ is the number of edges.
- **Overall**: $O(n + m)$.

### Space Complexity
- **Graph Storage**: $O(n + m)$ for the adjacency list.
- **Visitation States**: $O(n)$.
- **Recursive Stack**: $O(n)$ in the worst case (depth of recursion).
- **Overall**: $O(n + m)$.

---

## Alternative Approaches

1. **Kahn's Algorithm (BFS-based)**:
   - Uses an in-degree array to track the number of incoming edges for each node.
   - Nodes with zero in-degree are processed iteratively, and their dependencies are removed.
   - This approach is also $O(n + m)$ but may be easier to implement for some.

2. **Dynamic Programming**:
   - For problems where additional constraints (e.g., weights) are involved, dynamic programming on DAGs can be used.

---

## Extended Learning

1. **Applications of Topological Sorting**:
   - Task scheduling, build systems, dependency resolution, etc.
   
2. **Graph Algorithms**:
   - Cycle detection, strongly connected components, and shortest paths in DAGs.

3. **Advanced Graph Representations**:
   - Weighted graphs, adjacency matrices, and edge lists.

---

## Tips for Similar Problems

1. **Recognizing Topological Sort Problems**:
   - Look for phrases like "order of tasks", "prerequisites", or "dependencies".
   
2. **Cycle Detection**:
   - Always check for cycles when dealing with directed graphs and dependencies.

3. **Efficient Graph Representation**:
   - Use adjacency lists for sparse graphs and adjacency matrices for dense graphs.

4. **Practice Problems**:
   - Solve problems like "Alien Dictionary", "Task Scheduling", or "Build Order" to reinforce concepts.

--- 

