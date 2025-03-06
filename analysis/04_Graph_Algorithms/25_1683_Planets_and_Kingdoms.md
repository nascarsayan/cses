# Planets and Kingdoms

[Problem Link](https://cses.fi/problemset/task/1683) | [Solution Link](../../solutions/04_Graph_Algorithms/25_1683_Planets_and_Kingdoms.cpp)

## TL;DR

The problem involves finding the Strongly Connected Components (SCCs) of a directed graph, where each SCC represents a "kingdom." The solution uses Kosaraju's or Tarjan's algorithm to efficiently identify SCCs. The output includes the number of SCCs and the kingdom label for each planet. The approach runs in $O(n + m)$ time, making it suitable for large inputs.

---

## Problem Overview

The task is to group planets into "kingdoms" based on the condition that two planets belong to the same kingdom if and only if there exists a path from one to the other and vice versa. This boils down to finding the Strongly Connected Components (SCCs) of a directed graph, where nodes represent planets and edges represent teleporters.

### Input:
- $n$: Number of planets (nodes).
- $m$: Number of teleporters (edges).
- $m$ pairs of integers $(a, b)$ indicating a directed edge from $a$ to $b$.

### Output:
- $k$: Number of kingdoms (SCCs).
- A kingdom label (1 to $k$) for each planet.

---

## Solution Approach

The problem is a classic application of finding SCCs in a directed graph. Here's the step-by-step breakdown:

### 1. **Graph Representation**
The graph is represented using adjacency lists:
- `adj`: Adjacency list for the original graph.
- `rev_adj`: Adjacency list for the reversed graph (used in Kosaraju's algorithm).

### 2. **Finding SCCs**
To find SCCs, we can use **Kosaraju's Algorithm** or **Tarjan's Algorithm**. Below is an outline of Kosaraju's approach:

#### **Step 1: Topological Ordering**
Perform a Depth First Search (DFS) on the original graph to compute a "finish order" of nodes. This order is stored in a stack, where nodes are pushed after all their neighbors have been visited.

#### **Step 2: Reverse the Graph**
Reverse all edges in the graph. This creates a new graph where the directions of all teleporters are flipped.

#### **Step 3: Process Nodes in Reverse Finish Order**
Perform DFS on the reversed graph, processing nodes in the reverse order of their finish times (from the stack). Each DFS traversal identifies one SCC, and all nodes visited during this traversal belong to the same SCC.

### 3. **Assign Kingdom Labels**
Each SCC is assigned a unique label (1 to $k$). The nodes visited in the same DFS traversal on the reversed graph are assigned the same label.

### 4. **Output**
- The number of SCCs ($k$).
- The kingdom label for each planet.

---

## Key Learning Points

1. **Strongly Connected Components (SCCs):**
   - SCCs are subgraphs where every node is reachable from every other node in the subgraph.
   - SCCs partition the graph into disjoint subsets.

2. **Kosaraju's Algorithm:**
   - Efficiently finds SCCs in $O(n + m)$ time by leveraging two DFS passes (one on the original graph and one on the reversed graph).

3. **Graph Reversal:**
   - Reversing the graph is a key step in Kosaraju's algorithm to identify SCCs.

4. **DFS Finish Order:**
   - The order in which nodes finish during the first DFS is critical for processing nodes in the correct order in the second DFS.

5. **Applications of SCCs:**
   - SCCs are widely used in problems involving directed graphs, such as dependency analysis, circuit detection, and network flow.

---

## Common Pitfalls

1. **Incorrect Graph Reversal:**
   - Ensure all edges are reversed correctly when constructing the reversed graph.

2. **DFS Order in Second Pass:**
   - Nodes must be processed in reverse finish order during the second DFS. Failing to do so will result in incorrect SCC identification.

3. **Handling Large Inputs:**
   - The graph can have up to $10^5$ nodes and $2 \cdot 10^5$ edges. Ensure the implementation is efficient and avoids unnecessary operations.

4. **Disconnected Graphs:**
   - The graph may not be fully connected. Ensure the algorithm handles disconnected components correctly.

---

## Complexity

### Time Complexity:
- **Graph Construction:** $O(n + m)$ for building adjacency lists.
- **First DFS (Finish Order):** $O(n + m)$.
- **Graph Reversal:** $O(n + m)$.
- **Second DFS (SCC Identification):** $O(n + m)$.
- **Total:** $O(n + m)$.

### Space Complexity:
- **Graph Storage:** $O(n + m)$ for adjacency lists.
- **Stack and Visited Arrays:** $O(n)$.
- **Total:** $O(n + m)$.

---

## Alternative Approaches

1. **Tarjan's Algorithm:**
   - A single-pass DFS-based algorithm that uses a stack and low-link values to identify SCCs in $O(n + m)$ time.
   - More complex to implement but avoids the need for graph reversal.

2. **Path-Based SCC Algorithm:**
   - Another single-pass DFS algorithm that uses a path stack to track SCCs.
   - Less commonly used but also runs in $O(n + m)$.

---

## Extended Learning

1. **Related Problems:**
   - Finding connected components in undirected graphs.
   - Topological sorting of directed acyclic graphs (DAGs).
   - 2-SAT problem (can be solved using SCCs).

2. **Graph Theory Concepts:**
   - Directed Acyclic Graph (DAG): The SCCs of a graph form a DAG when collapsed into single nodes.
   - Transpose of a Graph: Used in Kosaraju's algorithm.

3. **Algorithms:**
   - Depth First Search (DFS).
   - Breadth First Search (BFS) for connected components in undirected graphs.

---

## Tips for Similar Problems

1. **Recognizing SCC Problems:**
   - Look for conditions involving bidirectional reachability (e.g., "reachable from $a$ to $b$ and vice versa").
   - Problems involving cycles in directed graphs often involve SCCs.

2. **Efficient Graph Traversal:**
   - Use adjacency lists for efficient graph representation.
   - Use iterative DFS to avoid stack overflow in languages with limited recursion depth.

3. **Preprocessing for Large Graphs:**
   - Optimize input parsing and graph construction for large graphs.

4. **Debugging Graph Algorithms:**
   - Visualize the graph and its SCCs for small test cases.
   - Verify edge cases like disconnected graphs, self-loops, and multiple edges.

---