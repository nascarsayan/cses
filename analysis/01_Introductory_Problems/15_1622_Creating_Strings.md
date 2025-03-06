# Creating Strings

## TL;DR
This problem involves generating all different strings that can be created using the characters of a given string. The solution uses permutations and character frequency counting to generate the strings efficiently.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1622)

Given a string, your task is to generate all different strings that can be created using its characters.

## Approach
The approach to solve this problem is straightforward:

1. Count the frequency of each character in the string.
2. Use a recursive function to generate all permutations of the string.
3. Print the total number of unique permutations and the permutations in alphabetical order.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/15_1622_Creating_Strings.py)

```python
from typing import List, Tuple
from collections import Counter
from functools import cache
def permute(arr: List[Tuple[str, int]], size: int, combo: str):
  if len(combo) == size:
    print(combo)
    return
  for i in range(len(arr)):
    ch, cnt = arr[i]
    if cnt == 0:
      continue
    arr[i] = (ch, cnt-1)
    permute(arr, size, combo+ch)
    arr[i] = (ch, cnt)
s = input()
@cache
def factorial(n):
  if n < 2:
    return 1
  return n * factorial(n-1)
cnt = list(sorted(Counter(s).items()))
tot = factorial(len(s))
for _, freq in cnt:
  tot //= factorial(freq)
print(tot)
permute(cnt, len(s), '')
```

The solution works as follows:
1. Define a recursive function permute to generate all permutations of the string.
2. Count the frequency of each character using the Counter class from the collections module.
3. Calculate the total number of unique permutations using factorials and character frequencies.
4. Print the total number of unique permutations.
5. Call the permute function to print the permutations in alphabetical order.

## Time and Space Complexity
- **Time Complexity**: O(n!) for generating and printing the permutations, where n is the length of the string.
- **Space Complexity**: O(n) for storing the character frequencies and the resulting permutations.

## Key Insights
1. This problem teaches us to handle permutations and use character frequencies to generate unique permutations efficiently.
2. It emphasizes the importance of understanding recursion and its applications.
3. The problem is a good exercise in recursion, permutations, and frequency counting techniques.

## Common Pitfalls
1. Forgetting to handle the case where the string has duplicate characters.
2. Incorrectly implementing the recursive function without handling the character frequencies correctly.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to generate permutations with specific properties? The approach would depend on the specific properties and constraints.
2. What if the string contains special characters? The solution would still work, but we need to adjust the frequency counting accordingly.
3. What if we need to find the number of permutations for a different type of problem? The approach would depend on the specific problem constraints.