# Array Division

[Problem Link](https://cses.fi/problemset/task/1085) | [Solution Link](../../solutions/02_Sorting_and_Searching/31_1085_Array_Division.cpp)

## TL;DR

The problem is solved using binary search on the maximum subarray sum. The approach involves determining the smallest possible "maximum sum" across $k$ subarrays by checking feasibility with a helper function. The solution efficiently narrows down the range of possible answers using binary search, leveraging the constraints of the problem.

---

## Problem Overview

The task is to divide an array of $n$ positive integers into $k$ contiguous subarrays such that the maximum sum of any subarray is minimized. The goal is to find this minimized maximum sum.

### Example:
For the input:
```
n = 5, k = 3
array = [2, 4, 7, 3, 5]
```
An optimal division is $[2,4], [7], [3,5]$, where the subarray sums are $6, 7, 8$. The largest sum is $8$, which is the answer.

---

## Solution Approach

### Key Idea
The problem can be solved using **binary search on the answer**. The key observation is that the maximum sum of a subarray in the optimal division lies between:
1. The largest element in the array (lower bound).
2. The total sum of the array (upper bound).

Using binary search, we iteratively narrow down this range to find the smallest possible "maximum sum" that satisfies the condition of dividing the array into $k$ subarrays.

### Steps
1. **Define the Search Space**:
   - The smallest possible maximum sum is the largest element in the array (`lo = max(array)`).
   - The largest possible maximum sum is the sum of all elements in the array (`hi = sum(array)`).

2. **Binary Search**:
   - Compute the midpoint of the current range, `mid = (lo + hi) / 2`.
   - Check if it is possible to divide the array into $k$ subarrays such that no subarray has a sum greater than `mid`.

3. **Feasibility Check**:
   - Use a helper function `check(maxSum)` to determine if the array can be divided into $k$ subarrays with the given `maxSum`.
   - Iterate through the array, maintaining a running sum of the current subarray. If adding the next element exceeds `maxSum`, start a new subarray and increment the subarray count.
   - If the subarray count exceeds $k$, return `false`. Otherwise, return `true`.

4. **Update Search Range**:
   - If `check(mid)` is `true`, update the answer to `mid` and search for smaller values (`hi = mid - 1`).
   - If `check(mid)` is `false`, search for larger values (`lo = mid + 1`).

5. **Output the Result**:
   - The final value of `lo` (or `ans`) after the binary search is the smallest possible maximum sum.

---

## Key Learning Points

1. **Binary Search on the Answer**:
   - This problem is a classic example of using binary search to find the optimal value of a function, rather than searching for an element in an array.

2. **Feasibility Function**:
   - The helper function `check(maxSum)` is crucial for determining if a candidate value is valid. It ensures that the solution respects the constraints of the problem.

3. **Range of Possible Answers**:
   - The bounds for binary search are determined by the problem constraints:
     - The largest element in the array (minimum possible maximum sum).
     - The total sum of the array (maximum possible maximum sum).

4. **Greedy Subarray Splitting**:
   - The feasibility check uses a greedy approach to split the array into subarrays while minimizing the number of subarrays.

---

## Common Pitfalls

1. **Incorrect Bounds**:
   - Forgetting to set the lower bound to the maximum element in the array can lead to incorrect results.

2. **Off-by-One Errors**:
   - Mismanaging the binary search range (`lo` and `hi`) or the subarray count during the feasibility check can cause errors.

3. **Overflow Issues**:
   - Since the array elements and their sums can be large ($10^9$), ensure that calculations use `long long` to avoid overflow.

4. **Edge Cases**:
   - Single-element arrays or cases where $k = n$ (each element is its own subarray) and $k = 1$ (entire array is one subarray) must be handled correctly.

---

## Complexity

### Time Complexity
1. **Binary Search**:
   - The binary search runs for $\log(\text{sum(array)} - \max(\text{array}))$ iterations, which is approximately $O(\log(\text{sum(array)}))$.
2. **Feasibility Check**:
   - Each check involves a single pass through the array, i.e., $O(n)$.

Thus, the total time complexity is:
$$
O(n \cdot \log(\text{sum(array)}))
$$

### Space Complexity
- The solution uses $O(n)$ space for the input array and a few variables, so the space complexity is:
$$
O(n)
$$

---

## Alternative Approaches

1. **Dynamic Programming**:
   - A DP approach could be used to compute the minimum maximum sum for dividing the array into $k$ subarrays. However, this would have a higher time complexity of $O(n^2 \cdot k)$ and is not feasible for the given constraints.

2. **Greedy with Priority Queue**:
   - A greedy approach with a priority queue could be used to balance subarray sums dynamically. However, this is more complex to implement and less efficient than binary search.

---

## Extended Learning

1. **Binary Search on the Answer**:
   - Problems like "Aggressive Cows" (placing cows in stalls) or "Book Allocation Problem" use similar techniques.

2. **Greedy Algorithms**:
   - The feasibility check is a greedy algorithm that ensures the constraints are satisfied while minimizing the number of subarrays.

3. **Divide and Conquer**:
   - This problem can also be viewed as a divide-and-conquer problem, where the array is divided into subarrays based on the constraints.

---

## Tips for Similar Problems

1. **Identify the Search Space**:
   - For optimization problems, determine the range of possible answers and whether binary search can be applied.

2. **Design a Feasibility Function**:
   - Ensure that the helper function correctly checks if a candidate solution satisfies the constraints.

3. **Handle Edge Cases**:
   - Always consider edge cases like minimum/maximum input sizes, single-element arrays, or extreme values.

4. **Optimize for Large Inputs**:
   - Use efficient algorithms (like binary search) and data structures to handle large constraints within time limits.