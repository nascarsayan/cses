# Elevator Rides

[Problem Link](https://cses.fi/problemset/task/1653) | [Solution Link](../../solutions/03_Dynamic_Programming/17_1653_Elevator_Rides.cpp)

## TL;DR

The problem is solved using **bitmask dynamic programming (DP)**. Each state in the DP represents a subset of people and tracks the minimum number of elevator rides and the remaining weight in the current ride. By iterating through all subsets of people and updating the DP states efficiently, we find the minimum number of rides required. The solution exploits the small constraint on $n$ (up to 20) to use a $2^n$ state space.

---

## Problem Overview

We are tasked with finding the **minimum number of elevator rides** required to transport $n$ people, given their weights and the maximum weight capacity of the elevator. Each person must be transported exactly once, and the sum of weights in any ride must not exceed the elevator's capacity.

### Input:
- $n$ (number of people): $1 \leq n \leq 20$
- $x$ (maximum weight capacity of the elevator): $1 \leq x \leq 10^9$
- $w_i$ (weights of the people): $1 \leq w_i \leq x$

### Output:
- A single integer: the minimum number of rides required.

---

## Solution Approach

### Key Idea: Bitmask Dynamic Programming
The problem is solved using **bitmask DP**, where each state represents a subset of people and tracks the minimum number of rides required to transport them.

#### DP State Definition:
Let `dp[mask]` represent the **minimum number of rides** required to transport the subset of people represented by `mask`. Additionally, we track the **remaining weight** in the current ride for this subset.

- `mask` is a bitmask of size $n$ where the $i$-th bit is `1` if the $i$-th person is included in the subset, and `0` otherwise.
- The state `dp[mask]` is a tuple `(rides, remaining_weight)`:
  - `rides`: the number of rides used so far.
  - `remaining_weight`: the remaining capacity in the current ride.

#### Transition:
To compute `dp[mask]`, we consider adding one person to the subset represented by `mask`. For each person $i$ not yet in `mask`:
1. If their weight $w_i$ fits in the current ride (i.e., $w_i \leq remaining\_weight$):
   - Add $i$ to the subset and update the remaining weight.
2. Otherwise, start a new ride for $i$.

The transition can be expressed as:
$$
dp[mask \cup \{i\}] = \min \Big(dp[mask \cup \{i\}], (rides + 1, x - w_i)\Big)
$$
if $w_i$ does not fit in the current ride, or:
$$
dp[mask \cup \{i\}] = \min \Big(dp[mask \cup \{i\}], (rides, remaining\_weight - w_i)\Big)
$$
if $w_i$ fits in the current ride.

#### Base Case:
- `dp[0] = (1, x)`: Starting with no people, we need one ride with full capacity available.

#### Final Result:
The answer is `dp[(1 << n) - 1].rides`, where `(1 << n) - 1` represents the bitmask with all $n$ people included.

---

### Implementation Outline:
1. **Initialize DP Table**: Create a DP table of size $2^n$, with each entry initialized to a large value.
2. **Iterate Over Subsets**: For each subset of people (`mask`), calculate the minimum rides required by considering all possible transitions.
3. **Update Transitions**: For each person not in the current subset, calculate the new state and update the DP table.
4. **Output Result**: The result is the number of rides in the DP state representing all people.

---

## Key Learning Points

1. **Bitmask Representation**:
   - Bitmasks are a compact way to represent subsets of a small set (e.g., $n \leq 20$). Each bit in the mask indicates whether a person is included in the subset.

2. **State Representation in DP**:
   - Tracking multiple pieces of information (e.g., number of rides and remaining weight) in a DP state is a common technique in optimization problems.

3. **Subset Iteration**:
   - Iterating over all subsets of a set can be done efficiently using bitwise operations, which is crucial for problems with constraints like $n \leq 20$.

4. **Efficiency with Small $n$**:
   - Problems with small $n$ (e.g., $n \leq 20$) often allow for $O(2^n)$ solutions, which are feasible within competitive programming limits.

---

## Common Pitfalls

1. **Incorrect Transition Logic**:
   - Forgetting to check whether a person's weight fits in the current ride can lead to incorrect results.

2. **Initialization Errors**:
   - Failing to initialize the DP table correctly (e.g., setting all states to infinity except the base case) can cause incorrect results.

3. **Handling Edge Cases**:
   - Ensure the solution works for edge cases like $n = 1$, all weights equal to $x$, or all weights much smaller than $x$.

---

## Complexity

### Time Complexity:
- There are $2^n$ subsets of people.
- For each subset, we iterate over $n$ people to calculate transitions.
- Total complexity: $O(n \cdot 2^n)$.

### Space Complexity:
- The DP table has $2^n$ states, each storing a tuple.
- Total space complexity: $O(2^n)$.

---

## Alternative Approaches

1. **Branch and Bound**:
   - Use a backtracking approach with pruning to explore all possible groupings of people into rides. This is less efficient than DP but can be implemented for small $n$.

2. **Greedy Heuristics**:
   - Sort people by weight and try to fill the elevator greedily. This does not guarantee the minimum number of rides but can be a quick approximation.

---

## Extended Learning

1. **Subset Problems**:
   - Problems involving subsets often benefit from bitmask DP or combinatorial techniques.

2. **Knapsack Variants**:
   - This problem is similar to the knapsack problem, where we aim to maximize the utilization of a constrained resource (elevator capacity).

3. **State Compression**:
   - Learn how to represent complex states compactly using bitmasks or other encoding techniques.

---

## Tips for Similar Problems

1. **Recognize Small $n$**:
   - If $n \leq 20$, consider bitmask DP or subset enumeration as potential approaches.

2. **Track Multiple State Variables**:
   - When optimizing over multiple dimensions (e.g., rides and remaining weight), use tuples or arrays to store state information.

3. **Subset Transitions**:
   - For problems involving subsets, focus on how to transition between states efficiently using bitwise operations.

4. **Test Edge Cases**:
   - Always test edge cases like minimum and maximum values of $n$, $x$, and $w_i$ to ensure correctness.