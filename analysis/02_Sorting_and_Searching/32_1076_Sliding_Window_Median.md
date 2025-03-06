# Sliding Window Median

[Problem Link](https://cses.fi/problemset/task/1076) | [Solution Link](../../solutions/02_Sorting_and_Searching/32_1076_Sliding_Window_Median.cpp)

## TL;DR

To solve the "Sliding Window Median" problem, we use two balanced multisets (or priority queues) to maintain the current window of size $k$. These structures allow efficient insertion, deletion, and median extraction. The key is to maintain the left set (smaller half) and right set (larger half) such that the median is always the largest element in the left set. The solution involves iterating through the array, updating the sets, and outputting the median for each window.

---

## Problem Overview

The problem requires calculating the median of every sliding window of size $k$ in an array of $n$ integers. The median is defined as the middle element when the window is sorted, or the smaller of the two middle elements if the size is even. The task is to efficiently compute these medians as the window slides from left to right.

### Input:
- $n$: Number of elements in the array.
- $k$: Size of the sliding window.
- Array of $n$ integers.

### Output:
- $n-k+1$ integers: The medians of all sliding windows.

### Constraints:
- $1 \leq k \leq n \leq 2 \cdot 10^5$
- $1 \leq x_i \leq 10^9$

---

## Solution Approach

### Key Idea:
The main challenge is to efficiently maintain the median of the current window as it slides. A brute-force approach (sorting the window for each position) would be too slow, so we use a data structure-based approach with two multisets or heaps.

### Steps:
1. **Two Multisets (or Heaps):**
   - Use two balanced multisets (or heaps):
     - `left`: Stores the smaller half of the current window.
     - `right`: Stores the larger half of the current window.
   - The median is always the largest element in `left`.

2. **Balancing the Sets:**
   - Ensure that the sizes of `left` and `right` differ by at most 1.
   - If the sizes are equal, the largest element in `left` is the median.

3. **Sliding the Window:**
   - For each new element added to the window:
     - Insert it into the appropriate set (`left` or `right`).
     - Balance the sets if necessary.
   - Remove the element that is sliding out of the window:
     - Locate and erase it from the appropriate set.
     - Rebalance the sets if necessary.

4. **Output the Median:**
   - After each update, the median is the largest element in `left`.

### Implementation Details:
- Use `std::multiset` in C++ to handle duplicates and support efficient insertion, deletion, and median extraction.
- Alternatively, use two heaps (max-heap for `left` and min-heap for `right`), but this requires additional logic to handle deletions.

---

## Key Learning Points

1. **Sliding Window Problems:**
   - Efficiently maintaining a subset of elements (e.g., a window) as it slides over an array is a common problem in competitive programming.

2. **Balanced Data Structures:**
   - Using two balanced sets or heaps is a powerful technique for problems involving medians or other order statistics.

3. **Median Maintenance:**
   - The median can be efficiently maintained by splitting the data into two halves and ensuring balance between them.

4. **Efficient Deletion:**
   - When using `std::multiset`, deletion is straightforward. For heaps, lazy deletion or auxiliary structures may be needed.

---

## Common Pitfalls

1. **Balancing Errors:**
   - Forgetting to rebalance the two sets after insertion or deletion can lead to incorrect medians.

2. **Handling Duplicates:**
   - Ensure that duplicates are correctly managed, especially during deletions.

3. **Edge Cases:**
   - Small values of $k$ (e.g., $k = 1$) or $n$ (e.g., $n = k$) can behave differently.
   - Ensure the implementation handles these cases correctly.

4. **Efficiency:**
   - Using a naive approach (e.g., sorting the window for each position) will exceed the time limit for large inputs.

---

## Complexity

### Time Complexity:
- **Insertion/Deletion in Multiset:** $O(\log k)$ per operation.
- **Sliding Window:** $O(n \cdot \log k)$ for $n-k+1$ windows.

### Space Complexity:
- **Multisets:** $O(k)$ for storing the current window.

Overall complexity:  
- **Time:** $O(n \cdot \log k)$  
- **Space:** $O(k)$

---

## Alternative Approaches

1. **Two Heaps:**
   - Use a max-heap for `left` and a min-heap for `right`. This approach is similar to the multiset solution but requires additional logic for deletions.

2. **Order Statistic Tree:**
   - Use a data structure like a Fenwick Tree or Segment Tree with order statistics to maintain the window and extract the median.

3. **Mo's Algorithm:**
   - For offline queries, Mo's Algorithm can be used to efficiently compute medians for multiple windows.

---

## Extended Learning

- **Order Statistics:**
  - Learn about data structures that efficiently support order statistics (e.g., finding the $k$-th smallest element).

- **Sliding Window Techniques:**
  - Explore other sliding window problems, such as maximum/minimum in a window or sum of a window.

- **Heap-Based Algorithms:**
  - Study heap-based algorithms for problems involving dynamic insertion and deletion.

---

## Tips for Similar Problems

1. **Identify the Key Metric:**
   - For sliding window problems, determine the key metric to maintain (e.g., median, maximum, sum).

2. **Use Balanced Data Structures:**
   - For problems involving order statistics, balanced data structures like heaps or multisets are often useful.

3. **Optimize for Sliding:**
   - Avoid recomputing the entire window for each step. Instead, update the window incrementally.

4. **Handle Edge Cases:**
   - Always test with small inputs, large inputs, and edge cases (e.g., duplicates, smallest/largest values).