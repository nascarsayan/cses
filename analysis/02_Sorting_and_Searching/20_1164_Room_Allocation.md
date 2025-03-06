# Room Allocation

[Problem Link](https://cses.fi/problemset/task/1164) | [Solution Link](../../solutions/02_Sorting_and_Searching/20_1164_Room_Allocation.cpp)

## TL;DR
Sort customers by arrival time and use a multiset to track room end times. Reuse rooms when possible, allocate new ones when needed.

## Problem Overview
Given n customers with arrival and departure times, assign rooms to minimize the total number of rooms needed while ensuring no two customers overlap in the same room.

## Solution Approach
This problem combines scheduling with room assignment:

1. **Event Processing**
   - Sort customers by arrival time
   - Track room availability using end times
   - Reuse earliest-freeing room when possible
   - Allocate new room when necessary

2. **Room Management**
   - Use multiset to store (end_time, room_number)
   - Check earliest ending room on new arrival
   - Remove and reuse room if available
   - Track room assignments for output

## Key Learning Points
1. **Efficient Room Reuse**
   - Sort by arrival for sequential processing
   - Multiset for dynamic end time tracking
   - Room number preservation for output
   - Minimal room allocation strategy

2. **Implementation Details**
   - Custom range struct with original index
   - Pair of (end_time, room_number) in multiset
   - Vector to store final room assignments
   - Track maximum rooms needed

## Common Pitfalls
1. Not tracking original order
2. Wrong room number assignment
3. Inefficient room reuse logic
4. Not handling equal arrival times

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Each operation: O(log n)

## Extended Learning
- Related problems:
  1. Meeting room allocation
  2. Resource scheduling
  3. Interval assignment
  4. Activity selection

## Tips for Similar Problems
1. Consider sorting by start time
2. Track resource availability efficiently
3. Maintain original indices
4. Look for reuse opportunities

## Implementation Notes
1. Data Structure Choice
   - Range struct for intervals
   - Multiset for end time tracking
   - Vector for room assignments
   - Custom comparator for sorting

2. Algorithm Steps
   - Sort by arrival time
   - Try to reuse earliest ending room
   - Allocate new room if needed
   - Track assignments for output

## Why It Works
1. Sorting ensures sequential processing
2. Earliest ending room is optimal choice
3. Multiset maintains sorted end times
4. Room reuse minimizes total rooms