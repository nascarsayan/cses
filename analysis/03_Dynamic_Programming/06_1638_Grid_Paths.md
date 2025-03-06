# Grid Paths

[Problem Link](https://cses.fi/problemset/task/1638) | [Solution Link](../../solutions/03_Dynamic_Programming/06_1638_Grid_Paths.cpp)

## TL;DR

The problem is solved using a **dynamic programming (DP)** approach. A 2D DP table is used to count the number of ways to reach each cell in the grid, considering only moves to the right or downward. Obstacles (`*`) are treated as cells with zero paths. The solution ensures modular arithmetic with $10^9+7$ to handle large numbers efficiently.

---

## Problem Overview

You are given an $n \times n$ grid where some cells contain traps (`*`) and others are empty (`.`). Starting from the top-left corner, you need to calculate the number of distinct paths to the bottom-right corner, moving only right or down. The result must be computed modulo $10^9+7$.

### Constraints:
- $1 \leq n \leq 1000$
- Input grid size and constraints require an efficient solution.

---

## Solution Approach

### Key Idea:
The problem is a classic **grid traversal problem** with obstacles, which can be solved using **dynamic programming**. The main idea is to calculate the number of ways to reach each cell based on the number of ways to reach its top and left neighbors.

### Steps:

1. **Input Parsing and Initialization**:
   - Read the grid size $n$ and the grid itself.
   - Initialize a DP table `grid` of size $(n+1) \times (n+1)$ with all values set to `-1` initially.
   - Mark cells containing traps (`*`) as `0` in the DP table, since they cannot be part of any path.

2. **Base Cases**:
   - If the starting cell `(1, 1)` or the ending cell `(n, n)` is a trap, output `0` immediately since no paths are possible.
   - Set the top row and leftmost column of the DP table to `0` to handle boundary conditions.

3. **Dynamic Programming Transition**:
   - For each cell `(i, j)` in the grid:
     - If the cell is a trap (`grid[i][j] == 0`), skip it.
     - Otherwise, calculate the number of ways to reach `(i, j)` as:
       $$
       \text{grid}[i][j] = (\text{grid}[i-1][j] + \text{grid}[i][j-1]) \mod 10^9+7
       $$
     - This formula ensures that the number of paths to `(i, j)` is the sum of paths from the cell directly above it and the cell directly to its left.

4. **Output**:
   - The value at `grid[n][n]` gives the total number of paths to the bottom-right corner modulo $10^9+7$.

### Modular Arithmetic:
- Since the number of paths can grow very large, all calculations are performed modulo $10^9+7$ to prevent overflow and meet the problem constraints.

---

## Key Learning Points

1. **Dynamic Programming for Grid Problems**:
   - Many grid-based problems can be solved using DP by breaking them into smaller subproblems (e.g., counting paths to each cell).

2. **Handling Obstacles**:
   - Obstacles can be treated as cells with zero paths, effectively blocking traversal.

3. **Boundary Conditions**:
   - Properly initializing the DP table and handling edge cases (e.g., traps at the start or end) is crucial.

4. **Modular Arithmetic**:
   - Use modular arithmetic to handle large numbers efficiently in competitive programming.

---

## Common Pitfalls

1. **Incorrect Initialization**:
   - Forgetting to initialize the DP table or handling traps incorrectly can lead to wrong results.

2. **Boundary Conditions**:
   - Not accounting for the grid boundaries (e.g., accessing out-of-bounds indices) can cause runtime errors.

3. **Modulo Errors**:
   - Forgetting to apply modulo $10^9+7$ at every step can lead to overflow or incorrect results.

4. **Starting or Ending Traps**:
   - If the starting or ending cell is a trap, the output must be `0`. Missing this edge case can lead to incorrect answers.

---

## Complexity

### Time Complexity:
- The solution iterates over all $n^2$ cells in the grid once.
- Each cell computation involves a constant amount of work (addition and modulo operation).
- **Time Complexity**: $O(n^2)$

### Space Complexity:
- The DP table requires $O(n^2)$ space to store the number of paths for each cell.
- **Space Complexity**: $O(n^2)$

---

## Alternative Approaches

1. **DFS with Memoization**:
   - Use depth-first search (DFS) to explore all paths recursively, with memoization to avoid redundant computations.
   - This approach is less efficient than the DP solution due to the overhead of recursion.

2. **Breadth-First Search (BFS)**:
   - Use BFS to traverse the grid level by level, keeping track of the number of ways to reach each cell.
   - BFS is less memory-efficient compared to DP for this problem.

3. **Space Optimization**:
   - Instead of maintaining a full $n \times n$ DP table, use a single array of size $n$ to store the current row's results, reducing space complexity to $O(n)$.

---

## Extended Learning

1. **Classic Grid Problems**:
   - Problems like "Unique Paths" and "Minimum Path Sum" are similar in nature and can be solved using DP.

2. **Obstacle Handling in Graphs**:
   - Learn how to incorporate obstacles into graph traversal algorithms like BFS or DFS.

3. **Modular Arithmetic**:
   - Master modular arithmetic techniques, as they are frequently used in competitive programming.

---

## Tips for Similar Problems

1. **Recognize Grid Traversal Patterns**:
   - Look for problems where you need to count paths or minimize/maximize costs in a grid.

2. **Dynamic Programming Indicators**:
   - If the problem involves breaking down a task into smaller overlapping subproblems, DP is likely a good approach.

3. **Handle Edge Cases Early**:
   - Always check for edge cases like blocked starting/ending points or grids of size $1 \times 1$.

4. **Optimize Space When Possible**:
   - For large grids, consider space-optimized DP solutions to reduce memory usage.

5. **Practice Modular Arithmetic**:
   - Ensure you apply modulo operations consistently to avoid overflow issues.