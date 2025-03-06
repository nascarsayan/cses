# Two Knights

## TL;DR
This problem involves counting the number of ways two knights can be placed on a k x k chessboard so that they do not attack each other. The solution uses combinatorial mathematics to determine the number of valid placements.

## Problem Summary
[Problem Link](https://cses.fi/problemset/task/1072)

Your task is to count for k=1,2,...,n the number of ways two knights can be placed on a k x k chessboard so that they do not attack each other.

## Approach
The approach to solve this problem is straightforward:

1. Calculate the total number of ways to place two knights on a k x k chessboard.
2. Subtract the number of ways two knights can attack each other.
3. Repeat this for all values of k from 1 to n.

## Solution Analysis
[Solution Link](/solutions/01_Introductory_Problems/07_1072_Two_Knights.py)

```python
_n = int(input())
for n in range(1, _n+1):
  total = ((n * n) * ((n * n)-1)) // 2
  excluded = ((n-1) * (n-2)) * 4
  res = total - excluded
  print(res)
```

The solution works as follows:
1. Read the input number n.
2. For each value of k from 1 to n, calculate the total number of ways to place two knights on a k x k chessboard using the formula (k^2 * (k^2 - 1)) / 2.
3. Calculate the number of ways two knights can attack each other using the formula 4 * (k-1) * (k-2).
4. Subtract the number of attacking placements from the total placements to get the number of valid placements.
5. Print the result for each value of k.

## Time and Space Complexity
- **Time Complexity**: O(n) where n is the input value, as we iterate through the values from 1 to n.
- **Space Complexity**: O(1) as we only use a few integer variables for counting.

## Key Insights
1. This problem teaches us to handle combinatorial counting and use mathematical formulas to determine valid placements.
2. It emphasizes the importance of edge cases, such as small values of k.
3. The problem is a good exercise in combinatorial mathematics and pattern recognition.

## Common Pitfalls
1. Forgetting to handle the case where k is 1 or 2.
2. Incorrectly calculating the number of attacking placements.
3. Not handling the input parsing correctly.

## Extensions
1. What if we need to count the number of ways to place three knights? The approach would be similar, but the formulas would be more complex.
2. What if the chessboard has a different size? The solution would still work, but we need to adjust the formulas accordingly.
3. What if we need to find the number of ways to place knights on a non-square board? The approach would depend on the board's dimensions and structure.