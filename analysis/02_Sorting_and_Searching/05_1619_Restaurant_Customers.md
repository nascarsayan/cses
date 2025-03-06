# Restaurant Customers

[Problem Link](https://cses.fi/problemset/task/1619) | [C++ Solution](../../solutions/02_Sorting_and_Searching/05_1619_Restaurant_Customers.cpp) | [Python Solution](../../solutions/02_Sorting_and_Searching/05_1619_Restaurant_Customers.py)

## TL;DR
Use line sweep technique by converting time intervals into entry/exit points and processing them in sorted order to track maximum overlapping intervals.

## Problem Overview
We need to find the maximum number of customers present in a restaurant at any point in time, given their arrival and departure times.

## Solution Approach
This problem introduces the powerful line sweep (also known as sweep line) algorithm:

1. **Event Point Transformation**
   - Convert each interval into two events:
     * Arrival (+1 to customer count)
     * Departure (-1 from customer count)
   - Store events as (time, count_change) pairs

2. **Line Sweep Process**
   - Sort all events by time
   - Sweep through events chronologically
   - Keep running sum of count changes
   - Track maximum count seen

## Key Learning Points
1. **Line Sweep Technique**
   - Perfect for interval overlap problems
   - Transforms interval problem into point problem
   - Reduces time complexity from O(n²) to O(n log n)

2. **Event Processing**
   - Using +1/-1 for entry/exit events
   - Sorting ensures chronological processing
   - Running sum tracks current overlap count

## Common Pitfalls
1. Not handling all events in strict time order
2. Forgetting to track maximum during sweep
3. Incorrect event point generation
4. Not considering edge cases (single customer)

## Complexity
- Time Complexity: O(n log n) for sorting events
- Space Complexity: O(n) for storing events

## Extended Learning
- Similar patterns in:
  - Meeting room allocation
  - Event scheduling conflicts
  - Resource usage tracking
  - Skyline problem

## Tips for Similar Problems
1. When dealing with intervals, consider converting to points
2. Think about what each point represents (+1/-1)
3. Sort events before processing
4. Keep track of running totals during sweep

## Python vs C++ Implementation Notes
Both solutions follow identical logic but with language-specific optimizations:
- C++: Uses vector<pair> with reserve for memory efficiency
- Python: Uses list of tuples with extend for cleaner syntax
- Both achieve same time complexity but C++ has better constant factors