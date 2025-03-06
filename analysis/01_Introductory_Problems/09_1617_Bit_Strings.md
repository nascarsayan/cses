# Bit Strings

## TL;DR
This problem involves calculating the number of bit strings of length n. The solution uses modular exponentiation to efficiently compute the result.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1617)

Your task is to calculate the number of bit strings of length n. The result should be printed modulo 10^9 + 7.

## Approach
The approach to solve this problem is straightforward:

1. The number of bit strings of length n is 2^n.
2. Use modular exponentiation to compute 2^n % (10^9 + 7) efficiently.
3. Print the result.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/09_1617_Bit_Strings.py)

```python
from functools import cache
@cache
def pow2(n: int):
  if n < 2:
    return int(2**n)
  return (pow2(n // 2) * pow2((n+1) // 2)) % (10**9 + 7)
n = int(input())
print(pow2(n))
```

The solution works as follows:
1. Define a recursive function pow2 to compute 2^n using memoization.
2. If n is less than 2, return 2^n directly.
3. Otherwise, compute 2^(n//2) and 2^((n+1)//2) recursively and multiply them, taking the result modulo 10^9 + 7.
4. Read the input number n and print the result of pow2(n).

## Time and Space Complexity
- **Time Complexity**: O(log n) for the recursive function, as we divide the problem size by 2 at each step.
- **Space Complexity**: O(log n) for the recursion stack and memoization.

## Key Insights
1. This problem teaches us to handle large exponentiation and use modular arithmetic to avoid overflow.
2. It emphasizes the importance of efficient algorithms for large inputs, such as modular exponentiation.
3. The problem is a good exercise in recursion and memoization techniques.

## Common Pitfalls
1. Forgetting to take the result modulo 10^9 + 7.
2. Incorrectly implementing the recursive function without memoization, leading to inefficiency.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to calculate the number of bit strings of length n with specific properties? The approach would depend on the properties and constraints.
2. What if the modulo value is different? The solution would still work, but we need to adjust the modulo value accordingly.
3. What if we need to compute other powers efficiently? The approach would be similar, using modular exponentiation.