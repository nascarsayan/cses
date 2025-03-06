# Missing Coin Sum

[Problem Link](https://cses.fi/problemset/task/2183) | [Solution Link](../../solutions/02_Sorting_and_Searching/10_2183_Missing_Coin_Sum.cpp)

## TL;DR
Sort coins and track prefix sums. If current coin value > prefix_sum + 1, then prefix_sum + 1 is the smallest impossible sum.

## Problem Overview
Given a set of coins with positive integer values, find the smallest sum that cannot be created using any subset of these coins.

## Solution Approach
This problem uses a clever greedy approach:

1. **Prefix Sum Property**
   - Sort coins in ascending order
   - For each prefix of array, track sum of all previous coins
   - If current coin > prefix_sum + 1, we found our answer
   - Otherwise, add current coin to prefix_sum

2. **Why It Works**
   - If prefix_sum = k, we can create all sums from 1 to k
   - If next coin > k + 1, we can't create sum k + 1
   - If next coin ≤ k + 1, we can extend our range up to k + coin_value

## Key Learning Points
1. **Constructible Sums Property**
   - With coins [1,2,4], can make 1,2,3,4,5,6,7
   - Key insight: no gaps allowed in constructible range

2. **Implementation Details**
   - Using long long for large sums
   - Sorting is crucial
   - Early termination when gap found

## Common Pitfalls
1. Not sorting the coins first
2. Integer overflow with regular ints
3. Not considering case when all sums possible
4. Wrong initialization of prefix sum

## Complexity
- Time Complexity: O(n log n) for sorting
- Space Complexity: O(1) extra space

## Extended Learning
- Related problems:
  1. Coin change with minimum coins
  2. Subset sum variations
  3. Knapsack problems
  4. Constructible range problems

## Tips for Similar Problems
1. Consider sorting when dealing with constructible sums
2. Look for early termination conditions
3. Watch for integer overflow
4. Draw out examples to understand patterns

## Real-world Applications
- Currency systems design
- Resource allocation
- Payment systems
- Denomination planning

## Why Greedy Works
1. Sorted order ensures we try smallest possibilities first
2. Can prove by induction that all sums up to prefix_sum are possible
3. First gap in sequence must be answer
4. No need to try combinations - prefix property is sufficient