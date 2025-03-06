# Array Description

[Problem Link](https://cses.fi/problemset/task/1746) | [Solution Link](../../solutions/03_Dynamic_Programming/08_1746_Array_Description.cpp)

## TL;DR

The problem is solved using dynamic programming (DP) to count the number of valid arrays that satisfy the constraints. A 2D DP table is used where `dp[i][v]` represents the number of ways to construct a valid array up to index `i` with value `v` at position `i`. The solution iterates through the array, updating the DP table based on the constraints, and finally sums up the values in the last row of the DP table to get the result.

---

## Problem Overview

You are given an array of size $n$ where each element is between $1$ and $m$, but some elements may be unknown (denoted as $0$). The task is to count the number of arrays that satisfy the following conditions:

1. The absolute difference between two adjacent elements is at most $1$.
2. The values of the array must respect the given constraints (i.e., known values must remain fixed).

The result should be computed modulo $10^9 + 7$.

---

## Solution Approach

### Key Idea

The problem is solved using dynamic programming. The main idea is to maintain a DP table where each entry represents the number of ways to construct valid subarrays up to a certain point, considering the constraints.

### DP Definition

Let `dp[i][v]` represent the number of ways to construct a valid array up to index $i$ such that the value at position $i$ is $v$.

### Transition Relation

For each index $i$:
- If the value at index $i$ is fixed (i.e., $x_i \neq 0$), then:
  $$
  dp[i][x_i] = dp[i-1][x_i-1] + dp[i-1][x_i] + dp[i-1][x_i+1]
  $$
  (only valid indices are considered, i.e., $x_i-1$, $x_i$, $x_i+1$ must be within $[1, m]$).

- If the value at index $i$ is unknown (i.e., $x_i = 0$), then:
  $$
  dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1] \quad \text{for all } v \in [1, m]
  $$

### Base Case

At index $0$:
- If $x_0 \neq 0$, then `dp[0][x_0] = 1` (only one valid way to start the array).
- If $x_0 = 0$, then `dp[0][v] = 1` for all $v \in [1, m]` (any value is valid).

### Final Result

The result is the sum of all values in the last row of the DP table:
$$
\text{Result} = \sum_{v=1}^m dp[n-1][v] \mod (10^9 + 7)
$$

### Implementation Highlights

1. **Initialization**: The DP table is initialized based on the first element of the array.
2. **Iterative Updates**: For each index, the DP table is updated using the transition relation.
3. **Modulo Operation**: All calculations are performed modulo $10^9 + 7$ to prevent overflow.

---

## Key Learning Points

1. **Dynamic Programming with States**: This problem demonstrates how to define and use a DP table with two dimensions (index and value) to solve a problem with constraints.
2. **Handling Constraints**: The solution efficiently handles fixed and unknown values in the array by adjusting the DP transitions.
3. **Modulo Arithmetic**: Modular arithmetic is crucial in competitive programming to handle large numbers.

---

## Common Pitfalls

1. **Out-of-Bounds Access**: When accessing `dp[i-1][v-1]` or `dp[i-1][v+1]`, ensure that $v-1$ and $v+1$ are within the range $[1, m]$.
2. **Incorrect Base Case**: Failing to initialize the DP table correctly for the first element can lead to incorrect results.
3. **Inefficient Implementation**: Using a naive approach without leveraging the constraints or optimizing the DP transitions can lead to time limit exceeded (TLE) errors.

---

## Complexity

### Time Complexity

The solution iterates through the array of size $n$ and, for each index, performs operations proportional to $m$. Thus, the time complexity is:
$$
O(n \cdot m)
$$

### Space Complexity

The DP table requires $O(n \cdot m)$ space. However, since only the previous row is needed at any point, the space can be optimized to $O(m)$ by using two rows alternately.

---

## Alternative Approaches

1. **Space Optimization**: Instead of maintaining the entire DP table, use two arrays of size $m$ to store the current and previous rows, reducing the space complexity to $O(m)$.
2. **Segment Tree or Fenwick Tree**: For problems with more complex constraints, advanced data structures like segment trees can be used to efficiently compute transitions.

---

## Extended Learning

1. **State Compression in DP**: Learn how to reduce the space complexity of DP problems by storing only necessary states.
2. **Modular Arithmetic**: Understanding modular arithmetic is essential for problems involving large numbers.
3. **Sliding Window Optimization**: In some cases, sliding window techniques can replace full DP tables.

---

## Tips for Similar Problems

1. **Look for Constraints**: Problems with constraints on adjacent elements often lend themselves to DP solutions.
2. **Define States Clearly**: Clearly define what each state in the DP table represents.
3. **Optimize Transitions**: Focus on optimizing the transition relations to avoid redundant calculations.
4. **Modulo Arithmetic**: Always consider modular arithmetic when the result can be large.

---