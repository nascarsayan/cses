# Two Sets

## TL;DR
This problem involves dividing the numbers 1 to n into two sets of equal sum. The solution uses mathematical properties to determine if such a division is possible and constructs the sets accordingly.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1092)

Your task is to divide the numbers 1, 2, ..., n into two sets of equal sum.

## Approach
The approach to solve this problem is straightforward:

1. Check if the sum of the first n natural numbers is even. If not, print "NO".
2. If the sum is even, use a greedy approach to construct the two sets.
3. Start from the largest number and add it to the first set until the remaining sum is less than the current number.
4. Add the remaining sum to the first set and the rest of the numbers to the second set.
5. Print the sets.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/08_1092_Two_Sets.py)

```python
n = int(input())
if n % 4 in [1, 2]:
  print("NO")
else:
  print("YES")
  sum_rem = (n * (n+1)) // 4
  s1 = set()
  for i in range(n, 1, -1):
    if sum_rem == 0:
      break
    if sum_rem < i:
      s1.add(sum_rem)
      break
    s1.add(i)
    sum_rem -= i
  print(len(s1))
  print(" ".join(list(map(str, s1))))
  print(n-len(s1))
  for i in range(1, n+1):
    if i not in s1:
      print(i, end=" ")
  print()
```

The solution works as follows:
1. Read the input number n.
2. Check if n % 4 is 1 or 2, and print "NO" if true.
3. If n % 4 is 0 or 3, print "YES".
4. Calculate the target sum for each set as (n * (n+1)) // 4.
5. Use a greedy approach to construct the first set by adding the largest numbers until the remaining sum is less than the current number.
6. Add the remaining sum to the first set and the rest of the numbers to the second set.
7. Print the sets.

## Time and Space Complexity
- **Time Complexity**: O(n) where n is the input value, as we iterate through the numbers from 1 to n.
- **Space Complexity**: O(n) to store the sets.

## Key Insights
1. This problem teaches us to handle partitioning problems and use mathematical properties to determine feasibility.
2. It emphasizes the importance of edge cases, such as n being 1 or 2.
3. The problem is a good exercise in greedy algorithms and set construction.

## Common Pitfalls
1. Forgetting to handle the case where the sum of the first n natural numbers is odd.
2. Incorrectly calculating the target sum for each set.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to divide the numbers into more than two sets? The approach would be more complex and require different algorithms.
2. What if the numbers are not consecutive? The solution would still work, but we need to adjust the target sum calculation accordingly.
3. What if we need to find all possible divisions? The approach would depend on the constraints and require more advanced algorithms.