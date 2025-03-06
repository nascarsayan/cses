# Removing Digits

[Problem Link](https://cses.fi/problemset/task/1637) | [Solution Link](../../solutions/03_Dynamic_Programming/05_1637_Removing_Digits.cpp)

## TL;DR

The problem involves finding the minimum number of steps to reduce a number $n$ to $0$ by repeatedly subtracting one of its digits. The solution uses dynamic programming (DP) to compute the minimum steps for each number up to $n$, leveraging previously computed results. The time complexity is $O(n \cdot d)$, where $d$ is the number of digits in $n$.

---

## Problem Overview

You are given an integer $n$ and need to reduce it to $0$ in the minimum number of steps. In each step, you can subtract one of the digits of the current number. The task is to determine the minimum number of steps required.

### Example
For $n = 27$, an optimal sequence of steps is:
$$
27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0
$$
This requires $5$ steps.

---

## Solution Approach

### Key Idea
The problem can be solved using **dynamic programming**. The main idea is to compute the minimum number of steps for each number $i$ from $1$ to $n$, using the results of smaller subproblems.

### Steps
1. **Define the DP State**:
   Let `dp[i]` represent the minimum number of steps required to reduce the number $i$ to $0$.

2. **Base Case**:
   For single-digit numbers, `dp[i] = 1` because you can subtract the number itself in one step.

3. **Transition**:
   For each number $i$, iterate through its digits. For each digit $d$, compute:
   $$
   dp[i] = \min(dp[i], dp[i - d] + 1)
   $$
   This represents subtracting the digit $d$ from $i$ and adding one step to the result of $dp[i - d]$.

4. **Iterative Computation**:
   Start from $1$ and compute `dp[i]` for all numbers up to $n$ using the above transition.

5. **Output**:
   The result is stored in `dp[n]`.

### Pseudocode
- Initialize `dp[0] = 0` and `dp[i] = \infty` for all $i > 0$.
- For each $i$ from $1$ to $n$:
  - Extract the digits of $i$.
  - For each digit $d$, update `dp[i] = \min(dp[i], dp[i - d] + 1)`.
- Return `dp[n]`.

---

## Key Learning Points

1. **Dynamic Programming**:
   - This problem demonstrates how to use DP for problems with overlapping subproblems and optimal substructure.
   - The state transition relies on breaking the problem into smaller subproblems.

2. **Digit Manipulation**:
   - Extracting digits of a number is a common operation in competitive programming. This is typically done using modulo and division operations.

3. **Optimization**:
   - The solution avoids recomputation by storing intermediate results in the `dp` array.

---

## Common Pitfalls

1. **Incorrect Base Case**:
   Forgetting to initialize single-digit numbers with `dp[i] = 1` can lead to incorrect results.

2. **Digit Extraction**:
   Ensure that only non-zero digits are considered during subtraction. Subtracting $0$ is invalid.

3. **Memory Constraints**:
   Using an unnecessarily large DP array or inefficient data structures can lead to memory issues for large $n$.

---

## Complexity

### Time Complexity
- For each number $i$ from $1$ to $n$, we extract its digits (at most $\log_{10}(i)$ digits).
- Thus, the total time complexity is:
  $$
  O(n \cdot \log_{10}(n))
  $$

### Space Complexity
- The solution requires an array `dp` of size $n + 1$.
- Space complexity: $O(n)$.

---

## Alternative Approaches

1. **Breadth-First Search (BFS)**:
   - Treat the problem as a shortest-path problem in an implicit graph where each node represents a number, and edges represent subtracting a digit.
   - Use BFS to find the shortest path from $n$ to $0$.
   - Time complexity is similar to the DP approach but may have higher constant factors.

2. **Greedy Approach**:
   - A naive greedy approach would subtract the largest digit at each step. However, this does not guarantee the minimum number of steps (e.g., for $n = 27$, subtracting $7$ first is suboptimal).

---

## Extended Learning

1. **Digit DP**:
   - Problems involving digit manipulation often use a technique called "digit DP," which is useful for constraints involving digits of a number.

2. **Shortest Path Algorithms**:
   - This problem can be modeled as a shortest-path problem in a graph, connecting it to algorithms like Dijkstra's or BFS.

3. **State Compression**:
   - Explore how to reduce memory usage in DP problems by compressing states or using iterative approaches.

---

## Tips for Similar Problems

1. **Identify Overlapping Subproblems**:
   - If the problem involves reducing a number or state iteratively, consider DP.

2. **Model as a Graph**:
   - Many problems can be reframed as graph traversal problems, enabling the use of BFS or DFS.

3. **Digit Manipulation**:
   - Practice extracting and working with digits of a number, as this is a common operation in competitive programming.

4. **Start Small**:
   - Solve for small values of $n$ manually to understand the problem and verify your approach.

---