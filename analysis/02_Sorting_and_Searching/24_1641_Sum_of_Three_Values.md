# Sum of Three Values

[Problem Link](https://cses.fi/problemset/task/1641) | [Solution Link](../../solutions/02_Sorting_and_Searching/24_1641_Sum_of_Three_Values.cpp)

## TL;DR
Fix middle element and use two-pointer technique to find remaining two elements. Sort array while preserving original indices.

## Problem Overview
Find three distinct positions in array whose values sum to target x. Need to return the positions (1-based indexing).

## Solution Approach
Extension of two-sum problem with index preservation:

1. **Index Preservation**
   - Store (value, position) pairs
   - Sort pairs by value
   - Keep original 1-based indices
   - Use pairs throughout algorithm

2. **Three-Sum Search**
   - For each middle element:
     * Use two pointers (lo, hi) for remaining elements
     * Move pointers based on sum comparison
     * Ensure distinct positions maintained
     * Early return on finding solution

## Key Learning Points
1. **Two-Pointer Extension**
   - How to handle third element
   - Maintaining position constraints
   - Efficient search space reduction
   - Early termination conditions

2. **Implementation Details**
   - Using pair<value, index>
   - Sorting with indices
   - Position boundary checks
   - Three-way sum comparison

## Common Pitfalls
1. Not preserving original indices
2. Wrong index boundaries
3. Duplicate position usage
4. Inefficient search space traversal

## Complexity
- Time Complexity: O(n² log n)
- Space Complexity: O(n)
- Better than O(n³) brute force

## Extended Learning
- Related problems:
  1. k-sum variations
  2. Two pointers with constraints
  3. Sorted array searching
  4. Index tracking problems

## Tips for Similar Problems
1. Consider sorting if order doesn't matter
2. Track indices when sorting required
3. Look for two-pointer opportunities
4. Handle position constraints carefully

## Why It Works
1. Sorting enables efficient search
2. Middle element fixes one value
3. Two pointers find remaining sum
4. All combinations covered efficiently

## Real-world Applications
- Financial calculations
- Resource combination finding
- Pattern matching
- Subset sum variations