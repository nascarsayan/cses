# Gray Code

## TL;DR
This problem involves generating a Gray code for a given length n. The solution uses bit manipulation to generate the Gray code sequence efficiently.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/2205)

A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one). Your task is to create a Gray code for a given length n.

## Approach
The approach to solve this problem is straightforward:

1. Iterate through the range from 0 to 2^n - 1.
2. For each number, generate the corresponding Gray code using bit manipulation.
3. Print the Gray code for each number.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/13_2205_Gray_Code.py)

```python
n = int(input())
for r in range(2**n):
  for c in range(n, 0, -1):
    batch = (r // (2**c))
    isAsc = batch % 2 == 0
    aboveMid = r % (2**c) < (2**(c-1))
    is1 = isAsc ^ aboveMid
    print(1 if is1 else 0, end='')
  print()
```

The solution works as follows:
1. Read the input number n.
2. Iterate through the range from 0 to 2^n - 1.
3. For each number, iterate through the bits from n to 1.
4. Calculate the batch and determine if the current bit is ascending or descending.
5. Determine if the current bit is above the midpoint and calculate the bit value using XOR.
6. Print the bit value for each bit and move to the next line for each number.

## Time and Space Complexity
- **Time Complexity**: O(2^n * n) for generating and printing the Gray code sequence, where n is the length of the bit strings.
- **Space Complexity**: O(1) as we only use a few integer variables for counting.

## Key Insights
1. This problem teaches us to handle bit manipulation and use it to generate sequences efficiently.
2. It emphasizes the importance of understanding bitwise operations and their applications.
3. The problem is a good exercise in bit manipulation and sequence generation techniques.

## Common Pitfalls
1. Forgetting to handle the case where n is very small.
2. Incorrectly implementing the bit manipulation logic.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to generate a different type of code? The approach would depend on the specific code and its properties.
2. What if the bit strings have different lengths? The solution would still work, but we need to adjust the range and bit manipulation accordingly.
3. What if we need to find the Gray code for a specific number? The approach would depend on the specific problem constraints.