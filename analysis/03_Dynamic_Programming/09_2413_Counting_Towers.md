# Counting Towers

[Problem Link](https://cses.fi/problemset/task/2413) | [Solution Link](../../solutions/03_Dynamic_Programming/09_2413_Counting_Towers.cpp)

## TL;DR

The problem involves counting the number of ways to build a tower of width 2 and height $n$ using dynamic programming. The solution uses two states to represent configurations of the top layer of the tower and iteratively computes the number of valid towers for increasing heights. The result is precomputed for all possible heights up to the maximum input, ensuring efficient query responses.

---

## Problem Overview

The task is to determine the number of distinct towers of width 2 and height $n$ that can be constructed using blocks, where mirrored and rotated configurations are considered distinct. The solution must handle multiple test cases efficiently, with constraints allowing heights up to $10^6$ and up to 100 test cases.

---

## Solution Approach

### Key Idea

The problem is solved using **dynamic programming (DP)** by breaking it into subproblems based on the configuration of the top layer of the tower. Two states are defined:

1. **`dp[i][0]`**: The number of towers of height $i$ where the top layer is a "flat" configuration (both columns are filled).
2. **`dp[i][1]`**: The number of towers of height $i$ where the top layer is a "staggered" configuration (one column is higher than the other).

The recurrence relations are derived based on how new blocks can be added to the top of the tower:

- **Flat to Flat**: A flat top layer can transition to another flat top layer in 4 ways.
- **Flat to Staggered**: A flat top layer can transition to a staggered top layer in 1 way.
- **Staggered to Flat**: A staggered top layer can transition to a flat top layer in 1 way.
- **Staggered to Staggered**: A staggered top layer can transition to another staggered top layer in 2 ways.

### Recurrence Relations

Using the above transitions, the recurrence relations are:

$$
dp[i][1] = (2 \cdot dp[i-1][1] + dp[i-1][0}) \mod (10^9 + 7)
$$

$$
dp[i][0] = (dp[i-1][1] + 4 \cdot dp[i-1][0}) \mod (10^9 + 7)
$$

The total number of towers for height $i$ is:

$$
\text{total}[i] = (dp[i][0] + dp[i][1]) \mod (10^9 + 7)
$$

### Precomputation

Since the maximum height $n$ can be as large as $10^6$, the solution precomputes the DP table for all heights up to the maximum input. This allows each test case to be answered in $O(1)$ time.

### Implementation Steps

1. Parse the input and determine the maximum height among all test cases.
2. Initialize the DP table with base cases:
   - $dp[1][0] = 1$ (1 flat tower of height 1)
   - $dp[1][1] = 1$ (1 staggered tower of height 1)
3. Use the recurrence relations to fill the DP table up to the maximum height.
4. For each test case, output the precomputed result for the given height.

---

## Key Learning Points

1. **Dynamic Programming with States**: Breaking the problem into states based on configurations simplifies the recurrence relations.
2. **Precomputation for Efficiency**: Precomputing results for all possible inputs ensures that queries can be answered in constant time.
3. **Modulo Arithmetic**: Using modular arithmetic prevents overflow and ensures results are within the required range.
4. **Transition Diagrams**: Visualizing state transitions helps in deriving recurrence relations.

---

## Common Pitfalls

1. **Incorrect Base Cases**: Forgetting to initialize the base cases correctly can lead to incorrect results.
2. **Modulo Arithmetic Errors**: Missing the modulo operation in intermediate steps can cause overflow or incorrect results.
3. **Inefficient Query Handling**: Recomputing results for each test case instead of precomputing can lead to time limit exceeded (TLE) errors.

---

## Complexity

### Time Complexity

- **Precomputation**: Filling the DP table takes $O(n_{\text{max}})$, where $n_{\text{max}}$ is the maximum height among all test cases.
- **Query Handling**: Each query is answered in $O(1)$ time.

Overall time complexity: $O(n_{\text{max}} + t)$, where $t$ is the number of test cases.

### Space Complexity

- The DP table requires $O(n_{\text{max}})$ space.

---

## Alternative Approaches

1. **Matrix Exponentiation**: The recurrence relations can be represented as a matrix multiplication, allowing for $O(\log n)$ computation for each height. This is useful if precomputation is not feasible due to memory constraints.
2. **Recursive DP with Memoization**: A recursive approach with memoization can also solve the problem but may be slower due to function call overhead.

---

## Extended Learning

1. **State-Based DP**: Problems involving configurations or transitions often benefit from state-based DP approaches.
2. **Matrix Exponentiation**: Learning how to represent linear recurrences as matrix multiplications is a powerful tool for solving similar problems.
3. **Combinatorics in DP**: Understanding how combinatorial transitions work can help in deriving recurrence relations.

---

## Tips for Similar Problems

1. **Identify States**: Break the problem into smaller subproblems based on configurations or states.
2. **Derive Recurrences**: Use transitions between states to derive recurrence relations.
3. **Precompute for Efficiency**: If constraints allow, precompute results to handle multiple queries efficiently.
4. **Modulo Arithmetic**: Always handle large numbers carefully using modular arithmetic.
5. **Visualize Transitions**: Drawing diagrams for state transitions can simplify complex problems.