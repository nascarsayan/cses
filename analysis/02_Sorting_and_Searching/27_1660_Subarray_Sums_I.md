# Subarray Sums I

[Problem Link](https://cses.fi/problemset/task/1660) | [Solution Link](../../solutions/02_Sorting_and_Searching/27_1660_Subarray_Sums_I.cpp)

## TL;DR
Use prefix sums and binary search to efficiently find subarrays that sum to target value. For each prefix, search for another prefix that differs by target sum.

## Problem Overview
Given an array of n positive integers, count the number of contiguous subarrays that sum exactly to x.

## Solution Approach
The solution combines prefix sums with binary search:

1. **Prefix Sum Array**
   - Build cumulative sum array
   - pre[i] = sum of elements [0..i]
   - Subarray sum [i..j] = pre[j] - pre[i-1]
   - O(n) preprocessing

2. **Search Strategy**
   - For each prefix position i:
     * Target value = pre[i] + x
     * Binary search for target in pre[i+1..]
     * Count exact matches
   - O(n log n) overall

## Key Learning Points
1. **Prefix Sum Properties**
   - Enables O(1) range sum queries
   - Sorted nature allows binary search
   - Handles large input efficiently
   - Avoids repeated summations

2. **Binary Search Usage**
   - Finding specific sum values
   - lower_bound for efficient search
   - Exact match verification needed
   - Careful with array bounds

## Common Pitfalls
1. Integer overflow in sums
2. Wrong prefix array indexing
3. Missing edge cases
4. Binary search boundary errors

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Each prefix requires binary search

## Extended Learning
- Alternative approaches:
  1. Two-pointer sliding window O(n)
  2. Hash map for O(n) solution
  3. Segment tree variations
  4. Kadane's algorithm variations

## Tips for Similar Problems
1. Consider preprocessing step
2. Look for efficient search methods
3. Handle array bounds carefully
4. Watch for overflow in sums

## Real-world Applications
- Financial analytics
- Signal processing
- Network traffic analysis
- Pattern detection

## Why It Works
1. Prefix sums enable quick range sums
2. Binary search exploits sorted property
3. All possible subarrays covered
4. No redundant calculations