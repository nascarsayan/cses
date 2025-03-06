# Subarray Sums II

[Problem Link](https://cses.fi/problemset/task/1661) | [Solution Link](../../solutions/02_Sorting_and_Searching/28_1661_Subarray_Sums_II.cpp)

## TL;DR
Use prefix sum with frequency map to track count of each cumulative sum. For each prefix, look for complement (current_sum - target) in map.

## Problem Overview
Same as Subarray Sums I, but now array elements can be negative. Count number of contiguous subarrays summing to target x.

## Solution Approach
Hash map based solution that's more efficient than previous binary search approach:

1. **Prefix Sum with Map**
   - Track running sum (prefix sum)
   - Store frequency of each prefix sum
   - For each prefix:
     * Check count of (sum - target)
     * Update frequency of current sum
   - O(n) solution

2. **Why Different from Part I**
   - Negative numbers possible
   - Can't use binary search (not monotonic)
   - Multiple subarrays possible
   - Need to track all prefix frequencies

## Key Learning Points
1. **Map Usage**
   - Count of each prefix sum
   - O(log n) map operations
   - Handles duplicates naturally
   - Works with negative numbers

2. **Problem Adaptation**
   - How approach changes with negatives
   - Why previous solution fails
   - Importance of complement counting
   - Running sum vs array storage

## Common Pitfalls
1. Not initializing map[0] = 1
2. Integer overflow in sums
3. Wrong order of operations
4. Missing edge cases

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Each map operation is O(log n)

## Extended Learning
- Related concepts:
  1. Continuous vs non-continuous subarrays
  2. Prefix sum variations
  3. Hash map optimizations
  4. Counting with conditions

## Tips for Similar Problems
1. Consider hash map when ordering lost
2. Track frequencies for duplicates
3. Initialize base cases properly
4. Handle negative numbers carefully

## Alternative Approaches
1. Two pointers (not optimal here)
2. Segment tree (overkill)
3. Sliding window (doesn't work with negatives)
4. Binary search (fails without positivity)

## Why It Works
1. Every subarray is a difference of prefixes
2. Map tracks all possible prefix sums
3. Complement finding gives valid subarrays
4. Works regardless of element signs