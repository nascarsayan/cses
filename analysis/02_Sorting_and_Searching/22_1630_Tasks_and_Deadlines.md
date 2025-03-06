# Tasks and Deadlines

[Problem Link](https://cses.fi/problemset/task/1630) | [Solution Link](../../solutions/02_Sorting_and_Searching/22_1630_Tasks_and_Deadlines.cpp)

## TL;DR
Sort tasks by duration (ascending) and process them in that order. Each task's contribution to final reward is deadline minus finish time.

## Problem Overview
Given n tasks with durations and deadlines, find the maximum possible reward where reward for each task is (deadline - finish_time).

## Solution Approach
The key insight leads to a surprisingly simple solution:

1. **Optimal Ordering**
   - Sort tasks by duration in ascending order
   - Process shorter tasks first
   - Total finish time minimization problem
   - Store all deadlines sum initially

2. **Reward Calculation**
   - Sum all deadlines initially (positive part)
   - For each task in sorted order:
     * Subtract (n-i)*duration from total
     * This accounts for each task's contribution to all later finish times

## Key Learning Points
1. **Greedy Strategy Proof**
   - If two tasks are swapped, longer task delays more tasks
   - Every task after a longer task is delayed more
   - Therefore, shorter tasks should come first
   - Exchange argument proves optimality

2. **Clever Math**
   - No need to track individual finish times
   - Each duration affects all subsequent tasks
   - One-pass solution possible
   - Avoid explicit finish time calculations

## Common Pitfalls
1. Trying dynamic programming (overkill)
2. Explicitly calculating finish times
3. Sorting by deadline (wrong approach)
4. Integer overflow in calculations

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(n)
- Single pass after sorting

## Extended Learning
- Related concepts:
  1. Job scheduling problems
  2. Minimizing total lateness
  3. Weighted completion time
  4. Exchange arguments in proofs

## Tips for Similar Problems
1. Look for greedy opportunities
2. Consider effect on future tasks
3. Think about pairwise exchanges
4. Try to simplify calculations

## Real-world Applications
- Process scheduling
- Task prioritization
- Project management
- Assembly line optimization

## Why It Works
1. Shorter tasks minimize delays
2. Each task affects all later ones
3. Order is independent of deadlines
4. Linear contribution to total cost