# Weird Algorithm

## TL;DR
This problem introduces the famous Collatz conjecture. The solution involves implementing a simple recursive sequence where each term is derived from the previous one by dividing by 2 if it's even, or multiplying by 3 and adding 1 if it's odd.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1068)

We need to simulate an algorithm that takes a positive integer n and transforms it as follows:
- If n is even, divide it by 2
- If n is odd, multiply it by 3 and add 1
- Repeat until n becomes 1

Our task is to print the entire sequence of numbers.

## Approach
This is a straightforward implementation problem that serves as a gentle introduction to the CSES problem set. The algorithm is explicitly defined in the problem statement, and we just need to follow it step by step:

1. Start with the input number n
2. Print n
3. Apply the transformation rule
4. Repeat until n becomes 1

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/01_1068_Weird_Algorithm.py)

```python
n = int(input())
while n > 1:
  print(n, end=" ")
  n = n // 2 if n % 2 == 0 else n * 3 + 1
print(n)
```

The solution is concise and elegant:
- We read the input integer
- We use a while loop to continue until n becomes 1
- Inside the loop, we print the current value of n
- We apply the transformation rule using a conditional expression
- Finally, we print the last value (which is 1)

## Time and Space Complexity
- **Time Complexity**: O(k) where k is the number of steps in the sequence before reaching 1. This is an open mathematical problem and not known to be bounded by a simple function of n.
- **Space Complexity**: O(1) as we only store the current value of n.

## Key Insights
1. This problem introduces the [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture), a famous unsolved problem in mathematics.
2. Despite its simple formulation, whether all positive integers eventually reach 1 under this process remains an open question in mathematics.
3. For competitive programming, this problem teaches us to carefully follow problem instructions and handle a simple iterative process.

## Common Pitfalls
1. Forgetting to print the final value (1) at the end of the sequence
2. Not handling the printing format correctly (with spaces between numbers)
3. Using inefficient calculations for large numbers (though not an issue with the given constraints)

## Extensions
For larger numbers, the sequence can grow very large before eventually reaching 1. The problem constraints are modest (n ≤ 10^6), but for much larger numbers, the sequence could potentially overflow standard integer types.