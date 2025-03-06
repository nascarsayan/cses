# Money Sums

[Problem Link](https://cses.fi/problemset/task/1745) | [Solution Link](../../solutions/03_Dynamic_Programming/12_1745_Money_Sums.cpp)

## TL;DR

The problem is solved using a dynamic programming (DP) approach where a boolean DP array is used to track all possible sums that can be formed using the given coins. The solution iteratively updates the DP array for each coin, ensuring all distinct sums are calculated efficiently. The final output is the count and the list of these sums in increasing order.

---

## Problem Overview

The task is to determine all distinct sums that can be formed using a given set of coins, where each coin has a specific value. The output includes the number of such sums and the sums themselves in sorted order.

### Input:
- $n$: Number of coins ($1 \leq n \leq 100$).
- $x_1, x_2, \dots, x_n$: Values of the coins ($1 \leq x_i \leq 1000$).

### Output:
- $k$: Number of distinct sums.
- The list of all possible sums in increasing order.

### Example:
**Input:**
```
4
4 2 5 2
```

**Output:**
```
9
2 4 5 6 7 8 9 11 13
```

---

## Solution Approach

### Key Idea:
The problem is a variation of the "subset sum problem." Using dynamic programming, we track which sums can be formed as we iterate through the coins.

### Steps:

1. **Initialize DP Array:**
   - Use a boolean DP array `dp` of size `mx + 1`, where `mx` is the sum of all coin values. 
   - `dp[val]` will be `true` if the sum `val` can be formed using the coins considered so far.
   - Initially, set `dp[0] = true` (sum of 0 is always possible with no coins).

2. **Iterate Through Coins:**
   - For each coin, update the DP array in reverse order (from `mx` down to the coin's value). This ensures that each coin is used at most once for any sum.
   - For each `val` from `mx` to `c` (current coin value), set:
     $$
     dp[val] = dp[val] \lor dp[val - c]
     $$
     This means that `val` can be formed if it was already possible (`dp[val] = true`) or if `val - c` was possible before adding the current coin.

3. **Count and Collect Results:**
   - After processing all coins, iterate through the DP array to count and collect all indices where `dp[val] = true` (these indices represent the possible sums).

4. **Output Results:**
   - Print the count of distinct sums and the list of sums in increasing order.

---

## Key Learning Points

1. **Dynamic Programming for Subset Problems:**
   - The problem is a classic example of using DP to solve subset-related problems efficiently.

2. **Reverse Iteration in DP:**
   - When updating the DP array, iterating in reverse ensures that each coin is used only once for a given sum.

3. **Efficient Space Usage:**
   - By using a 1D DP array instead of a 2D table, the space complexity is reduced to $O(\text{sum of coins})$.

4. **Sorting Coins:**
   - Although not strictly necessary, sorting the coins can sometimes help in debugging or optimizing certain cases.

---

## Common Pitfalls

1. **Forward Iteration in DP Update:**
   - If the DP array is updated in forward order, a coin may be used multiple times for the same sum, leading to incorrect results.

2. **Incorrect DP Array Size:**
   - The DP array must be large enough to accommodate the maximum possible sum (`mx`).

3. **Handling Large Input Sizes:**
   - Ensure that the solution respects the constraints, especially the memory limit, as the DP array size depends on the sum of all coins.

---

## Complexity

### Time Complexity:
- **Initialization:** $O(n)$ to read input and calculate the total sum.
- **DP Updates:** For each coin, iterate through the DP array in reverse. Total work is proportional to:
  $$
  O(n \cdot \text{sum of coins})
  $$
  In the worst case, $\text{sum of coins} \leq 100 \cdot 1000 = 100,000$.

### Space Complexity:
- The DP array requires $O(\text{sum of coins})$ space.

---

## Alternative Approaches

1. **Recursive Backtracking:**
   - Generate all subsets of the coins and calculate their sums. This approach is simpler conceptually but inefficient due to exponential time complexity ($O(2^n)$).

2. **Bitmasking:**
   - Use bitmasks to represent subsets of coins and calculate sums. This approach is also exponential but can be faster for small $n$.

3. **Optimized DP with Hashing:**
   - Use a hash set instead of a DP array to store possible sums. This reduces memory usage but may increase runtime due to hash operations.

---

## Extended Learning

1. **Subset Sum Problem:**
   - A fundamental problem in DP, where the goal is to determine if a subset with a given sum exists.

2. **Knapsack Problem:**
   - A generalization of the subset sum problem, where items have weights and values.

3. **Coin Change Problem:**
   - Another variation where the goal is to find the number of ways to make a specific sum using given coin denominations.

---

## Tips for Similar Problems

1. **Recognize Subset Problems:**
   - Look for problems involving sums or combinations of elements. These often map to subset or knapsack problems.

2. **Dynamic Programming vs. Brute Force:**
   - Use DP when the problem involves overlapping subproblems (e.g., reusing results for smaller sums).

3. **Optimize Space:**
   - For 1D DP problems, consider whether the DP array can be updated in place or reduced in size.

4. **Sort Input When Necessary:**
   - Sorting can simplify logic or improve efficiency in some cases.

5. **Practice Variants:**
   - Solve related problems like "Partition Equal Subset Sum" or "Target Sum" to strengthen your understanding of subset problems.