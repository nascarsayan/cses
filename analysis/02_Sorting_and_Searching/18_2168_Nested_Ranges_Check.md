# Nested Ranges Check

[Problem Link](https://cses.fi/problemset/task/2168) | [Solution Link](../../solutions/02_Sorting_and_Searching/18_2168_Nested_Ranges_Check.cpp)

## TL;DR
Sort ranges by left endpoint (ascending) and right endpoint (descending). Process ranges in both directions to check containment using max/min tracking.

## Problem Overview
Given n ranges [x,y], determine for each range:
1. If it contains any other range
2. If it is contained by any other range

## Solution Approach
Two-pass solution with clever sorting:

1. **Smart Range Sorting**
   - Sort by left endpoint (primary key)
   - For equal lefts, sort by right endpoint descending
   - This ordering helps identify containment

2. **Two-Direction Processing**
   - Forward pass: find ranges contained by others
     * Track maximum right endpoint seen
     * Current range contained if its right ≤ max
   - Backward pass: find ranges containing others
     * Track minimum right endpoint seen
     * Current range contains if its right ≥ min

## Key Learning Points
1. **Sorting Strategy**
   - Custom comparator for segments
   - Why descending order for equal lefts
   - Importance of maintaining indices

2. **Containment Properties**
   - Forward/backward processing logic
   - Max/min tracking sufficiency
   - No need for explicit comparisons

## Common Pitfalls
1. Wrong sorting order
2. Not tracking original indices
3. Missing edge cases in containment
4. Integer overflow in calculations

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Two linear passes after sort

## Extended Learning
- Related concepts:
  1. Interval scheduling
  2. Range overlap problems
  3. Line sweep variations
  4. Two-pass algorithms

## Tips for Similar Problems
1. Draw out range relationships
2. Consider sorting strategies
3. Look for efficient ways to check containment
4. Think about processing order

## Implementation Details
1. Segment Structure
   - Store left, right endpoints
   - Keep original index
   - Custom comparison operator
   
2. Processing Technique
   - Forward pass with maxEnd
   - Backward pass with minEnd
   - Use vector to store results
   - Maintain original order in output

## Why It Works
1. Sorting ensures proper order for checking
2. Max/min tracking sufficient for containment
3. Two passes handle both containment types
4. Original indices preserve input order