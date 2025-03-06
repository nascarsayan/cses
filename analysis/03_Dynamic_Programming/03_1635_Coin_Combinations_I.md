# Coin Combinations I

[Problem Link](https://cses.fi/problemset/task/1635) | [Solution Link](../../solutions/03_Dynamic_Programming/03_1635_Coin_Combinations_I.cpp)

## TL;DR

The problem is solved using a dynamic programming (DP) approach where a 1D array `dp` is used to store the number of ways to form each sum up to $x$. For each coin value, the solution iteratively updates the DP array by adding the number of ways to form the current sum minus the coin's value. The result is computed modulo $10^9 + 7$ to handle large numbers.

---

## Problem Overview

The task is to determine the number of distinct ways to form a target sum $x$ using a given set of $n$ coin denominations. Each coin can be used any number of times, and the order of coins in a combination matters. The result must be computed modulo $10^9 + 7$.

### Example
For coins $\{2, 3, 5\}$ and target sum $x = 9$, there are 8 valid combinations, such as $2+2+5$, $3+3+3$, etc.

---

## Solution Approach

### Dynamic Programming Formulation

The problem is a classic example of the **unbounded knapsack problem** where we aim to count the number of ways to achieve a target sum using given denominations. The solution uses a **bottom-up DP approach**:

1. **Define the DP State**:
   Let `dp[t]` represent the number of ways to form the sum $t$ using the given coins.

2. **Base Case**:
   - `dp[0] = 1`: There is exactly one way to form the sum $0$, which is by using no coins.

3. **Transition Relation**:
   - For each coin $c$ and each target sum $t$, if $c \leq t$, then:
     $$
     dp[t] = (dp[t] + dp[t - c]) \mod (10^9 + 7)
     $$
   - This means that the number of ways to form $t$ includes all the ways to form $t - c$ (by adding coin $c$ to those combinations).

4. **Iterative Update**:
   - Iterate over all possible sums from $1$ to $x$.
   - For each sum, iterate over all coins and update `dp[t]` using the above relation.

5. **Output**:
   - The result is stored in `dp[x]`, which gives the number of ways to form the target sum $x$.

### Implementation Highlights

- A 1D DP array `dp` of size $x+1$ is used to store the results for all sums up to $x$.
- The modulo operation ensures that the result does not exceed the constraints of the problem.
- The algorithm iterates over all sums and coins, updating the DP array in-place.

---

## Key Learning Points

1. **Dynamic Programming for Counting Problems**:
   - This problem demonstrates how to use DP to count combinations efficiently.
   - The key is to break the problem into smaller subproblems and use previously computed results.

2. **Order Matters**:
   - Since the order of coins matters, we iterate over sums in increasing order and consider all coins for each sum.

3. **Modulo Arithmetic**:
   - Modulo $10^9 + 7$ is used to handle large numbers and prevent overflow.

4. **Space Optimization**:
   - A 1D DP array is sufficient for this problem, as we only need results from previous states.

---

## Common Pitfalls

1. **Incorrect Base Case**:
   - Forgetting to initialize `dp[0] = 1` can lead to incorrect results, as it forms the foundation for all other sums.

2. **Order of Iteration**:
   - Iterating over coins before sums can lead to incorrect results, as it changes the order of combinations being considered.

3. **Modulo Operation**:
   - Failing to apply the modulo operation during updates can cause integer overflow.

4. **Handling Large Inputs**:
   - Not optimizing the DP array size or transitions can lead to time or memory limits being exceeded.

---

## Complexity

### Time Complexity
- The outer loop iterates over all sums from $1$ to $x$ ($O(x)$).
- The inner loop iterates over all $n$ coins for each sum ($O(n)$).
- Total time complexity: $O(n \cdot x)$.

### Space Complexity
- The DP array `dp` requires $O(x)$ space.
- Total space complexity: $O(x)$.

---

## Alternative Approaches

1. **Recursive DP with Memoization**:
   - Use a recursive approach with memoization to avoid recomputing results for the same subproblems.
   - This approach has the same time complexity but may be harder to implement efficiently for large inputs.

2. **Matrix Exponentiation**:
   - For specific cases where coins form an arithmetic progression, matrix exponentiation can be used to compute results faster.

3. **Combinatorics**:
   - For small inputs, combinatorics can be used to directly compute the number of ways to form the target sum.

---

## Extended Learning

1. **Unbounded Knapsack Problem**:
   - This problem is a variant of the unbounded knapsack problem, where items (coins) can be used multiple times.

2. **Subset Sum Problem**:
   - A related problem where we determine if a subset of coins can form a given sum.

3. **Coin Change II**:
   - A similar problem where the order of coins does not matter.

4. **Modulo Arithmetic**:
   - Understanding modular arithmetic is crucial for problems with large numbers.

---

## Tips for Similar Problems

1. **Identify the DP State**:
   - Clearly define what each state in the DP array represents.

2. **Base Case and Transition**:
   - Ensure the base case is correctly initialized and the transition relation is well-defined.

3. **Iterate in the Correct Order**:
   - For problems where order matters, iterate over sums first. For problems where order does not matter, iterate over coins first.

4. **Optimize Space**:
   - Use a 1D DP array whenever possible to save memory.

5. **Modulo Arithmetic**:
   - Always apply modulo operations during updates to prevent overflow.

By recognizing these patterns, you can approach similar problems with confidence and efficiency.