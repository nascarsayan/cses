# Trailing Zeros

## TL;DR
This problem involves calculating the number of trailing zeros in the factorial of a given number n. The solution uses the properties of factorials and prime factorization to determine the number of trailing zeros efficiently.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1618)

Your task is to calculate the number of trailing zeros in the factorial n!.

## Approach
The approach to solve this problem is straightforward:

1. The number of trailing zeros in n! is determined by the number of times 10 is a factor in n!.
2. Since 10 is the product of 2 and 5, and there are usually more factors of 2 than 5, the number of trailing zeros is determined by the number of times 5 is a factor in n!.
3. Count the number of multiples of 5, 25, 125, etc., in the range from 1 to n.
4. Sum these counts to get the total number of trailing zeros.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/10_1618_Trailing_Zeros.py)

```python
n = int(input())
res = 0
div = 5
while div <= n:
  res += n // div
  div *= 5
print(res)
```

The solution works as follows:
1. Read the input number n.
2. Initialize the result counter to 0 and the divisor to 5.
3. While the divisor is less than or equal to n, add the integer division of n by the divisor to the result counter and multiply the divisor by 5.
4. Print the result counter.

## Time and Space Complexity
- **Time Complexity**: O(log n) for the while loop, as we divide the problem size by 5 at each step.
- **Space Complexity**: O(1) as we only use a few integer variables for counting.

## Key Insights
1. This problem teaches us to handle large factorials and use prime factorization to determine properties efficiently.
2. It emphasizes the importance of efficient algorithms for large inputs, such as counting factors of 5.
3. The problem is a good exercise in mathematical reasoning and prime factorization techniques.

## Common Pitfalls
1. Forgetting to handle the case where n is very small.
2. Incorrectly implementing the while loop without updating the divisor correctly.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to calculate the number of trailing zeros in a different base? The approach would depend on the base and its prime factors.
2. What if the input value is very large? The solution would still work, but we need to ensure efficient handling of large numbers.
3. What if we need to find the number of trailing zeros in a product of multiple factorials? The approach would depend on the specific problem constraints.