# Reading Books

[Problem Link](https://cses.fi/problemset/task/1631) | [Solution Link](../../solutions/02_Sorting_and_Searching/23_1631_Reading_Books.cpp)

## TL;DR
Compare longest book time with sum of other books. If longest ≤ sum, answer is total sum; else it's 2 × longest.

## Problem Overview
Two people need to read all books sequentially, can't read same book simultaneously. Find minimum total time needed.

## Solution Approach
This problem has a beautiful mathematical insight:

1. **Key Observation**
   - Sort books by duration
   - Consider longest book vs sum of others
   - Two possible scenarios determine answer
   - No need for complex scheduling

2. **Two Cases**
   - Case 1: longest ≤ sum of others
     * Can interleave readings
     * Answer = total sum
   - Case 2: longest > sum of others
     * Must read longest book sequentially
     * Answer = 2 × longest

## Key Learning Points
1. **Problem Reduction**
   - Complex scheduling reduces to simple comparison
   - Only longest book matters
   - Rest can be treated as single unit
   - No need for explicit scheduling

2. **Proof of Optimality**
   - Can't do better than total sum
   - Must wait for longest book twice if dominant
   - Other orderings don't help
   - Simple formula covers all cases

## Common Pitfalls
1. Trying complex scheduling algorithms
2. Not handling single book case
3. Integer overflow in sum calculation
4. Overcomplicated solution approaches

## Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(1)
- Single pass for sum calculation

## Extended Learning
- Related concepts:
  1. Bottleneck identification
  2. Rate-limiting steps
  3. Resource sharing optimization
  4. Scheduling with dependencies

## Tips for Similar Problems
1. Look for simplifying observations
2. Consider extreme cases
3. Think about bottlenecks
4. Try to reduce to simpler problem

## Why It Works
1. If longest ≤ sum:
   - Can fill waiting time with other books
   - Total time = sum of all books
2. If longest > sum:
   - Must read longest book twice
   - Other books fit in gaps
   - Can't do better than 2 × longest

## Mathematical Insight
The elegant solution comes from realizing that:
- The scheduling complexity is irrelevant
- Only the relationship between longest and others matters
- The bottleneck dictates the minimum time
- All other optimizations are unnecessary