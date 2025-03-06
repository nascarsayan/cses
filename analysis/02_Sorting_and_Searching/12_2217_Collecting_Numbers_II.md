# Collecting Numbers II

[Problem Link](https://cses.fi/problemset/task/2217) | [Solution Link](../../solutions/02_Sorting_and_Searching/12_2217_Collecting_Numbers_II.cpp)

## TL;DR
Track inversions between consecutive numbers and update them efficiently after each swap operation. Number of rounds equals number of inversions plus one.

## Problem Overview
Same as Collecting Numbers I, but now we need to handle m swap operations and report the number of rounds needed after each swap.

## Solution Approach
Instead of using sets like in part I, we need a more dynamic approach:

1. **Inversion Tracking**
   - Count inversions between consecutive numbers (i, i+1)
   - Store both number→position and position→number mappings
   - Number of rounds = number of inversions + 1

2. **Smart Swap Updates**
   - Only need to check numbers affected by swap
   - Track positions that could create/remove inversions
   - Four possible affected positions: n1-1, n1, n2-1, n2
   - Update inversions count by checking these positions

## Key Learning Points
1. **Dynamic Updates**
   - Maintain both position and value mappings
   - Only update affected inversions
   - Handle boundary cases with dummy values

2. **Implementation Details**
   - Use 1-based indexing for simplicity
   - Add sentinel values at ends (0 and n+1)
   - Track position changes efficiently

## Common Pitfalls
1. Not handling boundary numbers correctly
2. Missing some affected positions
3. Double counting inversions
4. Wrong update order during swaps

## Complexity
- Time Complexity: O(m) for m swaps
- Space Complexity: O(n)
- Each swap operation: O(1)

## Extended Learning
- Related concepts:
  1. Inversion counting in arrays
  2. Dynamic sequence maintenance
  3. Range update problems
  4. Position tracking with swaps

## Tips for Similar Problems
1. Consider what information needs updating
2. Look for minimal set of changes
3. Use boundary sentinels for cleaner code
4. Track both forward and reverse mappings

## Implementation Notes
1. Bidirectional Mapping
   - nums[pos] gives number at position
   - pos[num] gives position of number
   - Both needed for efficient updates

2. Affected Positions
   - When swapping numbers n1 and n2:
   - Check relations: (n1-1,n1), (n1,n1+1), (n2-1,n2), (n2,n2+1)

## Why It Works
1. Only local changes affect round count
2. Inversion count directly relates to rounds needed
3. Swaps only affect adjacent number relationships
4. Adding/removing inversions updates rounds correctly