# Permutations

## TL;DR
This problem involves constructing a permutation of integers from 1 to n such that no two adjacent elements have a difference of 1. The solution uses a simple pattern to achieve this.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1070)

A permutation of integers 1, 2, ..., n is called beautiful if there are no adjacent elements whose difference is 1. Given n, construct a beautiful permutation if such a permutation exists.

## Approach
The approach to solve this problem is straightforward:

1. If n is 1, the only permutation is [1].
2. If n is less than 4 (except 1), it's impossible to create a beautiful permutation, so print "NO SOLUTION".
3. For n >= 4, we can construct the permutation by placing all even numbers first, followed by all odd numbers.
4. This ensures that no two adjacent elements have a difference of 1.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/05_1070_Permutations.py)

```python
n = int(input())
if n == 1:
  print("1")
elif n < 4:
  print("NO SOLUTION")
else:
  for st in [n-1, n]:
    for i in range(st, 0, -2):
      print(i, end=' ')
print()
```

The solution works as follows:
1. Read the input number n.
2. Check if n is 1, and print 1 if true.
3. Check if n is less than 4, and print "NO SOLUTION" if true.
4. For n >= 4, iterate through the numbers starting from n-1 and n, decrementing by 2 each time, and print them.
5. This ensures that all even numbers are printed first, followed by all odd numbers.

## Time and Space Complexity
- **Time Complexity**: O(n) where n is the length of the permutation, as we iterate through the numbers once.
- **Space Complexity**: O(1) as we only use a few integer variables for counting.

## Key Insights
1. This problem teaches us to handle permutations and use simple patterns to achieve desired properties.
2. It emphasizes the importance of edge cases, such as n being less than 4.
3. The problem is a good exercise in permutation construction and basic iteration techniques.

## Common Pitfalls
1. Forgetting to handle the case where n is 1.
2. Not handling the case where n is less than 4 correctly.
3. Incorrectly constructing the permutation by not following the even-odd pattern.

## Extensions
1. What if we need to construct a permutation with a different property? We could use a similar approach with different patterns.
2. What if the range of numbers is different? The solution would still work, but we need to adjust the pattern accordingly.
3. What if we need to find all possible beautiful permutations? We could use a backtracking approach to generate all permutations and filter them.