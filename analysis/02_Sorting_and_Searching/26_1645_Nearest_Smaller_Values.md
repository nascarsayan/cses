# Nearest Smaller Values

[Problem Link](https://cses.fi/problemset/task/1645) | [Solution Link](../../solutions/02_Sorting_and_Searching/26_1645_Nearest_Smaller_Values.cpp)

## TL;DR
Use monotonic stack to maintain increasing values, popping larger elements when a smaller one arrives to efficiently find nearest smaller value.

## Problem Overview
For each position in array, find the nearest position to its left that has a smaller value. Output 0 if no such position exists.

## Solution Approach
This problem demonstrates perfect use case for monotonic stack:

1. **Stack Maintenance**
   - Keep stack in increasing order
   - Stack stores (value, position) pairs
   - Pop elements ≥ current value
   - Stack top is nearest smaller value

2. **Processing Steps**
   - For each new element:
     * Pop while stack top ≥ current
     * Print stack top position (or 0)
     * Push current (value, position)
   - One-pass solution

## Key Learning Points
1. **Monotonic Stack Properties**
   - Maintains increasing sequence
   - Elements represent potential answers
   - Efficient nearest smaller/greater finding
   - Natural order preservation

2. **Implementation Details**
   - Using pair<value, position>
   - 1-based position handling
   - Stack emptiness checks
   - Immediate output generation

## Common Pitfalls
1. Wrong comparison (> vs ≥)
2. Incorrect position indexing
3. Missing stack empty checks
4. Wrong order in pair storage

## Complexity
- Time Complexity: O(n)
- Space Complexity: O(n)
- Each element pushed/popped at most once

## Extended Learning
- Related problems:
  1. Next greater element
  2. Maximum area histogram
  3. Online minimum queries
  4. Stack with history

## Tips for Similar Problems
1. Consider monotonic properties
2. Think about maintaining invariants
3. Store auxiliary information
4. Process elements sequentially

## Why Stack Works
1. Stack maintains potential answers
2. Larger elements can't be answers
3. Pop operations skip unnecessary checks
4. Natural left-to-right processing

## Real-world Applications
- Stock span calculation
- Building skyline problems
- Temperature range analysis
- Online data processing