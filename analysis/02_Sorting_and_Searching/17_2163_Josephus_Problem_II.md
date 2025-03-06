# Josephus Problem II

[Problem Link](https://cses.fi/problemset/task/2163) | [Solution Link](../../solutions/02_Sorting_and_Searching/17_2163_Josephus_Problem_II.cpp)

## TL;DR
Use GNU PBDS ordered_set with order statistics to efficiently find and remove kth elements in a circle. Much more efficient than manual iteration.

## Problem Overview
Similar to Josephus I, but now we skip k children before removing one. This makes manual iteration impractical for large k values.

## Solution Approach
This problem requires a specialized data structure with order statistics:

1. **Policy Based Data Structure**
   - Use GNU PBDS ordered_set
   - Provides order_of_key() and find_by_order()
   - Perfect for finding kth element
   - O(log n) for all operations

2. **Efficient k-skip Implementation**
   - Calculate initial position as k % n
   - After each removal, update position
   - New position = (p + k) % remaining_size
   - No need for manual iteration

## Key Learning Points
1. **Advanced Data Structures**
   - PBDS for order statistics
   - Order maintenance during deletions
   - Efficient random access in ordered set
   - Modulo arithmetic for circular access

2. **Implementation Details**
   - Include PBDS headers
   - Template syntax for ordered_set
   - Position updates with modulo
   - Size-based termination

## Common Pitfalls
1. Using regular set (too slow)
2. Wrong modulo calculation
3. Not handling size changes
4. Position update errors

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Each operation: O(log n)

## Extended Learning
- Related concepts:
  1. Order statistics trees
  2. Self-balancing BSTs
  3. Circular queue simulations
  4. Modular arithmetic

## Tips for Similar Problems
1. Consider specialized data structures
2. Look for efficient alternatives to iteration
3. Handle circular nature carefully
4. Think about position updates

## Why PBDS Works Best
1. O(log n) access to kth element
2. Maintains order automatically
3. Efficient removals
4. Built-in order statistics

## Implementation Notes
1. PBDS Setup
   - Include necessary headers
   - Define ordered_set template
   - Use find_by_order for access
   - Handle circular nature with modulo

2. Position Management
   - Initial position = k % n
   - Update formula crucial
   - Consider remaining set size
   - Avoid manual counting