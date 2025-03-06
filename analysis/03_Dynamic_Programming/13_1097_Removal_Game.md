# Removal Game

[Problem Link](https://cses.fi/problemset/task/1097) | [Solution Link](../../solutions/03_Dynamic_Programming/13_1097_Removal_Game.cpp)

## TL;DR

The problem is solved using dynamic programming (DP) to simulate the optimal moves of two players in a game where they alternately pick numbers from either end of a list. The solution uses a DP table to store the maximum scores for subproblems, ensuring that the first player always maximizes their score while accounting for the second player's optimal moves. The time complexity is $O(n^2)$, and the space complexity is also $O(n^2)$.

---

## Problem Overview

The problem involves two players alternately picking numbers from either the beginning or the end of a list. Each player aims to maximize their score. The goal is to determine the maximum score the first player can achieve if both players play optimally.

### Key Constraints:
- $1 \leq n \leq 5000$ (size of the list)
- $-10^9 \leq x_i \leq 10^9$ (values in the list)

### Example:
Input:
```
4
4 5 1 3
```
Output:
```
8
```
Explanation: The first player picks `4`, the second player picks `5`, the first player picks `3`, and the second player picks `1`. The first player's score is $4 + 3 = 8$.

---

## Solution Approach

### Dynamic Programming (DP) Overview:
The problem is solved using a **recursive DP approach** with memoization. The idea is to compute the maximum score the first player can achieve for any subarray of the list, considering that the second player also plays optimally.

### Key Observations:
1. At any turn, the current player can pick either the first or the last number in the list.
2. The second player will always try to minimize the first player's score in subsequent turns.
3. The problem can be reduced to smaller subproblems by removing the chosen number and considering the remaining subarray.

### DP State:
Define `dp[i][j]` as a pair `(first_score, second_score)`:
- `first_score`: Maximum score the first player can achieve for the subarray `nums[i...j]`.
- `second_score`: Maximum score the second player can achieve for the subarray `nums[i...j]`.

### Transition:
For a subarray `nums[i...j]`, the first player has two choices:
1. Pick `nums[i]`: The second player then plays optimally on the subarray `nums[i+1...j]`.
   - Resulting scores: `(nums[i] + dp[i+1][j].second, dp[i+1][j].first)`
2. Pick `nums[j]`: The second player then plays optimally on the subarray `nums[i...j-1]`.
   - Resulting scores: `(nums[j] + dp[i][j-1].second, dp[i][j-1].first)`

The first player will choose the option that maximizes their score:
$$
dp[i][j] = \text{max}\left(
    (nums[i] + dp[i+1][j].second, dp[i+1][j].first), 
    (nums[j] + dp[i][j-1].second, dp[i][j-1].first)
\right)
$$

### Base Case:
If `i == j` (subarray has one element), then:
$$
dp[i][j] = (nums[i], 0)
$$

### Implementation:
1. Use a 2D DP table `dp` of size $n \times n$ to store the results for all subarrays.
2. Recursively compute `dp[i][j]` using the above transition formula, with memoization to avoid redundant calculations.
3. The final answer is `dp[0][n-1].first`, which gives the maximum score for the first player for the entire array.

---

## Key Learning Points

1. **Game Theory in DP**:
   - This problem demonstrates how to model competitive games where both players play optimally using DP.

2. **State Representation**:
   - The use of a pair `(first_score, second_score)` in the DP table is a key insight to track both players' scores.

3. **Recursive Thinking**:
   - Breaking the problem into smaller subproblems based on the players' choices is essential for solving such problems.

4. **Optimal Substructure**:
   - The problem exhibits optimal substructure, as the solution to the larger problem depends on the solutions to its subproblems.

---

## Common Pitfalls

1. **Incorrect Transition**:
   - Forgetting to swap the roles of the players when transitioning between states can lead to incorrect results.

2. **Handling Negative Numbers**:
   - Since the list can contain negative numbers, ensure that the DP table accounts for all possible values.

3. **Initialization**:
   - Properly initialize the base cases (`dp[i][i]`) to avoid accessing uninitialized values during recursion.

4. **Memory Usage**:
   - Using a 2D DP table for large inputs (e.g., $n = 5000$) can lead to high memory usage. Ensure efficient memory management.

---

## Complexity

### Time Complexity:
- Filling the DP table requires solving $O(n^2)$ subproblems.
- Each subproblem involves constant work (comparing two options).
- Total time complexity: $O(n^2)$.

### Space Complexity:
- The DP table requires $O(n^2)$ space.
- Recursive stack space is $O(n)$ in the worst case.
- Total space complexity: $O(n^2)$.

---

## Alternative Approaches

1. **Iterative DP**:
   - Instead of recursion, use an iterative approach to fill the DP table bottom-up. This avoids the overhead of recursive function calls.

2. **Space Optimization**:
   - Since the DP state only depends on the current and previous rows, the space complexity can be reduced to $O(n)$ by maintaining only two rows of the DP table.

3. **Greedy Approach** (Incorrect for this problem):
   - A naive greedy approach (always picking the larger of the two ends) does not work because it ignores the second player's optimal strategy.

---

## Extended Learning

1. **Minimax Algorithm**:
   - This problem is a simplified version of the minimax algorithm used in AI for two-player games like chess or tic-tac-toe.

2. **Impartial Games**:
   - Study combinatorial game theory for problems where players alternate moves and aim to optimize their outcomes.

3. **Interval DP**:
   - This problem is an example of interval DP, where the state is defined over subarrays or intervals.

---

## Tips for Similar Problems

1. **Recognize Optimal Play**:
   - If the problem involves two players playing optimally, think about how to simulate their decisions using DP.

2. **State Representation**:
   - Clearly define the DP state and what it represents (e.g., scores, outcomes, etc.).

3. **Break Down Choices**:
   - Identify the possible choices at each step and how they affect the subproblem.

4. **Look for Overlapping Subproblems**:
   - If the problem involves overlapping subarrays or intervals, DP is likely a good approach.

5. **Start Small**:
   - Solve the problem for small cases or subarrays to understand the transitions and dependencies.