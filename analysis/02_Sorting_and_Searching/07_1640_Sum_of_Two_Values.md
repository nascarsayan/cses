# Sum of Two Values

[Problem Link](https://cses.fi/problemset/task/1640) | [Solution Link](../../solutions/02_Sorting_and_Searching/07_1640_Sum_of_Two_Values.cpp)

## TL;DR
Find two numbers in array that sum to target using two-pointer technique on sorted array while maintaining original indices.

## Problem Overview
Given an array of n integers and a target sum x, find two distinct positions whose values sum to x.

## Solution Approach
This is the classic two-sum problem with a position-tracking twist:

1. **Index Preservation**
   - Store (value, position) pairs
   - Sort pairs by value
   - Keep original 1-based indices for output

2. **Two-Pointer Search**
   - Use left and right pointers
   - Move inward based on sum comparison:
     * If sum = target: found solution
     * If sum < target: increase left pointer
     * If sum > target: decrease right pointer

## Key Learning Points
1. **Handling Indices**
   - Need to store original positions before sorting
   - Using pair<int,int> for value-index pairs
   - 1-based indexing requirement

2. **Two-Pointer Efficiency**
   - O(n log n) sorting but O(n) search
   - Better than O(n²) naive approach
   - Works because array is sorted

## Common Pitfalls
1. Forgetting to store original indices
2. Using 0-based indexing in output
3. Not handling "IMPOSSIBLE" case
4. Incorrect sum comparison logic

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)

## Extended Learning
- Alternative approaches:
  1. Hash Map solution O(n) time, O(n) space
  2. Binary search on sorted array
  3. Two pointers on sorted array (current solution)

## Tips for Similar Problems
1. Consider if sorting helps
2. Remember to preserve needed information
3. Think about space vs time tradeoffs
4. Watch out for index requirements

## Real-world Applications
- Financial calculations
- Database querying
- Resource matching
- Target value searching

## Why Two Pointers Work
1. Sorted array gives direction
2. Sum too small → need larger value
3. Sum too big → need smaller value
4. Never need to backtrack