# Missing Number

## TL;DR
This problem introduces the mathematical sum technique. By calculating the expected sum of numbers from 1 to n and comparing with the actual sum of the provided numbers, we can efficiently find the missing number.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1083)

You are given n-1 distinct numbers from the range 1 to n. Your task is to find the one missing number.

## Approach
There are several approaches to this problem:

1. **Mathematical Approach**: Calculate the sum of all numbers from 1 to n using the formula n*(n+1)/2, then subtract the sum of the given n-1 numbers. The difference is the missing number.
2. **XOR Approach**: XOR all numbers from 1 to n, and then XOR with all given numbers. The result is the missing number.
3. **Marking Approach**: Create an array of size n+1 and mark each number that appears. The unmarked number is the missing one.

The mathematical approach is the most efficient in terms of both time and space complexity.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/02_1083_Missing_Number.py)

```python
n = int(input())
sigma_n = (n * (n + 1)) // 2
res = sigma_n - sum(list(map(int, input().strip().split())))
print(res)
```

The solution uses the mathematical approach:
1. Read the input number n.
2. Calculate the sum of all numbers from 1 to n using the formula n*(n+1)/2.
3. Calculate the sum of the n-1 given numbers.
4. The missing number is the difference between the expected sum and the actual sum.

## Time and Space Complexity
- **Time Complexity**: O(n) for reading the input array and calculating its sum.
- **Space Complexity**: O(n) to store the input array.

## Key Insights
1. This problem introduces a common mathematical technique in competitive programming: using formulas for arithmetic sequences.
2. The arithmetic sum formula n*(n+1)/2 is a fundamental tool that appears in many problems.
3. This problem demonstrates how mathematical properties can be leveraged to avoid naive approaches like sorting or searching.

## Common Pitfalls
1. Integer overflow for large values of n (not an issue with Python but could be in languages with fixed-size integers).
2. Using inefficient approaches like sorting the array and then finding the gap, which would be O(n log n).
3. Not handling the input parsing correctly, especially when reading the second line of space-separated integers.

## Extensions
1. What if there are multiple missing numbers? You could use a similar approach with a hashtable or bit manipulation.
2. What if the range starts from a number other than 1? You would need to adjust the sum formula accordingly.
3. What if the numbers are not consecutive? The mathematical approach wouldn't work, and you'd need to use a hashtable or sorting.