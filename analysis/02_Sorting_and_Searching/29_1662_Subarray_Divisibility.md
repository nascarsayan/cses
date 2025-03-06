# Subarray Divisibility

[Problem Link](https://cses.fi/problemset/task/1662) | [Solution Link](../../solutions/02_Sorting_and_Searching/29_1662_Subarray_Divisibility.cpp)

## TL;DR

The problem is solved using prefix sums and modular arithmetic. By tracking the frequency of prefix sums modulo $n$, we efficiently count subarrays whose sums are divisible by $n$. The solution runs in $O(n)$ time and uses $O(n)$ space.

---

## Problem Overview

The task is to count the number of subarrays in a given array of $n$ integers such that the sum of the subarray is divisible by $n$. 

### Key Constraints:
- $1 \leq n \leq 2 \cdot 10^5$
- $-10^9 \leq a_i \leq 10^9$

### Example:

Input:
```
5
3 1 2 7 4
```

Output:
```
1
```

Explanation: The only subarray with a sum divisible by $n = 5$ is the entire array $[3, 1, 2, 7, 4]$, whose sum is $17$ and $17 \mod 5 = 0$.

---

## Solution Approach

### Key Idea:

The problem leverages **prefix sums** and **modular arithmetic** to efficiently count subarrays with sums divisible by $n$. Here's the breakdown:

1. **Prefix Sum Modulo $n$**:
   - Compute a running prefix sum as we iterate through the array.
   - For each prefix sum, compute its remainder when divided by $n$ (i.e., `prefix_sum % n`).
   - If two prefix sums have the same remainder, the subarray between them has a sum divisible by $n$.

2. **Frequency Map**:
   - Use a hash map (`aggCount`) to store the frequency of each remainder modulo $n$.
   - Initialize `aggCount[0] = 1` because a prefix sum itself being divisible by $n$ is a valid subarray.

3. **Counting Subarrays**:
   - For each prefix sum remainder, add the frequency of that remainder (from the map) to the result. This counts all subarrays ending at the current index that are divisible by $n$.
   - Update the frequency of the current remainder in the map.

4. **Handling Negative Remainders**:
   - To ensure all remainders are non-negative, use the formula:
     $$
     \text{remainder} = (\text{prefix\_sum} \% n + n) \% n
     $$

### Algorithm Steps:

1. Initialize `agg = 0` (prefix sum) and `res = 0` (result).
2. Create a map `aggCount` and set `aggCount[0] = 1`.
3. Iterate through the array:
   - Update the prefix sum: `agg = (agg + val) % n`.
   - Normalize the remainder: `agg = (agg + n) % n`.
   - Add `aggCount[agg]` to `res`.
   - Increment `aggCount[agg]`.
4. Print the result `res`.

---

## Key Learning Points

1. **Prefix Sums**:
   - Prefix sums are a powerful tool for solving subarray problems efficiently.
   - By storing intermediate results, they reduce the need for nested loops.

2. **Modular Arithmetic**:
   - Modular arithmetic is crucial for handling cyclic properties, such as divisibility.
   - Normalizing negative remainders ensures consistency.

3. **Hash Maps for Frequency Counting**:
   - Hash maps allow efficient tracking of occurrences of values (in this case, remainders).

4. **Efficient Counting**:
   - The solution avoids explicitly iterating over all subarrays, reducing time complexity from $O(n^2)$ to $O(n)$.

---

## Common Pitfalls

1. **Negative Remainders**:
   - Forgetting to normalize remainders can lead to incorrect results, especially when the array contains negative numbers.

2. **Initialization of `aggCount`**:
   - Failing to initialize `aggCount[0] = 1` will miss subarrays starting from the beginning of the array.

3. **Overflow in Prefix Sum**:
   - Although not an issue in this problem due to modular arithmetic, be cautious of potential overflow when dealing with large numbers.

---

## Complexity

### Time Complexity:
- **$O(n)$**: We iterate through the array once, and all operations (prefix sum, modulo, map access) are $O(1)$.

### Space Complexity:
- **$O(n)$**: The hash map can store up to $n$ unique remainders in the worst case.

---

## Alternative Approaches

1. **Brute Force**:
   - Iterate over all subarrays and compute their sums, checking divisibility by $n$.
   - **Time Complexity**: $O(n^2)$ (inefficient for large $n$).

2. **Fenwick Tree / Segment Tree**:
   - Use a Fenwick Tree or Segment Tree to calculate prefix sums and ranges efficiently.
   - **Time Complexity**: $O(n \log n)$ (slower than the hash map approach).

---

## Extended Learning

1. **Modular Arithmetic**:
   - Explore properties of modular arithmetic, such as $(a + b) \% n = ((a \% n) + (b \% n)) \% n$.

2. **Prefix Sum Applications**:
   - Problems involving subarray sums, ranges, or cumulative properties often benefit from prefix sums.

3. **Hash Maps in Competitive Programming**:
   - Learn to use hash maps effectively for frequency counting and lookups.

---

## Tips for Similar Problems

1. **Recognize Prefix Sum Patterns**:
   - If a problem involves subarray sums or ranges, consider using prefix sums.

2. **Look for Modular Arithmetic**:
   - If divisibility or cyclic properties are involved, modular arithmetic is likely useful.

3. **Use Hash Maps for Counting**:
   - When tracking occurrences of values or states, hash maps are often the most efficient tool.

4. **Optimize for Constraints**:
   - For large inputs, avoid nested loops and aim for linear or logarithmic solutions.

---