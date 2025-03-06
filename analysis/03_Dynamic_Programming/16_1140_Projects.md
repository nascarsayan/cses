# Projects

[Problem Link](https://cses.fi/problemset/task/1140) | [Solution Link](../../solutions/03_Dynamic_Programming/16_1140_Projects.cpp)

## TL;DR

The problem is solved using **Dynamic Programming (DP)** with coordinate compression. The projects are sorted by their ending times, and a DP array is used to store the maximum reward achievable up to each compressed time point. The solution efficiently handles overlapping intervals by leveraging coordinate compression and iterating over valid project ranges.

---

## Problem Overview

You are given $n$ projects, each with a start day, end day, and reward. You can only attend one project at a time, and the goal is to maximize the total reward by selecting non-overlapping projects. The constraints make it necessary to use an efficient approach since $n$ can be as large as $200,000$, and the time range can go up to $10^9$.

---

## Solution Approach

### Key Steps:

1. **Coordinate Compression**:
   - Since the project start and end times can range up to $10^9$, directly using these values in a DP array would be infeasible due to memory constraints.
   - To address this, we compress the start and end times into a smaller range of indices. This is done by mapping each unique time point to a smaller index.

2. **Sorting Projects**:
   - The projects are sorted by their (compressed) ending times. This ensures that when processing a project, all previously considered projects have already been processed.

3. **Dynamic Programming**:
   - A DP array, `dp[end]`, is used where `dp[end]` represents the maximum reward achievable up to the compressed time `end`.
   - For each project ending at time `end`, the DP value is updated by considering the reward of the current project plus the best reward achievable up to its (compressed) start time.

4. **Efficient Updates**:
   - For each compressed time point, the DP value is either carried forward from the previous time point or updated based on the projects ending at the current time.

### Algorithm:

1. Parse the input and store the projects.
2. Perform coordinate compression on all start and end times.
3. Sort the projects by their compressed end times.
4. Use a DP array to compute the maximum reward:
   - For each compressed time point, update the DP value based on the projects ending at that time.
   - Use the maximum of the previous DP value and the reward of the current project plus the DP value of its start time.

5. The final answer is stored in the last entry of the DP array.

---

## Key Learning Points

1. **Coordinate Compression**:
   - Essential for handling problems with large ranges of values that cannot be directly used in arrays.
   - Maps large values to a smaller range while preserving relative order.

2. **Dynamic Programming with Intervals**:
   - A common pattern in interval-based problems is to sort by one endpoint (e.g., end time) and use DP to manage overlapping intervals.

3. **Efficient Updates**:
   - Instead of iterating over all previous intervals, the use of sorted intervals and compressed indices allows efficient updates.

4. **Optimization Tricks**:
   - Incrementing the end time by 1 during compression ensures that intervals are treated correctly without overlap.

---

## Common Pitfalls

1. **Not Compressing Coordinates**:
   - Attempting to directly use large time values in the DP array will result in excessive memory usage.

2. **Incorrect Sorting**:
   - Sorting by start time instead of end time can lead to incorrect results, as it disrupts the order of processing intervals.

3. **Overlapping Intervals**:
   - Failing to correctly handle overlapping intervals can lead to suboptimal solutions.

4. **Boundary Conditions**:
   - Forgetting to handle the case where no projects are selected or where projects start at the same time.

---

## Complexity

### Time Complexity:
1. **Coordinate Compression**:
   - Compressing the coordinates involves sorting the unique time points, which takes $O(n \log n)$.
2. **Sorting Projects**:
   - Sorting the projects by end time also takes $O(n \log n)$.
3. **DP Updates**:
   - Iterating over all compressed time points and updating the DP array takes $O(n)$ in total, as each project is processed once.

Overall: **$O(n \log n)$**

### Space Complexity:
1. **Coordinate Compression**:
   - Storing the mapping of time points requires $O(n)$ space.
2. **DP Array**:
   - The DP array size is proportional to the number of unique compressed time points, which is $O(n)$ in the worst case.

Overall: **$O(n)$**

---

## Alternative Approaches

1. **Binary Search with Sorted Intervals**:
   - Instead of coordinate compression, use a sorted list of intervals and binary search to find the latest non-overlapping project. This approach also achieves $O(n \log n)$ time complexity but avoids the need for compression.

2. **Segment Trees**:
   - Use a segment tree to store and query the maximum reward up to a given time point. This approach can handle updates and queries efficiently but is more complex to implement.

3. **Sweep Line Algorithm**:
   - Use a sweep line approach to process events (start and end of projects) in chronological order. This approach can be combined with data structures like Fenwick trees for efficient updates.

---

## Extended Learning

1. **Weighted Interval Scheduling**:
   - This problem is a classic example of weighted interval scheduling, where the goal is to maximize the sum of weights of non-overlapping intervals.

2. **Coordinate Compression**:
   - Useful in problems involving large ranges of discrete values, such as range queries or interval problems.

3. **Dynamic Programming on Ranges**:
   - A common pattern in problems involving intervals, scheduling, or subsequences.

---

## Tips for Similar Problems

1. **Look for Overlapping Intervals**:
   - If the problem involves intervals, consider sorting by one endpoint and using DP or binary search to handle overlaps.

2. **Use Coordinate Compression**:
   - If the input values are large but sparse, coordinate compression can simplify the problem.

3. **Optimize with Sorting**:
   - Sorting the intervals or events often simplifies the logic and reduces complexity.

4. **Think in Terms of States**:
   - For DP problems, define the state clearly (e.g., maximum reward up to a certain time) and derive transitions logically.

5. **Use Efficient Data Structures**:
   - For range queries or updates, consider segment trees, Fenwick trees, or binary search on sorted arrays.