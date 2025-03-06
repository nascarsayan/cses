# Two Sets II

[Problem Link](https://cses.fi/problemset/task/1093) | [Solution Link](../../solutions/03_Dynamic_Programming/14_1093_Two_Sets_II.cpp)

## TL;DR

The problem involves partitioning the numbers $1, 2, \ldots, n$ into two subsets with equal sums. The solution uses dynamic programming to count the number of ways to achieve a target sum (half the total sum) using the numbers from $1$ to $n$. The result is computed modulo $10^9+7$.

---

## Problem Overview

Given an integer $n$, the task is to determine the number of ways to divide the numbers $1, 2, \ldots, n$ into two subsets such that the sums of the subsets are equal. If the total sum of the numbers, $\sigma_n = \frac{n(n+1)}{2}$, is odd, the answer is $0$ because it is impossible to split the numbers into two equal sums. Otherwise, the problem reduces to counting the number of ways to achieve a sum of $\frac{\sigma_n}{2}$ using the numbers $1$ to $n$.

---

## Solution Approach

### Key Observations
1. The total sum of the numbers from $1$ to $n$ is:
   $$ \sigma_n = \frac{n(n+1)}{2} $$
   If $\sigma_n$ is odd, it is impossible to divide the numbers into two subsets with equal sums, so the answer is $0$.

2. If $\sigma_n$ is even, the problem reduces to finding the number of ways to achieve a target sum:
   $$ \text{target} = \frac{\sigma_n}{2} $$

3. This is a variation of the "subset sum problem," where we count the number of subsets that sum to a specific value.

### Dynamic Programming Approach
The solution uses a dynamic programming (DP) approach to count the number of ways to achieve the target sum.

#### DP State Definition
Let `dp[sum]` represent the number of ways to achieve a sum of `sum` using some subset of the numbers $1, 2, \ldots, n$.

#### Transition
For each number `curr` from $1$ to $n$, update the DP table in reverse order:
$$ dp[sum] = dp[sum] + dp[sum - curr] \pmod{10^9+7} $$
This means that the number of ways to achieve `sum` includes all the ways to achieve `sum` without using `curr`, plus all the ways to achieve `sum - curr` (by adding `curr`).

#### Initialization
- `dp[0] = 1`: There is exactly one way to achieve a sum of $0$ (using an empty subset).
- All other `dp[sum]` values are initialized to $0$.

#### Final Answer
The final answer is the value of `dp[target]`, where `target = \frac{\sigma_n}{2}`.

#### Optimization
To avoid double-counting subsets (e.g., swapping the two subsets), the solution considers only numbers from $2$ to $n$ in the DP loop. This ensures that each subset pair is counted exactly once.

---

## Key Learning Points

1. **Subset Sum Problem**: This problem is a variation of the subset sum problem, where we count the number of subsets that sum to a specific value.
2. **Dynamic Programming**: The problem demonstrates how to use a DP array to iteratively build solutions for increasing sums.
3. **Modulo Arithmetic**: The solution uses modulo $10^9+7$ to handle large numbers and prevent overflow.
4. **Symmetry in Subset Partitioning**: By considering only one subset (and implicitly defining the other), we avoid double-counting.

---

## Common Pitfalls

1. **Odd Total Sum**: Forgetting to check if $\sigma_n$ is odd can lead to incorrect results or unnecessary computations.
2. **Reverse DP Update**: Updating the DP array in forward order can lead to incorrect results because it allows reusing the same number multiple times in a single iteration.
3. **Modulo Operations**: Missing modulo operations during updates can result in integer overflow or incorrect answers.

---

## Complexity

### Time Complexity
- The outer loop iterates over the numbers $1$ to $n$.
- The inner loop iterates over possible sums up to $\sigma_n$.
- Total complexity: $O(n \cdot \sigma_n)$, where $\sigma_n = \frac{n(n+1)}{2}$.

In the worst case ($n = 500$), $\sigma_n \approx 125,250$, so the time complexity is approximately $O(500 \cdot 125,250) \approx 62.6 \times 10^6$ operations, which is efficient within the constraints.

### Space Complexity
- The DP array requires $O(\sigma_n)$ space.
- Total space complexity: $O(\sigma_n)$.

---

## Alternative Approaches

1. **Recursive Backtracking**: A recursive approach could explore all possible subsets and count valid partitions. However, this would be computationally expensive with exponential time complexity, $O(2^n)$.

2. **Optimized DP with Space Reduction**: Instead of maintaining a full DP array, we could use a rolling array of size $O(\text{target})$ to reduce space complexity.

---

## Extended Learning

1. **Knapsack Problem**: This problem is closely related to the 0/1 Knapsack Problem, where we decide whether to include each number in a subset to achieve a target sum.
2. **Partition Problems**: Explore other partitioning problems, such as partitioning into subsets with specific properties (e.g., equal size, minimum difference in sums).
3. **Combinatorics and Modulo Arithmetic**: Understanding modular arithmetic and combinatorial counting is crucial for problems involving large numbers.

---

## Tips for Similar Problems

1. **Check Feasibility Early**: For partitioning problems, check if the total sum satisfies basic conditions (e.g., divisibility) before proceeding.
2. **Subset Sum Problems**: Look for ways to reduce the problem to a subset sum or knapsack problem, which can often be solved using DP.
3. **Modulo Arithmetic**: Be mindful of modulo operations when dealing with large numbers.
4. **Avoid Double-Counting**: Ensure that symmetric solutions are not counted multiple times by carefully designing the DP transitions or constraints.