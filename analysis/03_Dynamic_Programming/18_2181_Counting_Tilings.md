# Counting Tilings

[Problem Link](https://cses.fi/problemset/task/2181) | [Solution Link](../../solutions/03_Dynamic_Programming/18_2181_Counting_Tilings.cpp)

## TL;DR

The problem involves counting the number of ways to tile an $n \times m$ grid using $1 \times 2$ and $2 \times 1$ tiles. The solution uses dynamic programming with bitmasking to represent the state of each row and transitions between valid states. This approach efficiently handles the constraints, leveraging modular arithmetic to avoid overflow.

---

## Problem Overview

The task is to determine the number of ways to completely tile an $n \times m$ grid using dominoes of size $1 \times 2$ and $2 \times 1$. The solution must account for all valid tiling configurations and return the result modulo $10^9 + 7$. 

Key constraints include:
- $n$ (height of the grid) is small ($1 \leq n \leq 10$), making it feasible to use bitmasking to represent rows.
- $m$ (width of the grid) can be large ($1 \leq m \leq 1000$), necessitating an efficient algorithm.

---

## Solution Approach

### 1. **Dynamic Programming with Bitmasking**
The main idea is to use dynamic programming (DP) to compute the number of ways to tile the grid column by column. Each state in the DP is represented by a bitmask that encodes the "current row configuration" (i.e., which cells in the current row are already covered).

#### Key Components:
- **State Representation**: Use a bitmask of length $n$ to represent the current row. A `0` in the bitmask means the cell is uncovered, and a `1` means it is covered.
- **Transitions**: For each column, compute all possible ways to transition from one valid row configuration to another by placing tiles. This involves recursively filling the uncovered cells with horizontal or vertical dominoes.
- **Base Case**: The initial state is an empty grid (all cells uncovered), represented by a bitmask of all zeros.
- **Final State**: Count the number of ways to reach a fully covered grid (all cells covered) after processing all $m$ columns.

### 2. **Recursive Transition Function**
The transition function recursively tries to place tiles in all possible ways:
- Place a horizontal domino ($1 \times 2$) across two adjacent cells in the current row.
- Place a vertical domino ($2 \times 1$) spanning the current row and the row below.

The recursion ensures that all valid configurations are explored, and invalid configurations (e.g., overlapping tiles or uncovered cells) are skipped.

### 3. **Modulo Arithmetic**
Since the number of tiling configurations can grow very large, all computations are performed modulo $10^9 + 7$ to prevent overflow and meet the problem's requirements.

### 4. **Optimization with Precomputation**
To speed up transitions:
- Precompute all valid row configurations for a given $n$.
- Precompute valid transitions between configurations to avoid recalculating them repeatedly.

---

## Key Learning Points

1. **Bitmasking for State Representation**: Representing the state of a grid row as a bitmask is a powerful technique for problems involving small dimensions and combinatorial configurations.
2. **Dynamic Programming with Transitions**: Efficiently transitioning between states is crucial for solving tiling problems.
3. **Recursive Backtracking**: Recursive approaches can explore all valid configurations, provided the state space is manageable.
4. **Modulo Arithmetic**: Essential for handling large numbers in combinatorial problems.

---

## Common Pitfalls

1. **Mismanaging Transitions**: Forgetting to handle edge cases (e.g., overlapping tiles or uncovered cells) can lead to incorrect results.
2. **Inefficient State Representation**: Using an inefficient representation for the grid state can lead to excessive memory usage or slow transitions.
3. **Modulo Errors**: Failing to apply modulo $10^9 + 7$ consistently can cause overflow or incorrect results.
4. **Ignoring Symmetry**: Not leveraging symmetry in tiling configurations can lead to redundant computations.

---

## Complexity

### Time Complexity:
- **State Space**: There are $2^n$ possible bitmask states for a row.
- **Transitions**: For each state, transitions to other states are precomputed.
- **Overall**: The DP table has $O(m \cdot 2^n)$ entries, and transitions are $O(2^n \cdot 2^n)$ in the worst case. Thus, the total complexity is approximately:
  $$ O(m \cdot 2^n \cdot 2^n) = O(m \cdot 4^n) $$
  Since $n \leq 10$, this is feasible for $m \leq 1000$.

### Space Complexity:
- The DP table requires $O(m \cdot 2^n)$ space.
- Precomputed transitions require $O(2^n \cdot 2^n)$ space.

---

## Alternative Approaches

1. **Matrix Exponentiation**:
   - Represent the transitions between states as a matrix and use matrix exponentiation to compute the result in $O(\log m)$ time for the $m$ columns.
   - This approach is faster for large $m$ but requires careful implementation of the transition matrix.

2. **Divide and Conquer**:
   - Divide the grid into smaller subproblems (e.g., tiling smaller subgrids) and combine results. This is less efficient for large $m$ but can be useful for specific cases.

---

## Extended Learning

1. **Domino Tiling Problems**:
   - Explore other tiling problems, such as tiling with $2 \times 2$ tiles or L-shaped tiles.
2. **Bitmask DP**:
   - Study other problems that use bitmasking for state representation, such as subset problems or graph problems.
3. **Matrix Exponentiation**:
   - Learn how to use matrix exponentiation for problems involving repeated transitions over a fixed state space.

---

## Tips for Similar Problems

1. **Recognize Small Dimensions**:
   - If one dimension of the grid is small, consider using bitmasking to represent states.
2. **Look for Modular Arithmetic**:
   - Problems involving large numbers often require modulo operations; implement them carefully.
3. **Precompute Transitions**:
   - For problems with repetitive transitions, precompute valid configurations to save time.
4. **Use Symmetry**:
   - Exploit symmetry in the problem to reduce the number of states or transitions.

---