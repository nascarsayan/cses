# Ferris Wheel

[Problem Link](https://cses.fi/problemset/task/1090) | [Solution Link](../../solutions/02_Sorting_and_Searching/03_1090_Ferris_Wheel.py)

## TL;DR
Use two-pointer technique with sorted weights to pair heaviest possible child with lightest possible child while respecting weight limit, minimizing gondola count.

## Problem Overview
We need to assign children to gondolas where each gondola can hold up to 2 children and has a maximum weight limit. The goal is to use the minimum number of gondolas possible.

## Solution Approach
The key insight is to try to pair the heaviest children with the lightest ones whenever possible:

1. **Sort and Two Pointers**
   - Sort all weights in ascending order
   - Use left pointer for lightest child
   - Use right pointer for heaviest child
   - Try to pair them if their sum doesn't exceed limit

2. **Greedy Strategy**
   - If we can't pair the heaviest child with the current lightest
   - The heaviest must go alone (no other pairing would work)
   - Move to next heaviest and try again

## Key Learning Points
1. **Optimal Pairing Strategy**
   - Always try to pair heaviest with lightest
   - If they can't be paired, heaviest must go alone
   - This greedy approach guarantees minimum gondolas

2. **Two-Pointer Variation**
   - Unlike standard two-pointer sum problems
   - We move pointers inward regardless of sum
   - Special handling for odd number of children

## Common Pitfalls
1. Not sorting the weights first
2. Wrong handling of the case when left == right (last child)
3. Trying to optimize by pairing close weights (non-optimal)
4. Forgetting that a gondola can take one child

## Complexity
- Time Complexity: O(n log n) for sorting
- Space Complexity: O(1) extra space

## Extended Learning
- Similar pattern in:
  - Boat saving problem
  - Bin packing with at most 2 items
  - Pairing problems with constraints

## Tips for Similar Problems
1. Consider sorting when dealing with pairing/grouping
2. Think about extreme cases (heaviest/lightest)
3. Try to prove greedy approach correctness
4. Watch out for off-by-one errors with pointers