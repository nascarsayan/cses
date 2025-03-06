# Subarray Distinct Values

[Problem Link](https://cses.fi/problemset/task/2428) | [Solution Link](../../solutions/02_Sorting_and_Searching/30_2428_Subarray_Distinct_Values.cpp)

## TL;DR

The problem is solved using the **sliding window (two pointers)** technique combined with a hash map to efficiently count subarrays with at most $k$ distinct values. The algorithm maintains a dynamic window of valid subarrays and calculates the count in $O(n)$ time.

---

## Problem Overview

You are given an array of $n$ integers and a number $k$. The task is to count the number of subarrays that contain at most $k$ distinct values. 

### Key Constraints:
- $1 \leq k \leq n \leq 2 \cdot 10^5$
- $1 \leq x_i \leq 10^9$

### Example:
Input:
```
5 2
1 2 3 1 1
```

Output:
```
10
```

Explanation: The valid subarrays are:
- [1], [2], [3], [1], [1] (single-element subarrays)
- [1, 2], [2, 3], [3, 1], [1, 1] (two-element subarrays)
- [1, 2, 3] (three-element subarray)

---

## Solution Approach

### Key Idea:
The solution uses the **sliding window (two pointers)** technique to efficiently find subarrays with at most $k$ distinct values. The main idea is to maintain a window `[start, end]` such that the number of distinct values in the window does not exceed $k$. 

### Steps:
1. **Initialize Variables**:
   - `start`: The left pointer of the sliding window.
   - `res`: The result variable to store the total count of valid subarrays.
   - `uniq`: A counter to track the number of distinct values in the current window.
   - `count`: A hash map to store the frequency of each element in the current window.

2. **Expand the Window**:
   - Iterate over the array with the right pointer `end`.
   - Add the current element to the `count` map and update the `uniq` counter if it's a new distinct value.

3. **Shrink the Window**:
   - If `uniq > k`, shrink the window by incrementing `start` until the condition `uniq <= k` is satisfied. Update the `count` map and decrement `uniq` when a distinct value is removed.

4. **Count Valid Subarrays**:
   - For every position of `end`, the number of valid subarrays ending at `end` is `(end - start + 1)`. Add this to `res`.

5. **Output the Result**:
   - After processing all elements, print the value of `res`.

---

### Example Walkthrough:
Input: 
```
n = 5, k = 2
Array: [1, 2, 3, 1, 1]
```

- **Step 1**: Start with `start = 0`, `res = 0`, `uniq = 0`, and an empty `count` map.
- **Step 2**: Expand the window:
  - Add `1` → `count = {1: 1}`, `uniq = 1`.
  - Add `2` → `count = {1: 1, 2: 1}`, `uniq = 2`.
  - Add `3` → `count = {1: 1, 2: 1, 3: 1}`, `uniq = 3` (exceeds $k$).
- **Step 3**: Shrink the window:
  - Remove `1` → `count = {1: 0, 2: 1, 3: 1}`, `uniq = 2`.
- **Step 4**: Count subarrays:
  - For each position of `end`, add `(end - start + 1)` to `res`.
- Final result: `res = 10`.

---

## Key Learning Points

1. **Sliding Window Technique**:
   - A powerful method to solve problems involving subarrays or substrings with constraints.
   - Dynamically adjusts the window size to maintain the validity of the condition.

2. **Efficient Frequency Counting**:
   - Using a hash map to track the frequency of elements in the current window allows for efficient updates and checks.

3. **Mathematical Insight**:
   - The number of subarrays ending at index `end` is `(end - start + 1)`. This avoids explicitly iterating over all subarrays.

4. **Handling Large Constraints**:
   - The $O(n)$ solution is critical for handling the upper limit of $n = 2 \cdot 10^5$.

---

## Common Pitfalls

1. **Incorrect Window Shrinking**:
   - Forgetting to decrement the frequency in the `count` map or update the `uniq` counter when shrinking the window can lead to incorrect results.

2. **Edge Cases**:
   - Arrays with all identical elements or $k = 1$.
   - Empty subarrays (though not relevant here due to constraints).

3. **Hash Map Performance**:
   - Using an inefficient data structure (e.g., a list instead of a hash map) can lead to $O(n^2)$ performance.

---

## Complexity

### Time Complexity:
- The `end` pointer iterates over the array once, and the `start` pointer also iterates at most once for each position of `end`. Thus, the total complexity is $O(n)$.

### Space Complexity:
- The hash map `count` stores at most $k$ distinct elements at any time, so the space complexity is $O(k)$.

---

## Alternative Approaches

1. **Brute Force**:
   - Generate all subarrays and count the distinct elements for each. This approach is $O(n^3)$ and infeasible for large $n$.

2. **Binary Search with Prefix Arrays**:
   - Use a prefix array to store the number of distinct elements up to each index and binary search to find the valid range for each subarray. This is more complex and less efficient than the sliding window approach.

---

## Extended Learning

1. **Sliding Window Variants**:
   - Problems involving substrings, subarrays, or ranges with constraints often use sliding window techniques.

2. **Frequency Maps**:
   - Efficiently tracking occurrences of elements is a common requirement in competitive programming.

3. **Two Pointers**:
   - A generalization of the sliding window technique that can be applied to problems like merging sorted arrays or finding pairs with a given sum.

---

## Tips for Similar Problems

1. **Identify Constraints**:
   - Look for phrases like "at most $k$", "exactly $k$", or "no more than $k$ distinct values" to recognize sliding window applicability.

2. **Dynamic Window**:
   - If the problem involves a range or subarray that changes dynamically, consider using two pointers.

3. **Optimize Counting**:
   - Use hash maps or frequency arrays to efficiently track elements in the current range.

4. **Break Down the Problem**:
   - Focus on counting valid subarrays or substrings ending at a specific position to simplify the solution.

