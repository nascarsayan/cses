# Collecting Numbers

[Problem Link](https://cses.fi/problemset/task/2216) | [Solution Link](../../solutions/02_Sorting_and_Searching/11_2216_Collecting_Numbers.cpp)

## TL;DR
Count how many times we need to restart collection by tracking when a number appears before its predecessor in the sequence.

## Problem Overview
Given a permutation of numbers 1 to n, we need to collect numbers in increasing order by scanning left to right multiple times. Find minimum number of scans needed.

## Solution Approach
The solution uses a clever observation about sequence breaks:

1. **Key Observation**
   - Each number needs its predecessor to be collected first
   - Need new round when current number's predecessor hasn't been seen
   - Use set to track currently "active" numbers in current round

2. **Implementation Details**
   - For each number x in array:
     * If x-1 exists in set, remove it (can continue sequence)
     * Add x to set (new active sequence)
   - Final set size = number of rounds needed

## Key Learning Points
1. **Sequence Break Analysis**
   - Each break in increasing sequence forces new round
   - Can collect multiple increasing subsequences in one round
   - Order of collection within round doesn't matter

2. **Set Usage**
   - Unordered_set for O(1) operations
   - Set tracks active sequence endpoints
   - Dynamic maintenance of sequences

## Common Pitfalls
1. Trying to simulate actual collection process
2. Not handling case when 1 appears late
3. Overcomplicated tracking of sequences
4. Missing that multiple increasing subsequences can be collected in same round

## Complexity
- Time Complexity: O(n)
- Space Complexity: O(n)

## Extended Learning
- Related concepts:
  1. Longest Increasing Subsequence
  2. Sequence partitioning
  3. Permutation cycles
  4. Greedy sequence collection

## Tips for Similar Problems
1. Look for sequence breaks/discontinuities
2. Consider what forces new rounds/operations
3. Try to avoid simulation when possible
4. Draw out small examples to spot patterns

## Real-world Applications
- Task scheduling with dependencies
- Assembly line sequencing
- Document version control
- Resource collection planning

## Why It Works
1. Each time we can't continue sequence, need new round
2. Set size tracks minimal breaks needed
3. Numbers between breaks can be collected in same round
4. Greedy left-to-right collection is optimal