# Factory Machines

[Problem Link](https://cses.fi/problemset/task/1620) | [Solution Link](../../solutions/02_Sorting_and_Searching/21_1620_Factory_Machines.cpp)

## TL;DR
Use binary search on the time needed to produce required products. For each time, check if machines can produce enough products.

## Problem Overview
Given n machines with different production times, find minimum time needed to produce t products when machines work in parallel.

## Solution Approach
Binary search on answer technique:

1. **Search Space Setup**
   - Minimum time: fastest machine's time
   - Maximum time: t × fastest machine's time
   - Binary search in this range

2. **Feasibility Check**
   - For given time T, each machine i produces ⌊T/k[i]⌋ items
   - Sum all products and compare with target t
   - If sum ≥ t, time is feasible
   - If sum < t, need more time

## Key Learning Points
1. **Binary Search on Answer**
   - When direct computation is hard
   - Need monotonic feasibility function
   - Careful range selection
   - Integer overflow handling

2. **Early Exit Optimization**
   - Stop summing when target reached
   - Sort machines for better pruning
   - Use long long for large numbers
   - Handle division carefully

## Common Pitfalls
1. Integer overflow in calculations
2. Wrong binary search boundaries
3. Not using long long integers
4. Division rounding errors

## Complexity
- Time Complexity: O(n log(t*min_time))
- Space Complexity: O(n)
- Each check: O(n)

## Extended Learning
- Related concepts:
  1. Binary search on monotonic functions
  2. Rate-limiting problems
  3. Parallel processing scheduling
  4. Optimization with feasibility checks

## Tips for Similar Problems
1. Consider binary search when:
   - Answer lies in a range
   - Can check feasibility
   - Problem asks for minimum/maximum
   - Direct solution is too slow

2. Implementation Advice
   - Start with boundary cases
   - Handle overflow carefully
   - Consider optimization opportunities
   - Test with large inputs

## Why Binary Search Works
1. Problem has monotonic property
2. Can verify feasibility efficiently
3. Search space is well-defined
4. Each machine's contribution is independent

## Real-world Applications
- Production planning
- Resource allocation
- Load balancing
- Throughput optimization