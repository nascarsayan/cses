# Traffic Lights

[Problem Link](https://cses.fi/problemset/task/1163) | [Solution Link](../../solutions/02_Sorting_and_Searching/15_1163_Traffic_Lights.cpp)

## TL;DR
Use two sets: one for light positions and another for segment lengths. For each new light, split the segment it falls in and update maximum gap.

## Problem Overview
Given a street of length x, traffic lights are added one by one. After each addition, find the longest segment without any traffic lights.

## Solution Approach
Efficient interval management using two ordered sets:

1. **Dual Set Management**
   - Set 'pos' tracks all light positions (including endpoints 0,x)
   - Multiset 'segs' maintains all segment lengths
   - For each new light, update both sets

2. **Segment Updates**
   - Find segment containing new light using lower_bound
   - Remove old segment length from segs
   - Add two new segment lengths
   - Report largest current segment (segs.rbegin())

## Key Learning Points
1. **Set Operations**
   - lower_bound to find containing segment
   - prev() to get left endpoint
   - multiset for duplicate lengths
   - rbegin() for maximum value

2. **Implementation Details**
   - Include endpoints (0,x) initially
   - Handle zero-length segments
   - Fast I/O optimization
   - Efficient segment splitting

## Common Pitfalls
1. Forgetting to include street endpoints
2. Not using multiset for segments
3. Wrong segment calculation
4. Not handling duplicate segment lengths

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Each operation: O(log n)

## Extended Learning
- Related concepts:
  1. Range queries and updates
  2. Interval tree variations
  3. Dynamic segment problems
  4. Line sweep with intervals

## Tips for Similar Problems
1. Consider maintaining sorted positions
2. Think about efficient segment updates
3. Use appropriate data structures for duplicates
4. Handle boundary cases carefully

## Real-world Applications
- Resource allocation
- Network bandwidth management
- Traffic control systems
- Dynamic partitioning

## Why It Works
1. Sets maintain ordered positions efficiently
2. Multiset handles duplicate segment lengths
3. Only local updates needed for each light
4. Maximum segment always at end of multiset