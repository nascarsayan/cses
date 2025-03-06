# Counting Rooms

[Problem Link](https://cses.fi/problemset/task/1192) | [Solution Link](../../solutions/04_Graph_Algorithms/01_1192_Counting_Rooms.cpp)

## TL;DR

The problem involves counting connected components (rooms) in a grid where `.` represents floor and `#` represents walls. The solution uses a graph traversal technique (BFS) to explore each connected component and increment a counter for every new room discovered. The grid is padded with a boundary to simplify edge handling, and the BFS ensures all reachable floor tiles are marked as visited.

---

## Problem Overview

You are given an $n \times m$ grid representing a building's layout. Each cell is either a floor (`.`) or a wall (`#`). A room is defined as a connected component of floor cells, where connectivity is determined by adjacent cells (up, down, left, right). The task is to count the number of distinct rooms in the building.

### Input:
- Two integers $n$ and $m$ representing the grid dimensions.
- $n$ lines of $m$ characters (`.` or `#`) representing the grid.

### Output:
- A single integer: the number of rooms.

---

## Solution Approach

### Key Idea:
The problem can be modeled as a graph traversal task:
- Each floor cell (`.`) is a node.
- An edge exists between two nodes if they are adjacent (up, down, left, right).

The goal is to count the number of connected components in this graph.

### Steps:
1. **Grid Representation**:
   - The grid is stored in a 2D vector, with an additional boundary of walls (`2`) to simplify edge checks.
   - Floor cells are initialized as `0` (unvisited), and walls are initialized as `2`.

2. **Traversal**:
   - Use BFS (Breadth-First Search) to explore each connected component.
   - Start from any unvisited floor cell (`0`), mark it as visited (`1`), and explore all reachable floor cells.
   - Increment a counter for every new BFS initiation, as it corresponds to a new room.

3. **Direction Handling**:
   - Use a predefined list of directions `dirs = {(-1, 0), (0, 1), (1, 0), (0, -1)}` to simplify movement in the grid.

4. **Boundary Check**:
   - A helper function ensures that coordinates are within the valid range of the grid.

5. **Output**:
   - After processing all cells in the grid, the counter holds the total number of rooms.

---

## Key Learning Points

1. **Graph Representation in Grids**:
   - Grids can be treated as graphs where each cell is a node, and edges are defined by adjacency.

2. **Connected Components**:
   - Counting connected components is a common graph problem, often solved using DFS or BFS.

3. **Boundary Simplification**:
   - Padding the grid with a boundary simplifies edge cases, such as accessing out-of-bounds indices.

4. **Traversal Techniques**:
   - BFS and DFS are interchangeable for exploring connected components, but BFS is often easier to implement iteratively.

---

## Common Pitfalls

1. **Out-of-Bounds Access**:
   - Forgetting to check grid boundaries can lead to runtime errors. The solution avoids this by padding the grid with walls.

2. **Marking Visited Nodes**:
   - Failing to mark nodes as visited during traversal can lead to infinite loops or incorrect results.

3. **Direction Handling**:
   - Incorrectly defining movement directions (e.g., missing one or reversing coordinates) can lead to incomplete exploration.

4. **Initialization Errors**:
   - Incorrectly initializing the grid or forgetting to reset variables between test cases can cause bugs.

---

## Complexity

### Time Complexity:
- **Grid Traversal**:
  - Each cell is visited at most once, leading to a time complexity of $O(n \times m)$.
- **BFS**:
  - Each BFS traversal processes all reachable floor cells in a connected component, which is bounded by the total number of cells.

Overall: **$O(n \times m)$**

### Space Complexity:
- **Grid Storage**:
  - The grid requires $O(n \times m)$ space.
- **BFS Queue**:
  - In the worst case, the queue can hold all floor cells in a connected component, which is $O(n \times m)$.

Overall: **$O(n \times m)$**

---

## Alternative Approaches

1. **Depth-First Search (DFS)**:
   - DFS can be used instead of BFS for traversal. It can be implemented recursively or iteratively using a stack.
   - Recursive DFS may lead to stack overflow for large grids.

2. **Union-Find (Disjoint Set Union)**:
   - Treat each floor cell as a node and use union-find to group connected components.
   - This approach is less intuitive for grid problems but works well for sparse graphs.

3. **Flood Fill**:
   - A variation of DFS/BFS, flood fill is commonly used in image processing and can be adapted for this problem.

---

## Extended Learning

1. **Graph Traversal Algorithms**:
   - Explore BFS, DFS, and their applications in connected components, shortest paths, and flood fill.

2. **Union-Find**:
   - Learn about union-find for efficiently managing connected components in dynamic graphs.

3. **Grid-Based Problems**:
   - Practice problems involving grids, such as maze solving, island counting, and pathfinding.

4. **Boundary Simplification**:
   - Understand how padding simplifies edge handling in grid-based problems.

---

## Tips for Similar Problems

1. **Recognize Graph Structure**:
   - If a problem involves connectivity or adjacency in a grid, it can often be modeled as a graph problem.

2. **Traversal Choice**:
   - Use BFS for iterative solutions and DFS for recursive solutions, depending on the problem constraints.

3. **Boundary Handling**:
   - Consider padding the grid or using helper functions to manage boundary checks.

4. **Marking Visited Nodes**:
   - Always ensure nodes are marked as visited to avoid redundant work or infinite loops.

5. **Practice**:
   - Solve problems like "Number of Islands" (LeetCode), "Flood Fill" (LeetCode), and "Connected Components in a Graph" to build intuition.