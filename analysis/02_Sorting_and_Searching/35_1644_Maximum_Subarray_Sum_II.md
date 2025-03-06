# Maximum Subarray Sum II

[Problem Link](https://cses.fi/problemset/task/1644) | [Solution Link](../../solutions/02_Sorting_and_Searching/35_1644_Maximum_Subarray_Sum_II.cpp)

## TL;DR

The problem requires finding the maximum sum of a contiguous subarray with a length between $a$ and $b$. The solution uses prefix sums and a sliding window minimum/maximum technique with a balanced data structure (e.g., multiset or deque) to efficiently track the valid subarray sums. The approach ensures the solution runs in $O(n)$ or $O(n \log n)$ time, depending on the implementation.

---

## Problem Overview

You are given an array of $n$ integers and two integers $a$ and $b$ that define the minimum and maximum lengths of subarrays to consider. The goal is to find the maximum sum of any contiguous subarray whose length lies between $a$ and $b$. 

### Key Constraints:
- The array size $n$ can go up to $200,000$, so a brute-force solution is infeasible.
- The array values can be very large (up to $10^9$ in magnitude), so efficient handling of sums is critical.

---

## Solution Approach

### Observations:
1. The sum of any subarray can be computed using prefix sums:
   $$
   \text{sum}(i, j) = \text{prefix}[j] - \text{prefix}[i-1]
   $$
   where $\text{prefix}[k]$ is the sum of the first $k$ elements.

2. To maximize the subarray sum, we need to minimize $\text{prefix}[i-1]$ for valid $i$ values while maximizing $\text{prefix}[j]$ for valid $j$ values.

3. The problem can be reduced to efficiently finding the minimum prefix sum in a sliding window of size $[a, b]$.

### Algorithm:
1. **Compute Prefix Sums**:
   Compute the prefix sums for the array. Let $\text{prefix}[0] = 0$ for convenience.

2. **Sliding Window with Minimum Tracking**:
   Use a sliding window approach to maintain the minimum prefix sum in the range $[j-b, j-a]$ for each $j$. This ensures that the subarray length is within $[a, b]$.

3. **Efficient Data Structure**:
   Use a deque or multiset to maintain the minimum prefix sums in the sliding window. For each $j$:
   - Remove prefix sums that are no longer in the valid range $[j-b, j-a]$.
   - Add the current prefix sum $\text{prefix}[j-a]$ to the data structure.
   - Compute the maximum subarray sum using the current prefix sum and the minimum prefix sum in the window.

4. **Iterate Over the Array**:
   Iterate through the array while updating the sliding window and tracking the maximum subarray sum.

### Pseudocode:
```python
prefix = [0] * (n + 1)
for i in range(1, n + 1):
    prefix[i] = prefix[i - 1] + x[i - 1]

max_sum = -inf
deque = empty

for j in range(1, n + 1):
    # Remove elements outside the window [j-b, j-a]
    if deque and deque[0] < j - b:
        deque.pop_front()
    
    # Add the new element for the window
    if j - a >= 0:
        deque.push_back(prefix[j - a])
    
    # Update the maximum sum
    if deque:
        max_sum = max(max_sum, prefix[j] - deque.min())

print(max_sum)
```

---

## Key Learning Points

1. **Prefix Sums**:
   Prefix sums are a powerful tool for efficiently calculating subarray sums.

2. **Sliding Window Technique**:
   The sliding window approach is useful for maintaining a range of values while iterating through an array.

3. **Efficient Minimum/Maximum Tracking**:
   Using a deque or multiset allows efficient tracking of minimum or maximum values in a sliding window.

4. **Optimization for Constraints**:
   The problem constraints ($n \leq 200,000$) necessitate an $O(n)$ or $O(n \log n)$ solution, which is achieved by combining prefix sums and a sliding window.

---

## Common Pitfalls

1. **Incorrect Window Management**:
   Forgetting to remove elements that fall outside the valid range $[j-b, j-a]$ can lead to incorrect results.

2. **Handling Edge Cases**:
   Ensure that the implementation correctly handles edge cases, such as $a = b = 1$ or all elements being negative.

3. **Data Structure Choice**:
   Using an inefficient data structure (e.g., a simple list for the sliding window) can lead to time complexity issues.

4. **Integer Overflow**:
   Be cautious of integer overflow when working with large sums, especially in languages like C++.

---

## Complexity

### Time Complexity:
- Computing prefix sums: $O(n)$.
- Sliding window operations: $O(n)$ if using a deque, or $O(n \log n)$ if using a multiset.

Overall: $O(n)$ or $O(n \log n)$ depending on the implementation.

### Space Complexity:
- Prefix sums: $O(n)$.
- Sliding window data structure: $O(b - a + 1)$, which is $O(n)$ in the worst case.

Overall: $O(n)$.

---

## Alternative Approaches

1. **Brute Force**:
   Iterate over all possible subarrays of lengths $[a, b]$ and compute their sums. This approach is $O(n^2)$ and infeasible for large $n$.

2. **Segment Tree**:
   Use a segment tree to maintain the minimum prefix sum in a range. This approach has $O(n \log n)$ time complexity but is more complex to implement.

3. **Binary Search**:
   Combine prefix sums with binary search to find valid subarray sums. This is less efficient and harder to implement than the sliding window approach.

---

## Extended Learning

1. **Kadane's Algorithm**:
   Learn how Kadane's algorithm solves the maximum subarray sum problem for unrestricted lengths.

2. **Monotonic Queues**:
   Study how monotonic queues can be used to optimize sliding window problems.

3. **Range Queries**:
   Explore other range query techniques, such as Fenwick trees or sparse tables, for similar problems.

---

## Tips for Similar Problems

1. **Recognize Prefix Sum Applications**:
   If the problem involves subarray sums, consider using prefix sums to simplify calculations.

2. **Sliding Window for Ranges**:
   When constraints involve a range of indices, the sliding window technique is often applicable.

3. **Efficient Data Structures**:
   Use appropriate data structures (e.g., deque, multiset) to maintain and query values efficiently in a sliding window.

4. **Edge Cases**:
   Always test edge cases, such as smallest/largest possible subarray lengths or arrays with all negative/positive values.