# Sum of Four Values

[Problem Link](https://cses.fi/problemset/task/1642) | [Solution Link](../../solutions/02_Sorting_and_Searching/25_1642_Sum_of_Four_Values.cpp)

## TL;DR
Use nested loops for first two numbers and two-pointer technique for remaining two numbers. Sort array while preserving original indices.

## Problem Overview
Find four distinct positions in array whose values sum to target x. Need to return the positions (1-based indexing).

## Solution Approach
Extension of three-sum problem with additional pointer:

1. **Four-Number Search**
   - Sort array with preserved indices
   - Fix first two numbers with nested loops
   - Use two pointers for remaining sum
   - O(n³) complexity but optimized

2. **Implementation Details**
   - Store (value, index) pairs
   - Sort by values for efficient search
   - Maintain 1-based indexing
   - Early termination checks

## Key Learning Points
1. **Multiple Pointer Management**
   - Two fixed + two moving pointers
   - Boundary conditions for all pointers
   - Efficient search space pruning
   - Early exit opportunities

2. **Search Space Optimization**
   - Fixed elements reduce dimensionality
   - Two-pointer technique for remaining sum
   - Sorting enables efficient search
   - No need to try all combinations

## Common Pitfalls
1. Integer overflow in sum calculation
2. Wrong pointer movement logic
3. Missing boundary checks
4. Inefficient search space traversal

## Complexity
- Time Complexity: O(n³)
- Space Complexity: O(n)
- Better than O(n⁴) brute force

## Extended Learning
- Related concepts:
  1. k-sum problems
  2. Multi-pointer techniques
  3. Search space reduction
  4. Sorting with index preservation

## Tips for Similar Problems
1. Break down into simpler subproblems
2. Look for dimension reduction
3. Consider sorting benefits
4. Handle index constraints carefully

## Alternative Approaches
1. Hash table for pair sums (O(n²) space)
2. Meet in middle technique
3. Two separate two-sum problems
4. Binary search variations

## Why It Works
1. Sorting enables efficient searching
2. Fixed elements reduce dimensions
3. Two pointers optimize remaining search
4. All combinations covered systematically