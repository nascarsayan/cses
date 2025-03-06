# Minimizing Coins

[Problem Link](https://cses.fi/problemset/task/1634) | [Solution Link](../../solutions/03_Dynamic_Programming/02_1634_Minimizing_Coins.cpp)

## TL;DR

The problem is solved using a **Dynamic Programming (DP)** approach. We maintain a DP array where each index represents the minimum number of coins required to form that sum. By iterating through all possible sums up to the target and updating the DP array using the given coin denominations, we can efficiently compute the result. If the target sum is not reachable, we return `-1`.

---

## Problem Overview

The task is to find the minimum number of coins required to form a given sum $x$ using a set of $n$ coin denominations. If it is not possible to form the sum, the output should be `-1`. 

### Input:
1. $n$ - Number of coin denominations.
2. $x$ - Target sum.
3. $c_1, c_2, \dots, c_n$ - Values of the coin denominations.

### Output:
- The minimum number of coins required to form the sum $x$, or `-1` if it is not possible.

### Example:
**Input:**  
$n = 3, x = 11$  
Coin denominations: $\{1, 5, 7\}$  

**Output:**  
$3$ (e.g., $5 + 5 + 1$)

---

## Solution Approach

### Dynamic Programming Formulation:

1. **Define the DP array:**  
   Let `dp[t]` represent the minimum number of coins required to form the sum $t$.

2. **Base Case:**  
   - `dp[0] = 0`: No coins are required to form the sum $0$.

3. **Transition Relation:**  
   For each sum $t$ from $1$ to $x$, and for each coin $c$:
   - If $c \leq t$, update `dp[t]` as:
     $$
     dp[t] = \min(dp[t], dp[t - c] + 1)
     $$
   This means that if we use the coin $c$, the number of coins required for $t$ is the number of coins required for $t - c$ plus one (the coin $c$ itself).

4. **Final Result:**  
   - If `dp[x]` is still set to a large value (e.g., infinity), it means the sum $x$ cannot be formed, and we output `-1`.
   - Otherwise, `dp[x]` gives the minimum number of coins required.

### Implementation Highlights:
- Initialize the DP array with a large value (e.g., $10^9$) to represent "unreachable sums."
- Iterate over all sums from $1$ to $x$ and update the DP array using the coin denominations.
- Return the value of `dp[x]` or `-1` if the sum is unreachable.

---

## Key Learning Points

1. **Dynamic Programming for Optimization Problems:**  
   This problem is a classic example of using DP to solve a **minimization problem**. The key is to break the problem into smaller subproblems and use their solutions to build the final answer.

2. **State Transition:**  
   The transition relation $dp[t] = \min(dp[t], dp[t - c] + 1)$ is a fundamental concept in DP, where we decide whether to include a particular coin in the solution.

3. **Handling Edge Cases:**  
   - If the target sum $x$ is smaller than the smallest coin denomination, the result is `-1`.
   - If no combination of coins can form the target sum, the DP value remains "infinity."

4. **Efficient Initialization:**  
   Initializing the DP array with a large value ensures that unreachable sums are easily identifiable.

---

## Common Pitfalls

1. **Incorrect Initialization:**  
   Forgetting to initialize `dp[0] = 0` can lead to incorrect results since it serves as the base case.

2. **Out-of-Bounds Access:**  
   When updating `dp[t]`, ensure that $t - c \geq 0$ to avoid accessing invalid indices.

3. **Inefficient Nested Loops:**  
   Iterating over all coins for every sum is necessary, but ensure that the implementation avoids redundant computations.

4. **Handling Large Inputs:**  
   With $x$ up to $10^6$, ensure the solution is efficient in both time and space.

---

## Complexity

### Time Complexity:
- The outer loop runs for all sums from $1$ to $x$, i.e., $O(x)$.
- The inner loop iterates over all $n$ coin denominations.
- Total complexity: $O(n \cdot x)$.

### Space Complexity:
- The DP array requires $O(x)$ space.

---

## Alternative Approaches

1. **Greedy Algorithm:**  
   A greedy approach (e.g., always picking the largest coin less than the remaining sum) does not work for all cases. For example, with coins $\{1, 3, 4\}$ and $x = 6$, the greedy approach would pick $\{4, 1, 1\}$ (3 coins), but the optimal solution is $\{3, 3\}$ (2 coins).

2. **Breadth-First Search (BFS):**  
   Treat the problem as a shortest-path problem in an unweighted graph where each node represents a sum, and edges represent using a coin. BFS can be used to find the minimum number of steps to reach $x$.

3. **Recursive DP with Memoization:**  
   Use recursion to compute the minimum coins for each sum, storing results in a memoization table to avoid redundant computations. This approach is less efficient than iterative DP for large inputs.

---

## Extended Learning

1. **Unbounded Knapsack Problem:**  
   This problem is a variation of the unbounded knapsack problem where we aim to minimize the number of items (coins) to achieve a target weight (sum).

2. **Coin Change Variants:**  
   Explore related problems such as:
   - Finding the total number of ways to form a sum.
   - Finding the actual combination of coins used.

3. **Optimization Techniques in DP:**  
   Learn about space optimization techniques like using a 1D array instead of a 2D array when only the previous state is needed.

---

## Tips for Similar Problems

1. **Recognize the Problem Type:**  
   If the problem involves finding the minimum or maximum number of steps/items to achieve a target, it is likely a DP problem.

2. **Define the State Clearly:**  
   Clearly define what each state in the DP array represents (e.g., `dp[t]` is the minimum coins to form sum $t$).

3. **Start with Base Cases:**  
   Always initialize the base cases (e.g., `dp[0] = 0` for sums).

4. **Iterate Systematically:**  
   Ensure that the transitions cover all possible cases (e.g., iterate over all coins).

5. **Test Edge Cases:**  
   Test for small inputs, unreachable sums, and cases where the target sum equals a single coin denomination.

---