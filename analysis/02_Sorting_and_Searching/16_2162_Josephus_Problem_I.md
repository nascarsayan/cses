# Josephus Problem I

[Problem Link](https://cses.fi/problemset/task/2162) | [Solution Link](../../solutions/02_Sorting_and_Searching/16_2162_Josephus_Problem_I.cpp)

## TL;DR
Use an ordered set to simulate the circle of children, iterating and removing every second child until none remain.

## Problem Overview
n children stand in a circle. Starting from the first child, every second child is removed until no children remain. Output the order of removal.

## Solution Approach
This problem can be solved using a set to simulate the circular structure:

1. **Circle Simulation**
   - Set maintains children in order
   - Use iterator to track current position
   - Skip one child (next()) and remove next
   - Handle wrap-around at set end

2. **Iterator Management**
   - Store iterator before deletion
   - Move to next position after deletion
   - Reset to begin() when reaching end()
   - Special handling for last element

## Key Learning Points
1. **Set Iterator Operations**
   - next() for advancing iterator
   - erase() returns void in C++
   - Iterator invalidation after erase
   - Circular traversal handling

2. **Problem Pattern**
   - Classic Josephus problem with k=2
   - Mathematical solution exists
   - Set-based simulation is intuitive
   - Careful iterator management needed

## Common Pitfalls
1. Invalid iterator access after erase
2. Wrong wrap-around handling
3. Not handling last element correctly
4. Iterator increment/decrement errors

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Each removal: O(log n)

## Extended Learning
- Alternative solutions:
  1. Mathematical formula (O(n))
  2. Linked list implementation
  3. Array-based simulation
  4. Recursive solution

## Tips for Similar Problems
1. Consider mathematical patterns
2. Watch iterator invalidation
3. Handle boundary cases carefully
4. Think about data structure trade-offs

## Mathematical Connection
For k=2 (this problem):
- Position formula exists
- Can be solved in O(n)
- Binary representation pattern
- Recursive relation exists

## Why Set Works
1. Ordered nature maintains circle
2. Efficient element removal
3. Easy iterator manipulation
4. Simple wrap-around handling