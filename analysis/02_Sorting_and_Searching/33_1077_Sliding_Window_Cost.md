# Sliding Window Cost

[Problem Link](https://cses.fi/problemset/task/1077) | [Solution Link](../../solutions/02_Sorting_and_Searching/33_1077_Sliding_Window_Cost.cpp)

## TL;DR

The problem involves calculating the minimum total cost of making all elements in a sliding window of size $k$ equal. The solution leverages the properties of the median and uses efficient data structures like balanced binary search trees (or their equivalents) to maintain the sliding window and compute the cost in $O(n \log k)$ time.

---

## Problem Overview

The task is to compute the minimum total cost for each sliding window of size $k$ in an array of $n$ integers. The cost is defined as the sum of absolute differences between each element in the window and a chosen target value. The optimal target value for minimizing the cost is the **median** of the elements in the window.

### Key Observations:
1. The cost function is minimized when the target value is the median of the window.
2. Efficiently maintaining the median as the window slides is crucial for solving the problem within the constraints.

---

## Solution Approach

### Core Idea:
The solution revolves around maintaining a sliding window of size $k$ and efficiently computing the median and the corresponding cost for each window. This is achieved using a balanced data structure (e.g., multiset or two heaps).

### Steps:
1. **Sliding Window with Median Maintenance**:
   - Use two heaps (a max-heap for the left half and a min-heap for the right half) to maintain the elements of the current window.
   - The max-heap stores the smaller half of the elements, and the min-heap stores the larger half. This ensures that the median is always at the top of one of the heaps.

2. **Adding and Removing Elements**:
   - When the window slides, add the new element to one of the heaps and remove the outgoing element from the appropriate heap.
   - Rebalance the heaps to ensure that the size difference between the two heaps is at most 1.

3. **Calculating the Cost**:
   - The median is the top of the max-heap if the window size is odd, or the average of the tops of the two heaps if the window size is even.
   - Compute the cost by summing the absolute differences between the elements in the window and the median. This can be done efficiently by maintaining cumulative sums of the elements in each heap.

4. **Output the Results**:
   - For each window, output the computed cost.

### Pseudocode:
```plaintext
Initialize two heaps: maxHeap (left) and minHeap (right)
For i in 0 to n-1:
    Add x[i] to the appropriate heap
    Rebalance the heaps if necessary
    If i >= k-1:
        Compute the median
        Compute the cost using the median
        Output the cost
        Remove x[i-k+1] from the appropriate heap
```

---

## Key Learning Points

1. **Median Minimizes Absolute Differences**:
   - The median is the optimal value for minimizing the sum of absolute differences, which is a key mathematical property used in this problem.

2. **Efficient Sliding Window Management**:
   - Using two heaps (or a balanced binary search tree) allows efficient insertion, deletion, and median computation within logarithmic time.

3. **Data Structure Choice**:
   - The choice of data structure (e.g., heaps or balanced trees) is critical for achieving the required performance.

4. **Cumulative Sums for Cost Calculation**:
   - Maintaining cumulative sums of elements in each heap allows efficient computation of the total cost.

---

## Common Pitfalls

1. **Incorrect Median Calculation**:
   - Failing to correctly rebalance the heaps can lead to incorrect median computation.

2. **Handling Edge Cases**:
   - Ensure proper handling of edge cases, such as when the window size $k$ is 1 or equal to $n$.

3. **Inefficient Operations**:
   - Using naive approaches like sorting the window for each slide results in $O(nk \log k)$ time, which is too slow for large inputs.

---

## Complexity

### Time Complexity:
- **Insertion/Deletion in Heaps**: $O(\log k)$ per operation.
- **Sliding Window**: $O(n)$ insertions and deletions.
- Total: $O(n \log k)$.

### Space Complexity:
- Two heaps store at most $k$ elements: $O(k)$.

---

## Alternative Approaches

1. **Balanced Binary Search Tree**:
   - Use a balanced BST (e.g., `std::multiset` in C++) to maintain the window. This allows efficient insertion, deletion, and median calculation.

2. **Brute Force**:
   - For each window, sort the elements and compute the median and cost. This is computationally expensive ($O(nk \log k)$) and not feasible for large inputs.

3. **Prefix Sums**:
   - Use prefix sums to compute the cost more efficiently, but this still requires efficient median maintenance.

---

## Extended Learning

1. **Sliding Window Techniques**:
   - Learn about other problems involving sliding windows, such as finding maximum/minimum values or sums in a window.

2. **Median Properties**:
   - Study the mathematical properties of the median and its applications in optimization problems.

3. **Data Structures**:
   - Explore advanced data structures like Fenwick Trees, Segment Trees, and Balanced BSTs for efficient range queries and updates.

---

## Tips for Similar Problems

1. **Recognize Median-Based Optimization**:
   - If the problem involves minimizing absolute differences, the median is likely involved.

2. **Sliding Window + Data Structures**:
   - Combine sliding window techniques with efficient data structures (heaps, BSTs) for dynamic updates.

3. **Focus on Constraints**:
   - Analyze the constraints to determine whether a brute-force approach is feasible or if optimization is necessary.

4. **Precompute Where Possible**:
   - Use prefix sums or other precomputation techniques to reduce redundant calculations.