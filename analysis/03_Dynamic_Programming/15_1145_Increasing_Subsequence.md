# Increasing Subsequence

[Problem Link](https://cses.fi/problemset/task/1145) | [Solution Link](../../solutions/03_Dynamic_Programming/15_1145_Increasing_Subsequence.cpp)

## TL;DR

The problem is to find the length of the longest increasing subsequence (LIS) in an array. The solution uses a greedy approach combined with binary search to efficiently construct the LIS in $O(n \log n)$ time. A `vector` is maintained to represent the smallest possible ending values of increasing subsequences of different lengths.

---

## Problem Overview

Given an array of size $n$, the task is to find the length of the longest subsequence such that every element in the subsequence is strictly greater than the previous one. A subsequence is defined as a sequence derived from the array by deleting some or no elements without changing the order of the remaining elements.

### Example:

**Input:**  
$n = 8$  
Array: $[7, 3, 5, 3, 6, 2, 9, 8]$

**Output:**  
$4$ (The LIS is $[3, 5, 6, 9]$)

---

## Solution Approach

The solution employs a combination of a greedy strategy and binary search to efficiently compute the LIS length.

### Key Steps:

1. **Maintain a `vector` (`lis`)**:  
   This `vector` stores the smallest possible ending values of increasing subsequences of different lengths. For example:
   - `lis[0]` stores the smallest ending value of a subsequence of length 1.
   - `lis[1]` stores the smallest ending value of a subsequence of length 2, and so on.

2. **Iterate through the array**:  
   For each element in the array:
   - Use binary search (`std::lower_bound`) to find the position in `lis` where the current element can replace an existing value or extend the subsequence.
   - If the element is larger than all elements in `lis`, append it to the end (extend the LIS).
   - Otherwise, replace the first element in `lis` that is greater than or equal to the current element (maintain the smallest possible ending value).

3. **Output the size of `lis`**:  
   The size of `lis` at the end of the iteration will be the length of the LIS.

### Example Walkthrough:

**Input:** $[7, 3, 5, 3, 6, 2, 9, 8]$

- Start with an empty `lis`.
- Process each element:
  - $7$: Append to `lis` → `lis = [7]`
  - $3$: Replace $7$ with $3$ → `lis = [3]`
  - $5$: Append to `lis` → `lis = [3, 5]`
  - $3$: Replace $3$ with $3$ (no change) → `lis = [3, 5]`
  - $6$: Append to `lis` → `lis = [3, 5, 6]`
  - $2$: Replace $3$ with $2$ → `lis = [2, 5, 6]`
  - $9$: Append to `lis` → `lis = [2, 5, 6, 9]`
  - $8$: Replace $9$ with $8$ → `lis = [2, 5, 6, 8]`

**Output:** Length of `lis = 4`.

---

## Key Learning Points

1. **Greedy + Binary Search for LIS**:  
   The combination of maintaining a "smallest possible ending value" array and binary search is a powerful technique for solving LIS problems efficiently.

2. **Binary Search with `std::lower_bound`**:  
   The use of `std::lower_bound` ensures that we find the correct position in $O(\log n)$ time to either replace or extend the LIS.

3. **Dynamic Programming Optimization**:  
   While a naive dynamic programming approach for LIS takes $O(n^2)$ time, the greedy + binary search approach reduces it to $O(n \log n)$, making it suitable for large inputs.

---

## Common Pitfalls

1. **Misunderstanding the Role of `lis`**:  
   The `lis` array does not store the actual LIS but rather the smallest possible ending values for increasing subsequences of different lengths.

2. **Confusing `std::lower_bound` and `std::upper_bound`**:  
   Using `std::upper_bound` instead of `std::lower_bound` would lead to incorrect results, as we need the first position where the current element can replace an equal or larger value.

3. **Handling Edge Cases**:  
   Ensure the solution works for edge cases like:
   - $n = 1$ (single-element array).
   - All elements are the same (e.g., $[5, 5, 5, 5]$).
   - Already sorted or reverse-sorted arrays.

---

## Complexity

### Time Complexity:
- **Binary Search per Element:** $O(\log n)$ using `std::lower_bound`.
- **Total Iterations:** $O(n)$ for $n$ elements.
- **Overall Complexity:** $O(n \log n)$.

### Space Complexity:
- The `lis` vector requires $O(n)$ space in the worst case.
- Overall space complexity: $O(n)$.

---

## Alternative Approaches

1. **Dynamic Programming (DP):**  
   Use a DP array where `dp[i]` represents the length of the LIS ending at index $i$. For each $i$, iterate over all previous indices $j < i$ to update `dp[i]`.  
   - **Time Complexity:** $O(n^2)$.
   - **Space Complexity:** $O(n)$.

2. **Segment Tree or Fenwick Tree:**  
   Use a Fenwick Tree or Segment Tree to maintain the LIS length for each value. This approach is more complex to implement but can also achieve $O(n \log n)$.

---

## Extended Learning

1. **Patience Sorting:**  
   The greedy + binary search approach is conceptually similar to the card game patience sorting, where piles represent increasing subsequences.

2. **Longest Decreasing Subsequence (LDS):**  
   The same approach can be adapted for finding the longest decreasing subsequence by reversing the comparison logic.

3. **Applications of LIS:**  
   LIS has applications in various fields, including bioinformatics (sequence alignment) and data compression.

---

## Tips for Similar Problems

1. **Recognize Subsequence Problems:**  
   Look for keywords like "subsequence," "increasing," or "decreasing" in the problem statement.

2. **Binary Search for Optimization:**  
   When the problem involves finding positions or ranges, consider using binary search to optimize the solution.

3. **Dynamic Programming with State Optimization:**  
   For problems with overlapping subproblems, explore ways to reduce the state space using greedy strategies or data structures like Fenwick Trees.

4. **Practice Classic Problems:**  
   Solve classic problems like LIS, Longest Common Subsequence (LCS), and Longest Palindromic Subsequence to build intuition for subsequence-related problems.