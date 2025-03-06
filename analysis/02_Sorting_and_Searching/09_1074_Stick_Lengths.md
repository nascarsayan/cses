# Stick Lengths

[Problem Link](https://cses.fi/problemset/task/1074) | [Solution Link](../../solutions/02_Sorting_and_Searching/09_1074_Stick_Lengths.cpp)

## TL;DR
The optimal length to minimize total cost is the median of all stick lengths. Sort array and pick middle element.

## Problem Overview
Given n sticks of different lengths, make all sticks equal length by either increasing or decreasing their lengths. The cost is the absolute difference between new and original length.

## Solution Approach
This problem introduces an important mathematical concept:

1. **Median Minimizes Absolute Deviations**
   - Sort all stick lengths
   - Take middle element (n/2 th element)
   - Sum absolute differences from median

2. **Why Median Works**
   - Any value less than median: more sticks above than below
   - Any value more than median: more sticks below than above
   - Median balances costs in both directions

## Key Learning Points
1. **Mathematical Insight**
   - Median minimizes sum of absolute deviations
   - Mean would minimize sum of squared deviations
   - No need to try other values

2. **Implementation Details**
   - Using long long for large sums
   - No need to handle even/odd n differently
   - Sort first for O(n log n) solution

## Common Pitfalls
1. Using mean instead of median
2. Integer overflow with regular ints
3. Trying to binary search solution space
4. Not sorting before finding median

## Complexity
- Time Complexity: O(n log n) for sorting
- Space Complexity: O(1) extra space

## Extended Learning
- Related concepts:
  1. Geometric median (2D/3D version)
  2. L1 vs L2 norm minimization
  3. Robust statistics
  4. Outlier sensitivity

## Tips for Similar Problems
1. Think about what measure to minimize
2. Consider statistical properties
3. Watch for integer overflow
4. Look for mathematical shortcuts

## Real-world Applications
- Resource allocation
- Manufacturing standardization
- Error minimization
- Data clustering

## Why It Works
1. Moving target away from median increases total cost
2. Balanced number of elements above/below
3. Optimal for minimizing absolute differences
4. Works for any distribution of values