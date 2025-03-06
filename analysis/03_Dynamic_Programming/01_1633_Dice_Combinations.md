# Dice Combinations

[Problem Link](https://cses.fi/problemset/task/1633) | [Solution Link](../../solutions/03_Dynamic_Programming/01_1633_Dice_Combinations.cpp)

## TL;DR

The problem involves counting the number of ways to form a sum $n$ using dice rolls, where each roll can result in a value between $1$ and $6$. The solution uses dynamic programming with modular arithmetic to efficiently compute the result for large $n$ up to $10^6$, leveraging a rolling array to optimize space usage.

---

## Problem Overview

The task is to determine the number of ways to achieve a sum $n$ by rolling a standard six-sided dice multiple times. Each dice roll contributes a value between $1$ and $6$ to the sum. The result must be computed modulo $10^9+7$ due to the large size of possible outputs. 

For example, for $n=3$, the valid combinations are:

- $1+1+1$
- $1+2$
- $2+1$
- $3$

Thus, the output is $4$.

---

## Solution Approach

### Dynamic Programming Formulation

The problem can be solved using dynamic programming (DP) by defining a state $dp[i]$ as the number of ways to form the sum $i$ using dice rolls. The recurrence relation is:

$$
dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
$$

This equation sums up the ways to reach $i$ by considering the last dice roll, which could contribute $1, 2, 3, 4, 5$, or $6$. The base case is $dp[0] = 1$, as there is exactly one way to form the sum $0$ (using no dice rolls).

### Modulo Arithmetic

Since the result can grow very large, all calculations are performed modulo $10^9+7$ to prevent integer overflow and adhere to the problem constraints.

### Space Optimization

Instead of maintaining a full array of size $n+1$, the solution uses a rolling array of size $7$ (corresponding to the last $6$ values plus the current one). This reduces the space complexity from $O(n)$ to $O(1)$.

### Implementation Highlights

1. **Initialization**: Start with $dp[0] = 1$ and all other entries in the rolling array as $0$.
2. **Iterative Update**: For each $i$ from $1$ to $n$, compute $dp[i \% 7]$ using the values of the previous $6$ states.
3. **Modulo Handling**: Ensure all additions are performed modulo $10^9+7$.

---

## Key Learning Points

1. **Dynamic Programming**: This problem demonstrates how to break down a problem into smaller overlapping subproblems and solve it iteratively.
2. **Space Optimization**: By using a rolling array, the space complexity is reduced from $O(n)$ to $O(1)$.
3. **Modulo Arithmetic**: Handling large numbers efficiently using modular arithmetic is a critical skill in competitive programming.
4. **Sliding Window Technique**: The rolling array is an example of a sliding window approach applied to DP.

---

## Common Pitfalls

1. **Incorrect Base Case**: Forgetting to initialize $dp[0] = 1$ can lead to incorrect results.
2. **Modulo Errors**: Failing to apply modulo $10^9+7$ at every step can cause integer overflow or incorrect results.
3. **Indexing Errors**: Mismanaging the rolling array indices (e.g., using $i-7$ instead of $i-6$) can lead to incorrect computations.
4. **Off-by-One Errors**: Ensure the loop correctly iterates from $1$ to $n$ and accounts for all dice outcomes.

---

## Complexity

### Time Complexity

The solution iterates from $1$ to $n$, and for each $i$, it performs a constant amount of work (updating $dp[i \% 7]$). Thus, the time complexity is:

$$
O(n)
$$

### Space Complexity

The rolling array has a fixed size of $7$, so the space complexity is:

$$
O(1)
$$

---

## Alternative Approaches

1. **Recursive DP with Memoization**: Use a top-down approach with recursion and memoization. However, this approach has higher overhead due to recursive function calls and is less efficient for large $n$.
2. **Matrix Exponentiation**: Represent the recurrence relation as a matrix and use matrix exponentiation to compute $dp[n]$ in $O(\log n)$. This approach is more complex but can be faster for very large $n$.

---

## Extended Learning

1. **Fibonacci Sequence**: The recurrence relation is similar to the Fibonacci sequence, where each term depends on a fixed number of previous terms.
2. **Sliding Window Optimization**: Learn how to apply sliding window techniques to optimize space in other DP problems.
3. **Modular Arithmetic**: Study modular arithmetic properties and their applications in competitive programming.

---

## Tips for Similar Problems

1. **Identify the Recurrence Relation**: Break down the problem into smaller subproblems and derive the recurrence relation.
2. **Optimize Space**: Look for opportunities to reduce space complexity using techniques like rolling arrays or sliding windows.
3. **Handle Large Numbers**: Always consider modular arithmetic when the output can grow large.
4. **Start with Small Examples**: Test the recurrence relation on small inputs to ensure correctness before implementing the full solution.