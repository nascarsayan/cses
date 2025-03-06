# Nested Ranges Count

[Problem Link](https://cses.fi/problemset/task/2169) | [Solution Link](../../solutions/02_Sorting_and_Searching/19_2169_Nested_Ranges_Count.cpp)

## TL;DR
Use coordinate compression and Fenwick Tree (Binary Indexed Tree) for efficient range counting. Process ranges in sorted order to count containments.

## Problem Overview
Similar to Nested Ranges Check, but now we need to count the number of ranges that each range contains and is contained by, not just check existence.

## Solution Approach
This problem requires more sophisticated data structures:

1. **Coordinate Compression**
   - Map large coordinate values to smaller indices
   - Store original values in sorted order
   - Convert all coordinates to compressed form
   - Makes Fenwick Tree operations efficient

2. **Fenwick Tree Usage**
   - Track cumulative count of endpoints
   - Forward pass: count ranges containing current
   - Backward pass: count ranges contained by current
   - Range sum queries for counting

## Key Learning Points
1. **Advanced Data Structures**
   - Fenwick Tree implementation
   - Coordinate compression technique
   - Range counting optimizations
   - Efficient prefix sum updates

2. **Two-Pass Strategy**
   - Forward pass with range queries
   - Backward pass with prefix queries
   - Maintain original indices
   - Handle duplicates properly

## Common Pitfalls
1. Integer overflow without compression
2. Wrong Fenwick Tree range queries
3. Not handling coordinate mapping correctly
4. Inefficient range sum calculations

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Each query: O(log n)

## Extended Learning
- Related concepts:
  1. Range update and query structures
  2. Coordinate compression techniques
  3. Fenwick Tree variations
  4. Space-time trade-offs

## Implementation Details
1. Data Structure Components
   - Segment struct for range info
   - SparseArray for compression
   - Fenwick template class
   - Custom sorting comparator

2. Processing Steps
   - Compress coordinates first
   - Sort ranges by left endpoint
   - Two passes with Fenwick Tree
   - Restore original order

## Why This Approach
1. Fenwick Tree enables efficient counting
2. Compression reduces memory and time
3. Two passes handle both count types
4. Maintains O(n log n) despite counting

## Tips for Similar Problems
1. Consider coordinate compression
2. Look for efficient range query structures
3. Think about order of processing
4. Handle large coordinate ranges carefully