# Apartments

[Problem Link](https://cses.fi/problemset/task/1084) | [Solution Link](../../solutions/02_Sorting_and_Searching/02_1084_Apartments.cpp)

## TL;DR
Two-pointer technique with sorted arrays to match apartment seekers with available apartments, considering a tolerance range (k) for size differences.

## Problem Overview
We need to match applicants to apartments where each applicant has a desired size and will accept an apartment if its size is within ±k units of their desired size. The goal is to accommodate maximum number of applicants.

## Solution Approach
This is a classic example of the two-pointer technique with sorted arrays:

1. **Sorting**
   - Sort both the desired sizes and actual apartment sizes
   - This allows us to move through both arrays efficiently

2. **Two-Pointer Traversal**
   - One pointer (d) for desired sizes
   - One pointer (a) for actual apartment sizes
   - When we find a match within tolerance k, increment both pointers
   - If apartment is too small, move apartment pointer
   - If apartment is too big, move desired pointer

## Key Learning Points
1. **Two-Pointer Optimization**
   - Shows why sorting first makes the solution efficient
   - Demonstrates how to handle range matches (not just exact matches)
   - Avoids the O(n×m) complexity of checking every combination

2. **Greedy Strategy**
   - Always try to match the smallest available apartment with the smallest suitable applicant
   - This greedy choice leads to optimal solution

## Common Pitfalls
1. Not sorting the arrays first
2. Using nested loops instead of two pointers
3. Incorrect handling of the k-difference range
4. Not handling edge cases when one pointer reaches the end

## Complexity
- Time Complexity: O(n log n + m log m) due to sorting
- Space Complexity: O(1) extra space (excluding input arrays)

## Extended Learning
- Similar pattern appears in:
  - Merge operation in merge sort
  - Finding pairs with given difference
  - Interval matching problems

## Tips for Similar Problems
1. When dealing with range matches, consider sorting first
2. Two pointers are often useful when working with sorted arrays
3. Draw out examples to understand pointer movement logic
4. Consider what happens at array boundaries