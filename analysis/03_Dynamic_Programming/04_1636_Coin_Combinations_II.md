# Coin Combinations II

[Problem Link](https://cses.fi/problemset/task/1636) | [Solution Link](../../solutions/03_Dynamic_Programming/04_1636_Coin_Combinations_II.cpp)

## TL;DR

The problem is solved using a **dynamic programming (DP)** approach, where a 1D array `dp` is used to store the number of ways to form each sum up to $x$. The solution iterates over each coin and updates the `dp` array to include combinations that use the current coin. The final result is stored in `dp[x]`, and all calculations are performed modulo $10^9 + 7$ to handle large numbers.

---

## Problem Overview

The task is to determine the number of distinct ways to form a sum $x$ using a given set of $n$ coins, where each coin can be used multiple times. The order of coins in the combinations does not matter. The result must be computed modulo $10^9 + 7$.

### Input:
- Two integers $n$ (number of coins) and $x$ (desired sum).
- An array of $n$ integers representing the coin values.

### Output:
- A single integer: the number of ways to form the sum $x$.

### Constraints:
- $1 \leq n \leq 100$
- $1 \leq x \leq 10^6$
- $1 \leq c_i \leq 10^6$

---

## Solution Approach

The problem is a variation of the **unbounded knapsack problem** and is solved using **dynamic programming**. Here's the step-by-step breakdown:

### 1. Define the DP State
Let `dp[t]` represent the number of ways to form the sum $t$ using the given coins.

### 2. Base Case
The base case is:
- `dp[0] = 1`: There is exactly one way to form the sum $0$ (by using no coins).

### 3. Transition
For each coin value `coin`:
- Iterate through all possible sums $t$ from `coin` to $x`.
- Update `dp[t]` as:
  $$ dp[t] = dp[t] + dp[t - \text{coin}} \mod (10^9 + 7) $$
This means the number of ways to form $t$ includes all the ways to form $t - \text{coin}$ (by adding the current coin).

### 4. Iteration Order
The coins are processed one by one, and for each coin, the `dp` array is updated in increasing order of $t$. This ensures that combinations are counted in a way that avoids overcounting permutations.

### 5. Result
The value of `dp[x]` at the end of the computation gives the number of ways to form the sum $x$.

### Modular Arithmetic
Since the number of ways can be very large, all calculations are performed modulo $10^9 + 7$ to prevent overflow and meet the problem's requirements.

---

## Key Learning Points

1. **Dynamic Programming for Combinatorics**:
   - Problems involving counting combinations often use DP with states representing partial results.

2. **Unbounded Knapsack Pattern**:
   - This problem is a classic example of the unbounded knapsack problem, where each item (coin) can be used an unlimited number of times.

3. **Order of Iteration**:
   - Iterating over coins first ensures that combinations are counted without considering permutations.

4. **Modular Arithmetic**:
   - Modular arithmetic is essential in competitive programming to handle large numbers efficiently.

---

## Common Pitfalls

1. **Incorrect Iteration Order**:
   - If the inner loop iterates in decreasing order of $t$, it may lead to overcounting permutations instead of combinations.

2. **Forgetting the Base Case**:
   - Missing the initialization `dp[0] = 1` can lead to incorrect results since it represents the foundation of the DP solution.

3. **Not Using Modular Arithmetic**:
   - Failing to take results modulo $10^9 + 7$ can cause integer overflow or incorrect outputs.

4. **Handling Large Constraints**:
   - The constraints on $x$ and $c_i$ are large, so using a 2D DP table or inefficient algorithms can lead to memory or time limit exceeded errors.

---

## Complexity

### Time Complexity
- The outer loop runs for each coin ($n$ iterations).
- The inner loop runs for each sum from the coin value to $x$ ($O(x)$ iterations).
- Total complexity: $O(n \cdot x)$.

### Space Complexity
- A 1D array `dp` of size $x + 1$ is used.
- Space complexity: $O(x)$.

---

## Alternative Approaches

1. **Recursive Approach with Memoization**:
   - Use recursion to explore all combinations and memoize results to avoid redundant calculations.
   - This approach is less efficient due to the overhead of recursion and may run into stack overflow for large $x$.

2. **Matrix Exponentiation**:
   - For some variations of this problem, matrix exponentiation can be used to compute results efficiently for large $x$.

3. **Optimized Space DP**:
   - Since only the previous states are required, the `dp` array can be optimized further using rolling arrays to reduce space usage.

---

## Extended Learning

1. **Knapsack Problems**:
   - Explore other variations of the knapsack problem, such as 0/1 knapsack and bounded knapsack.

2. **Counting Problems in DP**:
   - Study problems like "Subset Sum", "Partition Problem", and "Coin Change I" to understand similar patterns.

3. **Modular Arithmetic**:
   - Learn about modular inverses and properties of modular arithmetic for advanced problems.

---

## Tips for Similar Problems

1. **Recognize the Pattern**:
   - If the problem involves counting ways to achieve a target using given items, it likely involves DP.

2. **Understand the Constraints**:
   - Large constraints often indicate the need for an efficient $O(n \cdot x)$ or $O(x)$ solution.

3. **Use Modular Arithmetic**:
   - Always check if the problem requires results modulo a large number and implement modular arithmetic correctly.

4. **Iterate Carefully**:
   - Pay attention to the order of iteration to ensure combinations are counted correctly (not permutations).

5. **Start with Small Examples**:
   - Test your approach on small inputs to verify correctness before scaling to larger constraints.