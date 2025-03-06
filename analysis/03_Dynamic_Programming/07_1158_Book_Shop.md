# Book Shop

[Problem Link](https://cses.fi/problemset/task/1158) | [Solution Link](../../solutions/03_Dynamic_Programming/07_1158_Book_Shop.cpp)

## TL;DR

The problem is a variation of the **0/1 Knapsack Problem**, where we maximize the number of pages we can buy without exceeding a given budget. The solution uses **dynamic programming (DP)** with a space optimization technique (rolling arrays) to efficiently compute the result. The DP state tracks the maximum pages achievable for a given budget and iterates over the books to update this state.

---

## Problem Overview

You are given `n` books, each with a price and a number of pages. You have a budget of `x` and need to determine the maximum number of pages you can buy without exceeding this budget. Each book can be purchased at most once.

### Input:
- `n`: Number of books.
- `x`: Maximum budget.
- Arrays `h` and `s`:
  - `h[i]`: Price of the $i$-th book.
  - `s[i]`: Pages of the $i$-th book.

### Output:
- A single integer representing the maximum number of pages you can buy without exceeding the budget.

### Constraints:
- $1 \leq n \leq 1000$
- $1 \leq x \leq 10^5$
- $1 \leq h_i, s_i \leq 1000$

---

## Solution Approach

This problem is a classic **0/1 Knapsack Problem**, where:
- The "weight" corresponds to the price of a book.
- The "value" corresponds to the number of pages in the book.
- The "capacity" corresponds to the budget `x`.

### Dynamic Programming Formulation

We define a DP state:
- `dp[m]`: The maximum number of pages that can be achieved with a budget of `m`.

#### Transition:
For each book `(price, pages)`:
- If we do not buy the book, the maximum pages remain the same: `dp[m] = dp[m]`.
- If we buy the book, the maximum pages are updated: `dp[m] = max(dp[m], dp[m - price] + pages)` (only if `m >= price`).

#### Base Case:
- `dp[0] = 0`: With a budget of 0, no pages can be bought.

#### Iteration:
We iterate over all books and update the DP array for each possible budget.

### Space Optimization (Rolling Arrays)

Instead of maintaining a 2D DP array (`dp[i][m]` for the first `i` books and budget `m`), we use a **rolling array**:
- Use two 1D arrays (`dp[0]` and `dp[1]`) to represent the current and previous states.
- Alternatively, use a single 1D array and iterate backward over the budget to avoid overwriting values prematurely.

### Implementation Highlights:
1. Parse input and store book data.
2. Initialize a DP array of size `x + 1` with all values set to 0.
3. For each book, iterate over the budget in reverse (to avoid overwriting values) and update the DP array.
4. The final answer is stored in `dp[x]`.

---

## Key Learning Points

1. **0/1 Knapsack Problem**:
   - This problem is a direct application of the knapsack problem, which is fundamental in dynamic programming.

2. **Space Optimization**:
   - By iterating the budget in reverse, we can reduce the space complexity from $O(n \cdot x)$ to $O(x)$.

3. **Iterative DP Transitions**:
   - Understanding how to update the DP state for each item and capacity is crucial for solving knapsack-like problems.

4. **Constraints-Driven Optimization**:
   - With $n \leq 1000$ and $x \leq 10^5$, a naive $O(n \cdot x)$ solution is feasible but requires careful memory management to stay within limits.

---

## Common Pitfalls

1. **Incorrect DP Transitions**:
   - Forgetting to check if the budget is sufficient (`m >= price`) before updating the DP state.

2. **Overwriting DP Values**:
   - Iterating the budget forward instead of backward can lead to incorrect results due to overwriting values prematurely.

3. **Inefficient Space Usage**:
   - Using a 2D DP array unnecessarily increases memory usage when a 1D array suffices.

4. **Sorting or Preprocessing Errors**:
   - Sorting the books (if attempted) is unnecessary and can introduce bugs if implemented incorrectly.

---

## Complexity

### Time Complexity:
- **Outer loop**: Iterate over `n` books.
- **Inner loop**: Iterate over budgets from `x` to 0.
- Total: $O(n \cdot x)$.

### Space Complexity:
- Using a rolling array, the space complexity is $O(x)$.

---

## Alternative Approaches

1. **Recursive DP with Memoization**:
   - Use a recursive function with memoization to compute the maximum pages for a given book index and budget.
   - This approach is less efficient due to function call overhead and higher memory usage.

2. **Greedy Approach (Not Applicable)**:
   - A greedy approach (e.g., picking books with the highest pages-to-price ratio) does not guarantee an optimal solution in this case.

3. **Bitmask DP**:
   - For small values of `n`, a bitmask DP approach could enumerate all subsets of books and compute the maximum pages under the budget constraint.

---

## Extended Learning

1. **Knapsack Variants**:
   - Explore other knapsack problems, such as the unbounded knapsack or the fractional knapsack.

2. **Space Optimization Techniques**:
   - Learn about rolling arrays and in-place DP updates to reduce memory usage.

3. **Subset Sum Problem**:
   - This problem is closely related to the subset sum problem, where the goal is to determine if a subset of items sums to a target value.

---

## Tips for Similar Problems

1. **Recognizing Knapsack Problems**:
   - Look for problems involving a "capacity" (e.g., budget, weight limit) and items with "weights" and "values."

2. **DP State Design**:
   - Clearly define the DP state and transitions before implementation.

3. **Iterate Backward for Space Optimization**:
   - When updating a 1D DP array, iterate backward to avoid overwriting values.

4. **Constraints Analysis**:
   - Analyze constraints to determine if an $O(n \cdot x)$ solution is feasible or if further optimizations are needed.