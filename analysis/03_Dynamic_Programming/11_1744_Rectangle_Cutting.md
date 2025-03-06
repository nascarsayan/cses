# Rectangle Cutting

[Problem Link](https://cses.fi/problemset/task/1744) | [Solution Link](../../solutions/03_Dynamic_Programming/11_1744_Rectangle_Cutting.cpp)

## TL;DR

The problem is solved using dynamic programming. A 2D DP table is used to store the minimum number of cuts required to divide a rectangle of size $a \times b$ into squares. The solution iteratively calculates the minimum cuts for all sub-rectangles by considering both horizontal and vertical cuts. The time complexity is $O(a \cdot b \cdot \max(a, b))$, which is efficient for the given constraints.

---

## Problem Overview

The task is to divide a given $a \times b$ rectangle into squares using the minimum number of cuts. Each cut must divide the rectangle into two smaller rectangles, and the side lengths of all resulting rectangles must remain integers.

### Input:
- Two integers $a$ and $b$ representing the dimensions of the rectangle.

### Output:
- A single integer denoting the minimum number of cuts required.

### Constraints:
- $1 \leq a, b \leq 500$

---

## Solution Approach

The solution uses **dynamic programming (DP)** to compute the minimum number of cuts required for rectangles of all dimensions up to $a \times b$.

### Key Idea:
If a rectangle is already a square (i.e., $a = b$), no cuts are needed. Otherwise, the rectangle can be split either horizontally or vertically, and the problem is recursively solved for the resulting sub-rectangles.

### DP Table:
Let `dp[i][j]` represent the minimum number of cuts required to divide a rectangle of size $i \times j$ into squares.

#### Base Case:
- If $i = j$, then `dp[i][j] = 0` (no cuts are needed for a square).

#### Transition:
- For a rectangle of size $i \times j$:
  - Try all possible **horizontal cuts**: Cut the rectangle into two smaller rectangles of sizes $k \times j$ and $(i-k) \times j$ for $1 \leq k < i$.
    $$ dp[i][j] = \min(dp[i][j], dp[k][j] + dp[i-k][j] + 1) $$
  - Try all possible **vertical cuts**: Cut the rectangle into two smaller rectangles of sizes $i \times k$ and $i \times (j-k)$ for $1 \leq k < j$.
    $$ dp[i][j] = \min(dp[i][j], dp[i][k] + dp[i][j-k] + 1) $$

#### Iterative Computation:
The DP table is filled iteratively for all rectangles of size $1 \times 1$ to $a \times b$.

### Implementation Highlights:
1. Initialize a 2D DP table `dp` of size $(a+1) \times (b+1)$ with large values (e.g., $10^9$).
2. Set `dp[i][i] = 0` for all $i$ (base case for squares).
3. For each rectangle size $(i, j)$, compute the minimum cuts by considering all possible horizontal and vertical cuts.
4. The final answer is stored in `dp[a][b]`.

---

## Key Learning Points

1. **Dynamic Programming for 2D Problems**:
   - This problem demonstrates how to use a 2D DP table to solve problems involving rectangular grids or shapes.
   - The transitions involve breaking the problem into smaller subproblems (sub-rectangles).

2. **Optimization by Precomputing**:
   - Precomputing the results for all smaller rectangles allows efficient computation for larger rectangles.

3. **Divide-and-Conquer with DP**:
   - The problem is inherently a divide-and-conquer problem, where the rectangle is split into smaller parts, and the solution is built from the results of those parts.

---

## Common Pitfalls

1. **Incorrect Base Case**:
   - Forgetting to set `dp[i][i] = 0` for squares can lead to incorrect results.

2. **Off-by-One Errors**:
   - Ensure that the loops for horizontal and vertical cuts iterate correctly (e.g., $1 \leq k < i$ and $1 \leq k < j$).

3. **Inefficient Transitions**:
   - Not minimizing over all possible cuts can lead to suboptimal results.

4. **Memory Usage**:
   - The DP table can be large for the maximum constraints ($500 \times 500$), so ensure sufficient memory allocation.

---

## Complexity

### Time Complexity:
- Filling the DP table involves iterating over all rectangle sizes $(i, j)$.
- For each rectangle, we consider up to $i$ horizontal cuts and $j$ vertical cuts.
- Total complexity:
  $$ O(a \cdot b \cdot \max(a, b)) $$

### Space Complexity:
- The DP table requires $O(a \cdot b)$ space.

---

## Alternative Approaches

1. **Greedy Approach**:
   - A naive greedy approach could involve repeatedly cutting the largest possible square from the rectangle. However, this does not guarantee the minimum number of cuts.

2. **Recursive with Memoization**:
   - Instead of iterative DP, a recursive approach with memoization could be used. This would involve solving the problem recursively for sub-rectangles and storing the results to avoid recomputation.

---

## Extended Learning

1. **2D Dynamic Programming**:
   - Problems involving grids, matrices, or rectangular shapes often use 2D DP. Examples include matrix chain multiplication, tiling problems, and grid pathfinding.

2. **Divide-and-Conquer Optimization**:
   - This problem is a good example of combining divide-and-conquer with dynamic programming.

3. **Geometric DP**:
   - Problems involving shapes (e.g., cutting, tiling, or partitioning) often require geometric reasoning combined with DP.

---

## Tips for Similar Problems

1. **Identify Subproblems**:
   - Break the problem into smaller, independent subproblems (e.g., sub-rectangles).

2. **Use DP Tables**:
   - For problems involving 2D grids or shapes, a 2D DP table is often a natural choice.

3. **Optimize Transitions**:
   - Ensure that all possible transitions (e.g., cuts) are considered to guarantee correctness.

4. **Start with Base Cases**:
   - Clearly define the base cases for the smallest subproblems.

5. **Precompute Results**:
   - Precomputing results for smaller subproblems can significantly speed up the solution for larger inputs.