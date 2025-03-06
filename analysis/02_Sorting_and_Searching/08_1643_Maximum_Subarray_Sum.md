# Maximum Subarray Sum

[Problem Link](https://cses.fi/problemset/task/1643) | [Solution Link](../../solutions/02_Sorting_and_Searching/08_1643_Maximum_Subarray_Sum.cpp)

## TL;DR
Use Kadane's Algorithm to find maximum subarray sum in one pass. Keep track of current sum, reset to 0 when negative.

## Problem Overview
Find the maximum sum possible from a contiguous subarray in an array of integers. The array can contain negative numbers.

## Solution Approach
This problem is solved using Kadane's Algorithm, a brilliant example of dynamic programming simplified:

1. **Kadane's Algorithm Core Idea**
   - At each position, decide:
     * Continue current subarray (add current element)
     * Start new subarray (reset to current element)
   - Decision based on whether current sum becomes negative

2. **Implementation Details**
   - Track current sum and maximum sum seen
   - If current sum goes negative, reset to 0
   - Update maximum sum at each step

## Key Learning Points
1. **Dynamic Programming Simplification**
   - No need for DP array
   - Only need to track current state
   - Beautiful example of space optimization

2. **Handling Edge Cases**
   - All negative numbers
   - Single element array
   - Empty subarrays not allowed

## Common Pitfalls
1. Using INT_MIN instead of LLONG_MIN for large numbers
2. Not handling all negative numbers case
3. Wrong initialization of result variable
4. Forgetting to update maximum sum at each step

## Complexity
- Time Complexity: O(n)
- Space Complexity: O(1)

## Extended Learning
- Variations of this problem:
  1. Print the actual subarray
  2. Maximum circular subarray sum
  3. Maximum subarray product
  4. Maximum sum with size constraints

## Tips for Similar Problems
1. Think about carrying forward vs starting fresh
2. Consider what information needs to be maintained
3. Look for opportunities to optimize space
4. Handle edge cases carefully

## Real-world Applications
- Stock market analysis (max profit subperiod)
- Signal processing
- Performance analysis
- Resource utilization tracking

## Why It Works
1. Negative prefix can't help maximum sum
2. Single pass sufficient due to optimal substructure
3. Local decisions lead to global optimum
4. Linear time guarantee with constant space